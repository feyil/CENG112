#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <clocale>

#include "contact.h"

//fey
using namespace std;

const int RBT_BLACK = 0;
const int RBT_RED = 1;

ContactItem* array_contacts=read_contact_file();


void print_contact_info(int contact_index);

struct RBTreeNode {
  int contact_idx;

  int color;
  RBTreeNode *left;
  RBTreeNode *right;
};

RBTreeNode *new_node(int contact_idx, int color);
void free_tree(RBTreeNode *root);
RBTreeNode *add_contact(RBTreeNode *root, int contact_idx, int sw,int search_method);
int search_tree(RBTreeNode *root, const string &name,int search_method);

void print_contacts(const RBTreeNode *root);

static RBTreeNode z = {
  .contact_idx = -1,
  .color = RBT_BLACK,
  .left = &z,
  .right = &z
};

int main(int argc, char **argv)
{	
  string key;
  int choice=-1;
  int search_method=-1;
  
  cout<<"Hello"<<endl;
  while(true){
    cout<<"How do you want search using name, surname or telephone number"<<endl;
    cout<<"\tPress 0 for using name"<<endl;
    cout<<"\tPress 1 for using surname"<<endl;
    cout<<"\tPress 2 for using telephone number"<<endl;
    cout<<"Choice:";
    cin>>choice;
    if(choice==0){
      cout<<"Enter contact name:";
      cin>>key;
      search_method=0;
      break;
    }
    else if(choice==1){
      cout<<"Enter contact surname:";
      cin>>key;
      search_method=1;
      break;
    }
    else if(choice==2){
      cout<<"Enter telephone number:";
      cin>>key;
      search_method=2;
      break;
    }
    else{
      cerr<<"Invalid choice"<<endl;
    }
  }
  const int n_contacts=10000;//number of contact item
  RBTreeNode *root = &z;
  for (int i = 1; i < n_contacts; ++i) {
    root = add_contact(root, i, 0,search_method);
    root->color = RBT_BLACK;
  }
  
  int contact_idx = search_tree(root, key,search_method);
  if (contact_idx >= 0) {
    print_contact_info(contact_idx);
  } else {
    print_contacts(root);
    cerr << "There is no matching with " << key << endl;
  }
  
  free_tree(root);
  delete[] array_contacts;
  return EXIT_SUCCESS;
}

RBTreeNode *new_node(int contact_idx, int color)
{
  RBTreeNode *n = new RBTreeNode;
  if (n == 0) {
    cerr << "Out of memory!\n";
    exit(EXIT_FAILURE);
  }
  
  n->contact_idx = contact_idx;
  n->left = &z;
  n->right = &z;
  n->color = color;
  
  return n;
}

void free_tree(RBTreeNode *root)
{
  if (root == &z)
    return;
  
  free_tree(root->left);
  free_tree(root->right);
  delete root;
}

RBTreeNode *rotate_left(RBTreeNode *n)
{
  RBTreeNode *x = n->right;
  n->right = x->left;
  x->left = n;
  return x;
}

RBTreeNode *rotate_right(RBTreeNode *n)
{
  RBTreeNode *x = n->left;
  n->left = x->right;
  x->right = n;
  return x;
}

RBTreeNode *add_contact(RBTreeNode *root, int contact_idx, int sw,int search_method)
{
  int cmp_res;
  if (root == &z)
    return new_node(contact_idx, RBT_RED);
  
  if (root->left->color == RBT_RED
      && root->right->color == RBT_RED) {
    root->left->color = RBT_BLACK;
    root->right->color = RBT_BLACK;
    root->color = RBT_RED;
  }
  
  /* // strcoll is like strcmp but respects language order */
  if(search_method==0)//name
    cmp_res = strcoll(array_contacts[contact_idx].name.c_str(), array_contacts[root->contact_idx].name.c_str());
  else if(search_method==1) //surname
    cmp_res = strcoll(array_contacts[contact_idx].surname.c_str(), array_contacts[root->contact_idx].surname.c_str());
  else if(search_method==2) //telephone
    cmp_res = strcoll(array_contacts[contact_idx].tel_no.c_str(), array_contacts[root->contact_idx].tel_no.c_str());
  else{
    cerr<<"Search Method Failure"<<endl;
    exit(0);
  }
  if (cmp_res < 0) {
    root->left = add_contact(root->left, contact_idx, 0,search_method);
    if (root->color == RBT_RED && root->left->color == RBT_RED && sw)
      root = rotate_right(root);
    if (root->left->color == RBT_RED && root->left->left->color == RBT_RED) {
      root = rotate_right(root);
      root->color = RBT_BLACK;
      root->right->color = RBT_RED;
    }
  } else {
    root->right = add_contact(root->right, contact_idx, 1,search_method);
    if (root->color == RBT_RED && root->right->color == RBT_RED && !sw)
      root = rotate_left(root);
                if (root->right->color == RBT_RED && root->right->right->color == RBT_RED) {
		  root = rotate_left(root);
		  root->color = RBT_BLACK;
		  root->left->color = RBT_RED;
                }
  }
  
  return root;
}

int search_tree(RBTreeNode *root, const string &name,int search_method)
{
  int cmp_res;
  if (root == &z)
    return -1;
  
  // strcoll is like strcmp but respects language order
  if(search_method==0)//name
    cmp_res = strcoll(name.c_str(), array_contacts[root->contact_idx].name.c_str());
  else if(search_method==1)//surname
    cmp_res = strcoll(name.c_str(), array_contacts[root->contact_idx].surname.c_str());
  else if(search_method==2)//telphone
    cmp_res = strcoll(name.c_str(), array_contacts[root->contact_idx].tel_no.c_str());
  else{
    cerr<<"Search Method Failure"<<endl;
    exit(0);
  }
  
  if (cmp_res == 0)
    return root->contact_idx;
  else if (cmp_res < 0)
    return search_tree(root->left, name,search_method);
  else
    return search_tree(root->right, name,search_method);
}

void print_contacts(const RBTreeNode *root)
{
  if (root == &z)
    return;
  
  if (root->left != &z)
    print_contacts(root->left);
  
  print_contact_info(root->contact_idx);
  
  if (root->right != &z)
    print_contacts(root->right);
}

void print_contact_info(int contact_idx)
{
  cout << "tel/name/sur: " << array_contacts[contact_idx].tel_no << " / " << array_contacts[contact_idx].name <<" / "<<array_contacts[contact_idx].surname<<endl;
}

//fey
