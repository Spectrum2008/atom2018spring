#include "List.cpp"


  void doCommand(string cmd, DLList * list) {//must create list before doing the rest.
    switch(cmd[0]) {
      case 'A':
        cout << "VALUE " << headContents() << " AT HEAD" << endl;//done.
        break;
      case 'B':
        cout << "VALUE " << number << " ADDED TO TAIL" << endl; pushBack(number);//done.
        break;
      case 'C'://i think that i have to create object.
        cout << "LIST CREATED" << endl;
        break;
      case 'D':
        cout << "LIST DELETED" << endl; deleteList();
        break;
        case 'E':
        //cout << eliminateElement() << endl;
        break;
      case 'F':
        cout << "VALUE " << number <<" ADDED TO FRONT" << endl; pushFront(number);//done.
        break;
      case 'G':
      //  cout << hasElementStr(number) << endl;
        break;
      case 'N':
        cout << "LIST SIZE IS " << get_Size() << endl;//done.
        break;
      case 'P':
        cout << toString() << endl;//tail added nodes do not show.
        break;
        case 'R':
        cout << removeOne(number) << endl;//
        break;
      case 'T':
        cout << "REMOVED HEAD" << endl; removeHead();
        break;
      case 'K':
        cout << "REMOVED TAIL" << endl; removeTail();
        break;
      case 'Z':
        cout << "VALUE " << tailContents() << " AT TAIL" << endl;//loks done.
        break;
    }
  }

int int main(int argc, char const *argv[]) {
  DLList<int>* list = new DLList<int>;
doCommand('N', List)
  list->loadFile("test.txt");

  return 0;
}//aNewType
