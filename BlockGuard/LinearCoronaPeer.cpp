//
//  LinearCoronaPeer.cpp
//  BlockGuard
//
//  Created by Joseph Oglio on 6/15/21.//
//  Copyright © 2019 Kent State University. All rights reserved.
//

#include "LinearCoronaPeer.hpp"
#include "./Common/Peer.hpp"
#include "./Common/Packet.hpp"
#include <iostream>

LinearCoronaPeer::~LinearCoronaPeer() {

}

LinearCoronaPeer::LinearCoronaPeer(const LinearCoronaPeer& rhs) : Peer<LinearCoronaMessage>(rhs) {
	counter = rhs.counter;
}

LinearCoronaPeer::LinearCoronaPeer(std::string id) : Peer(id) {
	counter = 0;
}

void LinearCoronaPeer::preformComputation() {
	for (int i = 0; i < _inStream.size(); i++) {
		std::string source = _inStream[i].sourceId();
		LinearCoronaMessage message = _inStream[i].getMessage();
		std::string reqId = message.reqId;
		if (message.action == "R") {
			if (_id == reqId) {
				// Node found
			}
			else if (_id < reqId && reqId < right) {
				//Node gone
			}
			else if (reqId < _id) {
				sendMessage(left, message);
			}
			else {
				sendMessage(right, message);
			}
		}
		else if (reqId > _id) {
			if (reqId < right) {
				if (right < "ZZZZZZZZZZZZZZZZZZZZZZZZZZZ") {
					message.reqId = right;
					sendMessage(reqId, message);
				}
				right = reqId;
			}
			else {
				sendMessage(right, message);
			}
		}
		else if (reqId < _id) {
			if (_id > left) {
				if (left > "MIN") {
					message.reqId = left;
					sendMessage(reqId, message);
				}
				left = reqId;
			}
			else {
				sendMessage(left, message);
			}
		}
	}

	_inStream.clear();
}

void LinearCoronaPeer::heartBeat() {
	LinearCoronaMessage message;
	message.action = "N";
	message.reqId = _id;
	if (right < "ZZZZZZZZZZZZZZZZZZZZZZZZZZZ") {
		sendMessage(right, message);
	}
	if (left > "MIN") {
		sendMessage(left, message);
	}
}

void LinearCoronaPeer::sendMessage(std::string peer, LinearCoronaMessage message) {
	Packet<LinearCoronaMessage> newMessage(std::to_string(counter), peer, _id);
	newMessage.setBody(message);
	_outStream.push_back(newMessage);
	counter++;
}

std::ostream& LinearCoronaPeer::printTo(std::ostream& out)const {
	Peer<LinearCoronaMessage>::printTo(out);

	out << _id << std::endl;
	out << "counter:" << counter << std::endl;

	return out;
}

std::ostream& operator<< (std::ostream& out, const LinearCoronaPeer& peer) {
	peer.printTo(out);
	return out;
}
