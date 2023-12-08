
#include <cstdint>

#ifndef _NEURON_H
#define _NEURON_H 

class Neuron {
  /* 
  energy | Current energy of neuron. 
  _fires | Each bit represents whether the neuron fired during the last 32 ticks. 
  */
  public:
    float energy;

    Neuron(float initialEnergy);
    Neuron();
    void SetCurrentTickFire(bool did_fire);
    bool IsFiring();
    float GetTolFactor();

  private:
    uint32_t _fires; 
    int NumberOfFires();
};

#endif 
