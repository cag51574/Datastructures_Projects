/*
TreeType.h
Author: Cameron Garratt
Submission Date: 10/26/16
Purpose: This is the header file for TreeType. This states the functions that are implimented in TreeType.cpp
Statement of Academic Honesty:
The following code represents my own work. I have neither received nor given inappropriate assistance. I have not copied or modified code from any source other than the course webpage or the course textbook. I recognize that any unauthorized assistance or plagiarism will be handled in accordance with the University of Georgia's Academic Honesty Policy and the policies of this course. I recognize that my work is based on an assignment created by the Department of Computer Science at the University of Georgia. Any publishing or posting of source code for this project is strictly prohibited unless you have written consent from the Department of Computer Science at the University of Georgia.
*/
#ifndef TREETYPE_H
#define TREETYPE_H
#include <string>
#include <fstream>
#include <iostream>
#include "QueType.h"
//#include "QueType.cpp"

//typedef int ItemType;
template <class ItemType>
struct TreeNode;
enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};

template <class ItemType>
class TreeType
{
public:
  TreeType();                     // constructor
  ~TreeType();                    // destructor
  TreeType(const TreeType& originalTree); 
  void operator=(const TreeType& originalTree);
  // copy constructor
  void MakeEmpty();
  bool IsEmpty() const;
  bool IsFull() const;
  int GetLength() const; 
  ItemType GetItem(ItemType item, bool& found);
  void PutItem(ItemType item);
  void DeleteItem(ItemType item);
  void ResetTree(OrderType order); 
  ItemType GetNextItem(OrderType order, bool& finished);
  void Print() const;
  void PreOrderPrint() const;
  void InOrderPrint() const;
  void PostOrderPrint() const;
  void Ancestors(ItemType value) const;
  TreeType<ItemType> MirrorImage();
private:
  TreeNode<ItemType>* root;
  QueType<ItemType> preQue;
  QueType<ItemType> inQue;
  QueType<ItemType> postQue;
};

#endif
