//
//  LinearPeer.hpp
//  BlockGuard
//
//  Created by Joseph Oglio on 6/15/21.
//  Copyright © 2019 Kent State University. All rights reserved.
//

#ifndef LinearPeer_hpp
#define LinearPeer_hpp

#include "./Common/Peer.hpp"

struct LinearMessage {
    std::string reqId;
    std::string rightNeighbor; //used only in leave request
    std::string action; // options are R, join, leave, sua, sub, tda, tdb, ftd
    //                                          set up a/b, tear down a/b, finish tear down
    int roundSubmitted;
};

class LinearPeer : public Peer<LinearMessage>{
protected:
    int counter;
public:
    // methods that must be defined when deriving from Peer
    LinearPeer                              (std::string);
    LinearPeer                              (const LinearPeer &rhs);
    ~LinearPeer                             ();
    std::string left;
    std::string right;
    bool busy             = false;
    std::string reqType   = "N";
    bool leaving          = false;
    int requestsSatisfied = 0;
    int latency      = 0;
    void                 preformComputation ();
    void                 makeRequest        (){};
    void                 sendMessage        (std::string peer, LinearMessage message);
    void                 log                ()const{printTo(*_log);};
    std::ostream&        printTo            (std::ostream&)const;
    friend std::ostream& operator<<         (std::ostream&, const LinearPeer&);

    // its normally a good idea to make some getters and setters for a peer to enable testing 
    //  of the peers state durring an experment and to get metrics. 
    int                  getCounter()const                                      {return counter;};
    void                 setCounter(int c)                                      {counter = c;};
};
#endif LinearPeer_hpp
