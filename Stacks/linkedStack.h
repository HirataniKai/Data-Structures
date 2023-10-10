#ifndef LINKED_STACK
#define LINKED_STACK

#include "stack.h"
#include "node.h"

template<class ItemType> 
class LinkedStack: public StackInterface<ItemType> { 
private: 
    Node<ItemType>* topPtr; 
public: 
    LinkedStack();

    bool isEmpty() const; 
    bool push(const ItemType& newEntry); 
    bool pop(); 
    ItemType peek() const; 

    ~LinkedStack();
};

#include "linkedStack.cpp"
#endif
