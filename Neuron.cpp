
#include "Neuron.h" 
#include "utils.h"
#include "config.h"

Neuron::Neuron(float initialEnergy): _fires((unsigned short) 0), energy(initialEnergy) {
  for (int i = 0; i < 26; ++i) {
    synapses.push_back(RandomWeight());
  }
}
Neuron::Neuron(): _fires((unsigned short) 0), energy(0.f) {}

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
    SynapseIndex += Multipliers[i] * (sender_xyz[i] - this->xyz[i]);
  }
  // There isn't a synapse for the neuron to itself. 
  if (SynapseIndex > 13) {
    SynapseIndex--;
  }
  return SynapseIndex;
}

std::vector<PointIds3D> Neuron::GetNeighboringNeuronIds() {
  std::vector<PointIds3D> neighboring_neuron_ids;
  for (int x = -1; x < 2; ++x) {
    for (int y = -1; y < 2; ++y) {
      for (int z = -1; z < 2; ++z) {
        PointIds3D neighboring_xyz = { this->xyz[0] + x, this->xyz[1] + y, this->xyz[2] + z };
        if (neighboring_xyz != this->xyz) {
          neighboring_neuron_ids.push_back(neighboring_xyz);
        }
      }
    }
  }
  return neighboring_neuron_ids;
}

void Neuron::SetNeuronRecvs(std::vector<Neuron*> senders) {
  uint32_t recvs = 0;
  for (std::size_t i = 0; i < senders.size(); i++) {
    Neuron* current_neuron = senders[i];
    if (current_neuron->IsFiring()) {
      std::size_t current_neuron_index = this->GetSynapseIndex(current_neuron->xyz);
      recvs |= ((std::size_t)1) << current_neuron_index;
    }
  }
  this->_current_tick_recvs = recvs;
}

void Neuron::TickEnergy() {
  this->energy = (1.f - ENERGY_DECAY_PROP) * this->energy;
}

void Neuron::TickFire() {
  SetCurrentTickFire(IsFiring());
}
