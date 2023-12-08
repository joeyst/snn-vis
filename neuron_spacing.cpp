
#include "neuron_spacing.h" 

Point3D GetNeuronCoords(int x, int y, int z) {
  return { ((float)x) * NEURON_TOTAL_DIST, ((float)y) * NEURON_TOTAL_DIST, ((float)z) * NEURON_TOTAL_DIST };
}

std::pair<Point3D, Point3D> GetSynapseEndpoints(int x1, int y1, int z1, int x2, int y2, int z2) {
  
}
