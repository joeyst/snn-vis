
#include "Synapse.h" 
#include "utils.h"

Synapse::Synapse(Neuron& from, Neuron& to, std::size_t size) : from(from), to(to), weights(size) {
  for (std::size_t i = 0; i < size; i++) {
    weights.Push(0.0f);
  }
}

float Synapse::GetWeight() {
  return weights.Peek();
}

void Synapse::SetWeight(float weight) {
  weights.Push(weight);
}
