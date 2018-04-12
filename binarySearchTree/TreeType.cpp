/*
TreeType.cpp
Author: Cameron Garratt
Submission Date: 10/26/16
Purpose: This is the TreeType implimentation that defines all the functions for the recursive binary tree.
Statement of Academic Honesty:
The following code represents my own work. I have neither received nor given inappropriate assistance. I have not copied or modified code from any source other than the course webpage or the course textbook. I recognize that any unauthorized assistance or plagiarism will be handled in accordance with the University of Georgia's Academic Honesty Policy and the policies of this course. I recognize that my work is based on an assignment created by the Department of Computer Science at the University of Georgia. Any publishing or posting of source code for this project is strictly prohibited unless you have written consent from the Department of Computer Science at the University of Georgia.
*/
#include<iostream>
#include "TreeType.h"
//#include "QueType.h"

using namespace std;

template<class ItemType>
struct TreeNode {
    ItemType info;
    TreeNode<ItemType>* left;
    TreeNode<ItemType>* right;
};

// Function: Returns true if there is no room for another item 
//  on the free store; false otherwise.
// PreConditions: The tree has been initialized
// PostConditions: If the tree is full, true, otherwise, false.
template<class ItemType>
bool TreeType<ItemType>::IsFull() const {
    TreeNode<ItemType>* location;
    try {
        location = new TreeNode<ItemType>;
        delete location;
        return false;
    } catch(std::bad_alloc exception) {
        return true;
    }
}

// Function: Returns true if the tree is empty; false otherwise.
// PreConditions: The tree has been initialized
// PostConditions: Whether or not the tree is empty is returned
template<class ItemType>
bool TreeType<ItemType>::IsEmpty() const {
    return root == NULL;
}


template<class ItemType>
int CountNodes(TreeNode<ItemType>* tree);

// Function: Calls recursive function CountNodes to count the 
// nodes in the tree.
// PreConditions: The tree has been initialized
// PostConditions: The lenght is returned
template<class ItemType>
int TreeType<ItemType>::GetLength() const {
    return CountNodes(root);
}


// Function: Counts the number of nodes and returns that number
// PreConditions: The tree has been initialized
// PostConditions: returns the number of nodes in the tree.
template<class ItemType>
int CountNodes(TreeNode<ItemType>* tree) {
    if (tree == NULL)
        return 0;
    else 
        return CountNodes(tree->left) + CountNodes(tree->right) + 1;
}

template<class ItemType>
void Retrieve(TreeNode<ItemType>* tree, ItemType& item, bool& found);

// 
// Function: Calls recursive function Retrieve to search 
// the tree for item.
// PreConditions: The tree has been initialized
// PostConditions: An item is returned.
template<class ItemType>
ItemType TreeType<ItemType>::GetItem(ItemType item, bool& found) {
    Retrieve(root, item, found);
    return item;
}


// Function: Recursively searches tree for item.
// PreConditions: The tree has been initialized
// PostConditions: If there is an element someItem whose key matches item's,
//       found is true and item is set to a copy of someItem; 
//       otherwise found is false and item is unchanged.
template<class ItemType>
void Retrieve(TreeNode<ItemType>* tree, ItemType& item, bool& found) {
    if (tree == NULL)
        found = false;                     // item is not found.
    else if (item < tree->info)      
        Retrieve(tree->left, item, found); // Search left subtree.
    else if (item > tree->info)
        Retrieve(tree->right, item, found);// Search right subtree.
    else {
        item = tree->info;                 // item is found.
        found = true;
    }
} 

template<class ItemType>
void Insert(TreeNode<ItemType>*& tree, ItemType item);

// Function: Calls recursive function Insert to insert item into tree.
// PreConditions: The tree has been initialized
// PostConditions: Item has been put into tree
template<class ItemType>
void TreeType<ItemType>::PutItem(ItemType item) {
    Insert(root, item);
}


// Function: Inserts item into tree.
// PreConditions: The tree has been initialized
// PostConditions: item is in tree; search property is maintained.
template<class ItemType>
void Insert(TreeNode<ItemType>*& tree, ItemType item) {
    if (tree == NULL) {
        // Insertion place found.
        tree = new TreeNode<ItemType>;
        tree->right = NULL;
        tree->left = NULL;
        tree->info = item;
    } else if (item < tree->info){
        Insert(tree->left, item);    // Insert in left subtree.
    } else {
        Insert(tree->right, item);   // Insert in right subtree.
    }
} 

