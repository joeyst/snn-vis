
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

bool Neuron::EnergyExceedsFiringThreshold() {
  return this->energy > NEURON_FIRE_THRESH;
}

float Neuron::GetTolFactor() {
  return ::GetTolFactor(this->NumberOfFires());
}

void Neuron::DecayEnergy() {
  this->energy = (1.f - ENERGY_DECAY_PROP) * this->energy;
}

void Neuron::TickFire() {
  fires.Push(EnergyExceedsFiringThreshold());
}

float Neuron::GetRawEnergyReceived() {
  float e = 0.f;
  for (auto synapse : synapses) {
    if (synapse->from.JustFired()) {
      e += synapse->GetWeight();
    }
  }
  return e;
}

bool Neuron::JustFired() {
  return this->fires.Peek();
}

float Neuron::GetTolAdjustedEnergyReceived() {
  return GetRawEnergyReceived() * GetTolFactor();
}

void Neuron::SetFired() {
  if (energy + GetTolAdjustedEnergyReceived()) {
    fired = true;
  }
}

float Neuron::Output() {
  if (fired) {
    return 1.f;
  }
  else {
    return 0.f;
  }
}

void Neuron::ApplyOjas() {
  for (auto synapse : synapses) {
    float streng = synapse->from.JustFired() * Output();
    float forget = synapse->GetWeight() * Output() * Output();
    float change = (streng - forget) * LEARNING_RATE;
    synapse->SetWeight(synapse->GetWeight() + change);
  }
}
