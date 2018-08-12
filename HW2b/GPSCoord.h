#ifndef GPSCOORD_H
#define GPSCOORD_H
class GPSCoord
{
 public:
  GPSCoord(double,double);
  const double la_in_degrees(){return m_lattitude;};
  const double lo_in_degrees(){return m_longitude;};
 private:
  double m_lattitude;
  double m_longitude;
};

#endif
