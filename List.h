#ifndef LIST_H 
#define LIST_H


#include <cstdlib>
#include "defs.h"

//the List class is a class template for a linked list that stores T objects
template <class T>
class List
{

    class Node
    {
        public: 
        T data;
        Node*    next;
    };

  public:
    List();
    ~List();
    List<T>& operator+=(const T&);
    void convertToArray(T* arr, int& size);

  private:
    Node* head;
};

template <class T>
List<T>::List() 
{ 
    head = nullptr;
}

template <class T>
List<T>::~List()
{
  Node* currNode = head;
  Node* nextNode;


  while (currNode != nullptr) {
    nextNode = currNode->next;
    delete currNode->data;
    delete currNode;
    currNode = nextNode;
  }
}

template <class T>
List<T>& List<T>::operator+=(const T& t){
  Node  *newNode; 

  newNode = new Node; 
  newNode->data = t; 
  newNode->next = nullptr; 

  if(head == nullptr){
    head = newNode; 
  } else{
    Node* currNode = head; 
    while(currNode->next != nullptr){
      currNode = currNode->next; 
    }
    currNode->next = newNode; 
  }
  
  return *this;
}

template <class T>
void List<T>::convertToArray(T* arr, int& size){


    Node* currNode = head; 
    size = 0; 

    while(currNode != nullptr){

      arr[size] = currNode->data; 
      currNode = currNode->next; 
      ++size; 
    }
  

}









#endif
