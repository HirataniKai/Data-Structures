#ifndef ARRAY_PRIORITY_QUEUE 
#define ARRAY_PRIORITY_QUEUE

#include "arrayqueue.h"

template<class ItemType> 
class ArrayPriorityQueue: public ArrayQueue<ItemType> {
public:  
    bool enqueue(const ItemType& newEntry);

    ~ArrayPriorityQueue() { } 
};  
#include "priorityarrayqueue.cpp"
#endif