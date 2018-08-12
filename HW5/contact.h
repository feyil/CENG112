#ifndef CONTACT_H
#define CONTACT_H

#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>

using namespace std;

struct ContactItem {
  std::string tel_no;
  std::string name;
  std::string surname;
};

ContactItem* read_contact_file()
{
  int number_contact=10000;
  ContactItem* array_contacts=new ContactItem[number_contact];
  string n_line,s_line,t_line;
  int counter=0;
  ifstream contacts ("contact.txt");

  if(contacts.is_open())
    {
      //I can count but I know contact.txt has 10000 line
      for(int i=0; i<10000; i++)
	{
	  if(getline(contacts,n_line) && getline(contacts,s_line) && getline(contacts, t_line))
	    {
	      array_contacts[i].name=n_line;
	      array_contacts[i].surname=s_line;
	      array_contacts[i].tel_no=t_line;
	    }
	  else
	    {
	      cerr<<"Contact Item Read Failure"<<endl;
	      exit(0);
	    }
	}
      contacts.close();
      return array_contacts;
    }
  else
    {
      cerr<<"Unable to open contact.txt"<<endl;
      exit(0);
    }
  
};
#endif
