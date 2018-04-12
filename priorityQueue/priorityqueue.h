/*
priorityqueue.h
Author: Cameron Garratt
Submission Date: 10/7/16
Purpose: The priorityqueue.h file has the header and impliementation of the priorityqueue template.
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

template<class ItemType>
struct NodeType{
    NodeType<ItemType>* next;
    ItemType info;
    int priority;
};


template<class ItemType>
class PriorityQueue{
public:
    PriorityQueue(); 
    ~PriorityQueue(); 
    void enqueue(ItemType value, int priority);
    ItemType dequeue();
    void clear();
    ItemType peek() const;
    int peekPriority() const;
    int size() const;
    bool isEmpty() const;
    bool isFull() const;
    void printQueue() const;
private: 
    NodeType<ItemType>* qFront;
    NodeType<ItemType>* qRear;
};


template<class ItemType>
PriorityQueue<ItemType>::PriorityQueue(){
//function: Constructor for queue. Initializes queue.
//pre-condition: The queue has not been initialized.
//post-condition: The queue has now been initialized.
    qFront = NULL;
    qRear = NULL;
} 

template<class ItemType>
PriorityQueue<ItemType>::~PriorityQueue(){
//function: Deconstructor for queue. Deletes queue.
//pre-condition: The queue has been initialized.
//post-condition: The queue is now empty.
    clear();
} 

template<class ItemType>
void PriorityQueue<ItemType>::enqueue(ItemType value, int priority){
//function: Adds an item to the the queue in the order of priority.
//pre-condition: The queue has been initialized.
//post-condition: The queue has a new item added in the correct order. 
    if(!isFull()){
        NodeType<ItemType>* newNode;
        newNode = new NodeType<ItemType>;
        newNode -> info = value;
        newNode -> priority = priority;
        newNode -> next = NULL;
        if(isEmpty()){
            qFront = newNode;
            qRear = newNode;
        }else{
//    std::cout << "cats3" << std::endl;
            NodeType<ItemType>* curLoc;
            curLoc = qFront;
            //If priority is less than or equal to the starting priority
            //Then make newNode the new qFront
            if(newNode -> priority <= curLoc -> priority){
                newNode -> next = qFront;
                qFront = newNode;
            //Priority must be greater than qFront's priority
            }else{
                bool flag = true;
                while(flag && ((curLoc -> next) != NULL)){
                    if(newNode -> priority > (curLoc -> next) -> priority){
                        curLoc = curLoc -> next;
                    }else{
                        newNode -> next = curLoc -> next;
                        curLoc -> next = newNode;
                        flag = false;
                    }
                }
                if(curLoc -> next == NULL){
                    curLoc -> next = newNode;
                    qRear = newNode;
                }
            }
        }
    }
}

template<class ItemType>
ItemType PriorityQueue<ItemType>::dequeue(){
//function: The first item in the queue is removed from the 
//          queue and then returned.
//pre-condition: The queue has been initialized.
//post-condition: The first item of the queue has been removed
//          and returned.
    //If the priority queue is empty
    if(isEmpty()){
        return NULL;
    }else{
        NodeType<ItemType>* temp;
        ItemType result;
        result = qFront -> info;
        temp = qFront;
        //If the priority queue only has one item
        if(qFront -> next == NULL){
            qFront = NULL; 
            qRear= NULL; 
        }else{
            qFront = qFront -> next;
            delete temp;
        }
        return result;
    }
}

template<class ItemType>
void PriorityQueue<ItemType>::clear(){
//function: Removes all items in the queue.
//pre-condition: The queue has been initialized.
//post-condition: The queue is now empty.
    NodeType<ItemType>* temp;
    while(qFront != NULL){
        temp = qFront;
        qFront = qFront-> next;
        delete temp;
    }
    qRear = NULL;
}

template<class ItemType>
ItemType PriorityQueue<ItemType>::peek() const{
//function: Returns the value at the front of the queue
//          without changing the queue.
//pre-condition: The queue has been initialized.  //post-condition: The front value has been returned.
    if(isEmpty()){
        return NULL;
    }else{
        return qFront -> info;
    }
}

template<class ItemType>
int PriorityQueue<ItemType>::peekPriority() const{
//function: Returns the priority at the front of the queue
//          without changing the queue.
//pre-condition: The queue has been initialized.
//post-condition: The front priority has been returned.
    if(isEmpty()){
        return 0;
    }else{
        return qFront -> priority;
    }
}

template<class ItemType>
int PriorityQueue<ItemType>::size() const{
//function: Returns the size of the priority queue
//          without changing the queue.
//pre-condition: The queue has been initialized.
//post-condition: The size has been returned.
    if(!isEmpty()){
        NodeType<ItemType>* curLoc;
        curLoc = qFront;
        int count = 1;
        int maxPriority = curLoc -> priority;
        while(curLoc != qRear){
            if(curLoc -> priority < maxPriority){
                return count;
            }
            count++;
            maxPriority = curLoc -> priority;
            curLoc = curLoc -> next;
        }
        return count;
    }else{
        return 0;
    }
}

template<class ItemType>
bool PriorityQueue<ItemType>::isEmpty() const{
//function: Returns true if the queue is empty. False otherwise.
//pre-condition: The queue has been initialized.
//post-condition: If the queue is empty, true is returned,
//                  false otherwise.
    return qFront == NULL;
}

template<class ItemType>
bool PriorityQueue<ItemType>::isFull() const{
//function: Returns true if the queue is full. False otherwise.
//pre-condition: The queue has been initialized.
//post-condition: If the queue is full, true is returned, 
//                  false otherwise.
    NodeType<ItemType>* newNode;
    newNode = new NodeType<ItemType>;
    if(newNode == NULL){
        return true;
    }else{
        delete newNode;
        return false;
    }
}

template<class ItemType>
void PriorityQueue<ItemType>::printQueue() const{
//function: Prints out the queue information
//pre-condition: The queue has been initialized.
//post-condition: The information about the queue has
//                  been output to the screen.
    if(isEmpty()){
        std::cout << "The queue is empty" << std::endl;
    }else{
        NodeType<ItemType>* curLoc; 
        curLoc = qFront;
        bool flag = true;
        while(flag){
            std::cout <<  "["; 
            std::cout << curLoc -> info << ","; 
            std::cout << curLoc -> priority;
            //std::cout << "],"; 
            if(curLoc == qRear){
                std::cout << "]"; 
                flag = false;
            }else{
                std::cout << "],"; 
                curLoc = curLoc -> next;
            }
        }
        std::cout << std::endl;
    }
}



    
    
