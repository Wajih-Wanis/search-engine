#include<iostream>
#include<set>
#include<string>
#include <fstream>
#include <iterator>
#include <vector>
#include<map>
#include<cmath>
#include"traiteurH.h"
#include"lecteur_requeteH.h"
#include"lecteur_fichierH.h"
#include <dirent.h>
#include <sys/types.h>
#include"fichierH.h"
#include"AnalyseurH.h"


using namespace std;


vector<string> lecteur_requete::extracter(string requete)
{
    vector<string> mots;
    ch_min ch;
    requete=ch.nettoyer(requete);
    supp_symbole s;
    supp_espace e;
    requete=s.nettoyer(requete);
    long long unsigned int pos=0;
    string a=" ";
    string mot;

    requete=e.nettoyer(requete);

    while(requete[0]==' ')
    {
        requete.erase(0,1);
    }
    while(requete[requete.size()-1]==' ')
    {
        requete.erase(requete.size()-1,1);
    }

    while((pos = requete.find(a)) !=  string::npos)
    {
        mot=requete.substr(0,pos);
        mots.push_back(mot);

        requete.erase(0, pos + 1);
    }

    mots.push_back(requete);

    for(set<string>::iterator i=MotVide.begin();i!=MotVide.end();++i)
    {

        for (vector<string>::iterator j=mots.begin();j!=mots.end();++j)
        {
            if(*j==*i)
            {
                mots.erase(j);
                j--;
            }
        }
    }
  return mots;
}
