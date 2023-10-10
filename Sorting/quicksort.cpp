template<class ItemType>
QuickSort<ItemType>::QuickSort(){}

template<class ItemType>
void QuickSort<ItemType>::quickSort(ArrayList<ItemType>& data, int low, int high){
    if(low < high){
        int pi = partition(data, low, high);
        quickSort(data, low, pi - 1);
        quickSort(data, pi + 1, high);
    }
}
template<class ItemType>
int QuickSort<ItemType>::partition(ArrayList<ItemType>& data, int low, int high){
    ItemType pivot = data.getEntry(high), temp;
    int i = low;
    for(int j = low; j < high; j++){
        this->comparisons++;
        if(data.getEntry(j) < pivot){
            this->swaps++;
            temp = data.getEntry(j);
            data.replace(j, data.getEntry(i));
            data.replace(i, temp);
            i++;
        }
    }
    this->swaps++;
    temp = data.getEntry(high);
    data.replace(high, data.getEntry(i));
    data.replace(i, temp);
    
    return i;
}

template<class ItemType>
void QuickSort<ItemType>::sort(ArrayList<ItemType>& data){
    this->swaps = 0;
    this->comparisons = 0;
    
    auto begin = std::chrono::high_resolution_clock::now();

    quickSort(data, 1, data.getLength());
    
    auto end = std::chrono::high_resolution_clock::now();
    this->runTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
}