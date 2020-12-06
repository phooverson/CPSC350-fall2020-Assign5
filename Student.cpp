#include "Assign5.h"

Student::Student(){ //default constructor
  id = -1;
  level = "null";
  major = "null";
  gpa = -1;
  advisorId = -1;
}

Student::Student(int id, string level, string major, double gpa, int advisorId){ //overloaded constructor
  this->id = id;
  this->level = level;
  this->major = major;
  this->gpa = gpa;
  this->advisorId = advisorId;
}

Student::~Student(){ //destructor
  //cout << "Bye-bye student" << endl;
}

// Getters
int Student::GetId(){ //getter for student id
  return id;
}

int Student::GetAdvisorId(){ //getter for advisor id
  return advisorId;
}

void Student::SetAdvisorId(int newAdvisorId){ //setter for advisor ID
  advisorId = newAdvisorId;
}

void Student::PrintStats(){ //print stats of student to screen
  cout << "\nStudent ID: " << id << endl;
  cout << "Level: " << level << endl;
  cout << "Major: " << major << endl;
  cout << "GPA: " << gpa << endl;
  cout << "Advisor Id: " << advisorId << endl;
}

void Student::PrintStatsToFile(ofstream& outfile){ //print stats of student to a file
  outfile << id << endl;
  outfile << level << endl;
  outfile << major << endl;
  outfile << gpa << endl;
  outfile << advisorId << endl;
  outfile << endl;
}
