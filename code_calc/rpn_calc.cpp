#include<iostream>
#include"stack.h"

bool is_operande (char* token){
    return ('0'<=token[0]) and (token[0]<='9');
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