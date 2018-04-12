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
#include <iostream>
#include <string>
#include "SquareMatrix.h"
#include "SquareMatrix.cpp"
using namespace std;

int main(){
  bool flag = true;
  SquareMatrix<int> m1,m2;
  SquareMatrix<double> m3,m4;
  SquareMatrix<float> m5,m6;
  cout << endl<< "Welcome the the SquareMatrix test program." << endl;
  cout << "Six 50 x 50 Square matrices have already been created" << endl;
  cout << "Two containing ints(m1,m2)" << endl;
  cout << "Two containing doubles(m3,m4)" << endl;
  cout << "Two containing floats(m5,m6)" << endl << endl;
  while(flag){
    cout << endl<< "Enter 1 to test all the functions with matrices containing ints." << endl;
    cout << "Enter 2 to test all the functions with matrices containing doubles." << endl;
    cout << "Enter 3 to test all the functions with matrices containing floats." << endl;
    cout << "Enter q to quit out of program" << endl << endl;
    
    string input;
    cin >> input;
    
    if(input.compare("q") == 0){
      flag = false;
    }else if(input.compare("1") == 0){
      cout << "Matrix1" << endl;
      m1.Print();
      cout << "Matrix2" << endl;
      m2.Print();
      cout << "Matrix1.MakeEmpty(5)" << endl;
      m1.MakeEmpty(5);
      m1.Print();
      cout << "Matrix2.MakeEmpty(5)" << endl;
      m2.MakeEmpty(5);
      m2.Print();
      cout << "Matrix1.StoreAllValues(5)" << endl;
      m1.StoreAllValues(5);
      m1.Print();
      cout << "Matrix2.StoreAllValues(2)" << endl;
      m2.StoreAllValues(2);
      m2.Print();
      cout << "Matrix2 = Matrix1.Add(Matrix2)" << endl;
      m2 = m1.Add(m2);
      m2.Print();
      cout << "Matrix1.StoreValue(1,1,60)" << endl;
      m1.StoreValue(1,1,6);
      m1.Print();
      cout << "Matrix1 = Matrix2.Subtract(Matrix1)" << endl;
      m1 = m2.Subtract(m1);
      m1.Print();
      cout << "Matrix1 = Matrix2.Copy()" << endl;
      m1 = m2.Copy();
      m1.Print();
      
      
      
    }else if(input.compare("2") == 0){
      cout << "Matrix3" << endl;
      m3.Print();
      cout << "Matrix4" << endl;
      m4.Print();
      cout << "Matrix3.MakeEmpty(5)" << endl;
      m3.MakeEmpty(5);
      m3.Print();
      cout << "Matrix4.MakeEmpty(5)" << endl;
      m4.MakeEmpty(5);
      m4.Print();
      cout << "Matrix3.StoreAllValues(5.1)" << endl;
      m3.StoreAllValues(5.1);
      m3.Print();
      cout << "Matrix4.StoreAllValues(4.2)" << endl;
      m4.StoreAllValues(4.2);
      m4.Print();
      cout << "Matrix4 = Matrix3.Add(Matrix4)" << endl;
      m4 = m3.Add(m4);
      m4.Print();
      cout << "Matrix3.StoreValue(3,3,6.9)" << endl;
      m3.StoreValue(3,3,6.9);
      m3.Print();
      cout << "Matrix3 = Matrix4.Subtract(Matrix3)" << endl;
      m3 = m4.Subtract(m3);
      m3.Print();
      cout << "Matrix3 = Matrix4.Copy()" << endl;
      m3 = m4.Copy();
      m3.Print();
    }else if(input.compare("3") == 0){
      cout << "Matrix5" << endl;
      m5.Print();
      cout << "Matrix6" << endl;
      m6.Print();
      cout << "Matrix5.MakeEmpty(5)" << endl;
      m5.MakeEmpty(5);
      m5.Print();
      cout << "Matrix6.MakeEmpty(5)" << endl;
      m6.MakeEmpty(5);
      m6.Print();
      cout << "Matrix5.StoreAllValues(5.1)" << endl;
      m5.StoreAllValues(5.1);
      m5.Print();
      cout << "Matrix6.StoreAllValues(6.2)" << endl;
      m6.StoreAllValues(6.2);
      m6.Print();
      cout << "Matrix6 = Matrix5.Add(Matrix6)" << endl;
      m6 = m5.Add(m6);
      m6.Print();
      cout << "Matrix5.StoreValue(2,4,6.9)" << endl;
      m5.StoreValue(2,4,6.9);
      m5.Print();
      cout << "Matrix5 = Matrix6.Subtract(Matrix5)" << endl;
      m5 = m6.Subtract(m5);
      m5.Print();
      cout << "Matrix5 = Matrix6.Copy()" << endl;
      m5 = m6.Copy();
      m5.Print();
    }else{
    }
//SquareMatrix<int> cats,books;
//SquareMatrix<int> dogs, cars;
//cats.MakeEmpty(4);
//cats.StoreValue(2,3,4);
//books = cats.Add(dogs);
//cars = cats.Copy();
//cats.Print();
//books.Print();
//cars.Print();
  }

}


