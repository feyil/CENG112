#ifndef CENG112_QUEUE_H
#define CENG112_QUEUE_H

#include <cstdlib>
#include <iostream>

namespace ceng112 {

template <typename T>
class Queue {
public:
  Queue() { m_head =0; m_size = 0; }  //updated
  ~Queue() {clear(); }

        void enqueue(const T& item);
        T dequeue();
        void clear();

        size_t size() const { return m_size; }
        bool is_empty() const { return size() == 0; }
private:
        struct Node {
                T data;
                Node *next;
                Node *prev;
        };

        Node *m_head; // dequeue from head
        //updated
        size_t m_size;
};

template <typename T>
void Queue<T>::enqueue(const T& item)
{
        Node *node = new Node;
	node->data=item;
	  
        if (is_empty()) {
	  node->next=m_head;
	  node->prev=m_head;
	  m_head=node;
        } else {
	  if(m_size==1)
	    {
	      m_head->next=node;
	      m_head->prev=node;
	      node->next=m_head;
	      node->prev=m_head;
	    }
	  else
	    {
	      node->next=m_head->next;
	      node->prev=m_head;
	      m_head->next->prev=node;
	      m_head->next=node;

	    }
        }
        m_size++;
}

template <typename T>
T Queue<T>::dequeue()
{
        if (is_empty()) {
                std::cerr << "Can not dequeue from an empty queue!" << std::endl;
                std::exit(EXIT_FAILURE);
        }

        T item = m_head->data;
	  if(m_size==1)
	    {
	      delete m_head;
	    }
	  else if (m_size == 2)
	    {
	      Node *new_head=m_head->prev;
	      delete m_head;
	      m_head=new_head;
	      m_head->next=0;
	      m_head->prev=0;
	    }
	  else if(m_size>=3)
	    {
	      	m_head->next->prev=m_head->prev;
		m_head->prev->next=m_head->next;
		Node *new_head = m_head->prev;
		delete m_head;
		m_head=new_head;
	    }
	  else
	    {
	      std::cerr<<"Opps"<<std::endl;
	    }
             
        m_size--;

        return item;
}

template <typename T>
void Queue<T>::clear()
{
  Node *p=m_head;
  if(m_size==1)
    {
       delete p;
    }
  else
    {
     while(m_size!=0)
      {
        Node *to_delete=p;
        if(m_size!=1)
          {
	    p=p->prev;
            delete to_delete;
          }
	else
	  {
	    delete p;
	  }
	m_size--;
      }
    }
  m_size=0;
  m_head=0;
}



}

#endif
