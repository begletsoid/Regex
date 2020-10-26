#include "filemask.h"
using namespace std;
void filemask::show()
{
  cout << endl << words << endl;
}
int filemask::count = 0;
vector<filemask*> filemask::all;
vector<filemask*> filemask::allex;
filemask::filemask(string arg): regex(arg)
{
   filemask::all.push_back(this);
   filemask::count++;
}

  int filemask::IsFileMatch(string arg)
 {
   for(int i = 0; i < filemask::all.size(); i++)
   { 
     if((*filemask::all[i]).check(arg) != -1)
     {
       return (*filemask::all[i]).check(arg);
     }
   }
   return -1;
 }
  int filemask::IsExtensionMatch(string arg)
  {
    int save = 0;
    int dop = 0;
    int kau = 0;
    int equ = 0;
    for(int q = 0; q < words.size(); q++)
      {
        if (words[q] != '*')
        {
          equ++;
        }
      }
    string wards = words;
    int point = arg.find('.');
    for(int i = point; i < arg.size(); i++)
    {kau = 0;
      for(int k = 0; k < words.size(); k++)
      { 
        if(arg[i+k] == '.')
        {
          break;
        }
        if(wards[k] == '*')
        { if(k+1 == wards.size() && kau+dop == equ)
            {
              return 1;
            }
          save = i;      
             for(int q = 0; q < k; q++)
            {
              if (wards[q] != '*')
               {
                 dop++;
               }
            }
          wards.erase(0, k+1);

          k = 0;
        }
        else if(wards[k] == arg[i+k] || wards[k] == '?')
        {
          kau++;
        }
        else if(wards[k] != arg[i+k])
        {
          break;
        }
        if(i != save)
        {
          if(kau+dop == equ)
          {
            return 1;
          }
        }
      }
    }
      return -1;
  }
  int filemask::check(std::string arg)
  { 
    int save = 0;
    int dop = 0;
    int kau = 0;
    int equ = 0;
    for(int q = 0; q < words.size(); q++)
      {
        if (words[q] != '*')
        {
          equ++;
        }
      }
    string wards = words;
    int point = arg.find('.');
    for(int i = 0; i < point; i++)
    {kau = 0;
      for(int k = 0; k < words.size(); k++)
      { 
        if(arg[i+k] == '.')
        {
          break;
        }
        if(wards[k] == '*')
        { if(k+1 == wards.size() && kau+dop == equ)
            {
              return 1;
            }
          save = i;      
             for(int q = 0; q < k; q++)
            {
              if (wards[q] != '*')
               {
                 dop++;
               }
            }
          wards.erase(0, k+1);

          k = 0;
        }
        else if(wards[k] == arg[i+k] || wards[k] == '?')
        {
          kau++;
        }
        else if(wards[k] != arg[i+k])
        {
          break;
        }
        if(i != save)
        {
          if(kau+dop == equ)
          {
            return 1;
          }
        }
      }
    }
      return -1;
  }
  bool filemask::operator== (filemask& arg)
{
  return (words == arg.words) ? true : false;
}