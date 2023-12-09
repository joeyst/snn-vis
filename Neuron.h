
#ifndef _NEURON_H
#define _NEURON_H 

#include <cstdint>
#include <vector>
#include "Point3D.h"
#include "Synapse.h"
#include "CircularBuffer.h"

typedef CircularBuffer<bool> Fires;

class Neuron {
  /* 
  energy | Current energy of neuron. 
  _fires | Each bit represents whether the neuron fired during the last 32 ticks. 
  */
  public:
    float energy; // Current neuron energy. 
    Fires fires;
    std::vector<Synapse*> synapses;
    PointIds3D xyz; // Neuron's XYZ indices. 

  public:
    Neuron(float initialEnergy);
    Neuron();
    bool IsFiring();
    void DecayEnergy();
    void TickFire();

  private:
    int NumberOfFires();
    void SetCurrentTickFire(bool did_fire);
    float GetTolFactor();
  };

#endif 
