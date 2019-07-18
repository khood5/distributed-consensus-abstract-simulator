#include <utility>

//
// Created by srai on 6/9/19.
//

#ifndef Transaction_hpp
#define Transaction_hpp


class Transaction {
	std::string 							id;
	int 									introducedAt = -1;
	int 									confirmedAt = -1;

public:
	Transaction																(std::string txName, int txIntroducedAt):id(std::move(txName)), introducedAt(txIntroducedAt) {}
	void 									setConfirmedAt					(int txConfirmedAt) { confirmedAt = txConfirmedAt; }
	std::string 							getId()							{ return id; }
	int 									getIntroducedAt					() { return introducedAt; }
	int 									getConfirmedAt					() { return confirmedAt; }
};


#endif //Transaction_hpp
