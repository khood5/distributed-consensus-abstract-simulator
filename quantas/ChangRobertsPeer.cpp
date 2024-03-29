/*
Copyright 2022

This file is part of QUANTAS.
QUANTAS is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
QUANTAS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with QUANTAS. If not, see <https://www.gnu.org/licenses/>.
*/

#include <iostream>
#include "ChangRobertsPeer.hpp"

namespace quantas {

	ChangRobertsPeer::~ChangRobertsPeer() {

	}

	ChangRobertsPeer::ChangRobertsPeer(const ChangRobertsPeer& rhs) : Peer<ChangRobertsMessage>(rhs), /*current_leader(id()),*/ messages_sent(0) {
		
	}

	ChangRobertsPeer::ChangRobertsPeer(long id) : Peer(id), /*current_leader(id),*/ messages_sent(0) {
		
	}

	void ChangRobertsPeer::performComputation() {
		if(getRound() == 0) {
			ChangRobertsMessage msg;
			msg.aPeerId = id(); 
			unicast(msg);
			++messages_sent;
		}
		while (!inStreamEmpty()) {
			Packet<ChangRobertsMessage> newMsg = popInStream();
			long rid = newMsg.getMessage().aPeerId;
			long sid = newMsg.sourceId();
			if( rid == id() ) {
				cout << "Realizing " << id() << " is the leader" << endl;
				LogWriter::instance()->data["tests"][LogWriter::instance()->getTest()]["election_time"] = getRound();
			}
			else {
				if( rid > id() ) {
					ChangRobertsMessage msg;
					msg.aPeerId = rid;
					broadcastBut(msg,sid);
					++messages_sent;
				}
			}	
		}
	}

	void ChangRobertsPeer::endOfRound(const vector<Peer<ChangRobertsMessage>*>& _peers) {
		long all_messages_sent = 0;
		const vector<ChangRobertsPeer*> peers = reinterpret_cast<vector<ChangRobertsPeer*> const&>(_peers);
		for(auto it = peers.begin(); it != peers.end(); ++it) {
			all_messages_sent += (*it)->messages_sent;
		}
		LogWriter::instance()->data["tests"][LogWriter::instance()->getTest()]["nb_messages"].push_back(all_messages_sent);
	}

	ostream& ChangRobertsPeer::printTo(ostream& out)const {
		Peer<ChangRobertsMessage>::printTo(out);

		out << id() << endl;
		out << "counter:" << getRound() << endl;

		return out;
	}

	ostream& operator<< (ostream& out, const ChangRobertsPeer& peer) {
		peer.printTo(out);
		return out;
	}
}