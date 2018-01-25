//
// Created by d on 24.01.18.
//

#ifndef CPP_LIST_LIST_H
#define CPP_LIST_LIST_H
#include <cstdlib>
//#include <algorithm> //std::copy
class Item{
public:
    char str[10];
};

class List {
private:
    class Node{
    public:
        Node();
        virtual ~Node();
        void CopyToNode(Item &item);
        void Dispose();

    public:
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
    void Free();

public:
    Node* head;
};


#endif //CPP_LIST_LIST_H
