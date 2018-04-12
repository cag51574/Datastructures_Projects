// Test driver

#include <string>
#include <cctype>
#include <cstring>

#include "TreeType.h"
#include<iostream>
using namespace std;

int main()
{

 
  int command;        // operation to be executed
  
  int item;
  string orderItem;
  TreeType tree;
  OrderType order;
  bool found;
  bool finished;
  int numCommands;


  // Prompt for Commands
  // Include all commands in the project
  cout<< "Enter commands\n 1) PutItem\n 2) DeleteItem\n 3) GetItem\n 4) GetLength\n"<<
	  " 5) Is Empty\n 6) PrintTree\n 7) Reset Tree\n  8) Get Next Item\n 9) Is Full\n 10) MakeEmpty\n 11) Mirror\n 12) Quit" << endl;
  cin >> command;

 
  
  while (command != 12)
  { 
    if (command == 1)
    {
		cout << "Enter Item to be inserted in the tree  ";
		cin >> item;
      tree.PutItem(item);
      cout << item;
      cout << " is inserted" << endl;
    }
    else if (command == 2)
    {
		cout << "Enter Item to be deleted";
		cin >> item;
      tree.DeleteItem(item);
      cout << item;
      cout << " is deleted" << endl;
    }
    else if (command == 3)
    {
      cin >> item;

      item = tree.GetItem(item, found);
      if (found)
        cout << item << " found in list." << endl;
      else cout << item  << " not in list."  << endl;  
    } 
    else if (command == 4)  
      cout << "Number of nodes is " << tree.GetLength() << endl;
    else if (command == 5)
      if (tree.IsEmpty())
        cout << "Tree is empty." << endl;
      else cout << "Tree is not empty."  << endl;  
  
    else if (command == 6)
    {
      tree.Print();
      cout << endl;
    }  
    else if (command == 7)
    {
		cout << "Enter Order: PRE_ORDER or IN_ORDER or POST_ORDER ";
		cin >> orderItem;
      if (orderItem == "PRE_ORDER")
        order = PRE_ORDER;
      else if (orderItem == "IN_ORDER")
        order = IN_ORDER;
      else order = POST_ORDER;    
         
      tree.ResetTree(order);
    }
    else if (command == 8)
    {
		cout << "Enter Order: PRE_ORDER or IN_ORDER or POST_ORDER ";
		cin >> orderItem;
      if (orderItem == "PRE_ORDER")
        order = PRE_ORDER;
      else if (orderItem == "IN_ORDER")
        order = IN_ORDER;
      else order = POST_ORDER;    
      item = tree.GetNextItem(order,finished);
      cout << "Next item is: " << item << endl;
      if (finished)
        cout<< orderItem << " traversal is complete." << endl;
    }     
    else if (command == 9)
      if (tree.IsFull())
        cout << "Tree is full."  << endl;
      else cout << "Tree is not full." << endl;  
    else if (command == 10)
    {
      tree.MakeEmpty();
   cout << "Tree has been made empty." << endl;
    }  
	else cout << " Command not recognized." << endl;
    cout <<  " Command is completed."  << endl;
	cout<< "Enter commands\n 1) PutItem\n 2) DeleteItem\n 3) GetItem\n 4) GetLength\n"<<
	  " 5) Is Empty\n 6) PrintTree\n 7) Reset Tree\n  8) Get Next Item\n 9) Is Full\n 10) MakeEmpty\n 11) Mirror\n 12) Quit" << endl;
    cin >> command;
  }
 
  cout << "Testing completed."  << endl;
 
  return 0;
}




