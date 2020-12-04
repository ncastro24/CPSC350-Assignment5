//stack header file that will be used to keep track of advisees
#include <iostream>
using namespace std;

template <class type>
class DatabaseStack{
public:
  DatabaseStack();
  DatabaseStack(int msize);
  ~DatabaseStack();

  int size;
  int top;
  type *array;

  void push(type d);
  void resize();
  type pop();
  type peek();

  bool isFull();
  bool isEmpty();
};

//default constructor
template <class type>
DatabaseStack<type>::DatabaseStack(){
  size = 128;
  top = -1;
  array = new type[128];
}

//overloaded constructor
template <class type>
DatabaseStack<type>::DatabaseStack(int msize){
  size = msize;
  top = -1;
  array = new type[msize];
}

//destructor
template <class type>
DatabaseStack<type>::~DatabaseStack(){
  delete []array;
}

//push into stack
template <class type>
void DatabaseStack<type>::push(type d){
  if(isFull()){
    resize();
  }
  array[++top] = d;
}

//resize stack if full
template <class type>
void DatabaseStack<type>::resize(){
  type temp[size];
  for(int i = 0; i < size; i++){
    temp[i] = array[i];
  }
  delete []array;
  array = new type[size*2];
  for(int i = 0; i < size; i++){
    array[i] = temp[i];
  }
  size = size*2;
}

//pop function
template <class type>
type DatabaseStack<type>::pop(){
  try{
    if (top == -1){
      throw top;
    }
    return array[top--];
  }
  catch (int e){
    cout << "Error: Stack is empty." << endl;
  }
}

//peek function
template <class type>
type DatabaseStack<type>::peek(){
  try{
    if (top == -1){
      throw top;
    }
    return array[top];
  }
  catch (int e){
    cout << "Error: Stack is empty." << endl;
  }
}

//check if full
template <class type>
bool DatabaseStack<type>::isFull(){
  return (top == size-1);
}

//check if empty
template <class type>
bool DatabaseStack<type>::isEmpty(){
  return (top == -1);
}
