//
// Created by d on 24.01.18.
//

#include <cstring> //memcpy
#include "List.h"

List::List() {
    head = nullptr;
}

bool List::ListIsEmpty() {
    return (this->head == nullptr);
}

bool List::ListIsFull() {
    Node* pNode;

    pNode = new Node;
    delete pNode;

    return true;
}

List::~List() {

}

void List::AddItem(Item &item) {
    Node* newNode = new Node();
    Node* pNode = this->head;
    newNode->CopyToNode(item);

    //Add node to end
    if(this->head == nullptr){
        this->head = newNode;
    }else{
        while (pNode->next != nullptr){
            pNode = pNode->next;
        }
        pNode->next = newNode;
    }
}

void List::Traverse(void (*pFunc)(Item)) {
    Node* pNode = this->head;

    while (pNode != nullptr){
        pFunc(pNode->item);
        pNode = pNode->next;
    }
}

void List::Free() {
    Node* pNode = this->head;
    Node* del = nullptr;
    while (pNode != nullptr){
        del = pNode;
        pNode = pNode->next;
        del->Dispose();
    }

    this->head = nullptr;
}

void List::Node::CopyToNode(Item &item) {
  //  std::copy(&item, &item, &(this->item));
    memcpy(&(this->item), &item, sizeof(Item));//work
}

List::Node::~Node() {

}

List::Node::Node() {
    this->next = nullptr;

}

void List::Node::Dispose() {
    delete this;

}

