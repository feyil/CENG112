#include<iostream>
#include "GPSPathList.h"

using namespace std;

//230201057
int main(int argc,char* argv[])
{
  GPSPathList deneme;
  double la=0;
  double lo=0;
  size_t point=0;
  cout<<"Example:"<<endl;
  cout<<"40.1877378 29.045285"<<endl;
  cout<<"Hi,how many point do you want to give?"<<"(lattitude,longtitude)"<<endl;
  cin>>point;
  if((point>0)==true)
    {
      for(int i=0; i<point; ++i)
	{
	  cout<<"Please type GPS coordinates:"<<endl;
	  cin>>la>>lo;
	  deneme.add_point(la,lo);
	  cout<<"Left:"<<point-(i+1)<<endl;
	}
    }
  else
    {
      cerr<<"Please type nonzero positive integer"<<endl;
    }
  deneme.print();
  cout<<"Total Distance:"<<deneme.total_distance()/1000<<"km"<<endl;

}
//fey
