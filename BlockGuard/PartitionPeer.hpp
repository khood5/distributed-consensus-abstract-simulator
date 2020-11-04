#ifndef PartitionPeer_hpp
#define PartitionPeer_hpp

#include "./Common/Peer.hpp"
#include <string>
#include <vector>
#include <set>
#include <deque>
#include <random>
#include <algorithm>
using std::vector;
using std::deque;
using std::string;

struct PartitionBlock {
	int					blockIdNumber;
	int					trans;
	int					tipBlockIdNumbers;
	int					TipIndex;
	vector<int>			VerifIndex;
	int					length;
	bool				postSplit;
};

struct PartitionBlockMessage {
	PartitionBlock		block;
	bool				mined;
};

struct Partitiontransaction {
	PartitionBlock		transBlock;
	int					priority;
};

struct DroppedBlock {
	PartitionBlock		block;
	int					delay = -1;
};

class PartitionPeer : public Peer<PartitionBlockMessage> {
protected:
	int counter;

public:
	PartitionPeer(std::string);
	~PartitionPeer();
	vector<PartitionBlock> blockChain;
	vector<PartitionBlock> postSplitBlockChain;
	deque<PartitionBlock>  unlinkedBlocks;
	deque<DroppedBlock>  droppedBlocks;
	deque<Partitiontransaction>	  transactions;
	int					  preSplitTip = 0;
	int					  postSplitTip = 0;
	int					  mergeWaiting = 0;
	static int  		  doubleDelay;
	static int  		  NextblockIdNumber;
	static bool			  PostSplit;
	static bool			  Lying;
	static int			  DropRate;
	std::map<std::string, Peer<PartitionBlockMessage>*> PostSplitNeighbors;
	static bool PartitionTransactionSortFunc(Partitiontransaction i, Partitiontransaction j) {
		return (i.priority < j.priority);
	}
	void				  incrementMergeWaiting();
	void                  preformComputation();
	void				  intialSplitSetup();
	void				  findPostSplitNeighbors(vector<string> idList);
	std::set<int>		  findVerifTrans();
	bool                  linkUnlinkedBlocks(bool foundLonger);
	void				  findDroppedBlocks();
	void				  incrementDroppedBlocks();
	bool 				  mineBlock();
	bool                  checkInStrm();
	void				  sortTransactions();
	void                  sendBlock(PartitionBlock minedBlock);
	void                  sendTransaction(int tranID);
	void                  makeRequest() {};
	void                  log()const { printTo(*_log); };
	std::ostream&         printTo(std::ostream&)const;
	friend std::ostream& operator<<         (std::ostream&, const PartitionPeer&);
};
#endif PartitionPeer_hpp
#pragma once