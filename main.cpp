#include <iostream>
#include "List.h"
void print(Item item){
    std::cout << item.score << " ";
}

int main() {
    Item myItem;
    myItem.score = 5;
    List myList;
    myList.AddItem(myItem);
    myList.Traverse(print);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}