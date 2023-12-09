
#include "Net.h"
#include "Point3D.h"
#include "Direction.h"

#ifndef _NET_BUILDER_H
#define _NET_BUILDER_H

class NetBuilder {
  private:
    Net net;

  public:
    void AddRectangle(PointIds3D xyz1, PointIds3D xyz2, Direction direction);
};

#endif 
