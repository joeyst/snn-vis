
#include <utility>
#include <vector> 
#include <cstdint>

struct Point3D {
  float x, y, z;
};

std::pair<Point3D, Point3D> GetConnectionEndpoints(const Point3D& start, const Point3D& end, float segmentPercent); 

const float FIRING_RATE_GOAL = 4.f; 
float GetTolFactor(int n_fires);
std::vector<float> GetOjaWeightChanges(const std::vector<float>& energies, const std::vector<float>& weights); 

// SOURCE: https://stackoverflow.com/questions/109023/count-the-number-of-set-bits-in-a-32-bit-integer 
int NumberOfSetBits(uint32_t i);