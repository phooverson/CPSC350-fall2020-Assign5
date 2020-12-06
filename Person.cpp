#include "Assign5.h"

Person::Person(){ //default constructor
  id = -1;
  level = "null";
}

Person::Person(int id, string level){ //overloaded constructor
  this->id = id;
  this->level = level;
}

Person::~Person(){ //destructor
  //cout << "Bye-bye person" << endl;
}
