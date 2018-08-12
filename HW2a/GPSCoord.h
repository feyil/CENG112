#ifndef GPSCOORD_H
#define GPSCOORD_H

class GPSCoord
{
 public:
  GPSCoord(double,double);
  const double lo_in_degrees(){return m_longtitude;}
  const double la_in_degrees(){return m_lattitude;}
  double lo_in_radians() const;
  double la_in_radians() const;
  
  double distance_to(const GPSCoord &object_from) const;
  
 private:
  double m_longtitude; //in degrees
  double m_lattitude; //in degrees
};


#endif
