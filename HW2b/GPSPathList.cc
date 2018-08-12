#include<iostream>
#include<cmath>
#include "GPSPathList.h"

using namespace std;

const double PI=3.1415926535897;
const double R=6371e3;

bool GPSPathList::add_point(const double la,const double lo)
{
  GPSCoordNode *new_gps=new GPSCoordNode;
  new_gps->lattitude=la;
  new_gps->longtitude=lo;
  if(m_item_list==0)
    {
      new_gps->next=m_item_list;//null pointer
      m_item_list=new_gps; //head pointer
    }
  else
    {
      GPSCoordNode *p=m_item_list; //takes first pointer
      while(p->next !=0)
	{
	  p=p->next;
	}
      //now p=0 means that we can add item this point
      new_gps->next=p->next; //we knows it is null now
      p->next=new_gps; //it is a address new_gps
    }
  m_size++;
  cout<<"Point has been added..."<<endl;
  return true;
}
double GPSPathList::total_distance()
{
  GPSCoordNode *p=m_item_list;
  double total=0;
  while(p->next!=0)
    {
      const double lat1=p->lattitude*(PI/180);
      const double lat2=p->next->lattitude*(PI/180);
      const double lo1=p->longtitude*(PI/180);
      const double lo2=p->next->longtitude*(PI/180);
      double a,c,d;
      a=(sin((lat1-lat2)/2)*sin((lat1-lat2)/2)+cos(lat1)*cos(lat2)*(sin((lo1-lo2)/2)*sin((lo1-lo2)/2)));
      c=2*atan2(sqrt(a),sqrt(1-a));
      d=R*c;
      total=total+d;
      
      p=p->next;
    }
  return total;
}
void GPSPathList::print()
{
  GPSCoordNode *p=m_item_list;
  while(p!=0)
    {
      cout<<"("<<p->lattitude<<","<<p->longtitude<<")";
      p=p->next;
      if(p!=0)
	{
	  cout<<"--";
	}
    }
  cout<<endl;

}
void GPSPathList::delete_items()
{
  GPSCoordNode *p=m_item_list;
  while(p!=0)
    {
      GPSCoordNode *n=p->next;
      delete p;
      p=n;
    }
}
