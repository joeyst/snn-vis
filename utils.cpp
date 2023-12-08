
#include "utils.h"
#include "cstdlib"

std::pair<PointCoords3D, PointCoords3D> GetConnectionEndpoints(const PointCoords3D& start, const PointCoords3D& end, float segmentPercent) {
  PointCoords3D resultStart(3);
  PointCoords3D resultEnd(3);

  for (size_t i = 0; i < 3; ++i) {
    resultStart[i] = start[i] + (end[i] - start[i]) * segmentPercent;
    resultEnd[i]   = end[i]   - (end[i] - start[i]) * segmentPercent;
  }

  return std::make_pair(resultStart, resultEnd);
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
    float output = 0.f;
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
        result[i] = strengs[i] - forgets[i];
    }

    return result;
}

// SOURCE: https://stackoverflow.com/questions/109023/count-the-number-of-set-bits-in-a-32-bit-integer 
int NumberOfSetBits(uint32_t i) {
     i = i - ((i >> 1) & 0x55555555);        // add pairs of bits
     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);  // quads
     i = (i + (i >> 4)) & 0x0F0F0F0F;        // groups of 8
     i *= 0x01010101;                        // horizontal sum of bytes
     return  i >> 24;               // return just that top byte (after truncating to 32-bit even when int is wider than uint32_t)
}