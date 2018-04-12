/*
Author: Cameron Garratt
Submission Date: 8/30/16
Purpose: This assignment called for an ADT specification of a square matrix. The following are the conditions for each of the functions implimented in the code.
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
#include "SquareMatrix.h"
#include <iostream>
using namespace std;

//SquareMatrix();						
//Function: The constructor for the ADT SquareMatrix.	
//Precondition: Include SquareMatrix.h and SquareMatrix.cpp		
//Postcondition: SquareMatrix has been initialized to a 50 x 50 matrix, all the values have been set to 0. 
template<class T>
SquareMatrix<T> :: SquareMatrix(){
  MakeEmpty(50);
}

//void MakeEmpty(int n);
//Function: The matrix is resized to n x n and all the values are set to 0. 
//Precondition: The matrix has been initialized and n is an integer less than 51 and greater than 0 
//Postcondition: All values have been set to zero and the matrix has been resized to n x n. 
template<class T>
void SquareMatrix<T> :: MakeEmpty(int n){
  size = n;
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      values[i][j] = 0;
    }
  }
}

//void StoreValue(int i, int j,T value);
//Function: Stores a value at the location [i][j]			
//Precondition: The matrix has been initialized and both i and j are less than the size of the matrix. Also the value to be inserted must be of the same type as the matrix it is being inserted into 
//Postcondition: The value has been inserted into the matrix		
template<class T>
void SquareMatrix<T> :: StoreValue(int i,int j,T value){
  if(i < size && j < size){
    values[i][j] = value;
  }else{
    if(!(i < size)){ 
      cout << "The value "<< i << " is out of range. ";
    }
    if(!(j < size)){ 
      cout << "The value "<< j << " is out of range. ";
    }
    cout << "Please pick coordinates less than ";
    cout << size << "." << endl;
  }
}

//void StoreAllValues(T value);		
//Function: Stores a value at every location				
//Precondition: The matrix has been initialized. Also the value to be inserted must be of the same type as the matrix it is being inserted into 
//Postcondition: The values has been inserted into the matrix	
template<class T>
void SquareMatrix<T> :: StoreAllValues(T value){
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      values[i][j] = value;
    }
  }
}

//SquareMatrix$<$T$>$ Add(SquareMatrix&);				
//Function: Adds the values of the matrix being referenced and the matrix this operation is applied to. Returns a new added matrix. 
//Precondition: Both matrices have been initialized and they are both of the same type and size. 
//Postcondition: A matrix is returned with values such that each values is the sum of the respective values in the two original matrices. 
template<class T>
SquareMatrix<T> SquareMatrix<T> :: Add(SquareMatrix & matrix){
  SquareMatrix<T> result;
  result.MakeEmpty(size);
  for(int i = 0; i < size;i++){
    for(int j = 0; j < size;j++){
      T value = values[i][j] + matrix.values[i][j];
      result.StoreValue(i,j,value);
    }
  }
  return result;
}

//SquareMatrix$<$T$>$ Subtract(SquareMatrix&);			
//Function: Subtracts the values of the matrix being referenced and the matrix this operation is applied to. Returns a new subtracted matrix. 
//Precondition: Both matrices have been initialized and they are both of the same type and size. 
//Postcondition: A matrix is returned with values such that each values is the diffenence of the respective values in the two original matrices. 
template<class T>
SquareMatrix<T> SquareMatrix<T> :: Subtract(SquareMatrix & matrix){
  SquareMatrix<T> result;
  result.MakeEmpty(size);
  for(int i = 0; i < size;i++){
    for(int j = 0; j < size;j++){
      T value = values[i][j] - matrix.values[i][j];
      result.StoreValue(i,j,value);
    }
  }
  return result;
}

//SquareMatrix$<$T$>$ Copy();					
//Function: returns a matrix that is an exact copy of the matrix this operation is being applied to.	
//Precondition: The matrix has been initialized			
//Postcondition: A matrix is returned that is an exact copy of the original matrix. 
template<class T>
SquareMatrix<T> SquareMatrix<T> :: Copy(){
  SquareMatrix<T> result;
  result.MakeEmpty(size);
  for(int i = 0; i < size;i++){
    for(int j = 0; j < size;j++){
      result.StoreValue(i,j,values[i][j]);
    }
  }
  return result;
}

//void Print();					
//Function: Prints out the matrix to the command line.	
//Precondition: The matrix has been initialized. 		
//Postcondition: The matrix is printed to the screen.	
template<class T>
void SquareMatrix<T> :: Print(){
  for(int i = 0; i < size;i++){
    for(int j = 0; j < size;j++){
      cout << values[i][j] << " ";
    }
      cout << endl;
  }
}