template<class ItemType>
void DeleteNode(TreeNode<ItemType>*& tree);

template<class ItemType>
void Delete(TreeNode<ItemType>*& tree, ItemType item);

// Function: Calls recursive function Delete to delete item from tree.
// PreConditions: The tree has been initialized
// PostConditions: Deletes an item out of the tree
template<class ItemType>
void TreeType<ItemType>::DeleteItem(ItemType item) {
    bool found = false;
    GetItem(item, found);
    if (found)
        Delete(root, item);
    else
        cout << item << "is not in tree\n";
}


// Function: Deletes item from tree.
// PreConditions: The tree has been initialized
// PostConditions: item is not in tree.
template<class ItemType>
void Delete(TreeNode<ItemType>*& tree, ItemType item) {
    if (item < tree->info)
        Delete(tree->left, item);   // Look in left subtree.
    else if (item > tree->info)
        Delete(tree->right, item);  // Look in right subtree.
    else
        DeleteNode(tree);           // Node found; call DeleteNode.
}   

template<class ItemType>
void GetPredecessor(TreeNode<ItemType>* tree, ItemType& data);

// Function: Deletes the node pointed to by tree.
// PreConditions: The tree has been initialized
// PostConditions: The user's data in the node pointed to by tree is no 
//       longer in the tree.  If tree is a leaf node or has only 
//       non-NULL child pointer the node pointed to by tree is 
//       deleted; otherwise, the user's data is replaced by its 
//       logical predecessor and the predecessor's node is deleted.
template<class ItemType>
void DeleteNode(TreeNode<ItemType>*& tree) {
    TreeNode<ItemType>* tempPtr;
    tempPtr = tree;
    if (tree->left == NULL) {
        tree = tree->right;
        delete tempPtr;
    } else if (tree->right == NULL) {
        tree = tree->left;
        delete tempPtr;
    } else {
        tree -> info = PtrToSuccessor(tempPtr -> right);
        Delete(tree -> right, tree -> info);
    }
}

// Function: returns an itemtype that is the next logical 
// successor of the node to be deleted
// PreConditions: The tree has been initialized
// PostConditions: The item that is the next logical successor is returned
template<class ItemType>
ItemType PtrToSuccessor(TreeNode<ItemType>* succ){
    while (succ->left!= NULL)
        succ = succ->left;
    return succ -> info;
}

// Function: Prints info member of items in tree in sorted order on screen.
// PreConditions: The tree has been initialized 
// PostConditions:Recursively calls itself to print items in the tree.
template<class ItemType>
void PrintTree(TreeNode<ItemType>* tree) {
    if (tree != NULL) {
        PrintTree(tree->left);   // Print left subtree.
        cout << tree->info<<"  ";
        PrintTree(tree->right);  // Print right subtree.
    }
}

// Function: The tree has been printed to the screen
// PreConditions: the tree has been initialized
// PostConditions:Calls recursive function Print to print items in the tree.
template<class ItemType>
void TreeType<ItemType>::Print() const {
    PrintTree(root);
}

// Function: Constructor for TreeType
// PreConditions: None
// PostConditions: Initializes tree
template<class ItemType>
TreeType<ItemType>::TreeType() {
    root = NULL;
}

template<class ItemType>
void Destroy(TreeNode<ItemType>*& tree);

// Function: Calls recursive function Destroy to destroy the tree.
// PreConditions: the tree has been initialized
// PostConditions: tree is empty; nodes have been deallocated.
template<class ItemType>
TreeType<ItemType>::~TreeType() {
    Destroy(root);
}


// Function: The tree is destroyed 
// PreConditions: the tree has been initialized
// PostConditions: tree is empty; nodes have been deallocated.
template<class ItemType>
void Destroy(TreeNode<ItemType>*& tree) {
    if (tree != NULL) {
        Destroy(tree->left);
        Destroy(tree->right);
        delete tree;
    }
}

// Function: Revoves all nodes in the tree
// PreConditions: The tree has been initialized
// PostConditions: The tree is now empty.
template<class ItemType>
void TreeType<ItemType>::MakeEmpty() {
    Destroy(root);
    root = NULL;
}


template<class ItemType>
void CopyTree(TreeNode<ItemType>*& copy, const TreeNode<ItemType>* originalTree);

