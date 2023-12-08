
#include "Neuron.h" 
#include "utils.h"
#include "config.h"

Neuron::Neuron(float initialEnergy): energy(initialEnergy), _fires((unsigned short) 0) {}
Neuron::Neuron(): energy(0.f), _fires((unsigned short) 0) {}

int Neuron::NumberOfFires() {
  return NumberOfSetBits(this->_fires);
}

void Neuron::SetCurrentTickFire(bool did_fire) {
  this->_fires = (this->_fires << 1) | (did_fire ? 1 : 0);
}

bool Neuron::IsFiring() {
  return this->energy > NEURON_FIRE_THRESH;
}

float Neuron::GetTolFactor() {
  return ::GetTolFactor(this->NumberOfFires());
}

std::size_t Neuron::GetSynapseIndex(PointIds3D sender_xyz) {
  std::size_t SynapseIndex = 13;
  std::vector<int> Multipliers = { 1, 3, 9 };
  for (std::size_t i = 0; i < sender_xyz.size(); ++i) {
    SynapseIndex += Multipliers[i] * (this->xyz[i] - sender_xyz[i]);
  }
  return SynapseIndex;
}
