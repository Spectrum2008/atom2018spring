//Your program will read in and process, from a text file,
// a series of commands for a template doubly linked list.
// Each line of the input file will contain a single command,
// in the following format: OPERATION [DATA].
// The operations will be performed on a single instance of a
// doubly-linked list of uint32_t integers.

#include "dllist.hpp"

/*
this function has to process a letter that will be used for a command that will
work calling functions, this functions will need a number to be proccessed by
those functions
@param this is the letter that has been cutOFF by loadFile to be used as a command.
@param this
a number that will be used as the command
*/
  string doCommand(string cmd, uint32_t number, DLList<uint32_t> *& list) {//must create list before doing the rest.

if (list == nullptr && cmd != "C") {
  return("MUST CREATE LIST INSTANCE\n");
}
    switch(cmd[0]) {
      case 'A':
        cout << "VALUE " << list->headContents() << " AT HEAD" << endl;//done.
        break;
      case 'B':
        cout << "VALUE " << number << " ADDED TO TAIL" << endl; list->pushBack(number);//done.
        break;
      case 'C'://i think that i have to create object.
      if(list != nullptr){
        delete list;
      }
      list = new DLList<uint32_t>;
        cout << "LIST CREATED" << endl;
        break;
      case 'D':
      if(list == nullptr){
        cout << "MUST CREATE LIST INSTANCE\n";
      } else {
        delete list;
        list = nullptr;
        cout << "LIST DELETED" << endl;
      }
        break;
      case 'E':
          if(list->removeAll(number)){
            cout << "VALUE " << number << " ELIMINATED" << endl;
          } else {
            cout << "VALUE " << number << " NOT FOUND" << endl;
          }
        break;
      case 'F':
        cout << "VALUE " << number <<" ADDED TO FRONT" << endl; list->pushFront(number);//done.
        break;
      case 'G':
        if (list->getElment(number)) {
          cout << "VALUE " << number << " FOUND" << endl;
        } else {
          cout << "VALUE " << number << " NOT FOUND" << endl;
        }
        break;
      case 'I':
        cout << "VALUE " << number << " INSERTED" << endl; list->insert(number);
      case 'N':
        cout << "LIST SIZE IS " << list->get_Size() << endl;//done.
        break;
      case 'P':
        cout << list->toString() << endl;//tail added nodes do not show.
        break;
      case 'R':
          if(list->removeOne(number)){
            cout << "Value " << number << " REMOVED" << endl;
          } else {
            cout << "VALUE " << number << " FOUND" << endl;
          }
        break;
      case 'T':
        cout << "REMOVED HEAD" << endl; list->removeHead();
        break;
      case 'K':
        cout << "REMOVED TAIL" << endl; list->removeTail();
        break;
      case 'X':
          list->clear();
        break;
      case 'Z':
        cout << "VALUE " << list->tailContents() << " AT TAIL" << endl;//loks done.
        break;
    }
    return("");
  }
    /*
    Load the contents of a file into the list.
    Assumes that the file has one key value pair
    per line separated by 'space', with no extra spaces.

    Note: ignores empty lines and comment lines (lines that
  beguin '#')

  @param filename the name of the file to Load
  @return true if the file is sucessfully processed, else false
    */
    bool loadFile(string filename, DLList<uint32_t> *list){
      string arr;
      string first;
      string second;

      ifstream file(filename.c_str());//filename becomes file.

      if(file.is_open()){
        while(getline(file, arr)){//grabs file- store in arr.
          if(!arr.empty() && arr[0] != '#'){
            stringstream myStream(arr);//arr becomes file-like.
            getline(myStream, first, ' ');//grabs from arr and stores in first.
            getline(myStream, second);//second pieze remains to store is second.
            stringstream myToInt(second);
            uint32_t number = 0;
            myToInt >> number;
            cout << doCommand(first, number, list);/////here now////!!!
            //addOption(first, second);
          }
        }
        file.close();
        return true;
      }
      return false;
    }

int main(int argc, char const *argv[]) {

  //DLList<int>* list = new DLList<int>;
   DLList<uint32_t>* list = nullptr;
   if(argc == 2 && loadFile(argv[1], list)){

   } else if (argc == 2) {
      cout << "Wrong Filename" << endl;
   }
   else {
     cout << "Ussage: program.exe test.txt" << endl;
}

    return 0;
}


//rigth filename error.
//no file error.




//
// void doCommand(string cmd, DLList* list) {
//   switch(cmd[0]) {













// //it seems that i am going to need teacher's help
// //on the T number because it seems that, it suposes to acept other kinds of data.
// // T mumber.
//   void doCommand(string cmd, T number) {//must create list before doing the rest.
//     switch(cmd[0]) {
//       case 'A':
//         cout << "VALUE " << headContents() << " AT HEAD" << endl;//done.
//         break;
//       case 'B':
//         cout << "VALUE " << number << " ADDED TO TAIL" << endl; pushBack(number);//done.
//         break;
//       case 'C'://i think that i have to create object.
//         cout << "LIST CREATED" << endl;
//         break;
//       case 'D':
//         cout << "LIST DELETED" << endl; //deleteList();
//         break;
//       case 'E':
//           if(removeAll(number)){
//             cout << "VALUE " << number << " ELIMINATED" << endl;
//           } else {
//             cout << "VALUE " << number << " NOT FOUND" << endl;
//           }
//         break;
//       case 'F':
//         cout << "VALUE " << number <<" ADDED TO FRONT" << endl; pushFront(number);//done.
//         break;
//       case 'G':
//         if (getElment(number)) {
//           cout << "VALUE " << number << " FOUND" << endl;
//         } else {
//           cout << "VALUE " << number << " NOT FOUND" << endl;
//         }
//         break;
//       case 'I':
//         cout << "VALUE " << number << " INSERTED" << endl; insert(number);
//       case 'N':
//         cout << "LIST SIZE IS " << get_Size() << endl;//done.
//         break;
//       case 'P':
//         cout << toString() << endl;//tail added nodes do not show.
//         break;
//       case 'R':
//           if(removeOne(number)){
//             cout << "Value " << number << " REMOVED" << endl;
//           } else {
//             cout << "VALUE " << number << " FOUND" << endl;
//           }
//         break;
//       case 'T':
//         cout << "REMOVED HEAD" << endl; removeHead();
//         break;
//       case 'K':
//         cout << "REMOVED TAIL" << endl; removeTail();
//         break;
//       case 'Z':
//         cout << "VALUE " << tailContents() << " AT TAIL" << endl;//loks done.
//         break;
//     }
//   }
//
//
//     /*
//     Load the contents of a file into the list.
//     Assumes that the file has one key value pair
//     per line separated by 'space', with no extra spaces.
//
//     Note: ignores empty lines and comment lines (lines that
//   beguin '#')
//
//   @param filename the name of the file to Load
//   @return true if the file is sucessfully processed, else false
//     */
//     bool loadFile(string filename){
//       string arr;
//       string first;
//       string second;
//
//       ifstream file(filename.c_str());//filename becomes file.
//
//       if(file.is_open()){
//         while(getline(file, arr)){//grabs file- store in arr.
//           if(!arr.empty() && arr[0] != '#'){
//             stringstream myStream(arr);//arr becomes file-like.
//             getline(myStream, first, ' ');//grabs from arr and stores in first.
//             getline(myStream, second);//second pieze remains to store is second.
//             stringstream myToInt(second);
//             int number = 0;
//             myToInt >> number;
//             doCommand(first, number);
//             //addOption(first, second);
//           }
//         }
//         file.close();
//         return true;
//       }
//       return false;
//     }
