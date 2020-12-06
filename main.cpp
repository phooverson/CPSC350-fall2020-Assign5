#include "Assign5.h"
using namespace std;

int main(int argc, char** argv){
  ManageDataBase *manageDataBase = new ManageDataBase();
  manageDataBase->PromptUser();
  delete manageDataBase;
}
