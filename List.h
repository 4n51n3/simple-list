//
// Created by d on 24.01.18.
//

#ifndef CPP_LIST_LIST_H
#define CPP_LIST_LIST_H
#include <stdlib.h>

class Item{
public:
    int score;
};

class List {
private:
    class Node{
    public:
        void CopyToNode(Item &item);
        virtual ~Node();
        virtual void Free();
        Item item;
        Node* next;
    };
public:
    List();
    virtual ~List();
    bool ListIsEmpty();
    bool ListIsFull();
    void AddItem(Item &item);
    void Traverse(void (*pFunc)(Item item));

public:
    Node* head;
};


#endif //CPP_LIST_LIST_H
