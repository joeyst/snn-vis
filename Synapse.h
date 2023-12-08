
#ifndef _SYNAPSE_H
#define _SYNAPSE_H

#include <vector>
#include "Neuron.h"

class Neuron;
typedef std::vector<float> Weights;
typedef std::size_t Index;

class Synapse {
  public:
    Neuron& from;
    Neuron& to;
    Weights n_weights;
    Index   i;
};

#endif
