//main class for database
#include "BST.h"
#include "DatabaseStack.h"
#include "Rollback.h"
#include <iostream>
#include <fstream>
using namespace std;

    //STUDENTS//

//creates student and insert into tree
Rollback* createStudent(BST<Student>& stree){
  int id;
  string name;
  string level;
  string major;
  double gpa;

  cout << "Enter student ID: " << endl;
  cin >> id;
  if(!stree.searchNode(id)){
    cout << "Enter student name: " << endl;
    cin >> name;
    cout << "Enter studnet's level: " << endl;
    cin >> level;
    cout << "Enter studnet's major: " << endl;
    cin >> major;
    cout << "Enter studnet's GPA: " << endl;
    cin >> gpa;

    Student temp(id, name, level, major, gpa, -1);
    stree.insertNode(temp, id);
    cout << "Student has been created. Student does not have an advisor. Select option 11 and enter student's ID to add advisor." << endl;
  }
  else{
    cout << "ID already in database." << endl;
  }
}

//delete student from tree based off id
Rollback* deleteStudent(BST<Faculty>& ftree, BST<Student>& stree){
  int id;
  cout << "Enter student ID: " << endl;
  cin >> id;

  if(stree.searchNode(id)){
    int temp = stree.returnData(id).getAdvisor();
    Rollback *r = new Rollback(stree.returnData(id));
    r->setsDelete();
    stree.deleteNode(id);
    if(temp != -1){
      Faculty ftemp = ftree.returnData(temp);
      ftemp.removeAdvisee(id);
      ftemp.deleteNode(temp);
      ftemp.insertNode(ftemp, temp);
    }
    cout << "Student has been removed." << endl;
    return r;

  }
  else{
    cout << "Student cannot be removed because there is no student with that ID." << endl;
  }
}

//prints student tree
void printStudents(BST<Student>& tree){
  tree.printTree();
}

//prints student when given id
void showStudent(BST<Student>& tree){
  int id;
  cout << "Enter student ID: " << endl;
  cin >> id;

  if(tree.searchNode(id)){
    Student temp = tree.returnData(id);
    cout << temp << endl;
  }
  else{
    cout << "No student with that ID was found." << endl;
  }
}

//print advisor of student based off student id
void findAdvisor(BST<Student>& stree, BST<Faculty>& ftree){
  int id;
  cout << "Enter student ID: " << endl;
  cin >> id;

  if(stree.searchNode(id)){
    if(stree.returnData(id).getAdvisor() == -1){
      cout << "Student has no advisor." << endl;
    }
    else{
      Faculty temp = ftree.returnData(stree.returnData(id).getAdvisor());
      temp.printFaculty();
    }
  }
  else{
    cout << "No student with that ID was found." << endl;
  }
}

//changes student's advisor based off ids and updates info
void changeAdvisor(BST<Faculty>& ftree, BST<Student>& stree){
  int sid; //student id
  int fid; //faculty id

  cout << "Student ID: " << endl;
  cin >> sid;
  if(!stree.searchNode(sid)){
    cout << "No student with that ID found." << endl;
    return;
  }
  cout << "Faculty ID: " << endl;
  cin >> fid;
  if(!ftree.searchNode(fid)){
    cout << "No faculty with that ID found." << endl;
    return;
  }
  else{
    int temp = stree.returnData(sid).getAdvisor();
    if(temp == -1){
      Faculty ftemp = ftree.returnData(fid);
      ftemp.addAdvisee(sid);
      ftree.deleteNode(fid);
      ftree.insertNode(ftemp, fid);

      Student stemp = stree.returnData(sid);
      stemp.setAdvisor(fid);
      stree.deleteNode(sid);
      stree.insertNode(stemp, sid);
      cout << "Advisor has been changed." << endl;
    }
    else{
      Faculty tempF = ftree.returnData(temp);
      tempF.removeAdvisee(sid);
      ftree.deleteNode(temp);
      ftree.insertNode(tempF, temp);

      Faculty tempF2 = ftree.returnData(fid);
      tempF2.addAdvisee(sid);
      ftree.deleteNode(fid);
      ftree.insertNode(tempF2, fid);
      Student tempS = stree.returnData(sid);
      tempS.setAdvisor(fid);
      stree.deleteNode(sid);
      stree.insertNode(tempS, sid);
      cout << "Advisor has been changed." << endl;
    }
  }
}

    //FACULTY//

