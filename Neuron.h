
#include <cstdint>

#ifndef _NEURON_H
#define _NEURON_H 

class Neuron {
  /* 
  energy | Current energy of neuron. 
  _fires | Each bit represents whether the neuron fired during the last 32 ticks. 
  */
  public:
    Neuron(float initialEnergy);
    Neuron();
    float energy;
    uint32_t _fires; 
    int NumberOfFires();
    void SetCurrentTickFire(bool did_fire);
    bool IsFiring();
    float GetTolFactor();
};

#endif 
