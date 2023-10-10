#ifndef BUBBLE_SORT
#define BUBBLE_SORT

#include "sort.h"

template<class ItemType>
class BubbleSort: public SortABC<ItemType>{
public:
    BubbleSort();
    void sort(ArrayList<ItemType>&);
};

#include "bubblesort.cpp"
#endif