//create faculty and insert into tree
Rollback* createFaculty(BST<Faculty>& ftree){
  int id;
  string name;
  string level;
  string dep;

  cout << "Enter faculty ID: " << endl;
  cin >> id;
  if(!ftree.searchNode(id)){
    cout << "Enter faculty name: " << endl;
    cin >> name;
    cout << "Enter faculty's level: " << endl;
    cin >> level;
    cout << "Enter faculty's department: " << endl;
    cin >> dep;

    Faculty temp(id, name, level, dep);
    ft.insertNode(temp, id);
    Rollback *r = new Rollback(id);
    r->setfInsert();
    cout << "Faculty has been created. Faculty does not have an advisee." << endl;
    return r;
  }
  else{
    cout << "ID already in database." << endl;
  }
}

//prints faculty when given id
void showFaculty(BST<Faculty>& tree){
  int id;
  cout << "Enter faculty ID: " << endl;
  cin >> id;

  if(tree.searchNode(id)){
    Faculty temp = tree.returnData(id);
    cout << temp << endl;
  }
  else{
    cout << "No faculty with that ID was found." << endl;
  }
}

//delete faculty from tree based off id
Rollback* deleteFaculty(BST<Faculty>& ftree, BST<Student>& stree){
  int id;
  cout << "Enter faculty ID: " << endl;
  cin >> id;

  if(ftree.searchNode(id)){
    Faculty temp = ftree.returnData(id);
    Rollback *r = new Rollback(ftree.returnData(id));
    r->setfDelete();
    ftree.deleteNode(id);
    for(int i = 0; i < temp.getnumAdvisees(); i++){
      int tempid = temp.getAdvisee(i);
      Student stemp = stree.returnData(tempid);
      stemp.setAdvisor(-1);
      stree.deleteNode(tempid);
      stree.insertNode(stemp, tempid);
    }
    cout << "Faculty has been removed. Advisees under this faculty no longer have an advisor." << endl;
    return r;

  }
  else{
    cout << "Faculty cannot be removed because there is no faculty with that ID." << endl;
  }
}

//prints advisees of faculty based off faculty id
void findAdvisees(BST<Faculty>& ftree, BST<Student>& stree){
  int id;
  cout << "Enter the faculty ID: " << endl;
  cin >> id;

  if(ftree.searchNode(id)){
    if(ftree.returnData(id).getnumAdvisees() == 0){
      cout << "Faculty has no advisees" << endl;
    }
    else{
      for(int i = 0; i < ftree.returnData(id).getnumAdvisees(); i++){
        Student temp = stree.returnData(ftree.returnData(id).getAdvisee(i));
        cout << temp << endl;
      }
    }
  }
  else{
    cout << "No faculty with that ID was found." << endl;
  }
}

//prints faculty tree
void printFaculties(BST<Faculty>& tree){
  tree.printTree();
}

//removes advisee from faculty and updates info
void deleteAdvisee(BST<Faculty>& ftree, BST<Student>& stree){
  int sid;
  int fid;

  cout << "Faculty ID: ";
  cin >> fid;
  if(!ftree.searchNode(fid)){
    cout << "No faculty with that ID found." << endl;
    return;
  }
  cout << "Student ID: " << endl;
  cin >> sid;
  if(!stree.searchNode(sid)){
    cout << "No student with that ID found." << endl;
    return;
  }
  else if(stree.returnData(sid).getAdvisor() != fid){
    cout << "Student is not an advisee for this faculty." << endl;
    return;
  }
  else{
    Student stemp = stree.returnData(sid);
    stemp.setAdvisor(-1);
    stree.deleteNode(sid);
    stree.insertNode(stemp, sid);
    Faculty ftemp = ftree.returnData(fid);
    ftemp.removeAdvisee(sid);
    ftree.deleteNode(fid);
    ftree.insertNode(ftemp, fid);
    cout << "Removed advisee." << endl;
  }
}

//undos last operation if operation changed tree struct
void rollingback(BST<Faculty>& ftree, BST<Student>& stree, DatabaseStack<Rollback*>& stack){
  if(!stack.isEmpty()){
    Rollback *temp = stack.pop();
    if(temp->getfInsert()){
      ftree.deleteNode(temp->getID());
      cout << "Rollback done." << endl;
    }
    else if(temp->getsInsert()){
      stree.deleteNode(temp->getID());
      cout << "Rollback done." << endl;
    }
    else if(temp->getfDelete()){
      ftree.insertNode(temp->getFaculty(), temp->getFaculty().getID());
      cout << "Rollback done." << endl;
    }
    else if(temp->getsDelete()){
      stree.insertNode(temp->getStudent(), temp->getStudent().getID());
      cout << "Rollback done." << endl;
    }
  }
  else{
    cout << "Error" << endl;
  }
}

    /////

