
#include "Net.h"

std::vector<Neuron*> Net::GetNeighboringNeurons(Neuron* neuron) {
  std::vector<Neuron*> incoming_neurons;
  std::vector<PointIds3D> neighboring_neuron_ids = neuron->GetNeighboringNeuronIds();
  for (auto neighboring_neuron_id : neighboring_neuron_ids) {
    incoming_neurons.push_back(neuron_id_map[neighboring_neuron_id]);
  }
  return incoming_neurons;
}
