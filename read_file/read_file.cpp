#include <iostream>
#include <fstream>

#include "read_file.h"

using namespace std;

void read_file(string name, string &alphabet, std::vector<std::vector<std::string>> &table) {
  ifstream file;
  file.open(name);

  int len = 0;
  if (file.is_open()) {
    getline(file, alphabet);
    while (!file.eof()) {
      string line;
      getline(file, line);
      vector<string> tmp = split_string(line);
      table.push_back(tmp);
    }

    file.close();
  }
  else 
    cout << "Unable to open file " << name << endl;
}

vector<string> split_string(string str) {
  vector<string> result;
  string aux = "";

  for (int i = 0; i < str.length(); i++) {
    if (str[i] == ' ') {
      result.push_back(aux);
      aux = "";
    }
    else
      aux += str[i];
  }
  if(aux.length() > 0)
    result.push_back(aux);
  return result;
}