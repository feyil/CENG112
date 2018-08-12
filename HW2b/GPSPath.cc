#include<iostream>
#include "GPSPath.h"
#include <cmath>
using namespace std;

const double PI=3.1415926535897;
const double R=6371e3;

bool GPSPath::add_point(double lat, double log)
{
  GPSCoord point(lat,log);
  m_points.push_back(point);
  cout<<"Point has been added..."<<endl;
  return true;
}
double GPSPath::total_distance()
{
  double total=0;
  for(int i=0; i+1<m_points.size();++i)
    {
      const double lat1=m_points[i].la_in_degrees()*(PI/180);
      const double lat2=m_points[i+1].la_in_degrees()*(PI/180);
      const double lo1=m_points[i].lo_in_degrees()*(PI/180);
      const double lo2=m_points[i+1].lo_in_degrees()*(PI/180);
      double a,c,d;
      a=(sin((lat1-lat2)/2)*sin((lat1-lat2)/2)+cos(lat1)*cos(lat2)*(sin((lo1-lo2)/2)*sin((lo1-lo2)/2)));
      c=2*atan2(sqrt(a),sqrt(1-a));
      d=R*c;
      total=total+d;
    }
  
  return total;
}
void GPSPath::print()
{
  for(int i=0; i<m_points.size();++i)
    {
      cout<<"("<<m_points[i].la_in_degrees()<<","<<m_points[i].lo_in_degrees()<<")";
      if((i+1)!=m_points.size())
	{
	  cout<<"--";
	}
    }
  cout<<endl;
}


