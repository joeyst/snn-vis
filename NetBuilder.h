
#include "Net.h"
#include "Point3D.h"
#include "Direction.h"

#ifndef _NET_BUILDER_H
#define _NET_BUILDER_H

class NetBuilder {
  /*
  AddRectangle: 
    start => starting point. 
    width => (N, M, 0) | (N, 0, M) | (0, N, M). Creates initial plane. N and M can be negative. 
    dxyz  => jump rate in each dimension. 
    n     => number of layers. 
  */
  private:
    Net net;

  public:
    void AddRectangle(PointIds3D start, PointIds3D width, PointIds3D dxyz, std::size_t n);
    NetBuilder();
};

#endif 