//reads files
void readfile(BST<Faculty>& ftree, BST<Student>& stree, ifstream& studentIn, ifstream& facultyIn){
  string line = "";
  while(getline(studentIn,line)){
    string tempid = line.substr(4);
    int id = stoi(tempid);
    getline(studentIn,line);
    string name = line.substr(6);
    getline(studentIn,line);
    string level = line.substr(7);
    getline(studentIn,line);
    string major = line.substr(7);
    getline(studentIn,line);
    string tempgpa = line.substr(5);
    double gpa = stod(tempgpa);
    getline(studentIn,line);
    string tempAdvisorid = line.substr(12);
    int adid = stoi(tempAdvisorid);

    Student stemp(id, name, level, major, gpa, adid);
    stree.insertNode(stemp, id);
    getline(studentIn,line);
  }
  while(getline(facultyIn,line)){
    string tempid = line.substr(4);
    int id = stoi(tempid);
    getline(facultyIn,line);
    string name = line.substr(6);
    getline(facultyIn,line);
    string level = line.substr(7);
    getline(facultyIn,line);
    string dep = line.substr(12);
    getline(facultyIn,line);
    string tempAdvisees = line.substr(20);
    int numadvisees = stoi(tempAdvisees);

    Faculty ftemp(id, name, level, dep);
    getline(facultyIn,line);
    for(int i = 0; i < numadvisees; i++){
      getline(facultyIn,line);
      int atemp = stoi(line);
      ftemp.addAdvisee(atemp);
    }

    ftree.insertNode(ftemp, id);
    getline(facultyIn,line);
  }
}


//MAIN
int main(int argc, char *argv[]){
  BST<Student> masterStudent;
  BST<Faculty> masterFaculty;
  DatabaseStack<Rollback*> undostack;
  ifstream sinput("studentTable.txt");
  ifstream finput("facultyTable.txt");

  if(sinput.is_open() && finput.is_open()){
    readfile(masterFaculty, masterStudent, studentInput, facultyInput);
  }
  int userinput = 0;

  while(userinput != 14){
    cout << "Choose action by entering number: " << endl;
    cout << "1. Print all students and their information (sorted by ascending id #)" << endl;
    cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
    cout << "3. Find and display student information given the students id" << endl;
    cout << "4. Find and display faculty information given the faculty id" << endl;
    cout << "5. Given a student’s id, print the name and info of their faculty advisor" << endl;
    cout << "6. Given a faculty id, print ALL the names and info of his/her advisees" << endl;
    cout << "7. Add a new student" << endl;
    cout << "8. Delete a student given the id" << endl;
    cout << "9. Add a new faculty member" << endl;
    cout << "10. Delete a faculty member given the id" << endl;
    cout << "11. Change a student’s advisor given the student id and the new faculty id" << endl;
    cout << "12. Remove an advisee from a faculty member given the ids" << endl;
    cout << "13. Rollback" << endl;
    cout << "14. Exit" << endl;
    cout << endl;
    cin >> userinput;

    switch(userinput){
      case 1:
        printStudents(masterStudent);
        cout << endl;
        break;
      case 2:
        printFaculties(masterFaculty);
        cout << endl;
        break;
      case 3:
        showStudent(masterStudent);
        cout << endl
        break;
      case 4:
        showFaculty(masterFaculty);
        cout << endl
        break;
      case 5:
        findAdvisor(masterFaculty, masterStudent);
        cout << endl;
        break;
      case 6:
        findAdvisees(masterFaculty, masterStudent);
        cout << endl;
        break;
      case 7:
        undostack.push(createStudent(masterStudent));
        cout << endl;
        break;
      case 8:
        undostack.push(deleteStudent(masterFaculty, masterStudent));
        cout << end;
        break;
      case 9:
        undostack.push(createFaculty(masterFaculty));
        cout << endl;
        break;
      case 10:
        undostack.push(deleteFaculty(masterFaculty, masterStudent));
        cout << endl;
        break;
      case 11:
        changeAdvisor(masterFaculty, masterStudent);
        cout << endl;
        break;
      case 12:
        deleteAdvisee(masterFaculty, masterStudent);
        cout << endl;
        break;
      case 13:
        rollingback(masterFaculty, masterStudent, undostack);
        break;
      case 14:
        ofstream studentOutput("studentTable.txt");
        ofstream facultyOutput("facultyTable.txt");
        masterStudent.preorderFile(studentOutput);
        masterFaculty.preorderFile(facultyOutput);
      default:
        cout << "Invalid option." << endl;
    }

  return 0;
}
