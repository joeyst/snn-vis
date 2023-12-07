
#include <utility>

struct Point3D {
  float x, y, z;
};

std::pair<Point3D, Point3D> GetConnectionEndpoints(const Point3D& start, const Point3D& end, float segmentPercent); 
