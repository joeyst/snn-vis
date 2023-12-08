
#include <utility>
#include <vector> 

struct Point3D {
  float x, y, z;
};

std::pair<Point3D, Point3D> GetConnectionEndpoints(const Point3D& start, const Point3D& end, float segmentPercent); 

const float FIRING_RATE_GOAL = 4.f; 
float GetTolFactor(int n_fires);
std::vector<float> GetOjaWeightChanges(const std::vector<float>& energies, const std::vector<float>& weights); 
