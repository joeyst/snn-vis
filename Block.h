
#include "Neuron.h"
#include <vector>

#ifndef _BLOCK_H
#define _BLOCK_H

class Block {
  public: 
    Block();
    std::vector<std::vector<Neuron>> neurons;
};

#endif 
