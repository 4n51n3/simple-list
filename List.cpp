//
// Created by d on 24.01.18.
//

#include "List.h"

List::List() {
    head = nullptr;
}

bool List::ListIsEmpty() {
    return (this->head == NULL);
}

bool List::ListIsFull() {
    Node* pNode;

    pNode = new Node;

    return true;
}

List::~List() {

}

void List::AddItem(Item &item) {
    Node* newNode = new Node();
    Node* pNode = this->head;
    newNode->CopyToNode(item);

    //Add node to end
    while (pNode != NULL){
        pNode = pNode->next;
    }
    if(this->head == NULL){
        this->head = newNode;
    }else{
        pNode->next = newNode;
    }
}

void List::Traverse(void (*pFunc)(Item)) {
    Node* pNode = this->head;

    while (pNode != NULL){
        pFunc(pNode->item);
        pNode = pNode->next;
    }
}

void List::Node::CopyToNode(Item &item) {
    this->item.score = item.score;
    this->next = nullptr;
}

List::Node::~Node() {
    delete this;
}

void List::Node::Free() {
    delete this;
}
