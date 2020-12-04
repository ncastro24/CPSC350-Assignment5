//student header file
#include <iostream>
using namespace std;

class Student{
public:
  int id;
  string name;
  string level;
  string major;
  double gpa;
  int advisor;

  Student();
  Student(int i, string n, string l, string m, double g, int a);
  ~Student();

  void setID(int i);
  int getID();

  void setName(string n);
  string getName();

  void setLevel(string l);
  string getLevel();

  void setMajor(string m);
  string getMajor();

  void setGPA(double g);
  double getGPA();

  void setAdvisor(int a);
  int getAdvisor();

  void printStudent();

  //compare two student ids
  bool operator == (Student i){
    if(this->id == i.getID()){
      return true;
    }
    else{
      return false;
    }
  }
  bool operator < (Student i){
    if(this->id < i.getID()){
      return true;
    }
    else{
      return false;
    }
  }
  bool operator > (Student i){
    if(this->id > i.getID()){
      return true;
    }
    else{
      return false;
    }
  }
};

//default constructor
Student::Student(){
  id = 0;
  name = "";
  level = "";
  major = "";
  gpa = 0.0;
  advisor = 0;
}

//overloaded constructor
Student::Student(int i, string n, string l, string m, double g, int a){
  id = i;
  name = n;
  level = l;
  major = m;
  gpa = g;
  advisor = a;
}

//destructor
Student::~Student(){
}

//setters
void Student::setID(int i){
  id = i;
}
void Student::setName(string n){
  name = n;
}
void Student::setLevel(string l){
  level = l;
}
void Student::setMajor(string m){
  major = m;
}
void Student::setGPA(double g){
  gpa = a;
}
void Student::setAdvisor(int a){
  advisor = a;
}

//getters
int Student::getID(){
  return id;
}
string Student::getName(){
  return name;
}
string Student::getLevel(){
  return level;
}
string Student::getMajor(){
  return major;
}
double Student::getGPA(){
  return gpa;
}
int Student::getAdvisor(){
  return advisor;
}

//print student info
void Student::printStudent(){
  cout << "Student ID: " << id << endl;
  cout << "Student name: " << name << endl;
  cout << "Student level: " << level << endl;
  cout << "Studnet major: " << major << endl;
  cout << "Studnet GPA: " << gpa << endl;
  cout << "Adivsor ID: " << advisor << endl;
}
