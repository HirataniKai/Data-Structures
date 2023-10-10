template<class ItemType>
InsertionSort<ItemType>::InsertionSort(){}

template<class ItemType>
void InsertionSort<ItemType>::sort(ArrayList<ItemType>& data){
    this->swaps = 0;
    this->comparisons = 0;
    
    auto begin = std::chrono::high_resolution_clock::now();
    
    int size = data.getLength();

    for(int i = 2; i <= size; i++){
        int j = i;
        while(j > 1 && data.getEntry(j) < data.getEntry(j - 1)){
            ItemType old = data.getEntry(j);
            ItemType smallest = data.getEntry(j - 1);
            data.replace(j, smallest);
            data.replace(j - 1, old);
            
            this->swaps++;
            this->comparisons++;
            j--;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    this->runTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
}