// Function: Calls recursive function CopyTree to copy originalTree 
//  into root.
// PreConditions: The tree is passed a tree as a parameter
// PostConditions: The new tree has been initailized
template<class ItemType>
TreeType<ItemType>::TreeType(const TreeType& originalTree) {
    CopyTree(root, originalTree.root);
}

// Function: Calls recursive function CopyTree to copy originalTree 
// into root.
// PreConditions: The tree has been initialized
// PostConditions: The tree has been copied
template<class ItemType>
void TreeType<ItemType>::operator= (const TreeType<ItemType>& originalTree) {
    if (&originalTree == this){
        return;             // Ignore assigning self to self
    }
    Destroy(root);      // Deallocate existing tree nodes
    CopyTree(root, originalTree.root);
}

// Function: This function  calls Mirror to produce 
// a mirror image of the original tree
// PreConditions: The tree has been initialized
// PostConditions: A new tree has been created that is the image of the original.
template<class ItemType>
TreeType<ItemType> TreeType<ItemType>::MirrorImage()
// Calls recursive function Mirror.
// Post: A tree that is the mirror image the tree is returned.
{
    TreeType image;
    Mirror(root, image.root);
    return image;
}


// Function: This function recursively calls itself to produce 
// a mirror image of the original tree
// PreConditions: The tree has been initialized
// PostConditions: A new tree has been created that is the image of the original.
template<class ItemType>
void Mirror(const TreeNode<ItemType>* originalTree, TreeNode<ItemType>*& image){
    if (originalTree == NULL){
        image = NULL;
    }else{
        image = new TreeNode<ItemType>;
        image->info = originalTree->info;
        Mirror(originalTree->left,image->right);
        Mirror(originalTree->right,image->left);
    }
}

// Function: The tree is copied to another tree
// PreConditions: The tree has been initialized
// PostConditions: copy is the root of a tree that is a duplicate 
//       of originalTree.
template<class ItemType>
void CopyTree(TreeNode<ItemType>*& copy, const TreeNode<ItemType>* originalTree) {
    if (originalTree == NULL){
        copy = NULL;
    }else{
        copy = new TreeNode<ItemType>;
        copy->info = originalTree->info;
        CopyTree(copy->left, originalTree->left);
        CopyTree(copy->right, originalTree->right);
    }
}
// Function prototypes for auxiliary functions.

// Enqueues tree items in preorder.
template<class ItemType>
void PreOrder(TreeNode<ItemType>*, QueType<ItemType>&);


// Enqueues tree items in inorder.
template<class ItemType>
void InOrder(TreeNode<ItemType>*, QueType<ItemType>&);


// Enqueues tree items in postorder.
template<class ItemType>
void PostOrder(TreeNode<ItemType>*, QueType<ItemType>&);


// Function:Calls function to create a queue of the tree elements in 
// the desired order.
// PreConditions: The tree has been initialized
// PostConditions: The tree has been reset into the chosen order
template<class ItemType>
void TreeType<ItemType>::ResetTree(OrderType order) {
    switch (order) { 
        case PRE_ORDER:   preQue.MakeEmpty();
                          PreOrder(root, preQue);
                          break;
        case IN_ORDER:    inQue.MakeEmpty();
                          InOrder(root, inQue);
                          break;
        case POST_ORDER:  postQue.MakeEmpty();
                          PostOrder(root, postQue);
                          break;
    }
}


// Post: preQue contains the tree items in preorder.
// Function: The tree has been put into preorder
// PreConditions: The tree has been initialized
// PostConditions: PreQue contains the tree items in preorder
template<class ItemType>
void PreOrder(TreeNode<ItemType>* tree, QueType<ItemType>& preQue) {
    if (tree != NULL) {
        preQue.Enqueue(tree->info);
        PreOrder(tree->left, preQue);
        PreOrder(tree->right, preQue);
    }
}


// Function: The tree has been put into inorder
// PreConditions: The tree has been initialized
// PostConditions: inQue contains the tree items in inorder.
template<class ItemType>
void InOrder(TreeNode<ItemType>* tree, QueType<ItemType>& inQue) {
    if (tree != NULL) {
        InOrder(tree->left, inQue);
        inQue.Enqueue(tree->info);
        InOrder(tree->right, inQue);
    }
}


