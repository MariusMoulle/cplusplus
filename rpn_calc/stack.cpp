#include<iostream>

void push (int stack [], int* top, int token) {
   stack[*top] = token; 
   *top = *top + 1;
}
int pop (int stack [], int* top) {
  *top = *top - 1;
  return stack[*top];
}


int* init_stack(int taille){
    int* tab = new int[taille];
    return tab;
}

void delete_stack(int* tab){
    delete[] tab;
}

void print_stack(int* tab, int top){
    std::cout<<'['<<' ';
    for (int i=0; i<top; i++){
        std::cout<<tab[i]<<' ';
    }
    std::cout<<'['<<std::endl;
}