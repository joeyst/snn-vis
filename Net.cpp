
#include "Net.h"

std::vector<Neuron*> Net::GetNeighboringNeurons(Neuron* neuron) {
  std::vector<Neuron*> incoming_neurons;
  std::vector<PointIds3D> neighboring_neuron_ids = neuron->GetNeighboringNeuronIds();
  for (auto neighboring_neuron_id : neighboring_neuron_ids) {
    incoming_neurons.push_back(neuron_id_map[neighboring_neuron_id]);
  }
  return incoming_neurons;
}

void Net::EnableNeuron(int x, int y, int z) {
  if (!HasNeuron(x, y, z)) {
    ForceEnableNeuron(x, y, z);
  }
}

bool Net::HasNeuron(int x, int y, int z) {
  return neuron_id_map.find({x, y, z}) != neuron_id_map.end();
}

void Net::ForceEnableNeuron(int x, int y, int z) {
  Neuron n = Neuron();
  n.xyz = {x, y, z};
  neuron_id_map[{x, y, z}] = &n;
}

void Net::EnableSynapse(int x1, int y1, int z1, int x2, int y2, int z2) {
  EnableNeuron(x1, y1, z1);
  EnableNeuron(x2, y2, z2);
  Neuron* sender = neuron_id_map[{x1, y1, z1}];
  Neuron* receiver = neuron_id_map[{x2, y2, z2}];
  sender->_recvs |= (1 << receiver->GetSynapseIndex(sender->xyz));
}
