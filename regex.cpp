#include "simpregex.h"
using namespace std;
int regex::count = 0;
vector<regex*> all;
void regex::checklist(stringlist arg)
{ node* temp;
  node* tmp;
  tmp = arg.first;
  while(tmp->next != NULL)
  {
    if(this->check(tmp->content) == -1)
    { 
      temp = tmp;
      tmp = tmp->next;
      arg.del(temp);
    }
    else
    {
      tmp = tmp->next;
    }
  }
  if(this->check(tmp->content) == -1)
    { 
       arg.del(tmp);
    }
}
regex::regex(): words("\0")
{
   all.push_back(this);
   count++;
}
regex::regex(std::string start): words(start)
 {
   all.push_back(this);
   count++;
 }
 int regex::search(string arg)
 {
   for(int i = 0; i < all.size(); i++)
   {
     if((*all[i]).check(arg) != -1)
     {
       return (*all[i]).check(arg);
     }
   }
   return -1;
 }
  int regex::search(string arg, int& lenght)
 {
   for(int i = 0; i < all.size(); i++)
   {
     if((*all[i]).check(arg) != -1)
     {
       lenght = ((*all[i]).words).size();
       return (*all[i]).check(arg);
     }
   }
   return -1;
 }
 vector<regex*> regex::all;
 int regex::check(std::string arg)
 {
   if(words.size() > arg.size())
   {
        cout << arg.size() << endl;
   return -1;
   }
   for(int i = 0; i < arg.size(); i++)
   {
     int counter = 0;
     for(int k = 0; k < words.size(); k++)
     {  
       if(arg.size() - i < words.size())
       {
         return -1;
       }
       if(arg[i+k] == words[k])
       {
        counter++;
       }
       if(counter == words.size())
       {
       return i;
       }
       if(counter > words.size())
       {
       return -1;
       }
       if(k > words.size())
       {
       return -1;
       }
     }
   }
   return -1;
 }
ostream& operator<<(ostream& out, regex& arg)
{
  out << arg.words;
  return out;
}
regex regex::operator= (regex& arg)
{
  words = arg.words;
  return *this;
}
bool regex::operator== (regex& arg)
{
  return (words == arg.words) ? true : false;
}
bool regex::operator< (regex& arg)
{
  return (words < arg.words) ? true : false;
}
bool regex::operator> (regex& arg)
{
  return (words > arg.words) ? true : false;
}
regex::operator string() const
{
return words;
}