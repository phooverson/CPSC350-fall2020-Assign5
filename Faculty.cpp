#include "Assign5.h"

Faculty::Faculty(){ //default constructor
  id = -1;
  level = -1;
  department = "null";
}

Faculty::Faculty(int id, string level, string department){ //overloaded constructor
  this->id = id;
  this->level = level;
  this->department = department;
}

Faculty::~Faculty(){ //destructor
  //cout << "Bye-bye facutly" << endl;
}

int Faculty::GetId(){//getter for id
  return id;
}

void Faculty::PrintStats(){ //print all stats
  cout << "\nFaculty Id: " << id << endl;
  cout << "Level: " << level << endl;
  cout << "Department: " << department << endl;
  PrintFacultyMemberAdvisees();
}

void Faculty::PrintFacultyMemberAdvisees(){ //print all advisee id's of faculty member
  cout << "Advisees Ids: " << endl;
  adviseesIds->printList();
}

void Faculty::AddAdvisees(){ //add advisee
  int input;
  string checkAdd;
  while (input != -1) {
    cout << "Enter Student Id's of Advisees (-1 to stop): ";
    cin >> input;

    if (input != -1) {
      adviseesIds->insertFront(input);
    }
  }
}

void Faculty::AddAdviseesById(int id){ //add advisee id
  adviseesIds->insertFront(id);
}

void Faculty::RemoveAdvisee(int studentId){ //remove an advisee
  int pos = adviseesIds->find(studentId);
  int deletedStudentId = adviseesIds->deletePos(pos);
}

void Faculty::PrintStatsToFile(ofstream& outfile){ //print faculty member stats to file
  outfile << id << endl;
  outfile << level << endl;
  outfile << department << endl;
  outfile << "Advisees:" << endl;
  adviseesIds->printListToFile(outfile);
  outfile << "----------" << endl;
}

int Faculty::RemoveFrontAdvisee(){ //remove the front advisee
  return adviseesIds->removeFront();
}

bool Faculty::CheckIfThereAreAdvisees(){ //return a bool bases of if there are advisee's or not
  if (adviseesIds->isEmpty())
    return false;
  return true;
}
