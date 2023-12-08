
#include "neuron_spacing.h" 
#include "Point3D.h"

PointCoords3D GetNeuronCoords(PointIds3D xyz) {
  PointCoords3D coords;
  for (int i = 0; i < xyz.size(); i++) {
    coords.push_back(xyz[i] * NEURON_TOTAL_DIST);
  }
  return coords;
}

// std::pair<Point3D, Point3D> GetSynapseEndpoints(int x1, int y1, int z1, int x2, int y2, int z2) {
// 
// }
