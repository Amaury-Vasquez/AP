#include <iostream>
#include <cstdlib>

#include "verifica.h"
#include "../pila/pila.h"

using namespace std;

bool accept_str(string str, string alphabet) {
  bool accepted = true;
  
  for (int i = 0; accepted && i < str.length(); i++) {
    bool aux = false;
    
    for (int j = 0; !aux && j < alphabet.length(); j++) {
      if (str[i] == alphabet[j])
        aux = true;
    }

    if (!aux)
      accepted = false;
  }

  return accepted;
}

bool verifica_ap(string cadena, vector<vector<string>> table) {
  Pila pila = new_stack();
  int i = 0, j = 0;
  while (i < table.size() && j < cadena.length()) {
    cout << cadena[j] << " ";
    bool aux = eval(table[i], cadena[j], pila, j);
    cout << aux << " " << i << " top:" << top(pila) << endl;
    print_stack(pila);
    if (!aux)
      i++;
  }
  cout << endl;
  print_stack(pila);
  cout << empty(pila);
  return (empty(pila) && j == cadena.length());
}

bool eval(vector<string> v, char c, Pila &pila, int &i) {
  if (v[2].at(0) == c && ((v[3] == "z0" && empty(pila)) || v[3].at(0) == top(pila))) {
    ex(pila, v[4]);
    i++;
    return true;
  }
  // state++;
  return false;
}

void ex(Pila &pila, string str) {
  int pos = str.find("z0", 0);
  if (pos == 0)
    pila = new_stack();
  else if (pos == 1)
    push(pila, str[0]);
  else if (pos == -1) {
    cout << "eee";
    if (str.length() == 1 && !(top(pila) == str[0])) {
      pop(pila);
      push(pila, str[0]);
    }
    else if (str == "ε")
      pop(pila);
    else if(str.length() == 2)
      push(pila, str[1]);
  }
}