#ifndef SORT_ABC 
#define SORT_ABC 

#include <chrono>
#include "arraylist.h"

template<class ItemType> 
class SortABC { 
protected:
    long long int swaps;
    long long int comparisons;
    std::chrono::milliseconds runTime;     
public: 
    SortABC();

    int getSwaps();
    int getComparisons();
    std::chrono::milliseconds getRunTime();

    virtual void sort(ArrayList<ItemType>&) = 0; 
};

#include "sort.cpp"  
#endif
