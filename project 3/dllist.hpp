#include <cstdint>
#include <cstdint>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using std::logic_error;
using std::cout;
using std::cin;
using std::ifstream;
using std::stringstream;
using std::endl;
using std::string;

template <class T>
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
  void pushFront(T data){//needs the number from doCommand.
    Node* n = new Node(data);
    n->next = head;
    if (tail == nullptr) {
      tail = n;
    }else {
      head->prev = n;
    }
    head = n;
    size++;
  }
  /*
  adds another node at the back of the rist.
  @param the data to be added to the each noded created.
  */
  void pushBack(T data){
    Node* n = new Node(data);
    n->prev = tail;
    if (head == nullptr) {
      head = n;
    } else {
      tail->next = n;
    }
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


  void doCommand(string cmd, T number) {//must create list before doing the rest.
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
        cout << removeElement(number) << endl;//
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
  void insert(T sortNumber){
//me use get_element to know where to insert maybe.
//Node *n = ;



// //pseudocode staff
// void List::insert(){
   //Node *n = new Node(value)
   //if(head == nullptr || value < head->value){
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


   void deleteList(){///////to be romoved.
     cout << "to be DEleted in the future" << endl;
    //list = nullptr;

    }


  void clear(){
    while (head != nullptr) {
      removeHead();
    }
    head = nullptr;
    size = 0;
  }

  void removeHead(){
    if (size == 0)
      throw std::logic_error("EMPTY LIST");
    Node *marker = head;
    head = head->next;
    delete marker;
    size--;

  }
  void removeTail(){
    if (size == 0)
      throw std::logic_error("EMPTY LIST");
    Node *marker = tail;
    tail = tail->prev;
    delete marker;
    size--;
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
bool has_element(T number){
  //toString(number);
  Node *marker = head;
  while (marker != nullptr) {
    if (marker->data == number) {
      return true;
    } else {
      return false;
    }
  }
}
/*
theacher
the cout doesn't shows, it says no maching function
*/
string hasElementStr(T number){
  if (has_element(number) == true) {
    cout << "yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
  /*
  prints the Node list
  */
  void printList();
  /*

  */
  void removeAll();
  /*
  theacher
  remove element is just remove the value in that node?
  */
  string removeElement(T value){
    stringstream ss;
    if(get_element(value) != true){
      ss << "VALUE " << value << " NOT FOUND" << endl;
      return ss.str();
    } else {
      Node *n = head;
      //fixing get element first.

      ss << "VALUE " << value << " ELIMINATED" << endl;
      return ss.str();
    }

  }
  bool get_element(T value){
    Node *marker = head;
    while (marker != nullptr) {
      if (marker->data == value) {
        return true;
      } else {
        return false;
      }
    }
  }
  /*
  Return a string representation of this Node Doubly list.
  Display the values (starting from head) of each node
  in the list, separated by comma.
  */
  string toString(){
    stringstream ss;
    Node *marker = head;
    while (marker != nullptr) {
      ss << marker->data;
      if (marker->next != nullptr) {
        ss << ',';
      }
      marker = marker->next;
    }
    return ss.str();
  }

  private:
    uint32_t size;
    struct Node{
      T data;
      Node* prev;
      Node* next;
      Node(int newdata){
        prev = nullptr;
        next = nullptr;
        data = newdata;
      }
    } *head, *tail;
  };
