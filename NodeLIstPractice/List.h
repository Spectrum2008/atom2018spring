#pragma once

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class List{

public:
  /*
constructor, initializes
  */
List();
/*
deconstructor, destroys all the nodes by calling clear();
*/
~List();
/*
adds another node at the front of the list.
@param is the number to be stored in each node created.
*/
void pushFront(int addData);
/*
adds another node at the back of the rist.
@param the data to be added to the each noded created.
*/
void pushBack(int addData);
/*
returns the numbers of Nodes
@return variable size.
*/
int get_size();
/*
it cheks if list is empty or not
@return a bool, true if it is empty, Or false if it is not empty
*/
bool empty();
/*get head contents
return the value stored in the curent head Node
@return an integer, the value in the head Nodes
*/
int headContents();
/*get tail contents
return the value stored in the current head Nodes
@return the value stored in the current tail Nodes
*/
int tailContents();
/*
insert a Node between two chossen Nodes
@param the value for the Node te be inserted.
*/
void insert();
/*

*/
void find();
/*
deletes a choosen node between two nodes//[[[[[[[[[[[[]]]]]]]]]]]]
*/
void deleteNode(int delData);
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
  int size;
  struct Node{
    int data;
    Node* next;
    Node(int newdata){
      next = nullptr;
      data = newdata;
    }
  } *head, *tail;


}
