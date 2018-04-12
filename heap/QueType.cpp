/*
QueType.cpp
Author: Cameron Garratt
Submission Date: 10/26/16
Purpose: This is the implimentation file for QueType. All of the functions for a queue are implimented here.
Statement of Academic Honesty:
The following code represents my own work. I have neither received nor given inappropriate assistance. I have not copied or modified code from any source other than the course webpage or the course textbook. I recognize that any unauthorized assistance or plagiarism will be handled in accordance with the University of Georgia's Academic Honesty Policy and the policies of this course. I recognize that my work is based on an assignment created by the Department of Computer Science at the University of Georgia. Any publishing or posting of source code for this project is strictly prohibited unless you have written consent from the Department of Computer Science at the University of Georgia.
*/
#include <iostream>
#include <cstddef>                 // For NULL
#include <new>                     // For bad_alloc
#include "QueType.h"

template<class ItemType>
struct NodeType {
  ItemType info;
  NodeType<ItemType>* next;
};



// Post:  front and rear are set to NULL.
template<class ItemType>
QueType<ItemType>::QueType() {         // Class constructor.
  front = NULL;
  rear = NULL;
}


// Post: Queue is empty; all elements have been deallocated.
template<class ItemType>
void QueType<ItemType>::MakeEmpty() {
  NodeType<ItemType>* tempPtr;

    while (front != NULL)
  {
    tempPtr = front;
    front = front->next;
    delete tempPtr;
  }
  rear = NULL;
}

          // Class destructor.
template<class ItemType>
QueType<ItemType>::~QueType()
{
  MakeEmpty();
}


// Returns true if there is no room for another ItemType 
//  on the free store; false otherwise.
template<class ItemType>
bool QueType<ItemType>::IsFull() const {
  NodeType<ItemType>* location;
  try
  {
    location = new NodeType<ItemType>;
    delete location;
    return false;
  }
  catch(std::bad_alloc)
  {
    return true;
  }
}


// Returns true if there are no elements on the queue; false otherwise.
template<class ItemType>
bool QueType<ItemType>::IsEmpty() const {
  return (front == NULL);
}


// Adds newItem to the rear of the queue.
// Pre:  Queue has been initialized.
// Post: If (queue is not full) newItem is at the rear of the queue;
//       otherwise a FullQueue exception is thrown.  
template<class ItemType>
void QueType<ItemType>::Enqueue(ItemType newItem) {
  if (IsFull())
    throw FullQueue();
  else
  {
    NodeType<ItemType>* newNode;

    newNode = new NodeType<ItemType>;
    newNode->info = newItem;
    newNode->next = NULL;
    if (rear == NULL)
      front = newNode;
    else
      rear->next = newNode;
    rear = newNode;
  }
}


// Removes front item from the queue and returns it in item.
// Pre:  Queue has been initialized and is not empty.
// Post: If (queue is not empty) the front of the queue has been 
//       removed and a copy returned in item; 
//       othersiwe a EmptyQueue exception has been thrown.
template<class ItemType>
void QueType<ItemType>::Dequeue(ItemType& item) {
  if (IsEmpty())
    throw EmptyQueue();
  else {
    NodeType<ItemType>* tempPtr;

    tempPtr = front;
    item = front->info;
    front = front->next;
    if (front == NULL)
      rear = NULL;
    delete tempPtr;
  }
}

template<class ItemType>
QueType<ItemType>::QueType (const QueType<ItemType>& anotherQue){
  NodeType<ItemType>* ptr1;
  NodeType<ItemType>* ptr2;
  
  if (anotherQue.front == NULL)
    front = NULL;
  else {
    front = new NodeType<ItemType>;
    front->info = anotherQue.front->info;
    ptr1 = anotherQue.front->next;
    ptr2 = front;
    while (ptr1 != NULL) {
      ptr2->next = new NodeType<ItemType>;
      ptr2 = ptr2->next;
      ptr2->info = ptr1->info;
      ptr1 = ptr1->next;
    }
    ptr2->next = NULL;
    rear = ptr2;
  }    
}

