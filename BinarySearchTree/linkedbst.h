#ifndef LINKED_BSTREE
#define LINKED_BSTREE

#include "linkedtreenode.h"
#include "linkedbtree.h"

template<class ItemType> 
class LinkedBSearchTree: public LinkedBTree<ItemType>{ 
private: 
protected:
    LinkedTreeNode<ItemType>* placeNode(LinkedTreeNode<ItemType>* subTreePtr, LinkedTreeNode<ItemType>* newNodePtr);
    LinkedTreeNode<ItemType>* removeValue(LinkedTreeNode<ItemType>* subTreePtr, const ItemType target, bool& isSuccessful);
    LinkedTreeNode<ItemType>* removeNode(LinkedTreeNode<ItemType>* nodePtr);
    LinkedTreeNode<ItemType>* removeLeftmostNode(LinkedTreeNode<ItemType>* nodePtr, ItemType& inorderSuccessor);
    LinkedTreeNode<ItemType>* findNode(LinkedTreeNode<ItemType>* treePtr, const ItemType& target) const;
public:
    LinkedBSearchTree();

    bool add(const ItemType& newData); 
    bool remove(const ItemType& data); 
    bool contains(const ItemType& anEntry) const; 

    ~LinkedBSearchTree();
};
#include "linkedbst.cpp"
#endif