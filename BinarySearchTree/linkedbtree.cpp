template<class ItemType>
int LinkedBTree<ItemType>::getHeightHelper(LinkedTreeNode<ItemType>* subTreePtr) const{
    if (subTreePtr == nullptr){
        return 0;
    }
    else{
        return 1 + max(getHeightHelper(subTreePtr->getLeftChildPtr()), getHeightHelper(subTreePtr->getRightChildPtr()));
    }
}

template<class ItemType>
int LinkedBTree<ItemType>::getNumberOfNodesHelper(LinkedTreeNode<ItemType>* subTreePtr) const{
    if (subTreePtr == nullptr){
        return 0;
    }
    else{
        return 1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr()) + getNumberOfNodesHelper(subTreePtr->getRightChildPtr());
    }
}

template<class ItemType>
LinkedTreeNode<ItemType>* LinkedBTree<ItemType>::balancedAdd(LinkedTreeNode<ItemType>* subTreePtr, LinkedTreeNode<ItemType>* newNodePtr){
    if (subTreePtr == nullptr)
        return newNodePtr;
    else{
        LinkedTreeNode<ItemType>* leftPtr = subTreePtr->getLeftChildPtr();
        LinkedTreeNode<ItemType>* rightPtr = subTreePtr->getRightChildPtr();
        if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr)){
            rightPtr = balancedAdd(rightPtr, newNodePtr);
            subTreePtr->setRightChildPtr(rightPtr);
        }
        else{
            leftPtr = balancedAdd(leftPtr, newNodePtr);
            subTreePtr->setLeftChildPtr(leftPtr);
        } 
        return subTreePtr;
    }
}

template<class ItemType>
LinkedTreeNode<ItemType>* LinkedBTree<ItemType>::removeValue(LinkedTreeNode<ItemType>* subTreePtr, const ItemType target, bool& isSuccessful){
    if (subTreePtr == nullptr){
        isSuccessful = false;
        return nullptr;
    }
    else if(subTreePtr->getItem() == target){
        isSuccessful = true;
        //remove node
        if(subTreePtr->isLeaf()){
            delete subTreePtr;
            subTreePtr = nullptr;
            return subTreePtr;
        }
        else{
            return moveValuesUpTree(subTreePtr);
        }
    }
    else{
        LinkedTreeNode<ItemType>* tempPtr = removeValue(subTreePtr->getRightChildPtr(), target, isSuccessful);
        if(isSuccessful){
            subTreePtr->setRightChildPtr(tempPtr);
        }
        else{
            subTreePtr = removeValue(subTreePtr->getLeftChildPtr(), target, isSuccessful);
            if(isSuccessful){
                subTreePtr->setLeftChildPtr(tempPtr);
            }
        }
        return subTreePtr;
    }
    return subTreePtr;
}

template<class ItemType>
LinkedTreeNode<ItemType>* LinkedBTree<ItemType>::moveValuesUpTree(LinkedTreeNode<ItemType>* subTreePtr){
    if(subTreePtr->getRightChildPtr() != nullptr){
        subTreePtr->setItem(subTreePtr->getRightChildPtr()->getItem());
        subTreePtr->setRightChildPtr(moveValuesUpTree(subTreePtr->getRightChildPtr()));
        return subTreePtr;
    }
    else if(subTreePtr->getLeftChildPtr() != nullptr){
        subTreePtr->setItem(subTreePtr->getLeftChildPtr()->getItem());
        subTreePtr->setLeftChildPtr(moveValuesUpTree(subTreePtr->getLeftChildPtr()));
        return subTreePtr;
    }
    return nullptr;
}

