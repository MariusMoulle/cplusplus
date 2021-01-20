#include<iostream>
#include"classes.h"
#include<vector>

int main(){
    Cercle c(10,10,5);
    Rectangle r(15,25,5,30);
    Rectangle* pr = &r;
    Cercle* pc = &c;
    std::vector<Shape*> v;
    v.push_back(pc);
    v.push_back(pr);
    std::cout<<v[0]->abscisse()<<std::endl;
    std::cout<<v[0]->ordonnee()<<std::endl;
    v[0]->move(5,5);
    std::cout<<v[0]->abscisse()<<std::endl;
    std::cout<<v[0]->ordonnee()<<std::endl;
    std::cout<<v[1]->area()<<std::endl;
    return 0;
}