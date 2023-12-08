
#include "neuron_spacing.h" 

Point3D GetNeuronCoords(int x, int y, int z) {
  return { ((float)x) * NEURON_TOTAL_DIST, ((float)y) * NEURON_TOTAL_DIST, ((float)z) * NEURON_TOTAL_DIST };
}
