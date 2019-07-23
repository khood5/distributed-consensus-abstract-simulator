//
// Created by khood on 7/22/19.
//

#ifndef DISTRIBUTED_CONSENSUS_ABSTRACT_SIMULATOR_TXRATE_H
#define DISTRIBUTED_CONSENSUS_ABSTRACT_SIMULATOR_TXRATE_H

#include <iostream>
#include "params.hpp"
#include "metrics.hpp"
#include "bCoinReferenceCommittee.hpp"
#include "PBFTReferenceCommittee.hpp"
#include "SBFTReferenceCommittee.hpp"
#include "Sharded_PBFT_Experiments.hpp"
#include <fstream>

void txRate(std::ofstream &csv, std::ofstream &log);

#endif //DISTRIBUTED_CONSENSUS_ABSTRACT_SIMULATOR_TXRATE_H
