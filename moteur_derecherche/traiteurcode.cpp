#include<iostream>
#include"traiteurH.h"
#include<set>
#include<string>
#include <fstream>
#include <iterator>
#include <vector>
#include<map>
#include<set>
#include<cmath>
#include <string>

string ch_min::nettoyer(string &ch)
{
    transform(ch.begin(),ch.end(),ch.begin(),::tolower);
    return ch;
}

string ch_maj::nettoyer(string &ch)
{
    transform(ch.begin(),ch.end(),ch.begin(),::toupper);
    return ch;
}

string supp_symbole::nettoyer(string &ch)
{
     for(string ::iterator i=ch.begin();i!=ch.end();++i)
    {
        set<char>::iterator it =symbole.find(*i);
        if (it!=symbole.end())
        {
            ch.erase(i);
            ch.insert(i,' ');

        }
    }
    return ch;
}

string remplacer::nettoyer(string &rep)
{
    char c='/' ;
string ch2;

for(unsigned int i=0;i<rep.size();i++)
{
    ch2+=rep[i];
     if(rep[i]==c)
     {
         ch2.erase(ch2.size()-1,1);
         ch2.insert(ch2.size(),"\\");

     }
}
return ch2;
}
string sup_occ::nettoyer(string &ch)
{
    for(unsigned int i=0; i< ch.size(); ++i)
   {
      if(ch[i] == '\\')
      {

          int a;
          a=i;
          while(ch[a]==ch[a+1])
          {
                ch.erase(i,1);

          }

      }
   }
   return ch;
}

string supp_espace::nettoyer(string &ch)
{
    for(unsigned int i=0; i< ch.size(); ++i)
   {
      if(ch[i] == ' ')
      {

          int a;
          a=i;
          while(ch[a]==ch[a+1])
          {
                ch.erase(i,1);

          }

      }
   }
   return ch;
}


