//
// Created by khood on 7/22/19.
//

#ifndef DISTRIBUTED_CONSENSUS_ABSTRACT_SIMULATOR_TXRATE_H
#define DISTRIBUTED_CONSENSUS_ABSTRACT_SIMULATOR_TXRATE_H

#include <iostream>
#include "../params.hpp"
#include "metrics.hpp"
#include "../bCoin/bCoinReferenceCommittee.hpp"
#include "../PBFT/PBFTReferenceCommittee.hpp"
#include "../SBFT/SBFTReferenceCommittee.hpp"
#include "Sharded_PBFT_Experiments.hpp"
#include <fstream>

void txRate(std::ofstream &csv, std::ofstream &log);

#endif //DISTRIBUTED_CONSENSUS_ABSTRACT_SIMULATOR_TXRATE_H
