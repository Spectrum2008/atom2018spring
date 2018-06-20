//
// Created by honorio on 6/7/18.
//

#include "Exagon.h"

void Exagon::addNode(int newData) {
    _addNode(newData, firstExagon);
}

void Exagon::_addNode(int newData, Exagon::Node *troot) {
    if(firstExagon == nullptr) {
        firstExagon = new Node(newData);
        cout << "adding the first exagon" << endl;
        cout << firstExagon->data << endl;
    }else{
        cout << "there is one already" << endl;
    }

}

Exagon::Exagon():
firstExagon(nullptr)
{}
