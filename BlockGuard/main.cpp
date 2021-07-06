//
//  main.cpp
//  BlockGuard
//
//  Created by Kendric Hood on 3/8/19.
//  Copyright © 2019 Kent State University. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <set>
#include <iostream>
#include <chrono>
#include <random>
#include <vector>

#include "./Common/Network.hpp"
#include "./Common/Peer.hpp"
#include "ExamplePeer.hpp"
#include "LinearPeer.hpp"
#include "LinearCoronaPeer.hpp"
#include "LinearChordPeer.hpp"
#include "./Common/ByzantineNetwork.hpp"
// UTIL
#include "./Common/Logger.hpp"

using std::vector; using std::string;

void Example(std::ofstream& logFile);
void Linear(std::ofstream& logFile, int churnRate);
void LinearCorona(std::ofstream& logFile, int churnRate);
void LinearChord(std::ofstream& logFile, int churnRate);
vector<int> createLinearUnderlay(int size, vector<string> ids);

int main(int argc, const char* argv[]) {
	srand((float)time(NULL));

	std::string algorithm = "linearChord";
	std::string filePath = "linearChord";

	if (algorithm == "example") {
		std::ofstream out;
		std::string file = filePath;
		out.open(file);
		if (out.fail()) {
			std::cerr << "Error: could not open file" << file << std::endl;
		}
		Example(out);
	}
	else if (algorithm == "linear") {
		for (int churnRate = 3; churnRate < 6; churnRate++) {
			for (int i = 1; i < 11; i++) {
				std::ofstream out;
				std::string file = filePath + "churnRate" + std::to_string(churnRate) + "Test" + std::to_string(i) + ".txt";
				out.open(file);
				if (out.fail()) {
					std::cerr << "Error: could not open file" << file << std::endl;
				}
				Linear(out, churnRate);
			}
		}
	}
	else if (algorithm == "linearCorona") {
		for (int churnRate = 1; churnRate < 6; churnRate++) {
			for (int i = 1; i < 11; i++) {
				std::ofstream out;
				std::string file = filePath + "churnRate" + std::to_string(churnRate) + "Test" + std::to_string(i) + ".txt";
				out.open(file);
				if (out.fail()) {
					std::cerr << "Error: could not open file" << file << std::endl;
				}
				LinearCorona(out, churnRate);
			}
		}
	}
	else if (algorithm == "linearChord") {
		for (int churnRate = 1; churnRate < 6; churnRate++) {
			for (int i = 1; i < 11; i++) {
				std::ofstream out;
				std::string file = filePath + "churnRate" + std::to_string(churnRate) + "Test" + std::to_string(i) + ".txt";
				out.open(file);
				if (out.fail()) {
					std::cerr << "Error: could not open file" << file << std::endl;
				}
				LinearChord(out, churnRate);
			}
		}
	}
	else {
		std::cout << algorithm << " not recognized" << std::endl;
	}

	return 0;
}

void Example(std::ofstream& logFile) {
	ByzantineNetwork<ExampleMessage, ExamplePeer> system;
	system.setLog(logFile); // set the system to write log to file logFile
	system.setToRandom(); // set system to use a uniform random distribution of weights on edges (channel delays)
	system.setMaxDelay(3); // set the max weight an edge can have to 3 (system will now pick randomly between [1, 3])
	system.initNetwork(5); // Initialize the system (create it) with 5 peers given the above settings

	for (int i = 0; i < 3; i++) {
		logFile << "-- STARTING ROUND " << i << " --" << std::endl; // write in the log when the round started

		system.receive(); // do the receive phase of the round
		//system.log(); // log the system state
		system.preformComputation();  // do the preform computation phase of the round
		//system.log();
		system.transmit(); // do the transmit phase of the round
		//system.log();

		logFile << "-- ENDING ROUND " << i << " --" << std::endl; // log the end of a round
	}

	int numberOfMessages = 0;
	for (int i = 0; i < system.size(); i++) {
		numberOfMessages += system[i]->getMessageCount(); // notice that the index operator ([]) return a pointer to a peer. NEVER DELETE THIS PEER INSTANCE.
														  //    The netwrok class deconstructor will get ride off ALL peer instances once it is deconstructed.
														  //    Use the -> to call method on the peer instance. The Network class will also cast the instance to
														  //    your derived class so all methods that you add will be avalable via the -> operator
	}
	std::cout << "Number of Messages: " << numberOfMessages << std::endl;
}

