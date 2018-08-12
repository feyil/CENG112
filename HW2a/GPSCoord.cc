#include<iostream>
#include<cmath>
#include "GPSCoord.h"

const double PI=3.1415926535897;
const double R=6371e3;

GPSCoord::GPSCoord(double la,double lo)
{
  m_lattitude=la;
  m_longtitude=lo;
}
double GPSCoord::distance_to(const GPSCoord &object_from) const
{
  double lat1=la_in_radians();
  double lat2=object_from.la_in_radians();
  double lo1=lo_in_radians();
  double lo2=object_from.lo_in_radians();
  double a,c,d;
  a=(sin((lat1-lat2)/2)*sin((lat1-lat2)/2)+cos(lat1)*cos(lat2)*(sin((lo1-lo2)/2)*sin((lo1-lo2)/2)));
  c=2*atan2(sqrt(a),sqrt(1-a));
  d=R*c;
  return d;
}
double GPSCoord::lo_in_radians() const 
{
  return m_longtitude*(PI/180);
}
double GPSCoord::la_in_radians() const 
{
  return m_lattitude*(PI/180);
}
