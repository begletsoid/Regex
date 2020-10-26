#include <string.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <list>
using namespace std;
class stringlist;
struct node;
class regex
{
 protected:
 string words;
 public:
 void checklist(stringlist arg);
 static vector<regex*> all;
 static int count;
 regex(std::string start);
 regex();
 virtual int check(string);
 friend ostream& operator<<(ostream&, regex&);
 regex operator =(regex& arg);
 bool operator == (regex&);
 bool operator < (regex&);
 bool operator > (regex&);
 operator string () const;
 static int search(string);
 static int search(string, int&);
 
};
struct node
{
string content;
node* next;
node* prev;
friend class regex;
friend class stringlist;
};
class stringlist
{
  private:
 
  public: node* first;
  node* last;
  int count;
  stringlist();
  void del(node* arg);
  void show();
  void add (string arg);
  friend class regex;
  friend class node;
};