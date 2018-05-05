#include <iostream>
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdexcept>


using namespace std;

template <class T>
class BST
{

private:

  struct Node
  {
    string data;
    Node* leftChild;
    Node* rightChild;
    Node(T newData)
    : data(newData), leftChild(nullptr), rightChild(nullptr)
    {}
  }* root;

  void _insert(T data, Node* Ptr)
    {
      if(root == nullptr)
      {
        root = new Node(data);
      }
      else if(data < Ptr->data)
      {
        if (Ptr->leftChild != nullptr)
         {
          _insert(data, Ptr->leftChild);
        }
        else
        {
          Ptr->leftChild = new Node(data);
        }
      }
      else if(data > Ptr->data)
      {
        if (Ptr->rightChild != nullptr)
         {
          _insert(data, Ptr->rightChild);
        }
        else
        {
          Ptr->rightChild = new Node(data);
        }
      }
      else
      {
        cout << "They data " << data << " has already been added to the tree\n";
      }
  }
  void _printInOrder(Node* Ptr)
  {
    if(root != nullptr)
    {
      if(Ptr->rightChild != nullptr)
      {

      }
      cout << Ptr->data << " ";
      if (Ptr->rightChild != nullptr)
      {
        _printInOrder
        (Ptr->rightChild);
      }
    }
    else
    {
      cout << "The tree is empty\n";
    }
  }
  Node* ReturnNodePrivate(T data, Node* Ptr);


public:

  BST()
  {
    root = nullptr;
  }

  void insert(T data)
  {
    _insert(data, root);
  }

  void PrintInOrder()
  {
    _printInOrder(root);
  }

};
