#include <iostream>
#include <string>

using namespace std;

class ContactItem {
public:
  string name;
  string tel_no;

  bool operator>(const ContactItem& other){return tel_no > other.tel_no;
  }
};

template<typename T>
bool (*cmp_func)(T i0, T i1);

template<typename T>
bool greater_than(T i0, T i1){return i0>i1;}

template<typename T>
void print_array(int n,const T *x);

template<typename T>
bool is_sorted(int n,const T *x,bool (*cmp_func)(T i0, T i1));

template<typename T>
void exchange (T *x, int i, int j);

template<typename T>
void insertion_sort2(T *x,int l,int r,bool (*cmp_func)(T i0, T i1));


int main(int argc, char **argv)
{
  const int N=5;
  ContactItem x[N]={{"Mehmet","0543"},{"Ali","0532"},{"Fatma","0533"},{"Ayse","0543"},{"Radhakrisha","0532"}};
  
  print_array(N,x);
  
  insertion_sort2(x,0,N-1,&greater_than);
  print_array(N,x);

  if(is_sorted(N,x,&greater_than))
    cout<<"SORTED"<<endl;
  else
    cout<< "NOT SORTED"<<endl;
}


template<typename T>
void print_array(int n,const T *x)
{
  cout<<"[";
  for(int i=0; i<n; ++i)
    {
      cout<<"("<<x[i].name<<","<<x[i].tel_no<<")";
    }
  cout<<"]"<<endl;
}

template<typename T>
bool is_sorted(int n,const T*x,bool (*cmp_func)(T i0, T i1))
{
  for(int i=1; i<n; ++i)
    {
      if((*cmp_func)(x[i],x[i-1]))
	 return false;
    }
      return true;
}

template<typename T>
void exchange(T *x,int i,int j)
{
  T t=x[i];
  x[i]=x[j];
  x[j]=t;
}

template<typename T>
void insertion_sort2(T *x,int l,int r,bool (*cmp_func)(T i0, T i1))
{
  for(int i=r; i>l; --i)
    {
    if((*cmp_func)(x[i],x[i-1]))
      {
      exchange(x,i,i-1);
      }
    }
  for(int i=l+2; i<=r; ++i)
    {
      int j=i;
      T v=x[i];
      while((*cmp_func)(v,x[j-1]))
	{
	  x[j]=x[j-1];
	  --j;
	}
      x[j]=v;

      cout<<" ";
      print_array(r-l+1,x+l);
    }   
}
