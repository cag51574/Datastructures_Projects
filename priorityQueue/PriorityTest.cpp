/*
PriorityTest.cpp
Author: Cameron Garratt
Submission Date: 10/7/16
Purpose: The PriorityTest.cpp file has the implimentation of the priority test that tests tha priority queue to see if the queue works as described in the project description. To see how to use this file, read the comments or the README.
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
#include "priorityqueue.h"
using namespace std;

int main(){
//function: Main fuction runs test functions for priorityqueue.h to see if
//          it contains any errors.
//pre-condition: priorityqueue.h is in the same directory as PriorityTest.cpp
//post-condition: The test functions are run and the output is displayed
//                  to the screen.
    cout << "Creates new PQueue containing ints"<< endl;
    PriorityQueue<int> p1;
    p1.printQueue();
    cout << "Enqueue a bunch of values into queue"<< endl;
    for(int i = 0; i <= 10; i++){
        p1.enqueue(i,10-i);
        p1.printQueue();
    }
    cout << "Clear Priority Queue"<< endl;
    cout << p1.size() << endl;
    p1.clear();
    p1.printQueue();
    cout << "Enqueue more items into PQueue"<< endl;
    for(int i = 0; i <= 10; i++){
        p1.enqueue(i,i);
        p1.printQueue();
    }
    cout << "Dequeue those items"<< endl;
    for(int i = 0; i <= 10; i++){
        int thing = p1.dequeue();
        p1.printQueue();
    }
    p1.~PriorityQueue();
    cout << "Creates new PQueue containing chars"<< endl;
    PriorityQueue<char> p2;
    p2.printQueue();
    cout << "The following is the requested sample output from the project description."<< endl;
    p2.enqueue('C', 2);
    p2.printQueue();
    p2.enqueue('D', 4);
    p2.printQueue();
    p2.enqueue('A', 1);
    p2.printQueue();
    p2.enqueue('B', 3);
    p2.printQueue();
    p2.dequeue();
    p2.printQueue();
    cout << p2.peek() << endl;
    cout << p2.peekPriority() << endl;
    p2.dequeue();
    p2.printQueue();
    
    return 0;    
}


