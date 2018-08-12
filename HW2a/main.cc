#include<iostream>
#include "GPSCoord.h"

//230201057

using namespace std;

int main(int argc,char* argv[])
{
  cout<<"Hello Word"<<endl;
  GPSCoord izmir(38.423175, 27.143167);
  GPSCoord ankara(39.932816, 32.860769);
  cout<<"Distance from Ankara to Izmir is ";
  cout<<(izmir.distance_to(ankara)/1000)<<" km"<<endl;

  GPSCoord iyte_math(38.323251, 26.632949);
  GPSCoord iyte_library(38.319741, 26.639794);
  cout<<"Distance from IYTE Mathematics Department to IYTE Library is ";
  cout<<iyte_math.distance_to(iyte_library)<<" m"<<endl;
}
//fey
