#include<iostream>
#include"intstack.h"

int main(){
    IntStack s1;
    s1.print();
    s1.push(10);
    s1.print();

    s1.push(20);
    s1.push(30);
    s1.print();

    std::cout<<st.pop()<<std::endl;
    //st.delete_stack(); plus besoin car on l'a inclus dans IntStack
    return 0;
}