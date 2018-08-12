#include<iostream>
using namespace std;
//230201057

int main(int argc,char* argv[])
{
  int rows=0;
  int colums=0;
  cin>>rows;
  cin>>colums;
  int **p_matrix=new int*[rows];//it creates array of int pointers
  for(int a=0;a<rows;++a)
    {
      p_matrix[a]=new int[colums];
      //it create an array for each row pointer size of colums
    }
  for(int i=0; i<rows;++i)
    {
      for(int j=0; j<colums;++j)
	{
	  cin>>p_matrix[i][j];
	}
    }
  cout<<endl;
  for(int j=0; j<colums;++j)
    {
      for(int i=0;i<rows;++i)
	{
	  cout<<p_matrix[i][j]<<" ";
	}
      cout<<endl;
    }
  //below code deletes all the pointers
  for(int a=0;a<rows;++a)
    {
      delete []  p_matrix[a];
    }
  delete [] p_matrix;
  return 0;
}

//fey
