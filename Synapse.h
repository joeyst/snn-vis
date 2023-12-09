
#ifndef _SYNAPSE_H
#define _SYNAPSE_H

#include <vector>
#include "CircularBuffer.h"

class Neuron;
typedef CircularBuffer<float> Weights;
typedef std::size_t Index;

class Synapse {
  public:
    Neuron& from;
    Neuron& to;
    Weights weights;

  public:
    Synapse(Neuron& from, Neuron& to, std::size_t size);
    float GetWeight();
    void  SetWeight(float weight);
};

#endif
