// Kai Hiratani

#include <iostream>
#include <string>
using namespace std;

#include "linkedlist.h"

int getMenuChoice();
void displayTodo(LinkedList<string>&);
void deleteTask(LinkedList<string>&);
void addTask(LinkedList<string>&);
void deleteTodo(LinkedList<string>&);

using namespace std;

int main(void){
    int menuChoice;    
    LinkedList<string> stringList;

    do {
        menuChoice = getMenuChoice();
        displayTodo(stringList);
        
        switch(menuChoice){
            case 1: 
                addTask(stringList);
                break;            
            case 2: 
                deleteTask(stringList);
                break; 
            case 3:
                break;
            case 4:
                deleteTodo(stringList);
                break;           
            case 0: 
                break;            
            default: 
                cout << endl << "Invalid option!" << endl;
                break;
        }
    }while(menuChoice != 0);
    
    return 0;
}

int getMenuChoice(){
    int userChoice;

    cout << endl << "TODO LIST" << endl;
    cout << "1. Add task" << endl;
    cout << "2. Complete task" << endl;
    cout << "3. Display list" << endl;
    cout << "4. Complete list" << endl;
    cout << "0. Exit " << endl;
    
    cin >> userChoice;
    return userChoice;
}

void displayTodo(LinkedList<string>& list){
    if(list.isEmpty()){
        cout << "No tasks currently!" << endl;
        return;
    }

    for (int pos = 1; pos <= list.getLength(); pos++){
        cout << pos << ": " << list.getEntry(pos) << endl;
    }
}

void deleteTask(LinkedList<string>& list){
    int pos;
    string temp;

    if(!list.isEmpty()){
        cout << "Please select which task you've completed: " << endl;
        cin >> pos;

        temp = list.getEntry(pos);

        if(list.remove(pos)){
            cout << endl << "Completed: " << temp << endl;
        } 
        else{
            cout << endl << "Could not complete task " << temp << endl;
        }
    }
}

void addTask(LinkedList<string>& list){
    int priority;
    string newTask;

    cout << endl << "What is the priority of your new task?" << endl;
    cin >> priority;

    while(priority < 1 || priority > list.getLength() + 1){
        cout << "Choose a priority 1 through " << list.getLength() + 1 << endl;
        cin >> priority;
    }

    cout << "What is your new task?" << endl;
    getline(cin, newTask);
    getline(cin, newTask);

    list.insert(priority, newTask);
}

void deleteTodo(LinkedList<string>& list){
    if(!list.isEmpty()){    
        list.clear();        
        cout << endl << "Congratulations! List complete!" << endl;
    }
}