template<class ItemType>
LinkedTreeNode<ItemType>* LinkedBTree<ItemType>::findNode(LinkedTreeNode<ItemType>* treePtr, const ItemType& target, bool& isSuccessful) const{
    if(treePtr != nullptr){
        if(treePtr->getItem() == target){
            isSuccessful = true;
            return treePtr;
        }
        LinkedTreeNode<ItemType>* node;
        node = findNode(treePtr->getLeftChildPtr(), target, isSuccessful);
        if(isSuccessful){
            return node;
        }
        node = findNode(treePtr->getRightChildPtr(), target, isSuccessful);
        if(isSuccessful){
            return node;
        }
    }
    return nullptr;
}

template<class ItemType>
void LinkedBTree<ItemType>::destroyTree(LinkedTreeNode<ItemType>* subTreePtr){
    if (subTreePtr != nullptr ){
        destroyTree(subTreePtr->getLeftChildPtr());
        destroyTree(subTreePtr->getRightChildPtr());
        delete subTreePtr;
        subTreePtr = nullptr;
    }
}

template<class ItemType>
void LinkedBTree<ItemType>::preorder(void visit(ItemType&), LinkedTreeNode<ItemType>* treePtr) const{
    if(treePtr != nullptr){
        ItemType item = treePtr-> getItem();
        visit(item);

        preorder(visit, treePtr->getLeftChildPtr());
        preorder(visit, treePtr->getRightChildPtr());
    }
}
template<class ItemType>
void LinkedBTree<ItemType>::inorder(void visit(ItemType&), LinkedTreeNode<ItemType>* treePtr) const{
    if(treePtr != nullptr){
        inorder(visit, treePtr->getLeftChildPtr());

        ItemType item = treePtr-> getItem();
        visit(item);
        
        inorder(visit, treePtr->getRightChildPtr());
    }
}
template<class ItemType>
void LinkedBTree<ItemType>::postorder(void visit(ItemType&), LinkedTreeNode<ItemType>* treePtr) const{
    if(treePtr != nullptr){
        postorder(visit, treePtr->getLeftChildPtr());
        postorder(visit, treePtr->getRightChildPtr());

        ItemType item = treePtr-> getItem();
        visit(item);
    }
}

template<class ItemType>
LinkedBTree<ItemType>::LinkedBTree(){
    rootPtr = nullptr;
}

template<class ItemType>
bool LinkedBTree<ItemType>::isEmpty() const{
    return rootPtr == nullptr;
}
template<class ItemType>
int LinkedBTree<ItemType>::getHeight() const{
    return getHeightHelper(rootPtr);
}
template<class ItemType>
int LinkedBTree<ItemType>::getNumberOfNodes() const{
    return getNumberOfNodesHelper(rootPtr);
}
template<class ItemType>
ItemType LinkedBTree<ItemType>::getRootData() const{
    return rootPtr->getItem();
}
template<class ItemType>
bool LinkedBTree<ItemType>::add(const ItemType& newData){
    LinkedTreeNode<ItemType>* newNodePtr = new LinkedTreeNode<ItemType>(newData);
    rootPtr = balancedAdd(rootPtr, newNodePtr);
    return true;
} 
template<class ItemType>
bool LinkedBTree<ItemType>::remove(const ItemType& data){
    bool success;
    removeValue(rootPtr, data, success);
    return success;
} 

template<class ItemType>
void LinkedBTree<ItemType>::clear(){
    destroyTree(rootPtr);
}

template<class ItemType>
bool LinkedBTree<ItemType>::contains(const ItemType& anEntry) const{
    bool success;
    findNode(rootPtr, anEntry, success);
    return success;
} 

template<class ItemType>
void LinkedBTree<ItemType>::preorderTraverse(void visit(ItemType&)) const{
    preorder(visit, rootPtr);
}
template<class ItemType>
void LinkedBTree<ItemType>::inorderTraverse(void visit(ItemType&)) const{
    inorder(visit, rootPtr);
}
template<class ItemType>
void LinkedBTree<ItemType>::postorderTraverse(void visit(ItemType&)) const{
    postorder(visit, rootPtr);
}

template<class ItemType>
LinkedBTree<ItemType>::~LinkedBTree(){
    clear();
}
