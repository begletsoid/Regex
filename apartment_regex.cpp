 #include "apartment_regex.h"
using namespace std;
void apartment_regex::show()
{
  cout << endl << words << endl;
}
int apartment_regex::count = 0;
vector<apartment_regex*> apartment_regex::all;
apartment_regex::apartment_regex()
{
words = "\0";
}
apartment_regex::apartment_regex(string arg): regex(arg)
{
   apartment_regex::all.push_back(this);
   apartment_regex::count++;
}

  int apartment_regex::search(string arg, int& lenght)
 {
   for(int i = 0; i < apartment_regex::all.size(); i++)
   {
     if((*apartment_regex::all[i]).check(arg) != -1)
     {
       lenght = ((*apartment_regex::all[i]).words).size();
       return (*apartment_regex::all[i]).check(arg);
     }
   }
   return -1;
 }
  int apartment_regex::search(string arg)
 {
   for(int i = 0; i < apartment_regex::all.size(); i++)
   {
     if((*apartment_regex::all[i]).check(arg) != -1)
     {
       return (*apartment_regex::all[i]).check(arg);
     }
   }
   return -1;
 }

  int apartment_regex::check(std::string arg)
 {
   if(words.size() > arg.size())
   {
   return -1;
   }
   for(int i = 0; i < arg.size(); i++)
   {
     int counter = 0;
     for(int k = 0; k < words.size(); k++)
     {  
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