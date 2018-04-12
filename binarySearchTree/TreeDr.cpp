/*
TreeDr.cpp
Author: Cameron Garratt
Submission Date: 10/26/16
Purpose: This is the main driver for the TreeType.cpp. This tests the functions.
Statement of Academic Honesty:
The following code represents my own work. I have neither received nor given inappropriate assistance. I have not copied or modified code from any source other than the course webpage or the course textbook. I recognize that any unauthorized assistance or plagiarism will be handled in accordance with the University of Georgia's Academic Honesty Policy and the policies of this course. I recognize that my work is based on an assignment created by the Department of Computer Science at the University of Georgia. Any publishing or posting of source code for this project is strictly prohibited unless you have written consent from the Department of Computer Science at the University of Georgia.
*/
// Test driver
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
#include <cstring>
#include "TreeType.h"
#include "TreeType.cpp"
#include "QueType.cpp"

#include<iostream>

using namespace std;

// Function: Gets the array from the user 
// PreConditions: the user has selected 16
// PostConditions: An array has been returned containing the users
// desired insertions into the tree
void GetArray(vector<int>& vec);
void GetArray(vector<int>& vec) {
    cout << "Please enter a sorted array of integers." << endl;
    cout << "You may use the form: ";
    cout << "1,2,3,4,5,12,14,144,145\n" << endl;
    cout << "Enter array here: ";
    string input;
    string num;
    cin >> input;
    stringstream stream;
    stream.str(input);
    while(getline(stream, num, ',')){
        int n;
        istringstream(num) >> n;
        vec.push_back(n);
    }
}

// Function: Returns true if the tree is sorted, false otherwise
// PreConditions: the user has selected 16
// PostConditions: a bool value has been returned 
bool IsSorted(vector<int>* vec, int size);
bool IsSorted(vector<int>* vec, int size){
    if(size > 0) 
        for (int i = 0; i < size - 1; i++) 
            if(vec -> at(i) > vec -> at(1+i)) return false;
    return true;
}

// Function: Adds an item to the tree in the correct order so 
// that the tree has the minimum hight possible
// PreConditions:  the user has selected 16
// PostConditions: All the items have been added to the tree.
void AddItem(TreeType<int>& tree, int* array, int pivot);
void AddItem(TreeType<int>& tree, vector<int>* vec, int pivot){
    if(vec -> size() == 1) 
        tree.PutItem(vec -> at(0));
    //else if(pivot == 1) 
    else if(vec -> size() == 2) 
        for(auto &i : *vec) tree.PutItem(i);
    else{
        tree.PutItem(vec -> at(pivot));
        int newPivot = pivot/2;
        cout << "cats" << endl;
        vector<int> left(vec -> begin(),vec -> begin() + pivot);
        AddItem(tree, &left, newPivot);
        try{
        vector<int> right(vec -> begin() + pivot+1,vec -> end());
        AddItem(tree, &right, newPivot);
        }catch(exception ex){}
    }
}


// Function: Creates a new tree with the disired items in the tree, 
// then prints some usefull information about the items inserted into the tree
// PreConditions: The tree has been initialized and the user has selected 16
// PostConditions: the new tree has been created and the information
// about it is output to the screen 
void MakeTree(TreeType<int>& tree);
void MakeTree(TreeType<int>& tree){
	vector<int> vec;
    GetArray(vec);
    int size = vec.size();
    if(IsSorted(&vec, size)) {
        cout << endl;
        AddItem(tree, &vec, size/2);
        for(int i : vec){
            cout << "Finding ancestors for: " << i << endl;
            tree.Ancestors(i);
        }
    }else{
        cout << "This array was not sorted. "
             << "Please try again." << endl;
    }

}


// Function: Displays options to the user about the available 
// functions that they can use to test the program
// PreConditions: The program has been run
// PostConditions: The options have been displayed to the
// screen and the users input has been recorded.
void prompt(string& command);
void prompt(string& command){
    cout << "\n\nEnter commands\n " << 
        "1)  PutItem\n " << 
        "2)  DeleteItem\n " << 
        "3)  GetItem\n " << 
        "4)  GetLength\n "<<
        "5)  Is Empty\n " << 
        "6)  PrintTree\n " << 
        "7)  Reset Tree\n " <<
        "8)  Get Next Item\n " << 
        "9)  Is Full\n " << 
        "10) MakeEmpty\n " << 
        "11) PreOrderPrint\n " << 
        "12) InOrderPrint\n " << 
        "13) PostOrderPrint\n " << 
        "14) Ancestors\n " << 
        "15) Mirror\n " << 
        "16) MakeTree\n " << 
        "17) Quit\n" << endl;

    // getline(cin, command);
    cin >> command;
    cout << endl;
}


