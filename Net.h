
#include "tuple_hash.h"
#include <unordered_map>

class Net {
  std::unordered_map<PointIds3D, int, container_hash<PointIds3D>> neuron_id_map;
};
