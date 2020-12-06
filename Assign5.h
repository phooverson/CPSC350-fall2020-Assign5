//Files
#include "BST.h"
#include "GenStack.h"
#include "DoublyLinkedListT.h"

//Libraries
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Person {
public:
  Person();
  Person(int id, string level);
  ~Person();

protected:
  int id;
  string level;
};

//Inherits from class person.
class Student : public Person {
public:
  Student();
  Student(int id, string level, string major, double gpa, int advisor);
  ~Student();

  //methods
  void PrintStats();
  void PrintStatsToFile(ofstream& outfile);
  int GetId();
  int GetAdvisorId();
  void SetAdvisorId(int advisorId);
private:
  string major;
  double gpa;
  int advisorId;
};

//Inherits from class person
class Faculty : public Person {
public:
  Faculty();
  Faculty(int id, string level, string department);
  ~Faculty();

  //methods
  void PrintFacultyMemberAdvisees();
  void PrintStats();
  void PrintStatsToFile(ofstream& outfile);
  void RemoveAdvisee(int studentId);
  void AddAdvisees();
  void AddAdviseesById(int newAdvisorId);
  int RemoveFrontAdvisee();
  bool CheckIfThereAreAdvisees();
  int GetId();

private:
  string department;
  DoublyLinkedListT<int> *adviseesIds = new DoublyLinkedListT<int>; //DoublyLinkedListT of all advisees
};

class ManageDataBase {
public:
  ManageDataBase();
  ~ManageDataBase();

  //main method
  void PromptUser();

private:
  //main methods
  void AddToStack();
  void updateBSTsFromFile();
  void updateFacultyBST();
  void updateStudentBST();
  void Rollback();
  void insertStudentRollback(Student*& student);
  void insertFacultyRollback(Faculty*& faculty);
  void insertOperationType(int num);

  //Students methods
  void CreateStudent();
  void DeleteStudent();
  void PrintStudent();
  void ChangeAdvisor();
  bool CheckToSeeIfStudentExists(int studentId);
  void PrintAdvisor();

  //Faculty methods
  void CreateFacultyMember();
  void DeleteFaculty();
  void PrintFacultyMember(bool onlyAdvisees);
  void RemoveAdvisee();
  Faculty GetAdvisorWithLeastAmountOfAdvisees();
  void sortInAccendingOrder();
  void sortInDecendingOrder();

  BST<Student*> *studentTree = new BST<Student*>;
  BST<Faculty*> *facultyTree = new BST<Faculty*>;
  GenStack<Student*> *studentRollback = new GenStack<Student*>;
  GenStack<Faculty*> *facultyRollback = new GenStack<Faculty*>;
  GenStack<int> *lastOperation = new GenStack<int>;
};
