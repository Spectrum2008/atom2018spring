//####################################################################//
//###########PROJECT 3 DOUBLY LINKED LIST############################//
//##################################################################//
//Honorio Benitez,
//April 25

#include <cstdint>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdexcept>
using std::out_of_range;
using std::logic_error;
using std::cout;
using std::cin;
using std::ifstream;
using std::stringstream;
using std::endl;
using std::string;

/*
*implement a template doubly linked list with full functionality.
*/
template <class T>
class DLList {

public:
/*
*constructor, initializes head and tail to nullptr, size to 0.
*/
  DLList()
  : head(nullptr), tail(nullptr), size(0)
  {}
/*
*deconstructor, destroys all the nodes by calling clear();
*/
  ~DLList(){
    clear();
  }

/*
*adds another node at the front of the list.
*@param is the number to be stored in the new node.
*/
  void pushFront(T data){
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
*adds another node at the back of the list.
*@param the data to be added to the each noded created.
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
*returns the numbers of Nodes
*@return variable size.
*/
  uint32_t get_Size(){
    return size;
  }
/*
*it cheks if list is empty or not
*@return a bool, true if it is empty, Or false if it is not empty
*/
  bool empty(){
    return(size == 0);
  }
/*get head contents
*return the value stored in the curent head Node
*@return an integer, the value in the head Nodes
*/
  uint32_t headContents() throw(logic_error){
    if (head == nullptr && tail == nullptr) {
      throw logic_error("LIST EMPTY");
    }
    return head->data;
  }
/*get tail contents
*return the value stored in the current head Nodes
*@return the value stored in the current tail Nodes
*/
  uint32_t tailContents() throw(logic_error){
    if (head == nullptr) {
      throw logic_error("LIST EMPTY");
    }
    return tail->data;
  }
/*
*insert a Node (sorted), all nodes in order small to big.
*@param the value for the Node te be inserted.
*/
  void insert(T value){
   if(head == nullptr){
     pushBack(value);
   }else if(head->data == tail->data){
     if(head->data > value){
     pushFront(value);
   }else{
     pushBack(value);
   }
   }else if(value > tail->data){
     pushBack(value);
   }else if(value < head->data) {
     pushFront(value);
   }else {
     Node* marker = tail;
     while(marker->prev->data > value){
       marker = marker->prev;
     }
     if(marker->data == value) {
       Node* n = new Node(value);//NOT WORKING NEEDS CHECK!!!!.....
       n->prev = marker->prev;
       n->next = marker;
       marker->prev = n;
       marker->prev->next = n;
       size++;
     }else{
       Node* n = new Node(value);
       n->prev = marker->prev;
       n->next = marker;
       marker->prev->next = n;
       marker->prev = n;
       size++;
     }
   }
}
/*
*Dellete all Nodes in the Nodelist
*it uses removeHead() to remove them all.
*/
  void clear(){
    Node* marker = head;
    while (marker != nullptr) {
      marker = head->next;
      removeHead();
    }
  }
/*
*remove the head element.
*@throw a logic error if list is empty.
*@return true on sucess false if failure.
*/
  bool removeHead()throw(logic_error){
    if (head == nullptr){
      return false;
    }else if(head == tail){
        delete head;
        head = nullptr;
        tail = nullptr;
        size--;
        return true;
    }else{
      Node *marker = head;
      head = head->next;
      delete marker;
      head->prev = nullptr;
      size--;
      return true;
    }
  }
/*
*remove the tail element.
*@throw logic error if list is empty.
*@return true if sucess, false if failure.
*/
  bool removeTail()throw(logic_error){
    if (head == nullptr){
      return false;
    }else if(head == tail){
      delete head;
      head = nullptr;
      tail = nullptr;
      size--;
      return true;
    }else{
    Node *marker = tail;
    tail = tail->prev;
    delete marker;
    tail->next = nullptr;
    size--;
    return true;
  }
 }
/*
*get the element on the specified index
*just say yes exist or no it doesn't
*@param the value to find.
*@return on sucess VALUE x FOUND on failure VALUE x NOT FOUND
*will display messages on doCommand.
*/
  bool getElement(T value){
    Node *marker = head;
    while (marker != nullptr && marker->data != value) {
      marker = marker->next;
    }
  //marker is moving throw the pointers, and there is an extra
  //pointer because of the desing of the Nodes, there is a NOT
  //used pointer at the end.
    if (marker != nullptr && marker->data == value) {
      return true;
    }
    return false;
  }
/*
*Delete all nodes with the specific value.
*@param the value that is going to be removed entirely from the Nodelist
*the same number should not apear again. (remove all instances of the same
*value.)
*@return true if all instances of that value have been removed.
*/
  bool removeAll(T value){
    bool founded;
    Node* marker = new Node(value);
    marker = head;
    while (marker != nullptr) {
      if(marker->data == value){
        removeOne(value);
        founded = true;
      }
      marker = marker->next;
    }
  return founded;
}
/*
*remove only the first node with the value specified.
*@param the value that is going to be found and removed.
*@return true if an item has been removed else false.
*/
  bool removeOne(T value){
    if (head == nullptr) {
      return false;
    } else if (head->data == value) {
      removeHead();
      return true;
    } else if(tail->data == value) {
      removeTail();
      return true;
    }
    Node *marker = head;
    while(marker != nullptr && marker->data != value){
      marker = marker->next;
    }
    if(getElement(value)){
      marker->prev->next = marker->next;
      marker->next->prev = marker->prev;
      delete marker;
      size--;
      return true;
    }
    return false;
  }
/*
*Return a string representation of this Node Doubly list.
*Display the values (starting from head) of each node
*in the list, separated by comma.
*/
  string toString(){
    if (head == nullptr) {
      return("LIST EMPTY");
    }
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
      Node(uint32_t newdata){
        prev = nullptr;
        next = nullptr;
        data = newdata;
      }
    } *head, *tail;
  };
