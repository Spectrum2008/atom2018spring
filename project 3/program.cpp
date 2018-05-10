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
  string doCommand(string cmd, uint32_t number, DLList<uint32_t> *& list) {

if (list == nullptr && cmd[0] != 'C') {
  return("MUST CREATE LIST INSTANCE\n");
}
    switch(cmd[0]) {
      case 'A':
	      try{
            cout << "VALUE " << list->headContents() << " AT HEAD" << endl;//done.
	           } catch (logic_error e)
	            {
	               cout << e.what() << endl;
	              }
	     break;
      case 'B':
        cout << "VALUE " << number << " ADDED TO TAIL" << endl; list->pushBack(number);//done.
        break;
      case 'C':
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
        if (list->getElement(number)) {
          cout << "VALUE " << number << " FOUND" << endl;
        } else {
          cout << "VALUE " << number << " NOT FOUND" << endl;
        }
        break;
      case 'I':
        cout << "VALUE " << number << " INSERTED" << endl; list->insert(number);
        break;
      case 'N':
        cout << "LIST SIZE IS " << list->get_Size() << endl;
        break;
      case 'P':
        cout << list->toString() << endl;
        break;
      case 'R':
        if(list->removeOne(number)){
          cout << "VALUE " << number << " REMOVED" << endl;
        } else {
          cout << "VALUE " << number << " NOT FOUND" << endl;
        }
        break;
      case 'T':
        try{
             if(list->removeHead()){
               cout << "REMOVED HEAD" << endl;
             }else{
               cout << "LIST EMPTY" << endl;
             }
		      } catch (logic_error e)
	         {
	            cout << e.what() << endl;
	           }
             break;
      case 'K':
	      try{
             if(list->removeTail()){
               cout << "REMOVED TAIL" << endl;
             }else{
               cout << "LIST EMPTY" << endl;
             }
	          } catch (logic_error e)
	           {
	              cout << e.what() << endl;
	             }
               break;
      case 'X':
        cout << "LIST CLEARED" << endl; list->clear();
        break;
      case 'Z':
	      try{
            cout << "VALUE " << list->tailContents() << " AT TAIL" << endl;
	          } catch (logic_error e)
	           {
	   	          cout << e.what() << endl;
	             }
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
    bool loadFile(string filename, DLList<uint32_t> *& list){
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
            cout << doCommand(first, number, list);
          }
        }
        file.close();
        return true;
      }
      return false;
    }

int main(int argc, char const *argv[]) {

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
