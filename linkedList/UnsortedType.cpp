#include "UnsortedType.h"

struct NodeType{
    ItemType info;
    NodeType* next;
}

UnsortedType::UnsortedType(){
    length = 0;
    beginningOfList = NULL;
}

bool UnsortedType::IsFll() const{
    NodeType* location;
    try{
        location = new NodeType;
        delete location;
        return false;
    }catch(std::bad_alloc exception){
        return true;
    }
}

MakeEmpty(){
    resetList();
    while(correntPos -> next != NULL){
        NodeType* temp = currentPos;
        currentPos = currentPos -> next;
        delete[] temp;
    }
    delete[] currentPos;
    beginningOfList = NULL;
    length = 0;

}