// Function: This is the main driver function of the program
// PreConditions: The user has run the program
// PostConditions: The program has been tested 
int main() {

    //Change these if you would like to test other types
    TreeType<int> tree;
    TreeType<int> mirrorImage;
    int item;

    string command;        // operation to be executed
    string orderItem;
    OrderType order;
    bool found;
    bool finished;


    // Prompt for Commands
    // Include all commands in the project
    prompt(command);

    while (command != "17") { 
        if (command == "1") {

            cout << "Enter Item to be inserted in the tree  ";
            cin >> item;
            tree.PutItem(item);
            cout << item;
            cout << " is inserted" << endl;

        } else if (command == "2") {

            cout << "Enter Item to be deleted: ";
            cin >> item;
            tree.DeleteItem(item);
            cout << item;
            cout << " is deleted" << endl;

        } else if (command == "3") {

            cin >> item;

            item = tree.GetItem(item, found);
            if (found){
                cout << item << " found in list." << endl;
            } else { 
                cout << item  << " not in list."  << endl; 
            }

        } else if (command == "4") {

            cout << "Number of nodes is " << tree.GetLength() << endl;

        } else if (command == "5") {

            if (tree.IsEmpty()) {
                cout << "Tree is empty." << endl;
            } else { 
                cout << "Tree is not empty."  << endl;  
            }

        } else if (command == "6") {

            tree.Print();
            cout << endl;

        }  else if (command == "7") {

            cout << "Enter Order: PRE_ORDER or IN_ORDER or POST_ORDER ";
            cin >> orderItem;
            if (orderItem == "PRE_ORDER"){
                order = PRE_ORDER;
            } else if (orderItem == "IN_ORDER") {
                order = IN_ORDER;
            } else {
                order = POST_ORDER; 
            }
            tree.ResetTree(order);

        } else if (command == "8") {

            cout << "Enter Order: PRE_ORDER or IN_ORDER or POST_ORDER ";
            cin >> orderItem;
            if (orderItem == "PRE_ORDER"){
                order = PRE_ORDER;
            } else if (orderItem == "IN_ORDER") {
                order = IN_ORDER;
            } else { 
                order = POST_ORDER;    
            }
            item = tree.GetNextItem(order,finished);
            cout << "Next item is: " << item << endl;
            if (finished) {
                cout<< orderItem << " traversal is complete." << endl;
            }

        } else if (command == "9") { 

            if (tree.IsFull()){
                cout << "Tree is full."  << endl;
            } else { 
                cout << "Tree is not full." << endl;  
            }

        } else if (command == "10") {

            tree.MakeEmpty();
            cout << "Tree has been made empty." << endl;

        } else if (command == "11") {

            cout << "\nPreOrder Print\n--------------\n" << endl;
            tree.PreOrderPrint();
            cout << endl;

        } else if (command == "12") {

            cout << "\nInOrder Print\n-------------\n" << endl;
            tree.InOrderPrint();
            cout << endl;

        } else if (command == "13") {

            cout << "\nPostOrder Print\n---------------\n" << endl;
            tree.PostOrderPrint();
            cout << endl;

        } else if (command == "14") {

            cout << "Enter the value you would like to find the "
                << "ancestors of. " << endl;
            cin >> item;
            tree.Ancestors(item);

        } else if (command == "15") {


            if(tree.IsEmpty()) {
                cout << "The tree is empty. Add some values before "
                     << "creating a mirror image. " << endl;
            }else{
                mirrorImage = tree.MirrorImage();
                cout << "\nOriginal Tree PreOrder:\t  ";
                tree.PreOrderPrint();
                cout << "\nOriginal Tree InOrder:\t  ";
                tree.InOrderPrint();
                cout << "\nOriginal Tree PostOrder:  ";
                tree.PostOrderPrint();
                cout << "\nMirror Image PreOrder:    ";
                mirrorImage.PreOrderPrint();
                cout << "\nMirror Image InOrder:\t  ";
                mirrorImage.InOrderPrint();
                cout << "\nMirror Image PostOrder:   ";
                mirrorImage.PostOrderPrint();
                cout << endl << endl;
            }

        } else if (command == "16") {

            TreeType<int> newTree;
            cout << "\nMaking new Tree:\n----------------\n\n";
            MakeTree(newTree);
            cout << "\nNew Tree PreOrder:  ";
            newTree.PreOrderPrint();
            cout << "\nNew Tree InOrder:   ";
            newTree.InOrderPrint();
            cout << "\nNew Tree PostOrder: ";
            newTree.PostOrderPrint();

            

        } else { 

            cout << command << " Command not recognized." << endl;

        }
        cout <<  "\n\nCommand is completed."  << endl;
        prompt(command);
    }

    cout << "Testing completed."  << endl;

    return 0;
}





