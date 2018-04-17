//the main program goes here

#include "dllist.hpp"

int main(int argc, char const *argv[]) {

  DLList<int>* list = new DLList<int>;

list->loadFile("test.txt");

    return 0;
}






//
// void doCommand(string cmd, DLList* list) {
//   switch(cmd[0]) {
