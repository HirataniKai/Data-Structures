#ifndef MERGE_SORT
#define MERGE_SORT

#include "sort.h"

template<class ItemType>
class MergeSort: public SortABC<ItemType>{
private:
    void mergeSort(ArrayList<ItemType>&, int, int);
    void merge(ArrayList<ItemType>&, int, int, int);
public:
    MergeSort();
    void sort(ArrayList<ItemType>&);
};

#include "mergesort.cpp"
#endif