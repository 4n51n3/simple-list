//
// Created by d on 24.01.18.
//

#ifndef CPP_LIST_LIST_H
#define CPP_LIST_LIST_H

#include <cstdlib>

//#include <algorithm> //std::copy
class Item {
public:
    char str[10];
};





class List {
private:
    class Node;

private:
    unsigned long int Count;

public:
    Node *head;

public:
    List();

    virtual ~List();

    bool IsEmpty();

    bool IsFull();

    void AddItem(Item &item);

    void Traverse(void (*pFunc)(Item item));

    void Free();

    unsigned long int GetCount(){
        return Count;
    }

    Item &operator[](int x);

    List(const List &other);

    class Iterator;

};



class List::Node {
public:
    Item item;
    Node *next;
public:
    Node();

    virtual ~Node();

    void CopyToNode(Item &item){
        //  std::copy(&item, &item, &(this->item));
        memcpy(&(this->item), &item, sizeof(Item));//work
    }

    void Dispose() {
        delete this;
    }


};

class List::Iterator{
    Node* next;
public:
    Item* item;

    virtual ~Iterator() {
        item = nullptr;
        next = nullptr;
    }

    explicit Iterator(List &lst){
        this->next = lst.head;
        item = &next->item;
    }

    explicit Iterator(List *lst){
        this->next = lst->head;
        item = &next->item;
    }

    Iterator() = delete;

    bool operator()(){
        return next != nullptr;
    }

    void operator++(){
        next = next->next;
        item = &next->item;
    }

    void operator++(int notUsed){
        next = next->next;
        item = &next->item;
    }
};
#endif //CPP_LIST_LIST_H
