//the main program goes here

#include "dllist.hpp"

int main(int argc, char const *argv[]) {
  DLList* list = new DLList;

list->loadFile("test.txt");

    return 0;
}






//
// void doCommand(string cmd, DLList* list) {
//   switch(cmd[0]) {
//     case 'A':
//       cout << "VALUE " << list->headContents() << " AT HEAD" << endl;
//     break;
//     case 'B':
//       cout << "VALUE x ADDED TO TAIL" << endl;
//     break;
//     case 'C'://i think that i have to create object.
//       cout << "LIST CREATED" << endl;
//     break;
//     case 'D':
//       cout << "LIST DELETED" << endl;
//     break;
//     case 'F':
//       cout << "VALUE ADDED TO FRONT" << endl;
//     break;
//     case 'N':
//       cout << "LIST SIZE IS " << list->get_Size() << endl;
//     break;
//     case 'T':
//       cout << "REMOVED HEAD" << endl;
//     break;
//     case 'K':
//       cout << "REMOVED TAIL" << endl;
//     break;
//     case 'Z':
//       cout << "VALUE " << list->tailContents() << " AT TAIL" << endl;
//     break;
//
//   }
// }
