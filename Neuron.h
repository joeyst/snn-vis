
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
  fires | Last N ticks bools. 
  fired | If firing during current tick. 

  STEPS: 
  1. Update all synapses, with UpdateSynapses. 
  2. Update all energies, with UpdateEnergy. 
  */
  public:
    float energy; 
    Fires fires;
    bool fired; 
    std::vector<Synapse*> synapses;
    PointIds3D xyz; 

  public:
    Neuron(float initialEnergy);
    Neuron();
    void UpdateSynapses();
    void UpdateEnergy();

  private:
    bool EnergyExceedsFiringThreshold();
    void DecayEnergy();

    int NumberOfFires();
    void SetCurrentTickFire(bool did_fire);
    float GetTolFactor();

    float GetRawEnergyReceived();
    bool JustFired();
    float GetTolAdjustedEnergyReceived();

    void SetFired();
    float Output();
    void ApplyOjas();
  };

#endif 
