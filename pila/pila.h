#ifndef PILA_H
#define PILA_H

#include <iostream>

struct NODO {
  char c;  
  NODO *sig;  
};

typedef struct NODO *Pila;

bool empty(Pila p);
void free_stack(Pila &p);
Pila new_stack();
void print_stack(Pila p);
void push(Pila &p, char c);
char pop(Pila &p);
char top(Pila p);

#endif