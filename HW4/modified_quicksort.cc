#include<iostream>
#include<string>

using namespace std;

class ContactItem{
public:
  string name;
  string tel_no;

  bool operator<(const ContactItem& other){return tel_no<other.tel_no;
  }
};

template<typename T>
bool (*cmp_func)(T i0, T i1);

template<typename T>
bool less_than(T i0, T i1){return i0<i1;}

template<typename T>
void print_array(int n,const T *x);

template<typename T>
bool is_sorted(int n, const T *x, bool (*cmp_func)(T i0, T i1));

template<typename T>
void exchange(T *x, int i, int j);

template<typename T>
int partition(T *x, int l, int r,bool (*cmp_func)(T i0, T i1));

template<typename T>
void insertion_sort(T *x, int l, int r, bool (*cmp_func)(T i0, T i1));

template<typename T>
void quicksort_r(T *x, int l, int r, bool (*cmp_func)(T i0, T i1));

template<typename T>
void quicksort2(T *x, int l, int r, bool (*cmp_func)(T i0, T i1));

int main(int argc,char **argv)
{
  cout<<"Hello"<<endl;
  const int N=5;
  ContactItem x[N]={{"Mehmet","0543"},{"Ali","0532"},{"Fatma","0533"},{"Ayse","0543"},{"Radhakrisha","0532"}};
  print_array(N,x);

  quicksort2(x,0,N-1,&less_than);
  print_array(N,x);

  if(is_sorted(N,x,&less_than))
    cout<<"SORTED"<<endl;
  else
    cout<<"NOT SORTED"<<endl;
}

template<typename T>
void print_array(int n, const T *x)
{
  cout<<"[";
  for(int i=0; i<n; ++i)
    {
      cout<<"("<<x[i].name<<","<<x[i].tel_no<<")";
    }
  cout<<"]"<<endl;
}

template<typename T>
bool is_sorted(int n, const T *x, bool (*cmp_func)(T i0, T i1))
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
int partition(T *x,int l,int r,bool (*cmp_func)(T i0, T i1))
{
  cout<<"  ";
  print_array(r-l+1,x+l);

  int i=l-1;
  int j=r;
  T v=x[r];

  while(1){
    while((*cmp_func)(x[++i],v))
      ;
    while((*cmp_func)(v,x[--j]))
      if(j==l)
	break;
    if(i >=j)
      break;
    exchange(x,i,j);
  }
  exchange(x,i,r);
  return i;
}

template<typename T>
void quicksort_r(T *x,int l, int r, bool (*cmp_func)(T i0, T i1))
{
  const int QSORT_MIN_LENGTH=3;

  if(r-l<= QSORT_MIN_LENGTH)
    return;
  
  exchange(x,(l+r)/2,r-1);
  if((*cmp_func)(x[r-1],x[l]))
    exchange(x,l,r-1);
  if((*cmp_func)(x[r],x[l]))
    exchange(x,l,r);
  if((*cmp_func)(x[r],x[r-1]))
     exchange(x,r-1,r);

  int i= partition(x,l+1,r-1,cmp_func);
  quicksort_r(x,l,i-1,cmp_func);
  quicksort_r(x,i+1,r,cmp_func);
   
}

template<typename T>
void quicksort2(T *x, int l, int r, bool (*cmp_func)(T i0, T i1))
{
  quicksort_r(x,l,r,cmp_func);
  cout<<"  ";
  print_array(r-l+1,x);
  insertion_sort(x,l,r,cmp_func);
}

template<typename T>
void insertion_sort(T *x, int l, int r, bool (*cmp_func)(T i0, T i1))
{
  for(int i=r; i>l; --i)
    if((*cmp_func)(x[i],x[i-1]))
      exchange(x,i,i-1);

  for(int i=l+2; i<=r; ++i){
    int j=i;
    T v=x[i];
    while((*cmp_func)(v,x[j-1])){
      x[j]=x[j-1];
      --j;
    }
    x[j]=v;
  }
}
