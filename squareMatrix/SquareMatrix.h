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
#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

template <class T>
class SquareMatrix{
  public:
    SquareMatrix();
    void MakeEmpty(int n);
    void StoreValue(int i, int j,T value);
    void StoreAllValues(T value);
    SquareMatrix<T> Add(SquareMatrix&);
    SquareMatrix<T> Subtract(SquareMatrix&);
    SquareMatrix<T> Copy();
    void Print();

  private:
    int size;
    T values[50][50];
};

#endif
