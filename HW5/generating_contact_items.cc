#include<iostream>
#include<ctime>
#include<string>
#include<cstdlib>
#include<fstream>

//fey
using namespace std;

void read_files(string* a_names, string* a_surnames, string* a_tel_no);
string* create_array(const int line_number);
void create_contacts(string* a_names, string* a_surnames, string* a_tel_no);
void print_contacts_file();

template <typename T>
void relase_memory(T* pointer);

int main(int argc, char* argv[])
{
  const int n_line_number=1000;
  string *a_names=create_array(n_line_number);
  string *a_surnames=create_array(n_line_number);
  string *a_tel_no=create_array(n_line_number);
  
  read_files(a_names,a_surnames,a_tel_no);
  create_contacts(a_names,a_surnames,a_tel_no);
  print_contacts_file();
  
  relase_memory(a_names);
  relase_memory(a_surnames);
  relase_memory(a_tel_no);
  
  return 0;
}

void read_files(string* a_names,string* a_surnames, string* a_tel_no)
{
  //I know all three file contains 1000 line so there is no problem
  
  string n_line,s_line,t_line;
  int counter=0;
  ifstream names ("names.txt");
  ifstream surnames ("surnames.txt");
  ifstream tel_no ("phone_numbers.txt");
  if(names.is_open() && surnames.is_open() && tel_no.is_open())
    {
      while(getline(names,n_line) && getline(surnames,s_line) && getline(tel_no,t_line))
	{
	  a_names[counter]=n_line;
	  a_surnames[counter]=s_line;
	  a_tel_no[counter]=t_line;
	  counter++;
	}
      if(counter==1000)
	cout<<"Read Operation Completed"<<endl;
      else{
	cerr<<"Read Operation Failure"<<endl;
exit(0);
      }
      names.close();
      surnames.close();
      tel_no.close();
    }
  else{
    cerr<<"Unable to open files names.txt surnames.txt phone_numbers.txt"<<endl;
    exit(0);
  }
}
string* create_array(const int line_number)
{
  string* array;
  array=new string[line_number];
  return array;
}
template <typename T>
void relase_memory(T *pointer)
{
  delete[] pointer;
}

void create_contacts(string* a_names, string* a_surnames, string* a_tel_no)
{
  int counter=0;
  int num=0;
  const int M=999;
  const int N=0;
  srand(time(0));
  ofstream contact;
  contact.open("contact.txt");
  if(contact.is_open())
    {
      for(int i=0; i<10000; i++)
	{
	  counter++;
	  num=(rand()%M)+N;
	  contact<<a_names[num]<<endl;
	  num=(rand()%M)+N;
	  contact<<a_surnames[num]<<endl;
	  num=(rand()%M)+N;
	  contact<<a_tel_no[num]<<endl;
	}
      if(counter==10000)
	cout<<"Contacts Creation Completed"<<endl;
      else{
	cerr<<"Contacts Creation Failure"<<endl;
	exit(0);
}
      contact.close();
    }
  else{	 
    cerr<<"Unable to open file"<<endl;
    exit(0);
  }
}

void print_contacts_file()
{
  string name,surname,tel_no;
  ifstream contacts ("contact.txt");
  if(contacts.is_open())
    {
      for(int i=0; i<10000; i++)
	{
	  cout<<endl;
	  getline(contacts,name);
	  cout<<"<Name"<<i<<">"<<name<<endl;
	  getline(contacts,surname);
	  cout<<"<Surname"<<i<<">"<<surname<<endl;
	  getline(contacts,tel_no);
	  cout<<"<Telephone"<<i<<">"<<tel_no<<endl;
	}
    }
}

//fey
