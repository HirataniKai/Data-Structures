#ifndef SELECTION_SORT
#define SELECTION_SORT

#include "sort.h"

template<class ItemType>
class SelectionSort: public SortABC<ItemType>{
public:
    SelectionSort();
    void sort(ArrayList<ItemType>&);
};

#include "selectionsort.cpp"
#endif