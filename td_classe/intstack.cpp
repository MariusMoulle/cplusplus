#include <iostream>
class IntStack {

public:
  IntStack (int s) : size(s),  top(0){
    if(s>0){
      tab = new int[size];
    }
    else{
      std::cout<<"taille inférieure ou égale à 0\n";
      throw(2);
    }
  }
  void push (int e){
      if (is_full()){
        std::cout<<"la pile est pleine";
        throw(1);
      }
      else{
        tab[top]=e;
        top=top+1;
      }
  }
  int pop(){
      if (is_empty()){
          std::cout<<"la pile est vide\n";
          throw(2);   
      }
      else{
          top=top-1;
          return tab[top];
     }
  }
  
  void print(){
      std::cout<<'[';
      for (int i=0; i<top; i++){
          std::cout<<tab[i]<<' ';
      }
      std::cout<<'['<<std::endl;
  }
  ~IntStack(){
    delete[] tab;
  }
  bool is_empty(){
      return top==0;
  }
  bool is_full(){
      return top==size;
  }


private:
  int top;
  int size;
  int *tab;
};




