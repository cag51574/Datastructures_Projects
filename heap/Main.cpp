#include <iostream>
#include "Heap.cpp"

int main(){
#if __cplusplus==201402L
    std::cout << "C++14" << std::endl;
#elif __cplusplus==201103L
    std::cout << "C++11" << std::endl;
#else
    std::cout << "C++" << std::endl;
#endif
    std::cout << __cplusplus<< std::endl;
    Heap<int> heap;
    heap.elements[0] = 1;
    





    return 0;
}
