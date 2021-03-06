//
// Created by d on 24.01.18.
//

#include <cstring> //memcpy
#include "List.h"

List::List() {
    Count = 0;
    head = nullptr;
}

bool List::IsEmpty() {
    return (this->head == nullptr);
}

bool List::IsFull() {
    Node *pNode;

    pNode = new Node;
    delete pNode;

    return true;
}

List::~List() {
    Free();
}

void List::AddItem(Item &item) {
    auto newNode = new Node();
    Node *pNode = this->head;
    newNode->CopyToNode(item);

    //Add node to end
    if (this->head == nullptr) {
        this->head = newNode;
    } else {
        while (pNode->next != nullptr) {
            pNode = pNode->next;
        }
        pNode->next = newNode;
    }

    Count++;
}

void List::Traverse(void (*pFunc)(Item)) {
    Node *pNode = this->head;

    while (pNode != nullptr) {
        pFunc(pNode->item);
        pNode = pNode->next;
    }
}

void List::Free() {
    Node *pNode = this->head;
    Node *del = nullptr;
    while (pNode != nullptr) {
        del = pNode;
        pNode = pNode->next;
        del->Dispose();
    }

    this->head = nullptr;
    Count = 0;
}

Item &List::operator[](int x) {
    unsigned int index = 0;
    if (x > Count || x < 0)
        throw "[ERROR] (operator[]) Index out of range!\n";

    for(List::Iterator it(this); it(); it++){
        if(index == x)
            return *it.item;
        index++;
    }
    /*
    Node *pNode = this->head;
    while (pNode != nullptr) {
        if (index == x)
            return pNode->item;
        pNode = pNode->next;
        index++;
    }*/
    throw "[ERROR] (operator[]) Not found!\n";
}



List::List(const List &other) {
    //copy constructor
    this->head = nullptr;
    for(List::Iterator it(this); it(); it++){
        this->AddItem(*it.item);
    }

}

List::Node::~Node() = default;

List::Node::Node() {
    this->next = nullptr;
}


