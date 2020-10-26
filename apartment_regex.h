#include "simpregex.h"
using namespace std;
class apartment_regex : public regex
{public:
  apartment_regex(string arg);
  apartment_regex();
  static vector<apartment_regex*> all;
  static int count;
  int check(string);
  static int search(string);
  static int search(string, int&);
  void show();
};