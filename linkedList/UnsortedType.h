#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H
#include <cstddef>

template<class ItemType>
struct NodeType;

template<class ItemType>
struct NodeType{
    ItemType info;
    NodeType* next;
}

template<class ItemType>
class UnsortedType
{
public:
    UnsortedType();
    void MakeEmpty();
    bool IsFull() const;
    int GetLength() const;
    ItemType GetItem(ItemType item, bool& found);
    void PutItem(ItemType item);
    void DeleteItem(ItemType item);
    void ResetList();
    ItemType GetNextItem();
private:
NodeType<ItemType>* listData;
int length;
    NodeType* currentPos;
};
#endif
        

UnsortedType(){
    length = 0;
    listData = NULL;
}

bool IsFll() const{
    NodeType* location;
    try{
        location = new NodeType;
        delete location;
        return false;
    }catch(std::bad_alloc exception){
        return true;
    }
}


ItemType GetItem(ItemType item, bool& found){
    bool moreToSearch;
    found = false;
    moreToSearch = (location != NULL);
    
    while(moreToSearch && !found){
        switch(item.ComparedTo(info[location])){
            case LESS : 
            case GREATER : location = location -> next;
                           moreToSearch = (location != NULL);
                           break;
            case EQUAL   : found = true;
                           item - location -> info;
                           break;
        }
    }
}



