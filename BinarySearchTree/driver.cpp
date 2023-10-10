// Kai Hiratani

#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;

#include "linkedbst.h"

#define TREE_SIZE 100

void createTree(LinkedBSearchTree<int>&);
void display(int&);
void write(int&);

string FILENAME;

int main(){
    LinkedBSearchTree<int> newtree;
    createTree(newtree);

    newtree.inorderTraverse(display);
    newtree.preorderTraverse(display);
    newtree.postorderTraverse(display);

    FILENAME = "output/inorder.txt";
    newtree.inorderTraverse(write);
    FILENAME = "output/preorder.txt";
    newtree.preorderTraverse(write);
    FILENAME = "output/postorder.txt";
    newtree.postorderTraverse(write);

    return 0;
}

void createTree(LinkedBSearchTree<int>& data){    
    srand (time(NULL));
    for(int i = 0; i < TREE_SIZE; i++){
        data.add(rand() % 200 + 1);
    }
}

void display(int& num){
    cout << num << endl;
}

void write(int& num){
    ofstream outfile;
    outfile.open(FILENAME, ofstream::app);

    outfile << num << endl;

    outfile.close();
}