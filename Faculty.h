//faculty header file
#include "DatabaseLinkedlist.h"
#include <iostream>
using namespace std;

class Faculty{
public:
  int id;
  string name;
  string level;
  string dep;
  DatabaseLinkedlist<int> *list;

  Faculty();
  Faculty(int i, string n, string l, string d);
  ~Faculty();

  void setID(int i);
  int getID();

  void setName(string n);
  string getName();

  void setLevel(string l);
  string getLevel();

  void setDepartment(string d);
  string getDepartment();

  void printAdvisees();
  int getnumAdvisees();

  void addAdvisee(int a);
  void removeAdvisee(int a);
  int getAdvisee(int a);

  void printFaculty();

  //compare faculty ids
  bool operator == (Faculty i){
    if(id == i.getID()){
      return true;
    }
    else{
      return false;
    }
  }
  bool operator < (Faculty i){
    if(id < i.getID()){
      return true;
    }
    else{
      return false;
    }
  }

  bool operator > (Faculty i){
    if(id > i.getID()){
      return true;
    }
    else{
      return false;
    }
  }
};

//default constructor
Faculty::Faculty(){
  id = 0;
  name = "";
  level = "";
  dep = "";
  list = new DatabaseLinkedlist<int>;
}

//overloaded constructor
Faculty::Faculty(int i, string n, string l, string d){
  id = i;
  name = n;
  level = l;
  dep = d;
  list = new DatabaseLinkedlist<int>;
}

//destructor
Faculty::~Faculty(){
}

//setters
void Faculty::setID(int i){
  id = i;
}
void Faculty::setName(string n){
  name = n;
}
void Faculty::setLevel(string l){
  level = l;
}
void Faculty::setDepartment(string d){
  dep = d;
}

//getters
int Faculty::getID(){
  return id;
}
string Faculty::getName(){
  return name;
}
string Faculty::getLevel(){
  return level;
}
string Faculty::getDepartment(){
  return dep;
}

//advisees
void Faculty::addAdvisee(int a){
  list->insertBack(a);
}
void Faculty::removeAdvisee(int a){
  list->remove(a);
}
void Faculty::printAdvisees(){
  list->printList();
}
int Faculty::getAdvisee(int a){
  list->findPosition(a);
}
int Faculty::getnumAdvisees(){
  return list->getSize();
}

//print faculty info
void Faculty::printFaculty(){
  cout << "Faculty ID: " << id << endl;
  cout << "Faculty name: " << name << endl;
  cout << "Faculty level: " << level << endl;
  cout << "Faculty department: " << dep << endl;
  cout << "Advisees: " << endl;
  list->printList();
}
