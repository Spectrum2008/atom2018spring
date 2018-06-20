//
// Created by honorio on 6/7/18.
//

#include <iostream>
using namespace std;

#ifndef UNTITLED_EXAGON_H
#define UNTITLED_EXAGON_H


class Exagon {
public:
    struct Node {
        int data;
        Node* leftUp;
        Node* up;
        Node* rightUp;
        Node* down;
        Node* downLeft;
        Node* downRight;
        Node(int newData):
                data(newData), leftUp(nullptr), up(nullptr), rightUp(nullptr), downLeft(nullptr), down(nullptr), downRight(nullptr)
        {}
    }* firstExagon;

    Exagon();

    void addNode(int newData);
private:
    void _addNode(int newData, Node* troot);

};


#endif //UNTITLED_EXAGON_H
