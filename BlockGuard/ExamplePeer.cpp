//
//  ExamplePeer.cpp
//  BlockGuard
//
//  Created by Kendric Hood on 3/15/19.
//  Copyright © 2019 Kent State University. All rights reserved.
//

#include "ExamplePeer.hpp"
#include "./Common/Peer.hpp"
#include "./Common/Packet.hpp"
#include <iostream>

//
// Example Peer definitions
//
ExamplePeer::~ExamplePeer(){
    
}

ExamplePeer::ExamplePeer(const ExamplePeer &rhs) : Peer<ExampleMessage>(rhs){
    _counter = rhs._counter;
    _txQueue = rhs._txQueue;
}

ExamplePeer::ExamplePeer(std::string id) : Peer(id){
    _counter = 0;
    _txQueue = std::deque<ExampleMessage>();
}

void ExamplePeer::makeRequest(){
    // Here is our logic for submmitting a new trasactions to the system
    // How TX's are handled are dictated by the algorithm, type of experment, and 
    // measurement being taken. For example, if running an experiment to see the 
    // benefits of selfish mining a peer may only store new TX and never share 
    // them with others. While another experiment may requier TX to be broadcast, 
    // so there is delay in when other peers get the TX. While yet another may 
    // simple enqueue the new TX in a shared queue so that it is immediately avalable 
    // to all peers.

    // for ExamplePeer it simply creates a new message (TX) to be broadcasts to
    // all other peers and stores it in a queue to be used later in preformComputation

    std::cout<< "Peer:"<< _id<< " making request"<<std::endl;
    ExampleMessage message;
    message.message = "Message: " + std::to_string(_counter)  + " Hello From ";
    message.aPeerId = _id;

    _txQueue.push_back(message);
}

void ExamplePeer::preformComputation(){
    // here is where the logic of our algorithm goes. In most cases a peer will
    // change its behaviour depending on it's state (i.e. what messages it has receved
    // and any internal attributes it has) Each peer may have a unique state, and thus take
    // diffrent actions. For example a peer running PBFT may keep a running count of how many 
    // commit messages it has receved for some TX X. But do to delay in message propogation 
    // one peer may have a higher count then another. Thus one peer may commit X while another 
    // waits to commit X. 
    
    // for ExamplePeer our state is a combination of _counter, _txQueue, _inStream 
    // and _outStream. Our peers can take two actions each round depending on it's state 
    // 1. if _txQueue is not empty:
    //      then we pop the first message and broadcast it
    // 2. if we have receved any new messages (i.e. _inStream is not empty):
    //      then we log the message sent to us to the console
    // finailly we clear our _inStream

    // notice that some actions our algorithm takes happen every round regardless of the 
    // peers unique state i.e. we clear _inStream. While others only happen when some condition
    // is meet i.e. we have receved new messages or we have a new tx.

    std::cout<< "Peer:"<< _id<< " preforming computation"<<std::endl;

    if (!_txQueue.empty()){
        ExampleMessage message = _txQueue.front();
        _txQueue.pop_front();
        for (auto neighbor = _neighbors.begin(); neighbor != _neighbors.end(); neighbor++ )
        {
            Packet<ExampleMessage> newMessage(std::to_string(_counter), neighbor->first,_id);
            newMessage.setBody(message);
            _outStream.push_back(newMessage);
        }
    }

    
    for(int i = 0; i < _inStream.size(); i++){
        std::cout << std::endl << _id<< " has receved a message from "<< _inStream[i].sourceId()<< std::endl;
        std::cout << "  MESSAGE "<< _inStream[i].id() <<  ":"<< _inStream[i].getMessage().message<<  _inStream[i].getMessage().aPeerId<< std::endl;
    }
    std::cout << std::endl;
    _inStream.clear();
    _counter++;
}

std::ostream& ExamplePeer::printTo(std::ostream &out)const{
    Peer<ExampleMessage>::printTo(out);
    
    out<< _id<< std::endl;
    out<< "_counter:"<< _counter<< std::endl;
    
    return out;
}

std::ostream& operator<< (std::ostream &out, const ExamplePeer &peer){
    peer.printTo(out);
    return out;
}
