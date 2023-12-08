
#include "tuple_hash.h"
#include <unordered_map>
#include "Neuron.h"
#include <vector>

class Net {
  public:
    std::unordered_map<PointIds3D, Neuron&, container_hash<PointIds3D>> neuron_id_map;
    std::vector<Neuron&> GetIncomingNeurons(Neuron& neuron);
    std::vector<Neuron&> GetOutgoingNeurons(Neuron& neuron);
};
