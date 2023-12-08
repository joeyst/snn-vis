
#include "Neuron.h" 
#include "utils.h"

Neuron::Neuron(float initialEnergy): energy(initialEnergy), _fires((unsigned short) 0) {}

int Neuron::NumberOfFires() {
  return NumberOfSetBits(this->_fires);
}
