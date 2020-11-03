#include<iostream>
#include"rpn_calc.h"

int main(int argc, char* argv[]){
    int resultat=rpn_eval(argc-1, argv+1);
    std::cout<<resultat<<std::endl;
    return 0;
}