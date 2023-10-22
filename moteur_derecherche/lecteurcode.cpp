#include<iostream>
#include"LecteurH.h"
#include<set>
#include<string>
#include <fstream>
#include <iterator>
#include <vector>
#include<map>
#include<set>
#include<cmath>
#include <string>

using namespace std;
lecteur::lecteur(){};
lecteur::~lecteur(){};
void lecteur::nettoyer(string &ch)
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

}
LecteurRequete::LecteurRequete(){};
LecteurFichier::LecteurFichier(){};

vector<string> LecteurRequete::extracter(string requete)
{
    vector<string> mots;
    transform(requete.begin(),requete.end(),requete.begin(),::tolower);
    nettoyer(requete);
    long long unsigned int pos=0;
    string a=" ";
    string mot;
    while((pos = requete.find(a)) !=  string::npos)
    {
        mot=requete.substr(0,pos); // copier(pos,len)
        mots.push_back(mot);
        requete.erase(0, pos + 1); // supprimet(pos,len)


    }
    mots.push_back(requete);
  return mots;
}

vector<string> LecteurFichier::extracter(string cheminfichier)
{
  vector<string> mots;
  string mot;
  ifstream Fichier(cheminfichier);
  ofstream redirect("redirect");
  while (getline(Fichier,mot) )
  {
      transform(mot.begin() ,mot.end(),mot.begin(),::tolower);
      nettoyer(mot);
      redirect<<mot<<endl;
  }
  Fichier.close();
  redirect.close();
  ifstream f("redirect");
  while (f>>mot )
  {

    set<string>:: iterator i = MotVide.find(mot);
    if (i ==MotVide.end() ){
        mots.push_back(mot);
    }
  }
  Fichier.close();
  return mots;


}