void Linear(std::ofstream& logFile, int churnRate) {
	ByzantineNetwork<LinearMessage, LinearPeer> system;
	system.setLog(logFile); // set the system to write log to file logFile
	system.setToRandom(); // set system to use a uniform random distribution of weights on edges (channel delays)
	system.setMaxDelay(3); // set the max weight an edge can have to 3 (system will now pick randomly between [1, 3])
	
	int Peers = 100 + churnRate * 150;
	int StartingPeers = 100;
	int numberOfRounds = 1000;
	system.initNetwork(Peers); // Initialize the system (create it) with 5 peers given the above settings

	vector<int> CurrentNodes, UsedNodes;
	vector<string> ids;
	for (int i = 0; i < Peers; i++) {
		ids.push_back(system[i]->id());
	}
	CurrentNodes = createLinearUnderlay(StartingPeers, ids);
	system[CurrentNodes[0]]->left = "MIN";
	system[CurrentNodes[0]]->right = system[CurrentNodes[1]]->id();
	for (int i = 1; i < StartingPeers - 1; i++) {
		system[CurrentNodes[i]]->left = system[CurrentNodes[i - 1]]->id();
		system[CurrentNodes[i]]->right = system[CurrentNodes[i + 1]]->id();
	}
	system[CurrentNodes[StartingPeers - 1]]->left = system[CurrentNodes[StartingPeers - 2]]->id();
	system[CurrentNodes[StartingPeers - 1]]->right = "ZZZZZZZZZZZZZZZZZZZZZZZZZZZ";
	for (int i = 0; i < CurrentNodes.size(); i++) {
		UsedNodes.push_back(CurrentNodes[i]);
	}
	int submittedRequests = 0;
	for (int i = 0; i < numberOfRounds; i++) {
		//logFile << "-- STARTING ROUND " << i << " --" << std::endl; // write in the log when the round started
		int selectedNode;

		// Join leave rate
		if (rand() % 10 < churnRate) {
			submittedRequests++;
			// Leave
			if (rand() % 2 == 0) {
				// First and last node can't leave
				do {
					selectedNode = rand() % (CurrentNodes.size() - 1) + 1;
				} while (system[CurrentNodes[selectedNode]]->busy || system[CurrentNodes[selectedNode]]->right == "ZZZZZZZZZZZZZZZZZZZZZZZZZZZ");
				LinearMessage message;
				message.action = "leave";
				message.reqId = system[CurrentNodes[selectedNode]]->id();
				message.roundSubmitted = i;
				system[CurrentNodes[selectedNode]]->sendMessage(system[CurrentNodes[selectedNode]]->id(), message);
				system[CurrentNodes[selectedNode]]->leaving = true;
				CurrentNodes.erase(CurrentNodes.begin() + selectedNode);
			}
			// Join
			else {
				for (int j = 0; j < ids.size(); j++) {
					bool found = false;
					for (int k = 0; k < UsedNodes.size(); k++) {
						if (UsedNodes[k] == j) {
							found = true;
							break;
						}
					}
					if (!found) {
						selectedNode = j;
						LinearMessage message;
						message.action = "join";
						message.reqId = system[selectedNode]->id();
						message.roundSubmitted = i;
						system[selectedNode]->busy = true;
						int nodeToSendTo;
						do {
							nodeToSendTo = rand() % CurrentNodes.size();
						} while (system[CurrentNodes[nodeToSendTo]]->busy);
						system[selectedNode]->sendMessage(system[CurrentNodes[nodeToSendTo]]->id(), message);
						CurrentNodes.insert(CurrentNodes.begin() + 1, selectedNode);
						UsedNodes.insert(UsedNodes.begin() + 1, selectedNode);
						break;
					}
				}
				
			}
		}

		// Request rate
		if (true) {
			submittedRequests++;
			do {
				selectedNode = rand() % CurrentNodes.size();
			} while (system[CurrentNodes[selectedNode]]->busy);
			LinearMessage message;
			message.action = "R";
			message.roundSubmitted = i;
			message.reqId = system[CurrentNodes[selectedNode]]->id();
			int nodeToSendTo;
			do {
				nodeToSendTo = rand() % CurrentNodes.size() ;
			} while (system[CurrentNodes[nodeToSendTo]]->busy);
			system[CurrentNodes[selectedNode]]->sendMessage(system[CurrentNodes[nodeToSendTo]]->id(), message);
		}
		system.receive(); // do the receive phase of the round
		//system.log(); // log the system state
		system.preformComputation();  // do the preform computation phase of the round
		//system.log();
		system.transmit(); // do the transmit phase of the round
		//system.log();
		
		std::cout << "-- ENDING ROUND " << i << " --" << std::endl; // log the end of a round
	}
	int numberOfMessages = 0, requestsSatisfied = 0, latency = 0, pendingRequests = 0, pendingLatency = 0, totalLatency = 0;
	for (int i = 0; i < system.size(); i++) {
		numberOfMessages += system[i]->getMessageCount(); // notice that the index operator ([]) return a pointer to a peer. NEVER DELETE THIS PEER INSTANCE.
														  //    The netwrok class deconstructor will get ride off ALL peer instances once it is deconstructed.
														  //    Use the -> to call method on the peer instance. The Network class will also cast the instance to
														  //    your derived class so all methods that you add will be avalable via the -> operator
		requestsSatisfied += system[i]->requestsSatisfied;
		latency += system[i]->latency;
		for (int j = 0; j < Peers; j++) {
			if (system[i]->id() != system[j]->id()) {
				auto messages = *system[i]->getChannelFrom(system[j]->id());
				for (int k = 0; k < messages.size(); k++) {
					pendingRequests++;
					auto v = messages[k];
					pendingLatency += numberOfRounds - v.getMessage().roundSubmitted;
					int x = 1;
				}
			}
		}

	}
	logFile << "Number of Messages " << numberOfMessages << std::endl;
	logFile << "Number of Requests Satisfied " << requestsSatisfied << std::endl;
	logFile << "Number of Pending Requests " << pendingRequests << std::endl;
	logFile << "Latency " << (latency + pendingLatency) / (pendingRequests + requestsSatisfied) << std::endl;

	logFile << "-- ENDING TEST " << " --" << std::endl; // log the end of the test
}

