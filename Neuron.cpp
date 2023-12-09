
#include "Neuron.h" 
#include "utils.h"
#include "config.h"

Neuron::Neuron(float initialEnergy): fires(Fires(N_TICKS_TO_TRACK)), energy(initialEnergy) {}
Neuron::Neuron(): fires(Fires(N_TICKS_TO_TRACK)), energy(0.f) {}

int Neuron::NumberOfFires() {
  int number_of_fires = 0;
  for (std::size_t i = 0; i < this->fires.GetVector().size(); ++i) {
    if (this->fires.GetVector()[i]) {
      number_of_fires++;
    }
  }
}

bool Neuron::IsFiring() {
  return this->energy > NEURON_FIRE_THRESH;
}

float Neuron::GetTolFactor() {
  return ::GetTolFactor(this->NumberOfFires());
}

void Neuron::DecayEnergy() {
  this->energy = (1.f - ENERGY_DECAY_PROP) * this->energy;
}

void Neuron::TickFire() {
  fires.Push(IsFiring());
}
