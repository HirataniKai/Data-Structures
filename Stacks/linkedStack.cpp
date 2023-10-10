#include "linkedStack.h"

template<class ItemType>
LinkedStack<ItemType>::LinkedStack(){
    topPtr = nullptr;
}

template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const{
    return topPtr == nullptr;
} 

template<class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newEntry){
    Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry, topPtr);
    topPtr = newNodePtr;
    newNodePtr = nullptr;
    return true;
} 

template<class ItemType>
bool LinkedStack<ItemType>::pop(){
    bool canPop = !isEmpty();
    
    if (canPop){
        Node<ItemType>* nodeToDeletePtr = topPtr;

        topPtr = topPtr->getNext();        
        nodeToDeletePtr->setNext(nullptr);

        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;
    } 
    
    return canPop;
}

template<class ItemType>
ItemType LinkedStack<ItemType>::peek() const{
    bool canPeek = !isEmpty();
    
    if(canPeek){
        return topPtr->getItem();
    }
    else{
        throw "empty stack";
    }
}

template<class ItemType>
LinkedStack<ItemType>::~LinkedStack(){
    while (!isEmpty()){
        pop();
    }
}