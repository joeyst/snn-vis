
#include <cstdint>
#include <vector>
#include "Point3D.h"

#ifndef _NEURON_H
#define _NEURON_H 

class Neuron {
  /* 
  energy | Current energy of neuron. 
  _fires | Each bit represents whether the neuron fired during the last 32 ticks. 
  */
  public:
    float energy;
    uint32_t _recvs;
    std::vector<std::vector<float>> synapses; // Up to 26 synapses. (Think of neuron as being center of 3x3x3 box.)
    PointIds3D xyz;

    Neuron(float initialEnergy);
    Neuron();
    void SetCurrentTickFire(bool did_fire);
    bool IsFiring();
    float GetTolFactor();

  private:
    uint32_t _fires; 
    int NumberOfFires();
    std::size_t GetSynapseIndex(PointIds3D sender);
};

#endif 
