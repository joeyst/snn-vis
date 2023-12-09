
#include "Net.h"

void Net::EnableNeuron(PointIds3D xyz) {
  if (!HasNeuron(xyz)) {
    ForceEnableNeuron(xyz);
  }
}

bool Net::HasNeuron(PointIds3D xyz) {
  return neuron_id_map.find(xyz) != neuron_id_map.end();
}

void Net::ForceEnableNeuron(PointIds3D xyz) {
  Neuron n = Neuron();
  n.xyz = xyz;
  neuron_id_map[xyz] = &n;
}

void Net::EnableSynapse(PointIds3D xyz1, PointIds3D xyz2) {
  EnableNeuron(xyz1);
  EnableNeuron(xyz2);
  Neuron* sender = neuron_id_map[xyz1];
  Neuron* receiver = neuron_id_map[xyz2];
}

void Net::Tick() {
  for (auto kv : neuron_id_map) {
    kv.second->UpdateSynapses();
  }
  for (auto kv : neuron_id_map) {
    kv.second->UpdateEnergy();
  }
}

Net::Net() {}
