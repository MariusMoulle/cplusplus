#include<iostream>

class IntCell { 
    friend class IntList;
private:
   IntCell (int value) : prev(nullptr), next(nullptr), value(0) {}

    int value;
    IntCell* prev;
    IntCell* next;
};

class IntList {
public:   

    IntList () : first(nullptr), last(nullptr) {
    }

    ~IntList (){
         While (last != nullptr){
            remove_front();
         }
    }

    void add_front (int a) {
      IntCell *front = new IntCell(a);
      if (first != nullptr){
         first -> prev = front;  //la cellule créée passe en front
         front -> next = first;  //front pointe vers first qui est la deuxième
      }
      first = front;
      if (last==nullptr){
         last=front
      }
    }

    void add_back (int a) {
      IntCell *back = new IntCell(a);
      if (last != nullptr){
         last -> next = back;   //la cellule créée passe en back
         back -> prev = last;   //back pointe vers last qui est l'avant-dernière
      }
      last = back;
      if (first==nullptr){
         first = back;
    }

    void remove_front () {
      if (first != nullptr){
         if (first==last){
            IntCell* cell = first;
            first = nullptr;
            delete cell;
         }
         else {
            Intcell* cell = first;
            first = cell -> next;  //first pointe vers celle d'après
            first -> prev = nullptr;  //on supprime le lien de la 2ème à la 1ère
            cell -> next = nullptr;  //on supprime le lien de la 1ère à la 2ème
            delete cell;  //on supprime la première
         }
      }
    }

    void remove_back() {
      if (last != nullptr){
         if (first==last){
            IntCell* cell = last;
            last = nullptr;
            delete cell;
         }
         else{
            IntCell* cell = last;
            last = cell -> prev;
            last -> next = nullptr;
            cell -> prev = nullptr;
            delete cell;
         }
      }
    }

    void remove(int a) {
      bool b = search(a);
      if (b == true){
         IntCell *top = first;
         if (top -> value == a){
            remove_front()
         }
         else{
            while (top -> next != nullptr){
               top -> top = next;
               if (top -> value == a){
                  if (top -> next != nullptr){
                     IntCell* cell2 = top -> next;
                     IntCell* cell3 = top-> prev;
                     cell2 -> next = cell3;
                     cell3 -> prev = cell2;
                     top -> next = nullptr;
                     top -> prev = nullptr;
                     delete top;
                  }
                  else{
                     remove_back();
                  }
               }
            }
         }
      }
    }

    bool search (int a) {
       IntCell* top = first;
       if(top -> value = a){
          return true;
       }
       while (top -> next != nullptr){
          if (top -> value == a){
             return true;
          }
          top = top -> next;
       }
       return false;
    }

    void print () {
      std::cout<<'{'
      IntCell* top = first;
      while (top){
         std::cout<< top -> value <<' ';    
         top = top -> next;
      }
      std::cout<<'}'<<std::endl;
      }

private:
    IntCell *first;
    IntCell *last;
    };
    