void LinearCorona(std::ofstream& logFile, int churnRate) {
	ByzantineNetwork<LinearCoronaMessage, LinearCoronaPeer> system;
	system.setLog(logFile); // set the system to write log to file logFile
	system.setToRandom(); // set system to use a uniform random distribution of weights on edges (channel delays)
	system.setMaxDelay(3); // set the max weight an edge can have to 3 (system will now pick randomly between [1, 3])
	int Peers = 100 + churnRate * 150;
	int StartingPeers = 100;
	int numberOfRounds = 1000;
	system.initNetwork(Peers); // Initialize the system (create it) with 5 peers given the above settings

	vector<int> CurrentNodes, UsedNodes;
	vector<string> ids;
	for (int i = 0; i < Peers; i++) {
		ids.push_back(system[i]->id());
	}
	CurrentNodes = createLinearUnderlay(StartingPeers, ids);
	system[CurrentNodes[0]]->left = "MIN";
	system[CurrentNodes[0]]->right = system[CurrentNodes[1]]->id();
	for (int i = 1; i < StartingPeers - 1; i++) {
		system[CurrentNodes[i]]->left = system[CurrentNodes[i - 1]]->id();
		system[CurrentNodes[i]]->right = system[CurrentNodes[i + 1]]->id();
	}
	system[CurrentNodes[StartingPeers - 1]]->left = system[CurrentNodes[StartingPeers - 2]]->id();
	system[CurrentNodes[StartingPeers - 1]]->right = "ZZZZZZZZZZZZZZZZZZZZZZZZZZZ";
	for (int i = 0; i < CurrentNodes.size(); i++) {
		UsedNodes.push_back(CurrentNodes[i]);
		system[CurrentNodes[i]]->alive = true;
	}
	int submittedRequests = 0;
	for (int i = 0; i < numberOfRounds; i++) {
		//logFile << "-- STARTING ROUND " << i << " --" << std::endl; // write in the log when the round started
		int selectedNode;

		// Join leave rate
		if (rand() % 10 < churnRate) {
			submittedRequests++;
			// Leave
			if (rand() % 2 == 0) {
				selectedNode = rand() % CurrentNodes.size();
				system[CurrentNodes[selectedNode]]->alive = false;
			}
			// Join
			else {
				selectedNode = rand() % CurrentNodes.size();
				int nodeToSendTo = rand() % CurrentNodes.size();
				system[CurrentNodes[selectedNode]]->alive = true;
				LinearCoronaMessage message;
				message.action = "N";
				message.roundSubmitted = i;
				message.reqId = system[CurrentNodes[selectedNode]]->id();
				system[CurrentNodes[selectedNode]]->sendMessage(system[CurrentNodes[nodeToSendTo]]->id(), message);
			}
		}

		// Request rate
		if (true) {
			submittedRequests++;
			selectedNode = rand() % CurrentNodes.size();
			LinearCoronaMessage message;
			message.action = "R";
			message.roundSubmitted = i;
			message.reqId = system[CurrentNodes[selectedNode]]->id();
			int nodeToSendTo = rand() % CurrentNodes.size();
			system[CurrentNodes[selectedNode]]->sendMessage(system[CurrentNodes[nodeToSendTo]]->id(), message);
		}
		system.receive(); // do the receive phase of the round
		//system.log(); // log the system state
		system.preformComputation();  // do the preform computation phase of the round
		//system.log();
		system.transmit(); // do the transmit phase of the round
		//system.log();

		std::cout << "-- ENDING ROUND " << i << " --" << std::endl; // log the end of a round
	}
	int numberOfMessages = 0, requestsSatisfied = 0, latency = 0, pendingRequests = 0, droppedRequests = 0, pendingLatency = 0, droppedLatency = 0, totalLatency = 0;
	for (int i = 0; i < system.size(); i++) {
		numberOfMessages += system[i]->getMessageCount(); // notice that the index operator ([]) return a pointer to a peer. NEVER DELETE THIS PEER INSTANCE.
														  //    The netwrok class deconstructor will get ride off ALL peer instances once it is deconstructed.
														  //    Use the -> to call method on the peer instance. The Network class will also cast the instance to
														  //    your derived class so all methods that you add will be avalable via the -> operator
		requestsSatisfied += system[i]->requestsSatisfied;
		latency += system[i]->latency;
		for (int j = 0; j < Peers; j++) {
			if (system[i]->id() != system[j]->id()) {
				auto messages = *system[i]->getChannelFrom(system[j]->id());
				for (int k = 0; k < messages.size(); k++) {
					auto v = messages[k];
					if (v.getMessage().action == "R") {
						pendingRequests++;
						pendingLatency += numberOfRounds - v.getMessage().roundSubmitted;
					}
				}
			}
		}
		auto messages = system[i]->getInStream();
		for (int k = 0; k < messages.size(); k++) {
			auto v = messages[k];
			if (v.getMessage().action == "R") {
				droppedRequests++;
				droppedLatency += numberOfRounds - v.getMessage().roundSubmitted;
			}
		}

	}
	logFile << "Number of Messages " << numberOfMessages << std::endl;
	logFile << "Number of Requests Satisfied " << requestsSatisfied << std::endl;
	logFile << "Number of Pending Requests " << pendingRequests << std::endl;
	logFile << "Latency " << (latency + pendingLatency + droppedLatency) / (pendingRequests + requestsSatisfied + droppedRequests) << std::endl;

	logFile << "-- ENDING TEST " << " --" << std::endl; // log the end of the test
}

