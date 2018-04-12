/*
BankSimulationTest.cpp
Author: Cameron Garratt
Submission Date: 10/7/16
Purpose: The BankSimulationTest.cpp file has the implimentation of the bank simulation test that was described in the project description. It takes a command line argument of the input file and outputs the customer information about their wait time and departure times to the screen. This is assuming that the input file has the correct format as dectribed in the project description.
Statement of Academic Honesty:
The following code represents my own work. I have neither received nor given inappropriate
assistance. I have not copied or modified code from any source other than the course webpage or
the course textbook. I recognize that any unauthorized assistance or plagiarism will be handled in
accordance with the University of Georgia's Academic Honesty Policy and the policies of this
course. I recognize that my work is based on an assignment created by the Department of
Computer Science at the University of Georgia. Any publishing or posting of source code for this
project is strictly prohibited unless you have written consent from the Department of Computer
Science at the University of Georgia.
*/
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "priorityqueue.h"
#include "queuetype.h"
using namespace std;

void bankSimulation(QueueType<string>& q1, const int& numberOfTellers);
bool putFileIntoQueue(QueueType<string>& q1, char* args);
int getNumberOfTellers(QueueType<string>& q1);
void printCustomerInfo(QueueType<string>& q1, PriorityQueue<string>& pqueue, int nextToLeave);


int main(int argc, char *argv[]){
//function: Main fuction takes a file name as an input and runs simulation
//pre-condition: The file name containing customer information is given as 
//                  program input.
//post-condition: The program is run. If the correct input was given the program
//                  outputs the desired results. Otherwise, the program exits.
    if(argc != 2){
        cout << "Incorrect number of command line arguments"
            << ". Please Try again." << endl;
        return 0;
    }else{
        QueueType<string> q1;
        if(putFileIntoQueue(q1,argv[1])){
            if(!q1.isEmpty()){
                bankSimulation(q1, getNumberOfTellers(q1));
            }else{
                cout << "There was nothing in that file. "
                    << "Please try again." << endl;
            }
        }else{
            cout << "Unable to open that file. "
                << "Please try again." << endl;
        }
    }
    return 0;
}

void bankSimulation(QueueType<string>& unprocessedCustomers,const int& numberOfTellers){
//function: This is the main simulation. This takes a queue of unprocessed customers
//              and the number of tellers and produces the requeired output.
//pre-condition: The function is called with a queue containing all of the unprocessed  
//              customers and the number of tellers. The queue can not be empty and
//              the number of tellers can not be 0.
//post-condition: The simulation has been run and the output of the amount of time
//              each customer had to wait and their departure time is output to the screen
    PriorityQueue<string> pqueue;
    QueueType<string> customersWaitingInLine;
    int tellersAvailable = numberOfTellers;  
    int nextToLeave;
    while(!(unprocessedCustomers.isEmpty()
          && customersWaitingInLine.isEmpty())){
        if(tellersAvailable > 0){
            //No customers in line
            if(customersWaitingInLine.isEmpty()){
                printCustomerInfo(unprocessedCustomers, pqueue, 0);
                tellersAvailable--;
            }else{
            //There are customers in line
                printCustomerInfo(customersWaitingInLine, pqueue, nextToLeave);
                tellersAvailable--;
            }
        }else{
            customersWaitingInLine.enqueue(unprocessedCustomers.dequeue());
            nextToLeave = pqueue.peekPriority();
            pqueue.dequeue();
            tellersAvailable++;
        }
    }
}
            
    
    

bool putFileIntoQueue(QueueType<string>& q1,char* args){
//function: Opens the input file and reads all the information line by
//              line into a queue.
//pre-condition: The file name is the name of the file containing the
//              input information as described by the project descripion
//post-condition: The file has been opened and the contents read and inserted
//              into the queue. Then the file has been closed.
    bool flag = false;
    string line;
    ifstream myFile(args);
    if(myFile.is_open()){
        while(getline(myFile,line)){
            q1.enqueue(line);
        }
        flag = true;
    }
    myFile.close();
    return flag;
}

int getNumberOfTellers(QueueType<string>& q1){
//function: returns the number of tellers, which should be the first
//          item that the queue contains
//pre-condition: The queue contains the informaition from the file 
//          exactly as the project description describes so that 
//          the line containing the number of tellers is the first line.
//post-condition: The first line of the queue has been read and the 
//          number of tellers is extracted from that and returned.
    int numberOfTellers;
    string s;
    stringstream stream(q1.dequeue());
    stream >> s >> numberOfTellers;
    return numberOfTellers;
}


void printCustomerInfo(QueueType<string>& q1, PriorityQueue<string>& pqueue, int nextToLeave){
//function: Prints out the customer information that is passed to it, then
//          adds that customers departure time to the priority queue.
//pre-condition: The queue contains the customer information. The 
//          priority queue contains the already current departure time of the 
//          next customer. The next to leave is the departure time of the next
//          customer to leave.
//post-condition: The customer info has been printed to the screen and that 
//          customer has then been added to the priority queue.
    string name;
    int arrivalTime;
    int serviceTime;
    string s;
    stringstream stream(q1.dequeue());
    stream >>  name >> s >> arrivalTime >> s >> serviceTime;
    int wait;
    if(nextToLeave - arrivalTime > 0){
        wait = nextToLeave - arrivalTime ;
    }else{
        wait = 0;
    }
    cout << name << ": "<< wait << " wait and service ";
    cout << wait + arrivalTime + serviceTime << endl;
    pqueue.enqueue(name, arrivalTime+serviceTime + wait);
} 

