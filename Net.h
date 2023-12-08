
#include "tuple_hash.h"
#include <unordered_map>
#include "Neuron.h"
#include <vector>

#ifndef _NET_H
#define _NET_H

class Net {
  public:
    std::unordered_map<PointIds3D, Neuron*, container_hash<PointIds3D>> neuron_id_map;
    std::vector<Neuron*> GetNeighboringNeurons(Neuron* neuron);
    //std::vector<Neuron*> GetOutgoingNeurons(Neuron* neuron);
    void EnableNeuron(int x, int y, int z);
    void EnableSynapse(int x1, int y1, int z1, int x2, int y2, int z2);

  private:
    bool HasNeuron(int x, int y, int z);
    void ForceEnableNeuron(int x, int y, int z);
};

#endif
