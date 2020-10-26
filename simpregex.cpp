#include "simpregex.h"
using namespace std;
void simpregex::show()
{
  cout << endl << words << endl;
}
int simpregex::count = 0;
vector<simpregex*> simpregex::all;
simpregex::simpregex(string arg): regex(arg)
{
   simpregex::all.push_back(this);
   simpregex::count++;
}
int simpregex::search(string arg)
 {
   for(int i = 0; i < simpregex::all.size(); i++)
   {
     if((*simpregex::all[i]).check(arg) != -1)
     {
       return (*simpregex::all[i]).check(arg);
     }
   }
   return -1;
 }

  int simpregex::check(std::string arg)
 {
   if(words.size() > arg.size())
   {
   return -1;
   }
   for(int i = 0; i < arg.size(); i++)
   {
     if(arg[i] == '*')
     {
       throw star();
     }
     int counter = 0;
     for(int k = 0; k < words.size(); k++)
     {  
       if(words[k] == '*')
       {
         throw star();
       }
       if(arg.size() - i  < words.size())
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
 bool simpregex::operator== (simpregex& arg){
  return (words == arg.words) ? true : false;
}