#include"intstack.h"

inline int IntStack::pop(){
    if(not is_empty()){
        top=top-1;
        return tab[top];
    }
    else{
        std::cout<<"la pile est vide\n";
        throw(2);
    }
}
