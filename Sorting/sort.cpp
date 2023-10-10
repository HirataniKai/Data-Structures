template<class ItemType>
SortABC<ItemType>::SortABC(): swaps(0), comparisons(0){}

template<class ItemType>
int SortABC<ItemType>::getSwaps(){
    return swaps;
}

template<class ItemType>
int SortABC<ItemType>::getComparisons(){
    return comparisons;
}

template<class ItemType>
std::chrono::milliseconds SortABC<ItemType>::getRunTime(){
    return runTime;
}