template<class ItemType>
MergeSort<ItemType>::MergeSort(){}

template<class ItemType>
void MergeSort<ItemType>::mergeSort(ArrayList<ItemType>& data, int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        mergeSort(data, left, mid);
        mergeSort(data, mid + 1, right);
        merge(data, left, mid, right);
    }
}

template<class ItemType>
void MergeSort<ItemType>::merge(ArrayList<ItemType>& data, int begin, int mid, int end){
    int first1 = begin, last1 = mid, first2 = mid + 1, last2 = end;
    ArrayList<ItemType> temp = data;
    ItemType item1, item2;

    int index = first1;
    while(first1 <= last1 && first2 <= last2){
        item1 = temp.getEntry(first1);
        item2 = temp.getEntry(first2);
        
        this->comparisons++;
        if(item1 <= item2){
            data.replace(index, item1);
            first1++;
        }
        else{
            data.replace(index, item2);
            first2++;
        }
        index++;
    }
    while(first1 <= last1){
        item1 = temp.getEntry(first1);
        data.replace(index, item1);
        first1++;
        index++;
    }
    while(first2 <= last2){
        item2 = temp.getEntry(first2);
        data.replace(index, item2);
        first2++;
        index++;
    }
}

template<class ItemType>
void MergeSort<ItemType>::sort(ArrayList<ItemType>& data){
    this->swaps = 0;
    this->comparisons = 0;
    
    auto begin = std::chrono::high_resolution_clock::now();

    mergeSort(data, 1, data.getLength());
    
    auto end = std::chrono::high_resolution_clock::now();
    this->runTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
}