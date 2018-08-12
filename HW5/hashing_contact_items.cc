#include<iostream>
#include<string>
#include<cstring>

#include "contact.h"

//fey
using namespace std;

int hash(char *v,int M);
int hashU(char* v, int M);
void hash_contacts(ContactItem* array_contacts,const int M);

int main(int argc, char* argv[])
{
  const int M=31;

  cout<<"Hashing with names"<<endl;
  
  ContactItem* array_contacts=read_contact_file();
  hash_contacts(array_contacts,M);
  
  delete[] array_contacts;
  
  return 0;
}

int hashU(char *v, int M)//I have read the source book and took it
{
  int h,a=31415, b=27183;
  for(h=0; *v!=0; v++, a=a*b%(M-1))
    h=(a*h+*v)%M;
  return (h<0)?(h+M):h;
}

int hash(char *v,int M)//I have read the source book and took it
{
  int h=0,a=127;
  for(; *v!=0;v++){
    h=(a*h+*v)%M;
  }
  return h;
}

void hash_contacts(ContactItem* array_contacts,const int M)
{
  char* c_name;
  string name;
  int hash_result=-1;
  
  int hash_range[M]={};
  
  for(int i=0; i<10000; i++){
    
    name=array_contacts[i].name;
    c_name=new char[name.length()+1];
    strcpy(c_name,name.c_str());
    
    hash_result=hashU(c_name,M);
    hash_range[hash_result]++;
    
    delete[] c_name;
  }
  for(int i=0; i<M; i++)
    {
      cout<<i<<":"<<hash_range[i]<<endl;
    }
}
//fey

