/*
README.txt
Author: Cameron Garratt
Submission Date: 10/26/16
Purpose: This is the README that describes how to compile and run the project as well as other important information.
Statement of Academic Honesty:
The following code represents my own work. I have neither received nor given inappropriate assistance. I have not copied or modified code from any source other than the course webpage or the course textbook. I recognize that any unauthorized assistance or plagiarism will be handled in accordance with the University of Georgia's Academic Honesty Policy and the policies of this course. I recognize that my work is based on an assignment created by the Department of Computer Science at the University of Georgia. Any publishing or posting of source code for this project is strictly prohibited unless you have written consent from the Department of Computer Science at the University of Georgia.
*/

To compile the program, first enter the correct directory, then enter:

$ g++ -std=gnu++11 *.cpp

To run the program, first compile it, then enter:

$ ./a.out

To remove previously compiled progrems, enter:

$ rm a.out

If you would like to test the trees with types other than the
ones I have provided, you will need to modify the code. Simply
go into the TreeDr.cpp file and change the TreeType<int> to
TreeType<SOMETYPE>.
Additionally, you need to change the type of 
int item  to  SOMETYPE item



The implementation I have submitted is more efficiant that the
given files because I provide more functions to perform tasts
and to gain information about the tree. It also is different
in the implimentation of the delete function. In addition,
since TreeType is now a template, it can be used with more than 
one type.




Recursive Tree
Files:
TreeType.h      Contains the specification for class TreeType
TreeType.cpp    Contains the implementation for class TreeType
QueType.h       Contains the specification for class QueType
QueType.cpp     Contains the implementation for class QueType
TreeDr.cpp      Test driver for TreeType

The implementation defines three queues to store tree items according to traversal order.

preQue:  contains the tree items in preorder.
inQue:   contains the tree items in inorder.
postQue: contains the tree items in postorder.


