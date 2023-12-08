
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
  private:
    uint32_t _fires; // Stores the most recent 32 tick's fires. 

  public:
    float energy; // Current neuron energy. 
    uint32_t _recvs; // Stores the curent active incoming synapses. 
    PointIds3D xyz; // Neuron's XYZ indices. 
    std::vector<float> synapses; // Up to 26 synapses. (Think of neuron as being center of 3x3x3 box.)

  public:
    Neuron(float initialEnergy);
    Neuron();
    void SetCurrentTickFire(bool did_fire);
    bool IsFiring();
    float GetTolFactor();
    std::size_t GetSynapseIndex(PointIds3D sender);
    std::vector<PointIds3D> GetNeighboringNeuronIds();
    void SetNeuronRecvs(std::vector<Neuron*> senders);
    void TickEnergy();

  private:
    int NumberOfFires();
  };

#endif 
