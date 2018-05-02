#include "bst.hpp"

int main(int argc, char const *argv[]) {

int Treedatas[16] = {50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 80};
BST<int>* myTree;

cout << "Printing the tree in order\nBefore adding numbers\n";

myTree->PrintInOrder();

for (size_t i = 0; i < 16; i++)
{
 myTree->insert(Treedatas[i]);
}

cout << "Printing the tree in order\nAfter adding numbers\n";

myTree->PrintInOrder();

cout << endl << '\n';
  return 0;
}
