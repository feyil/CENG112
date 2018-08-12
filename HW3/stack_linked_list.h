#ifndef CENG112_STACK_H
#define CENG112_STACK_H

#include <cstdlib>
#include <iostream>
//updated

namespace ceng112 {

template <typename T>
class Stack {
public:
  Stack(){m_head=0; m_size=0;}; //updated
  ~Stack(){delete_items();};
  void push(const T& items);
  T pop();
  size_t size() const { return m_size; }; //updated
  bool is_empty() const { if (m_size==0) { return true; } else {return false;} }; //updated
private:
  struct Node
  {
    T data;
    Node *next;
  };
  void delete_items();
  Node *m_head; //updated
  size_t m_size; //updated
 };
 
template <typename T>
  void Stack<T>::push(const T& item) //updated
  {
    Node *new_item= new Node;
    new_item->data=item;
    
    new_item->next=m_head;
    m_head=new_item;
    
    m_size++;
  }

template <typename T>
  T Stack<T>::pop() //updated
  {
        if (is_empty()) {
                std::cerr << "Can not pop from an empty stack!" << std::endl;
                std::exit(EXIT_FAILURE);
        }
        Node *p;
	p=m_head;
	m_head=m_head->next;
	T item=p->data;
	delete p;
	m_size--;
        return item;
  }

 template <typename T>
   //I added this section because when the program take input like
   //>3 6 /5
   //it doesn't free the memory because of the pop function can't run
  void Stack<T>::delete_items()
  {
    Node *p=m_head;
    while(p!=0)
      {
	Node *n=p->next;
	delete p;
	p=n;
      }
  }
}
#endif
