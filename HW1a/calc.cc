#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

int main(int argc,char* argv[])
{
  if(argc==1)
    {
      cerr<<"Usage: "<<argv[0]<<" <+ or x> "<<" <numbers> "<<endl;
      return 1;
    }
  else
    {
      if(strcmp(argv[1],"+")==0)
	{
	  double sum=0;
	  if(argc==2)
	    {
	      cout<<"Result:"<<sum<<endl;
	    }
	  else
	    {
	      for(int i=2;i<argc;i++)
		{
		  sum=atof(argv[i])+sum;
		}
	      cout<<"Result:"<<sum<<endl;
	    }
	  
	}
      else if (strcmp(argv[1],"x")==0)
	{
	  double multiplication=1;
	  if(argc==2)
	    {
	      cout<<"Result:"<<multiplication<<endl;
	    }
	  else
	    {
	      for(int i=2;i<argc;i++)
		{
		  multiplication=atof(argv[i])*multiplication;
		}
	      cout<<"Result:"<<multiplication<<endl;
	    }
	}
      else
	{
	  cerr<<"Invalid Operator"<<endl;
	  return 1;
	}
    }
  return 0;
}
