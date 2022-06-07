#include "pila.h"

#include <iostream>
#include <cstdlib>

using namespace std;


bool empty(Pila p) { return p == NULL; }

void free_stack(Pila &p) {
  if (!empty(p)) {
    free(p->sig);
    delete p;
  }
}

Pila new_stack() { return NULL; }

void print_stack(Pila p) {
  while (!empty(p)) {
    cout << p->c << "";
    p = p->sig;
  }
  cout << endl;
}

char pop(Pila &p) {
  if (!empty(p)) {
    char c = p->c;
    Pila q = p->sig;
    free(p);
    p = q;
    return c;
  }
  return '\0';
}

void push(Pila &p, char c) {
  Pila q = new NODO;
  q->c = c;
  q->sig = p;
  p = q;
}

char top(Pila p) {
  if (!empty(p)) {
    return p->c;
  }
  return '\0';
}