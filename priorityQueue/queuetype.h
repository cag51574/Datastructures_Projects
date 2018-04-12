/*
queuetype.h
Author: Cameron Garratt
Submission Date: 10/7/16
Purpose: The queuetype.h file has the header and impliementation of the queuetype template.
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
using namespace std;

template<class ItemType>
struct Node{
    Node<ItemType>* next;
    ItemType info;
};

template<class ItemType>
class QueueType{
public:
    QueueType(); 
    ~QueueType(); 
    void enqueue(ItemType value);
    ItemType dequeue();
    void makeEmpty();
    bool isEmpty() const;
    bool isFull() const;
    void printQueue() const;
private: 
    Node<ItemType>* qFront;
    Node<ItemType>* qRear;
};


template<class ItemType>
QueueType<ItemType>::QueueType(){
//function: Constructor for queue. Initializes queue.
//pre-condition: The queue has not been initialized.
//post-condition: The queue has now been initialized.
    qFront = NULL;
    qRear = NULL;
} 

template<class ItemType>
QueueType<ItemType>::~QueueType(){
//function: Deconstructor for queue. Deletes queue.
//pre-condition: The queue has been initialized.
//post-condition: The queue is now empty.
    makeEmpty();
} 

template<class ItemType>
void QueueType<ItemType>::enqueue(ItemType item){
//function: Adds an item to the end of the queue.
//pre-condition: The queue has been initialized.
//post-condition: The queue has a new item added to the end. 
    Node<ItemType>* newNode;
    newNode = new Node<ItemType>;
    newNode -> info = item;
    newNode -> next = NULL;
    if(qRear == NULL){
        qFront = newNode;
    }else{
        qRear -> next = newNode;
    }   
    qRear = newNode;
}

template<class ItemType>
ItemType QueueType<ItemType>::dequeue(){
//function: The first item in the queue is removed from the 
//          queue and then returned.
//pre-condition: The queue has been initialized and is not empty.
//post-condition: The first item of the queue has been removed
//          and returned.
    Node<ItemType>* temp;
    temp = qFront;
    ItemType item = qFront -> info;
    qFront = qFront -> next;
    if(qFront == NULL){
        qRear = NULL;
    }
    delete temp;
    return item;
}

template<class ItemType>
void QueueType<ItemType>::makeEmpty(){
//function: Removes all items in the queue.
//pre-condition: The queue has been initialized.
//post-condition: The queue is now empty.
    Node<ItemType>* temp;
    while(qFront != NULL){
        temp = qFront;
        qFront = qFront->next;
        delete temp;
    }
    qRear = NULL;
}

template<class ItemType>
bool QueueType<ItemType>::isEmpty() const{
//function: Returns true if the queue is empty. False otherwise.
//pre-condition: The queue has been initialized.
//post-condition: If the queue is empty, true is returned,
//                  false otherwise.
    return qFront == NULL;
}

template<class ItemType>
bool QueueType<ItemType>::isFull() const{
//function: Returns true if the queue is full. False otherwise.
//pre-condition: The queue has been initialized.
//post-condition: If the queue is full, true is returned, 
//                  false otherwise.
    Node<ItemType>* newNode;
    newNode = new Node<ItemType>;
    if(newNode == NULL){
        return true;
    }else{
        delete newNode;
        return false;
    }
}


template<class ItemType>
void QueueType<ItemType>::printQueue() const{
//function: Prints out the queue information
//pre-condition: The queue has been initialized.
//post-condition: The information about the queue has
//                  been output to the screen.
    if(isEmpty()){
        std::cout << "The queue is empty" << std::endl;
    }else{
        Node<ItemType>* curLoc; 
        curLoc = qFront;
        bool flag = true;
        while(flag){
            if(curLoc == qFront){
                std::cout <<  "["; 
            }
            std::cout << curLoc -> info;
            if(curLoc != qRear){
             cout << ","; 
            }
            if(curLoc == qRear){
                std::cout << "]"; 
                flag = false;
            }else{
                curLoc = curLoc -> next;
            }
        }
        std::cout << std::endl;
    }
}




