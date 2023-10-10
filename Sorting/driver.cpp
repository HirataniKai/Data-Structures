// Kai Hiratani

#include <iostream>
#include <fstream>
using namespace std;

#include "arraylist.h"
#include "selectionsort.h"
#include "bubblesort.h"
#include "insertionsort.h"
#include "mergesort.h"
#include "quicksort.h"

#define RUNS 10

void generateRandomValues(int, ArrayList<int>&);
void runSort(string, SortABC<int>*, ArrayList<int>&);
void display(ArrayList<int>&);

int main(void){   
    ArrayList<int> random1000;
    ArrayList<int> random10000;
    ArrayList<int> random100000;

    generateRandomValues(1000, random1000);
    generateRandomValues(10000, random10000);
    generateRandomValues(100000, random100000);

    cout << "Selecting!" << endl;
    SelectionSort<int> selectionSort;
    runSort("Selection1000", &selectionSort, random1000);
    runSort("Selection10000", &selectionSort, random10000);
    runSort("Selection100000", &selectionSort, random100000);

    cout << "Bubbling!" << endl;
    BubbleSort<int> bubbleSort;
    runSort("Bubble1000", &bubbleSort, random1000);
    runSort("Bubble10000", &bubbleSort, random10000);
    runSort("Bubble100000", &bubbleSort, random100000);
    
    // cout << "Inserting!" << endl;
    // InsertionSort<int> insertionSort;
    // runSort("Insertion1000", &insertionSort, random1000);
    // runSort("Insertion10000", &insertionSort, random10000);
    // runSort("Insertion100000", &insertionSort, random100000);
    
    // cout << "Merging!" << endl;
    // MergeSort<int> mergeSort;
    // runSort("Merge1000", &mergeSort, random1000);
    // runSort("Merge10000", &mergeSort, random10000);
    // runSort("Merge100000", &mergeSort, random100000);
    
    // cout << "Quicking!" << endl;
    // QuickSort<int> quickSort;
    // runSort("Quick1000", &quickSort, random1000);
    // runSort("Quick10000", &quickSort, random10000);
    // runSort("Quick100000", &quickSort, random100000);
    
    return 0;
}

void generateRandomValues(int numValues, ArrayList<int>& data){
    srand (time(NULL));
    for(int i = 1; i <= numValues; i++){
        data.insert(i, rand() % 1000000 + 1);
    }
}

void runSort(string sortType, SortABC<int>* sort, ArrayList<int>& random){
    ofstream outfile;
    outfile.open("output/" + sortType + ".csv");
    outfile << "Run Time, Comparisons, Swaps" << endl;
    ArrayList<int> sorted = random;
    for(int i = 0; i < RUNS; i++){
        sorted = random;
        // sort random
        sort->sort(sorted);
        outfile << sort->getRunTime().count() << ", " << sort->getComparisons() << ", " << sort->getSwaps() << endl;
    }
    outfile << "Sorted" << endl;
    for(int i = 0; i < RUNS; i++){
        // sort sorted
        sort->sort(sorted);
        outfile << sort->getRunTime().count() << ", " << sort->getComparisons() << ", " << sort->getSwaps() << endl;
    }
    outfile.close();
}

void display(ArrayList<int>& data){
    for(int i = 1; i <= data.getLength(); i++){
        cout << data.getEntry(i) << " ";
    }
    cout << endl;
}