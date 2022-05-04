//
//  Packet.hpp
//  BlockGuard
//
// This is the class responsible for holding messages as they are sent from one peer to another (similar to a packet in a real network)
// It is templated so that the user can define their own message (body, payload, etc.) they want to include in the packet. This allows
// them to define what information is allowed in a single message between peers.
//
// A packet needs a source peer id (id of the network interface), target peer id (id of the network interface) and an id.
// The Id of the packet is used for comparison of two packets. Structs can not be compared unless the user defines the equal to and not
// equal operator. As such we do not expect or assume that the user does so. We define a packet ID to overcome this two packets with the
// same id are regarded as equal.


#ifndef Packet_hpp
#define Packet_hpp

#include <stdio.h>
#include <string>
#include <ctime>
#include <random>

namespace blockguard{

    using std::default_random_engine;
    using std::string;
    using std::uniform_int_distribution;
    
    static const long NO_PEER_ID = -1;  // number used to indicate invalid peer id or un init peer id

    //
    //Base Message Class
    //

    static default_random_engine RANDOM_GENERATOR = default_random_engine((int)time(nullptr));

    template<class message>
    class Packet{
    private:
        // message must have ID
        Packet(){};
        
    protected:
        long                        _id; // message id 
        long                        _targetId; // traget node id
        long                        _sourceId; // source node id
        
        message                     _body;
        
        int                         _delay; // delay of the message
        
    public:
        Packet                      (long id);
        Packet                      (long id, long to, long from);
        Packet                      (const Packet<message>&);
        ~Packet                     ();
        
        // setters
        void        setSource       (long s){_sourceId = s;};
        void        setTarget       (long t){_targetId = t;};
        void        setDelay        (int delayMax, int delayMin = 1);
        void        setMessage      (const message c){_body = c;};
        
        // getters
        long        id              ()const {return _id;};
        long        targetId        ()const {return _targetId;};
        long        sourceId        ()const {return _sourceId;};
        bool        hasArrived      ()const {return !(bool)(_delay);};
        message     getMessage      ()const {return _body;};
        int         getDelay        ()const {return _delay;};
        
        // mutators
        void        moveForward     (){_delay = _delay > 0 ? _delay-1 : 0;};
        
        //void
        
        Packet&     operator=       (const Packet<message> &rhs);
        bool        operator==      (const Packet<message> &rhs) const;
        bool        operator!=      (const Packet<message> &rhs) const;
        
    };

    template<class message>
    Packet<message>::Packet(long id){
        _id = id;
        _sourceId = NO_PEER_ID;
        _targetId = NO_PEER_ID;
        _body = message();
        _delay = 0;
    }

    template<class message>
    Packet<message>::Packet(long id, long to ,long from){
        _id = id;
        _sourceId = from;
        _targetId = to;
        _body = message();
        _delay = 0;
    }

    template<class message>
    Packet<message>::Packet(const Packet<message>& rhs){
        _id = rhs._id;
        _targetId = rhs._targetId;
        _sourceId = rhs._sourceId;
        _body = rhs._body;
        _delay = rhs._delay;
    }

    template<class message>
    Packet<message>::~Packet(){
        // no memory allocated so nothing to do
    }

    template <class message>
    void Packet<message>::setDelay(int maxDelay, int minDelay){
        uniform_int_distribution<int> uniformDist(minDelay, maxDelay);
        _delay = uniformDist(RANDOM_GENERATOR); // max is not included so delay 1 is next round delay 2 is one round waiting and then receve in the following round
    }

    template<class message>
    Packet<message>& Packet<message>::operator=(const Packet<message> &rhs){
        _id = rhs._id;
        _targetId = rhs._targetId;
        _sourceId = rhs._sourceId;
        _body = rhs._body;
        _delay = rhs._delay;
        return *this;
    }

    template<class message>
    bool Packet<message>::operator== (const Packet<message> &rhs)const{
        return _id == rhs._id;
    }

    template<class message>
    bool Packet<message>::operator!= (const Packet<message> &rhs)const{
        return !(_id == rhs._id);
    }
}
#endif /* Message_hpp */
