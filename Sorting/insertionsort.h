#ifndef INSERTION_SORT
#define INSERTION_SORT

#include "sort.h"

template<class ItemType>
class InsertionSort: public SortABC<ItemType>{
public:
    InsertionSort();
    void sort(ArrayList<ItemType>&);
};

#include "insertionsort.cpp"
#endif