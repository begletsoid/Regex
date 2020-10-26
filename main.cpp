#include <iostream>
#include <algorithm>
#include "regex.h"
using namespace std;
template <class T>
T GetRegex(string arg)
{
  T tmp(arg);
  return tmp;
}
int main() {
  string fname;
  string reg;
  cout << "Enter file name: ";
  cin >> fname;
  cout << "\nEnterregex: ";
  cin >> reg;
  string word;
  ifstream infile(fname);
  while(!infile.eof())
  {
    infile >> word;
    if(GetRegex<regex>(reg).check(word) != -1)
    {
      cout << endl << word;
    }
  }
}