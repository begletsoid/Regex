#include "regex.h"
using namespace std;
class simpregex : public regex
{public:
  class star {};
  simpregex(string arg);
  static vector<simpregex*> all;
  static int count;
  int check(string);
  static int search(string);
  static int search(string, int&);
  void show();
  bool operator== (simpregex& arg);
};