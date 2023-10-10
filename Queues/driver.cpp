// Kai Hiratani

#include <iostream>
#include <fstream>
using namespace std;

#include "arrayqueue.h"
#include "priorityarrayqueue.h"
#include "event.h"

#define ARRIVAL 'A'
#define DEPARTURE 'D'
#define FILENAME "input.txt"

void loadData(ArrayPriorityQueue<Event>&);
void processArrival(bool&, ArrayPriorityQueue<Event>&, ArrayQueue<Event>&);
int processDeparture(bool&, ArrayPriorityQueue<Event>&, ArrayQueue<Event>&);

int main(){
    ArrayQueue<Event> bankQ;
    ArrayPriorityQueue<Event> eventPQ;
    
    bool isTellerAvailable = true;
    int numCustomers = 0, waitSum = 0;

    loadData(eventPQ);

    cout << "Simulation Begins" << endl;
    while(!eventPQ.isEmpty()){
        Event currentEvent = eventPQ.peekFront();
        int currentTime = currentEvent.getTime();

        if(currentEvent.getType() == ARRIVAL){
            cout << "Processing an arrival event at time:\t" << currentTime << endl;
            processArrival(isTellerAvailable, eventPQ, bankQ);
            numCustomers++;
        }
        else if(currentEvent.getType() == DEPARTURE){
            cout << "Processing an departure event at time:\t" << currentTime << endl;
            waitSum += processDeparture(isTellerAvailable, eventPQ, bankQ);
        }
    }
    cout << "Simulation Ends" << endl << endl;

    cout << "Final Statistics" << endl;
    cout << "   Total number of people processed: " << numCustomers << endl;
    cout << "   Average amount of time spent waiting: " << double(waitSum) / numCustomers << endl;

    return 0;
}

void loadData(ArrayPriorityQueue<Event>& eventQ){    
    ifstream inFile(FILENAME);
    Event temp;

    while(inFile){
        inFile >> temp;
        if(inFile){
            eventQ.enqueue(temp);
        }
    }	
}

void processArrival(bool& teller, ArrayPriorityQueue<Event>& events, ArrayQueue<Event>& line){
    Event customer = events.peekFront();
    events.dequeue();

    if(line.isEmpty() && teller){
        int departureTime = customer.getTime() + customer.getDuration();
        Event departure(departureTime, 0, DEPARTURE);
        events.enqueue(departure);
        teller = false;
    }
    else{
        line.enqueue(customer);
    }
}

int processDeparture(bool& teller, ArrayPriorityQueue<Event>& events, ArrayQueue<Event>& line){
    Event current = events.peekFront();
    events.dequeue();
    int waitTime = 0;

    if(!line.isEmpty()){
        //customer gets to the teller
        Event customer = line.peekFront();
        line.dequeue();
        teller = false;

        //served time - arrival time
        waitTime = current.getTime() - customer.getTime();

        int departureTime = current.getTime() + customer.getDuration();
        Event departure(departureTime, 0, DEPARTURE);
        events.enqueue(departure);
    }
    else{
        teller = true;
    }
    return waitTime;
}
