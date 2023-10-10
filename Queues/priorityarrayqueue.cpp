#include "priorityarrayqueue.h"

template<class ItemType> 
bool ArrayPriorityQueue<ItemType>::enqueue(const ItemType& newEntry){
    bool canNQ = this->itemCount < this->DEFAULT_CAPACITY;

    if (canNQ){
        this->backIndex = (this->backIndex + 1) % this->DEFAULT_CAPACITY;
        int newIndex = this->backIndex;
        int prevIndex = (newIndex - 1 + this->DEFAULT_CAPACITY) % this->DEFAULT_CAPACITY;
        int numItems = this->itemCount;

        while(numItems > 0 && this->items[prevIndex] < newEntry){
            this->items[newIndex] = this->items[prevIndex];
            newIndex = (newIndex - 1 + this->DEFAULT_CAPACITY) % this->DEFAULT_CAPACITY;
            prevIndex = (newIndex - 1 + this->DEFAULT_CAPACITY) % this->DEFAULT_CAPACITY;
            numItems--;
        }
        
        this->items[newIndex] = newEntry;
        this->itemCount++;
    } 

    return canNQ;
}