void LinearChord(std::ofstream& logFile, int churnRate) {
	ByzantineNetwork<LinearChordMessage, LinearChordPeer> system;
	system.setLog(logFile); // set the system to write log to file logFile
	system.setToRandom(); // set system to use a uniform random distribution of weights on edges (channel delays)
	system.setMaxDelay(3); // set the max weight an edge can have to 3 (system will now pick randomly between [1, 3])
	int Peers = 100 + churnRate * 150;
	int StartingPeers = 100;
	int numberOfRounds = 1000;
	system.initNetwork(Peers); // Initialize the system (create it) with 5 peers given the above settings

	vector<int> CurrentNodes, UsedNodes;
	vector<string> ids;
	for (int i = 0; i < Peers; i++) {
		ids.push_back(system[i]->id());
	}
	CurrentNodes = createLinearUnderlay(StartingPeers, ids);
	for (int i = 0; i < StartingPeers - 1; i++) {
		Finger newNode;
		newNode.Id = system[CurrentNodes[i + 1]]->id();
		system[CurrentNodes[i]]->successor.push_back(newNode);
	}
	for (int i = 0; i < StartingPeers - 2; i++) {
		Finger newNode;
		newNode.Id = system[CurrentNodes[i + 2]]->id();
		system[CurrentNodes[i]]->successor.push_back(newNode);
	}
	for (int i = 1; i < StartingPeers; i++) {
		Finger newNode;
		newNode.Id = system[CurrentNodes[i - 1]]->id();
		system[CurrentNodes[i]]->predecessor.push_back(newNode);
	}
	for (int i = 2; i < StartingPeers; i++) {
		Finger newNode;
		newNode.Id = system[CurrentNodes[i - 2]]->id();
		system[CurrentNodes[i]]->predecessor.push_back(newNode);
	}
	for (int i = 0; i < CurrentNodes.size(); i++) {
		UsedNodes.push_back(CurrentNodes[i]);
		system[CurrentNodes[i]]->alive = true;
	}
	int submittedRequests = 0;
	for (int i = 0; i < numberOfRounds; i++) {
		//logFile << "-- STARTING ROUND " << i << " --" << std::endl; // write in the log when the round started
		int selectedNode;

		// Join leave rate
		if (rand() % 10 < churnRate) {
			submittedRequests++;
			// Leave
			if (rand() % 2 == 0) {
				selectedNode = rand() % CurrentNodes.size();
				system[CurrentNodes[selectedNode]]->alive = false;
			}
			// Join
			else {
				selectedNode = rand() % CurrentNodes.size();
				int nodeToSendTo = rand() % CurrentNodes.size();
				system[CurrentNodes[selectedNode]]->alive = true;
				LinearChordMessage message;
				message.action = "N";
				message.roundSubmitted = i;
				message.reqId = system[CurrentNodes[selectedNode]]->id();
				system[CurrentNodes[selectedNode]]->sendMessage(system[CurrentNodes[nodeToSendTo]]->id(), message);
			}
		}

		// Request rate
		if (true) {
			submittedRequests++;
			selectedNode = rand() % CurrentNodes.size();
			LinearChordMessage message;
			message.action = "R";
			message.roundSubmitted = i;
			message.reqId = system[CurrentNodes[selectedNode]]->id();
			int nodeToSendTo = rand() % CurrentNodes.size();
			system[CurrentNodes[selectedNode]]->sendMessage(system[CurrentNodes[nodeToSendTo]]->id(), message);
		}

		// HeartBeat rate
		if (i > 8 && i % 10 == 9) {
			for (int i = 0; i < CurrentNodes.size(); i++) {
				system[CurrentNodes[i]]->heartBeat();
			}
		}
		system.receive(); // do the receive phase of the round
		//system.log(); // log the system state
		system.preformComputation();  // do the preform computation phase of the round
		//system.log();
		system.transmit(); // do the transmit phase of the round
		//system.log();

		std::cout << "-- ENDING ROUND " << i << " --" << std::endl; // log the end of a round
	}
	int numberOfMessages = 0, requestsSatisfied = 0, latency = 0, pendingRequests = 0, droppedRequests = 0, pendingLatency = 0, droppedLatency = 0, totalLatency = 0;
	for (int i = 0; i < system.size(); i++) {
		numberOfMessages += system[i]->getMessageCount(); // notice that the index operator ([]) return a pointer to a peer. NEVER DELETE THIS PEER INSTANCE.
														  //    The netwrok class deconstructor will get ride off ALL peer instances once it is deconstructed.
														  //    Use the -> to call method on the peer instance. The Network class will also cast the instance to
														  //    your derived class so all methods that you add will be avalable via the -> operator
		requestsSatisfied += system[i]->requestsSatisfied;
		latency += system[i]->latency;
		for (int j = 0; j < Peers; j++) {
			if (system[i]->id() != system[j]->id()) {
				auto messages = *system[i]->getChannelFrom(system[j]->id());
				for (int k = 0; k < messages.size(); k++) {
					auto v = messages[k];
					if (v.getMessage().action == "R") {
						pendingRequests++;
						pendingLatency += numberOfRounds - v.getMessage().roundSubmitted;
					}
				}
			}
		}
		if (system[i]->alive == false) {
			auto messages = system[i]->getInStream();
			for (int k = 0; k < messages.size(); k++) {
				auto v = messages[k];
				if (v.getMessage().action == "R") {
					droppedRequests++;
					droppedLatency += numberOfRounds - v.getMessage().roundSubmitted;
				}
			}
		}

	}
	logFile << "Number of Messages " << numberOfMessages << std::endl;
	logFile << "Number of Requests Satisfied " << requestsSatisfied << std::endl;
	logFile << "Number of Pending Requests " << pendingRequests << std::endl;
	logFile << "Latency " << (latency + pendingLatency + droppedLatency) / (pendingRequests + requestsSatisfied + droppedRequests) << std::endl;

	logFile << "-- ENDING TEST " << " --" << std::endl; // log the end of the test
}

