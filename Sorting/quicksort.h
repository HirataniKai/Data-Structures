#ifndef QUICK_SORT
#define QUICK_SORT

#include "sort.h"

template<class ItemType>
class QuickSort: public SortABC<ItemType>{
private:
    void quickSort(ArrayList<ItemType>&, int, int);
    int partition(ArrayList<ItemType>&, int, int);
public:
    QuickSort();
    void sort(ArrayList<ItemType>&);
};

#include "quicksort.cpp"
#endif