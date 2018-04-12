#include <iostream>

template <class T>
struct Heap{
    void ReheapUp(int root, int bottom);
    void ReheapDown(int root, int bottom);
    T* elements;
    int numElements;
};

template <class T>
void Heap<T>::ReheapUp(int root, int bottom){
    int parent;
    if(bottom > root){
        parent = (bottom -1)/ 2;
        if(elements[parent] < elements[bottom]){
            T temp = elements[parent];
            elements[parent] = elements[bottom];
            elements[bottom] = temp;
            ReheapUp(root,parent);
        }
    }
}

template <class T>
void Heap<T>::ReheapDown(int root, int bottom){
    int max;
    int right;
    int left;

    left = root*2+1;
    right = root*2+2;
    if(left <= bottom){
        if(left == bottom)
            max = left;
        else{
            if(elements[left] <= elements[right])
                max = right;
            else
                max = left;
        }
        if(elements[root] < elements[max]){
            T temp = elements[max];
            elements[max] = elements[root];
            elements[root] = temp;
            ReheapDown(max, bottom);
        }
    }
}