vector<int> createLinearUnderlay(int size, vector<string> ids) {
	vector<int> peers;
	vector<int> Sortedpeers;
	vector<string> usedIds;

	int min = 0;
	for (int i = 0; i < ids.size(); i++) {
		if (ids[i] < ids[min]) {
			min = i;
		}
	}
	peers.push_back(min);

	int max = 0;
	for (int i = 0; i < ids.size(); i++) {
		if (ids[i] > ids[max]) {
			max = i;
		}
	}
	peers.push_back(max);
	bool found;
	for (int i = 0; i < size - 2; i++) {
		for (int j = 0; j < ids.size(); j++) {
			found = false;
			for (int k = 0; k < peers.size(); k++) {
				if (peers[k] == j) {
					found = true;
					break;
				}
			}
			if (!found) {
				peers.push_back(j);
				break;
			}
		}
	}
	for (int i = 0; i < peers.size(); i++) {
		usedIds.push_back(ids[peers[i]]);
	}
	std::sort(usedIds.begin(), usedIds.end());
	for (int i = 0; i < usedIds.size(); i++) {
		for (int j = 0; j < ids.size(); j++) {
			if (usedIds[i] == ids[j]) {
				Sortedpeers.push_back(j);
			}
		}
	}
	return Sortedpeers;
}