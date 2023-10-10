template<class ItemType>
ArrayList<ItemType>::ArrayList() : maxCount(DEFAULT_CAPACITY), itemCount(0){}

template<class ItemType>
ArrayList<ItemType>::ArrayList(const ArrayList<ItemType>& aList){
	itemCount = aList.itemCount;
    maxCount = aList.maxCount;

    for(int i = 0; i < itemCount; i++){
        items[i] = aList.items[i];
    }
}

template<class ItemType>
bool ArrayList<ItemType>::isEmpty() const{
	return itemCount == 0;
}

template<class ItemType>
int ArrayList<ItemType>::getLength() const{
	return itemCount;
}

template<class ItemType>
bool ArrayList<ItemType>::insert(int newPosition, const ItemType& newEntry){
	bool ableToInsert = itemCount < maxCount && 
                        newPosition >= 1 && 
                        newPosition <= itemCount + 1;
	if (ableToInsert){
        // shuffle items to make room for new
		for(int pos = itemCount; pos >= newPosition; pos--){
            items[pos + 1] = items[pos];
        }
        items[newPosition] = newEntry;
        itemCount++;
	} 
	return ableToInsert;
}

template<class ItemType>
bool ArrayList<ItemType>::remove(int position){
	bool ableToRemove = (position >= 1) && (position <= itemCount);
	if (ableToRemove){
        // overwrite item to remove by shuffling
        for(int pos = position; pos < itemCount; pos++){
            items[pos] = items[pos + 1];
        }
        itemCount--;
	}
	return ableToRemove;

}

template<class ItemType>
void ArrayList<ItemType>::clear(){
	itemCount = 0;
}

template<class ItemType>
ItemType ArrayList<ItemType>::getEntry(int position) const {
	bool ableToGet = (position >= 1) && (position <= itemCount);
	if (ableToGet){
        return items[position];	
	} 
	cout << "getEntry " << position << endl;
	throw "Item not found";
} 

template<class ItemType>
ItemType ArrayList<ItemType>::replace(int position, const ItemType& newEntry){
	bool ableToGet = (position >= 1) && (position <= itemCount);
	if (ableToGet){
        ItemType oldEntry = items[position];
        items[position] = newEntry;
        return oldEntry;	
	} 
	cout << "replace " << position << endl;
	throw "Item not found";
}