#include "stringlist.h"
using namespace std;
void stringlist::del(node* arg)
{
  if(arg == first)
  {
    first = arg->next;
  }
  else if(arg == last)
  {
    last = arg->prev;
  }
  else
  {
    (arg->prev)->next = arg->next;
    (arg->next)->prev = arg->prev;

  }
}
stringlist::stringlist()
{
  first = new node;
  first->content = "\0";
}
void stringlist::add(string arg)
{
if(first->content != "\0")
{
  node* tmp;
  node* temp;
tmp = first;
while(tmp->next != NULL)
{
tmp = tmp->next;
}
tmp->next = new node;
temp = tmp;
tmp = tmp->next;
tmp->content = arg;
tmp->prev = temp;
}
else
{
  first = new node;
  first->content = arg;
}
}
void stringlist::show()
{
node* tmp;
tmp = first;
while(tmp->next != NULL)
{
cout << endl << tmp->content;
tmp = tmp->next;
}
cout << endl << tmp->content;
}