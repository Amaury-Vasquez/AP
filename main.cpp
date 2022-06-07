#include <iostream>
#include <vector>

#include "verifica_ap/verifica.h"
#include "read_file/read_file.h"
#include "pila/pila.h"

using namespace std;

int main() {
  // Lectura de archivo
  string alphabet;
  vector<vector<string>> table;
  read_file("entrada.txt", alphabet, table);
  // string tmp = "ε";
  // cout << tmp.length() << endl << endl;
  // for (int i = 0; i < table.size(); i++) {
  //   for (int j = 0; j < table[i].size(); j++) {
  //     cout << table[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  // Lectura cadena
  string str;
  cout << "Ingrese cadena a evaluar: ";
  cin >> str;
  if (accept_str(str, alphabet)) 
    cout << verifica_ap(str, table) << endl;
  
  else {
    cout << "Cadena no valida" << endl;
    return -1;
  }
  // Verificacion AP
  return 0;
}

