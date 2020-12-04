//listnode header file for databaselinkedlist
#include <iostream>

template <class type>
class Listnode{
public:
  type data;
  Listnode *next;
  Listnode *prev;

  Listnode();
  Listnode(type d);
  ~Listnode();
};

//default constructor
template <class type>
Listnode<type>::Listnode(){
}

//overloaded constructor
template <class type>
Listnode<type>::Listnode(type d){
  data = d;
  next = NULL;
  prev = NULL;
}

//destructor
template <class type>
Listnode<type>::~Listnode(){
  next = NULL;
  prev = NULL;
}
