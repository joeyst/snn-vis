
#include "utils.h"
#include "cstdlib"

std::pair<Point3D, Point3D> GetConnectionEndpoints(const Point3D& start, const Point3D& end, float segmentPercent) {
    float xOffset = (end.x - start.x) * segmentPercent;
    float yOffset = (end.y - start.y) * segmentPercent;
    float zOffset = (end.z - start.z) * segmentPercent;

    Point3D newStart = {start.x + xOffset, start.y + yOffset, start.z + zOffset};
    Point3D newEnd = {end.x - xOffset, end.y - yOffset, end.z - zOffset};

    return std::make_pair(newStart, newEnd);
}

float GetTolFactor(int n_fires) {
  /* Fast Sigmoid-ish function. */
  float numer = 2 * (FIRING_RATE_GOAL - (float)n_fires);
  float denom = 2 + 2 * std::abs((float)n_fires - FIRING_RATE_GOAL);
  float C     = 1.f;
  return (numer / denom) + C;
}

std::vector<float> GetOjaWeightChanges(const std::vector<float>& energies, const std::vector<float>& weights) {
    // change = io - wo^2
    float output = 0;
    for (size_t i = 0; i < energies.size(); ++i) {
        output += energies[i] * weights[i];
    }

    std::vector<float> strengs(energies.size());
    std::vector<float> forgets(energies.size());

    for (size_t i = 0; i < energies.size(); ++i) {
        strengs[i] = energies[i] * output;
        forgets[i] = weights[i] * (output * output);
    }

    std::vector<float> result(energies.size());
    for (size_t i = 0; i < energies.size(); ++i) {
        result[i] = strengs[i] + forgets[i];
    }

    return result;
}
