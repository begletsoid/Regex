#include <iostream>
using namespace std;
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
  node* first;
  node* last;
  public:
  stringlist();
  void del(node* arg);
  void show();
  void add (string arg);
  friend class regex;
  friend class node;
};