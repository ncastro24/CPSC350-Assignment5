//linked list header file used to keep track of advisees
#include <iostream>
#include "Listnode.h"
using namespace std;

template <class type>
class DatabaseLinkedlist{
public:
  DatabaseLinkedlist();
  ~DatabaseLinkedlist();

  void insertFront(type d);
  void insertBack(type d);
  type removeFront();
  type removeBack();
  Listnode<type> *remove(type d);
  int find(type d);
  type findPosition(int d);

  bool isEmpty();
  void printList();
  type getFront();
  type getBack();
  unsigned int getSize();
private:
  unsigned int size;
  Listnode<type> *front;
  Listnode<type> *back;
};

//default constructor
template <class type>
DatabaseLinkedlist<type>::DatabaseLinkedlist(){
  size = 0;
  front = NULL;
  back = NULL;
}

//destructor
template <class type>
DatabaseLinkedlist<type>::~DatabaseLinkedlist(){
  Listnode<type> *curr = front;
  Listnode<type> *next = curr;
  while(curr != NULL){
    next = curr->next;
    delete curr;
    curr = next;
  }
  curr = NULL;
}

//insert node to front of list
template <class type>
void DatabaseLinkedlist<type>::insertFront(type d){
  Listnode<type> *node = new Listnode<type>(d);
  if(size == 0){
    back = node;
  }
  else{
    front->prev = node;
    node->next = front;
  }
  front = node;
  size++;
}

//insert node to back of list
template <class type>
void DatabaseLinkedlist<type>::insertBack(type d){
  Listnode<type> *node = new Listnode<type>(d);
  if(size == 0){
    front = node;
  }else{
    back->next = node;
    node->prev = back;
  }
  back = node;
  size++;
}

//remove front of list
template <class type>
type DatabaseLinkedlist<type>::removeFront(){
  if(size==0){
    cout << "Error: List empty." << endl;
    exit(0);
  }
  Listnode<type> *ft = front;
  if(size == 1){ //if only one element
    back = NULL;
  }
  else{ //if more than one
    front->next->prev = NULL;
  }
  front = front->next;
  type temp = ft->data;
  ft->next = NULL;
  delete ft;
  size--;

  return temp;
}

//removes back of list
template <class type>
type DatabaseLinkedlist<type>::removeBack(){
  if(size==0){
    cout << "Error: List empty." << endl;
    exit(0);
  }
  Listnode<type> *bk = back;
  if(size == 1){ //if only one element
    front = NULL;
  }
  else{ //if more than one
    back->prev->next = NULL;
  }
  back = back->prev;
  type temp = bk->data;
  bk->prev = NULL;
  delete bk;
  size--;

  return temp;
}

//remove
template <class type>
Listnode<type> *DatabaseLinkedlist<type>::remove(type d){
  Listnode<type> *curr = front;
  while(curr->data != d){
    curr = curr->next;
    if(curr == NULL){ //if value not found
      return NULL;
    }
  }
  //if value found
  if(curr == front){
    front = curr->next;
  }
  else{
    curr->prev->next = curr->next;
  }
  if(curr == back){
    back = curr->prev;
  }
  else{
    curr->next->prev = curr->prev;
  }

  curr->next = NULL;
  curr->prev = NULL;
  size--;
  return curr;
}

//find
template <class type>
int DatabaseLinkedlist<type>::find(type d){
  int idex = 0;
  Listnode<type> *curr = front;
  while(curr != NULL){
    if(curr->data == d){
      break;
    }
    idex++;
    curr = curr->next;
  }
  if(curr == NULL){
    idex = -1;
  }
  return idex;
}

//find position
template <class type>
type DatabaseLinkedlist<type>::findPosition(int d){
  Listnode<type> *curr = front;
  int idex = 0;

  while(idex != d){
    curr = curr->next;
    idex++;
  }
  return curr->data;
}

//returns list size
template <class type>
unsigned int DatabaseLinkedlist<type>::getSize(){
  return size;
}

//print list
template <class type>
void DatabaseLinkedlist<type>::printList(){
  Listnode<type> *curr = front;
  while(curr !=NULL){
    cout << curr->data << endl;
    curr = curr->next;
  }
}

//return front
template <class type>
type DatabaseLinkedlist<type>::getFront(){
  if(size==0){
    cout << "Error: List empty." << endl;
    exit(0);
  }
  type temp = front->data;
  return temp;
}

//return back
template <class type>
type DatabaseLinkedlist<type>::getBack(){
  if(size==0){
    cout << "Error: List empty." << endl;
    exit(0);
  }
  type temp = back->data;
  return temp;
}
