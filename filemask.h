
#include "apartment_regex.h"
using namespace std;
class filemask : public regex
{public:
  filemask(string arg);
  static vector<filemask*> all;
  static vector<filemask*> allex;
  static int search(string arg);
  static int count;
  int check(string);
  int IsFileMatch(string);
  static int search(string, int&);
  void show();
  int IsExtensionMatch(string arg);
  bool operator== (filemask& arg);
};