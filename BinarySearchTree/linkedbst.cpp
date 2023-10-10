template<class ItemType> 
LinkedTreeNode<ItemType>* LinkedBSearchTree<ItemType>::placeNode(LinkedTreeNode<ItemType>* subTreePtr, LinkedTreeNode<ItemType>* newNodePtr){
    if (subTreePtr == nullptr){
        return newNodePtr;
    }
    else if(subTreePtr->getItem() > newNodePtr->getItem()){
        LinkedTreeNode<ItemType>* tempPtr = placeNode(subTreePtr->getLeftChildPtr(), newNodePtr);
        subTreePtr->setLeftChildPtr(tempPtr);
    }
    else{
        LinkedTreeNode<ItemType>* tempPtr = placeNode(subTreePtr->getRightChildPtr(), newNodePtr);
        subTreePtr->setRightChildPtr(tempPtr);
    } 
    return subTreePtr;
}
template<class ItemType> 
LinkedTreeNode<ItemType>* LinkedBSearchTree<ItemType>::removeValue(LinkedTreeNode<ItemType>* subTreePtr, const ItemType target, bool& isSuccessful){
    if (subTreePtr == nullptr){
        isSuccessful = false;
        return nullptr;
    }
    else if(subTreePtr->getItem() == target){
        subTreePtr = removeNode(subTreePtr);
        isSuccessful = true;
        return subTreePtr;
    }
    else if(subTreePtr->getItem() > target){
        LinkedTreeNode<ItemType>* tempPtr = removeValue(subTreePtr->getLeftChildPtr(), target, isSuccessful);
        subTreePtr->setLeftChildPtr(tempPtr);
        return subTreePtr;
    } 
    else {
        LinkedTreeNode<ItemType>* tempPtr = removeValue(subTreePtr->getRightChildPtr(), target, isSuccessful);
        subTreePtr->setRightChildPtr(tempPtr);
        return subTreePtr;
    } 

    return subTreePtr;
}
template<class ItemType> 
LinkedTreeNode<ItemType>* LinkedBSearchTree<ItemType>::removeNode(LinkedTreeNode<ItemType>* nodePtr){
    if(nodePtr->isLeaf()){
        delete nodePtr;
        nodePtr = nullptr;
        
        return nodePtr;
    }
    else if(nodePtr->getLeftChildPtr() == nullptr){
        LinkedTreeNode<ItemType>* tempPtr = nodePtr->getRightChildPtr();
        
        delete nodePtr;
        nodePtr = nullptr;
        
        return tempPtr;
    }
    else if (nodePtr->getRightChildPtr() == nullptr){
        LinkedTreeNode<ItemType>* tempPtr = nodePtr->getLeftChildPtr();
        
        delete nodePtr;
        nodePtr = nullptr;
        
        return tempPtr;
    }    
    else { 
        ItemType newNodeValue;
        LinkedTreeNode<ItemType>* tempPtr = removeLeftmostNode(nodePtr->getRightChildPtr(), newNodeValue);

        nodePtr->setRightChildPtr(tempPtr);
        nodePtr->setItem(newNodeValue);

        return nodePtr;
    } 
    return nullptr;
}
template<class ItemType> 
LinkedTreeNode<ItemType>* LinkedBSearchTree<ItemType>::removeLeftmostNode(LinkedTreeNode<ItemType>* nodePtr, ItemType& inorderSuccessor){
    if (nodePtr->getLeftChildPtr() == nullptr){
        inorderSuccessor = nodePtr->getItem();
        return removeNode(nodePtr);
    }
    else{
        return removeLeftmostNode(nodePtr->getLeftChildPtr(), inorderSuccessor);
    }
}
template<class ItemType> 
LinkedTreeNode<ItemType>* LinkedBSearchTree<ItemType>::findNode(LinkedTreeNode<ItemType>* treePtr, const ItemType& target) const{
    if(treePtr != nullptr){
        if(treePtr->getItem() == target){
            return treePtr;
        }
        if(treePtr->getItem() > target){
            return findNode(treePtr->getRightChildPtr(), target);
        }
        else if(treePtr->getItem() < target){
            return findNode(treePtr->getLeftChildPtr(), target);

        }
    }
    return nullptr;
}

template<class ItemType> 
LinkedBSearchTree<ItemType>::LinkedBSearchTree(){}
template<class ItemType> 
bool LinkedBSearchTree<ItemType>::add(const ItemType& newData){ 
    LinkedTreeNode<ItemType>* newNodePtr = new LinkedTreeNode<ItemType>(newData);
    this->rootPtr = placeNode(this->rootPtr, newNodePtr);

    return true;
} 
template<class ItemType> 
bool LinkedBSearchTree<ItemType>::remove(const ItemType& data){
    bool success = false;
    this->rootPtr = removeValue(this->rootPtr, data, success);
    return success;
}
template<class ItemType> 
bool LinkedBSearchTree<ItemType>::contains(const ItemType& anEntry) const{
    bool success;
    findNode(this->rootPtr, anEntry);
    return success;
}

template<class ItemType>
LinkedBSearchTree<ItemType>::~LinkedBSearchTree(){
    this->clear();
}