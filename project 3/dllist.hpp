#include <cstdint>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using std::cout;
using std::cin;
using std::ifstream;
using std::stringstream;
using std::endl;
using std::string;
//#include "dllist.hpp"

class DLList {

public:
  /*
constructor, initializes
  */
  DLList()
  : head(nullptr), tail(nullptr), size(0)
  {}
  /*
  deconstructor, destroys all the nodes by calling clear();
  */
  ~DLList(){
    clear();//
  }

  /*
  adds another node at the front of the list.
  @param is the number to be stored in each node created.
  */
  void pushFront(int data){//needs the number from doCommand.
    Node* n = new Node(data);
    n->next = head;
    head = n;
    size++;
  }
  /*
  adds another node at the back of the rist.
  @param the data to be added to the each noded created.
  */
  void pushBack(int data){
    Node* n = new Node(data);
    n->prev = tail;
    tail = n;
    size++;
  }
  /*
  returns the numbers of Nodes
  @return variable size.
  */
  uint32_t get_Size(){
    return size;
  }
  /*
  it cheks if list is empty or not
  @return a bool, true if it is empty, Or false if it is not empty
  */
  bool empty(){
    return(size == 0);
  }
  /*get head contents
  return the value stored in the curent head Node
  @return an integer, the value in the head Nodes
  */
  int headContents(){
    return head->data;
  }
  /*get tail contents
  return the value stored in the current head Nodes
  @return the value stored in the current tail Nodes
  */
  int tailContents(){
    return tail->data;
  }


  void doCommand(string cmd, int number) {
    switch(cmd[0]) {
      case 'A':
        cout << "VALUE " << headContents() << " AT HEAD" << endl;
      break;
      case 'B':
        cout << "VALUE " << number << " ADDED TO TAIL" << endl; pushBack(number);
      break;
      case 'C'://i think that i have to create object.
        cout << "LIST CREATED" << endl;
      break;
      case 'D':
        cout << "LIST DELETED" << endl;
      break;
      case 'F':
        cout << "VALUE " << number <<" ADDED TO FRONT" << endl; pushFront(number);
      break;
      case 'N':
        cout << "LIST SIZE IS " << get_Size() << endl;
      break;
      case 'T':
        cout << "REMOVED HEAD" << endl;
      break;
      case 'K':
        cout << "REMOVED TAIL" << endl;
      break;
      case 'Z':
        cout << "VALUE " << tailContents() << " AT TAIL" << endl;
      break;

    }
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
  bool loadFile(string filename){
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
          int number = 0;
          myToInt >> number;
          doCommand(first, number);
          //addOption(first, second);
        }
      }
      file.close();
      return true;
    }
    return false;
  }
  /*
  insert a Node between two chossen Nodes
  @param the value for the Node te be inserted.
  */
  void insert(){

// //pseudocode staff
// void List::insert(){
//   Node *n = new Node(value)
//   if(head == nullptr || value < head->value){
//     pushFront(value)
//   }else if( value > tail->value){
//     pushBack(value);
//   }
//   else{
//     Node* marker = head;
//     while(value > marker->value){
//       marker = marker->next;
//     }
//     Node* n = new Node(value)
//     n->next = marker;
//     n->prev = marker->prev;
//     markers->prev = n;
//     n->prev->next = n;
//   }
// }
    }
/**/
  void clear(){
    cout << "clear()" << endl;
  }
  /*

  */
  void find();
  /*
  deletes a choosen node between two nodes//[[[
  */
  void deleteNode(int delData);
/*
get the element on the specified index
@param the index where the desired value is on the list.
@throw an error if value wasn't found
return */
int get_element(){

}
  /*
  prints the Node list
  */
  void printList();
  /*

  */
  void removeAll();
  /*
  */
  void remeveOne();
  /*
  */
  string toString();

  private:
    uint32_t size;
    struct Node{
      int data;
      Node* prev;
      Node* next;
      Node(int newdata){
        prev = nullptr;
        next = nullptr;
        data = newdata;
      }
    } *head, *tail;
  };
