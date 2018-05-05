#include "bst.hpp"

string doCommand(string cmd, string number, BST<string> *& tree)
{
  switch(cmd[0]) {

    case 'C':
      if(tree != nullptr){
        delete tree;
      }
      tree = new BST<string>;
      cout << "LIST CREATED" << endl;
      break;
    case 'D':
      if(tree == nullptr){
        cout << "MUST CREATE TREE INSTANCE\n";
      } else {
        delete tree;
        tree = nullptr;
        cout << "TREE DELETED" << endl;
      }
      break;
    case 'I':
      cout << "VALUE " << number << " INSERTED" << endl; tree->insert(number);
      break;
    //case 'N':
      //cout << "LIST SIZE IS " << tree->get_Size() << endl;
      //break;
     //case 'R':
      //if(tree->removeOne(number)){
        //cout << "Value " << number << " REMOVED" << endl;
      //} else {
        //cout << "VALUE " << number << " FOUND" << endl;
      //}
      //break;
    //case 'X':
      //cout << "TREE CLEARED" << endl; tree->clear();
      //break;
  case 'O':
      tree->PrintInOrder();
      break;
    }
  return("");
}


bool loadFile(string filename, BST<string> *tree){
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
          stringstream myToString(second);
          string number = "";
          myToString >> number;
          cout << doCommand(first, number, tree);
        }
      }
      file.close();
      return true;
    }
    return false;
  }


int main(int argc, char const *argv[]) {

 BST<string> *tree = nullptr;
 if(argc == 2 && loadFile(argv[1], tree)){

    } else if (argc == 2) {
       cout << "Wrong Filename" << endl;
    }
    else {
      cout << "Ussage: program.exe test.txt" << endl;
 }


  return 0;
}