// Function: The tree is put into post order.
// PreConditions: The tree has been initialized
// PostConditions: postQue contains the tree items in postorder.
template<class ItemType>
void PostOrder(TreeNode<ItemType>* tree, QueType<ItemType>& postQue) {
    if (tree != NULL) {
        PostOrder(tree->left, postQue);
        PostOrder(tree->right, postQue);
        postQue.Enqueue(tree->info);
    }
}


// Function: Returns the next item in the desired order.
// PreConditions: The tree has been initailized
// PostConditions: For the desired order, item is the next item in the queue.
//                 If item is the last one in the queue, finished is true; 
//                 otherwise finished is false.
template<class ItemType>
ItemType TreeType<ItemType>::GetNextItem(OrderType order, bool& finished) {
    finished = false;
    ItemType item;
    switch (order) {
        case PRE_ORDER  : preQue.Dequeue(item);
                          if (preQue.IsEmpty()) finished = true;
                          break;
        case IN_ORDER   : inQue.Dequeue(item);
                          if (inQue.IsEmpty()) finished = true;
                          break;
        case  POST_ORDER: postQue.Dequeue(item);
                          if (postQue.IsEmpty()) finished = true;
                          break;
    }
    return item;
}

//Function: Prints the Tree in preOrder
//Pre: The tree has been initialized
//Post: The tree has been printed
template<class ItemType>
void TreeType<ItemType>::PreOrderPrint() const {
    PrePrintTree(root);
}

//Function: Recursively calls itself to print the Tree in preOrder
//Pre: The tree has been initialized
//Post: The tree has been printed
template<class ItemType>
void PrePrintTree(TreeNode<ItemType>* tree) {
    if (tree != NULL) {
        cout << tree->info<<"  ";
        PrePrintTree(tree->left);   // Print left subtree.
        PrePrintTree(tree->right);  // Print right subtree.
    }
}

//Function: Prints the Tree in inOrder
//Pre: The tree has been initialized
//Post: The tree has been printed
template<class ItemType>
void TreeType<ItemType>::InOrderPrint() const {
    InPrintTree(root);

}

// Function: Recursively calls itself to print items in
// order
//Pre: The tree has been initialized
//Post: The tree has been printed
template<class ItemType>
void InPrintTree(TreeNode<ItemType>* tree) {
    if (tree != NULL) {
        InPrintTree(tree->left);   // Print left subtree.
        cout << tree->info<<"  ";
        InPrintTree(tree->right);  // Print right subtree.
    }
}

//Function: Prints the Tree in postOrder
//Pre: The tree has been initialized
//Post: The tree has been printed
template<class ItemType>
void TreeType<ItemType>::PostOrderPrint() const {
    PostPrintTree(root);
}

// Function: Prints the items in the tree in post order.
// PreConditions: The tree has been initialized.
// PostConditions:The tree has been printed in post order.
template<class ItemType>
void PostPrintTree(TreeNode<ItemType>* tree) {
    if (tree != NULL) {
        PostPrintTree(tree->left);   // Print left subtree.
        PostPrintTree(tree->right);  // Print right subtree.
        cout << tree->info<<"  ";
    }
}

// Function: Finds all the ancestors of the given itemtype and 
// prints them to the screen as well as the level of the tree
// at which they were found.
// PreConditions: The tree has been initialized.
// PostConditions:The ancestors have been printed to the screen
template<class ItemType>
void TreeType<ItemType>::Ancestors(ItemType value) const {
    QueType<ItemType> ancestors;
    bool found = false;
    if(root -> info == value){
        cout << "This item is at the root node and thus has"
            << " no ancestors" << endl;
    }else{
        bool itemExists = true;
        TreeNode<ItemType>* tempPtr;
        tempPtr = root;
        while(!found && itemExists) {
            if(tempPtr -> info == value){
                found = true;
            }else{
                ancestors.Enqueue(tempPtr -> info);
                if(value > tempPtr -> info){
                    if(tempPtr -> right == NULL){
                        itemExists = false;
                        cout << "This item is not in the tree.\n\n" << endl;
                    }else{
                        tempPtr = tempPtr -> right;
                    }
                }else{
                    if(tempPtr -> left == NULL){
                        itemExists = false;
                        cout << "This item is not in the tree\n\n" << endl;
                    }else{
                        tempPtr = tempPtr -> left;
                    }
                }
            }
        }
    }
    if(found){
        int level = 1;
        while(!ancestors.IsEmpty()){
            ancestors.Dequeue(value);
            cout << "Value: " << value
                << "\tLevel: " << level << endl;
            level++;
        }
    }
}
