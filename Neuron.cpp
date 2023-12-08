
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