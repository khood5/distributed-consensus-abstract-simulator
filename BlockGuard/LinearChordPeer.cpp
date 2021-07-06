//
//  LinearChordPeer.cpp
//  BlockGuard
//
//  Created by Joseph Oglio on 6/15/21.//
//  Copyright © 2019 Kent State University. All rights reserved.
//

#include "LinearChordPeer.hpp"
#include "./Common/Peer.hpp"
#include "./Common/Packet.hpp"
#include <iostream>

LinearChordPeer::~LinearChordPeer() {

}

LinearChordPeer::LinearChordPeer(const LinearChordPeer& rhs) : Peer<LinearChordMessage>(rhs) {
	counter = rhs.counter;
}

LinearChordPeer::LinearChordPeer(std::string id) : Peer(id) {
	counter = 0;
}

void LinearChordPeer::preformComputation() {
	if (alive) {
		for (int i = 0; i < _inStream.size(); i++) {
			std::string source = _inStream[i].sourceId();
			LinearChordMessage message = _inStream[i].getMessage();
			std::string reqId = message.reqId;
			if (message.action == "R") {
				if (_id == reqId) {
					requestsSatisfied++;
					latency += _clock - message.roundSubmitted - 1;
				}
				else if (reqId > _id) {
					if (successor.size() > 0) {
						if (_id < reqId && (reqId < successor[0].Id || successor[0].Id < _id)) {
							requestsSatisfied++;
							latency += _clock - message.roundSubmitted - 1;
						}
						else {
							sendMessage(successor[0].Id, message);
						}
					}
				}
				else if (predecessor.size() > 0) {
					sendMessage(predecessor[0].Id, message);
				}
			}
			else if (reqId != _id) {
				bool added = false;
				int position;
				if (reqId > _id) {
					if (successor.size() == 0) {
						Finger newNode;
						newNode.Id = reqId;
						newNode.roundUpdated = _clock;
						successor.insert(successor.begin(), newNode);
						added = true;
					}
					else if (successor.size() == 1 && reqId != successor[0].Id) {
						Finger newNode;
						newNode.Id = reqId;
						newNode.roundUpdated = _clock;
						if (reqId < successor[0].Id) {
							successor.insert(successor.begin(), newNode);
						}
						else {
							successor.push_back(newNode);
						}
						added = true;
					}
					else {
						for (int i = 0; i < successor.size(); i++) {
							if (reqId < successor[i].Id) {
								Finger newNode;
								newNode.Id = reqId;
								newNode.roundUpdated = _clock;
								successor.insert(successor.begin() + i, newNode);
								added = true;
								position = i;
								break;
							}
							else if (reqId == successor[i].Id) {
								successor[i].roundUpdated = _clock;
								break;
							}
						}

						if (!added) {
							sendMessage(successor[0].Id, message);
						}
					}
				}
				else if (reqId < _id) {
					if (predecessor.size() == 0) {
						Finger newNode;
						newNode.Id = reqId;
						newNode.roundUpdated = _clock;
						predecessor.insert(predecessor.begin(), newNode);
					}
					if (predecessor.size() == 1 && reqId != predecessor[0].Id) {
						Finger newNode;
						newNode.Id = reqId;
						newNode.roundUpdated = _clock;
						if (reqId > predecessor[0].Id) {
							predecessor.insert(predecessor.begin(), newNode);
						}
						else {
							predecessor.push_back(newNode);
						}

					}
					else {
						for (int i = 0; i < predecessor.size(); i++) {
							if (reqId > predecessor[i].Id) {
								Finger newNode;
								newNode.Id = reqId;
								newNode.roundUpdated = _clock;
								predecessor.insert(predecessor.begin() + i, newNode);
								added = true;
								position = i;
								break;
							}
							else if (reqId == predecessor[i].Id) {
								predecessor[i].roundUpdated = _clock;
								break;
							}
						}
						if (!added) {
							sendMessage(predecessor[0].Id, message);
						}
					}
				}

				if (added) {
					LinearChordMessage response;
					response.action = "N";
					for (int i = 0; i < successor.size(); i++) {
						if (successor[i].Id != reqId) {
							sendMessage(successor[i].Id, message);
							response.reqId = successor[i].Id;
							sendMessage(reqId, response);
						}
						else {
							response.reqId = _id;
							sendMessage(reqId, response);
						}
					}
					
					for (int i = 0; i < predecessor.size(); i++) {
						if (predecessor[i].Id != reqId) {
							sendMessage(predecessor[i].Id, message);
							response.reqId = predecessor[i].Id;
							sendMessage(reqId, response);
						}
						else {
							response.reqId = _id;
							sendMessage(reqId, response);
						}
					}
					for (int i = redundantSize; i < successor.size(); i++) {
						successor.erase(successor.end() - 1);
					}
					for (int i = redundantSize; i < predecessor.size(); i++) {
						predecessor.erase(predecessor.end() - 1);
					}
				}
			}
		}

		_inStream.clear();
	}
}

void LinearChordPeer::heartBeat() {
	if (alive) {
		LinearChordMessage message;
		message.action = "N";
		message.reqId = _id;
		for (int i = 0; i < successor.size(); i++) {
			if (successor[i].roundUpdated + 20 > _clock) {
				sendMessage(successor[i].Id, message);
			}
			else {
				successor.erase(successor.begin() + i);
				i--;
			}
		}
		for (int i = 0; i < predecessor.size(); i++) {
			if (predecessor[i].roundUpdated + 20 > _clock) {
				sendMessage(predecessor[i].Id, message);
			}
			else {
				predecessor.erase(predecessor.begin() + i);
				i--;
			}
		}
	}
}

void LinearChordPeer::sendMessage(std::string peer, LinearChordMessage message) {
	Packet<LinearChordMessage> newMessage(std::to_string(counter), peer, _id);
	newMessage.setBody(message);
	_outStream.push_back(newMessage);
	counter++;
}

std::ostream& LinearChordPeer::printTo(std::ostream& out)const {
	Peer<LinearChordMessage>::printTo(out);

	out << _id << std::endl;
	out << "counter:" << counter << std::endl;

	return out;
}

std::ostream& operator<< (std::ostream& out, const LinearChordPeer& peer) {
	peer.printTo(out);
	return out;
}
