//rollback header file for undoing
#include "Student.h"
#include "Faculty.h"

class Rollback{
public:
  bool fInsert;
  bool fDelete;
  bool sInsert;
  bool sDelete;
  int id;
  Student s;
  Faculty f;

  Rollback();
  Rollback(int d);
  Rollback(Faculty d);
  Rollback(Student d);
  ~Undo();

  void setfInsert();
  bool getfInsert();

  void setfDelete();
  bool getfDelete();

  void setsInsert();
  bool getsInsert();

  void setsDelete();
  bool getsDelete();

  int getID();
  Student getStudent();
  Faculty getFaculty();
};

//default constructor
Rollback::Rollback(){
  fInsert = false;
  fDelete = false;
  sDelete = false;
  sInsert = false;
}

//overloaded constructors
Rollback::Rollback(int d){
  fInsert = false;
  fDelete = false;
  sDelete = false;
  sInsert = false;
  id = d;
}

Rollback::Rollback(Faculty d){
  fInsert = false;
  fDelete = false;
  sDelete = false;
  sInsert = false;
  id = -1;
  f = d;
}

Rollback::Rollback(Student d){
  fInsert = false;
  fDelete = false;
  sDelete = false;
  sInsert = false;
  id = -1;
  s = d;
}

//destructor
Rollback::~Rollback(){
}

//setters
void Rollback::setfInsert(){
  fInsert = true;
}
void Rollback::setfDelete(){
  fDelete = true;
}
void Rollback::setsInsert(){
  sInsert = true;
}
void Rollback::setsDelete(){
  sDelete = true;
}

//getters
bool Rollback::getfInsert(){
  return fInsert;
}
bool Rollback::getfDelete(){
  return fDelete;
}
bool Rollback::getsInsert(){
  return sInsert;
}
bool Rollback::getsDelete(){
  return sDelete;
}


int Rollback::getID(){
  return id;
}

Student Rollback::getStudent(){
  return s;
}

Faculty Rollback::getFaculty(){
  return f;
}
