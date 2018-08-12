#ifndef GPSPATH_H
#define GPSPATH_H

#include<vector>
#include "GPSCoord.h"

class GPSPath
{
 public:
  bool add_point(double lat,double log);
  double total_distance();
  void print();
 private:
  std::vector<GPSCoord> m_points;
};

#endif
