#include<iostream>
int* init_stack(int taille);
int pop (int stack [], int* top);
void push (int stack [], int* top, int token);
void print_stack(int* tab, int top);
void delete_stack(int* tab);