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

List::List()
: head(nullptr), curr(nullptr), temp(nullptr)
{
  size = 0;
}
List::List(){
  clear();
}
int List::size(){
  return size;
}
bool empty(){
  return(size = 0);
}
int headContents(){
  return head->data;
}

//harder stuff
void List::pushFront(int addData){
  Node* n = new Node(data);
  n->next = head;
  head = n;
  size++;
}

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
