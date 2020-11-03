#include<iostream>

bool is_operande (char* token){
    return ('0'<=token[0]) and (token[0]<='9');
}

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

int rpn_eval (int n, char* tab[]){
    int* stack = init_stack(n);
    int top=0;
    for (int i=0 ; i<n ; i++){           //si i va jusqu'à n on aura une seg fault 
                                         //car les indices du tableau vont jusqu'à n-1
        char* token = tab[i];
        if (is_operande(token)){
            push(stack, &top, atoi(token));
        }
        else if (token[0]=='!'){
            int val = pop(stack,&top);
            push (stack, &top, -val);
        }
        else if (token[0]=='x'){
            int a = pop (stack, &top);
            int b = pop (stack, &top);
            int c = a*b;
            push (stack, &top, c);
        }
        else if (token[0]=='+'){
            int a = pop (stack, &top);
            int b = pop (stack, &top);
            int c = a+b;
            push (stack, &top, c);
        }
        else if (token[0]=='-'){
            int a = pop (stack, &top);
            int b = pop (stack, &top);
            int c = b-a;
            push (stack, &top, c);
        }
        else if (token[0]=='/'){
            int a = pop (stack, &top);
            int b = pop (stack, &top);
            int c = b/a;
            push (stack, &top, c);
        }
        print_stack(stack,top);    
    }
    int a = stack[0];
    delete_stack(stack);
    return a;
}

int main(int argc, char* argv[]){
    int resultat=rpn_eval(argc-1, argv+1);
    std::cout<<resultat<<std::endl;
    return 0;
}
