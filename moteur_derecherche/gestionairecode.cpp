#include<iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include<map>
#include<set>
#include<cmath>
#include <string>
#include"gestionaireH.h"
#include"IndexH.h"
using namespace std;

void gestionnaireindex::sauvgarder(index *in)
{
    ofstream fichier ("index.txt");
    vector<statistique> v;
    v=in->getindex();
    string m;
    string ch;
    double stat;
    for(vector<statistique>::iterator i=v.begin();i!=v.end();++i)
    {
        m=i->getmot();
        ch=i->getchemin();
        stat=i->getstat();
        fichier <<m<<" " <<ch<<" "<<stat<<endl;
    }
    fichier.close();

}

void gestionnaireindex::restaurer(index* in)
{
    ifstream index ("index.txt");
    string line , mot , chemin;
    double occ;
    vector<statistique> v;
    vector<statistique> a;
    a=in->getindex();
    while(getline(index,line))
    {
        istringstream iss(line);
        iss>>mot;
        iss>>chemin;
        iss>>occ;
        statistique s(mot,occ,chemin);
        int aa=0;

        for(vector<statistique>::iterator k=a.begin();k!=a.end();++k)
        {
            if((mot==k->getmot()) &&   (occ==k->getstat()) &&(chemin==k->getchemin()))
               {
                   aa=1;
               }
        }
        if((aa==0)|| (a.size()==0))
        {
            v.push_back(s);
        }


    }
    in->indexer(v);
}

void gestionnairebasederecherhe::sauvgarder(index *in)
{
    ofstream fichier ("basederecherche.txt");
    set<string> v;
    v=in->getbasederecherche();
    string m;

    for(set<string>::iterator i=v.begin();i!=v.end();++i)
    {
        m=*i;
        fichier <<*i<<endl;
    }
    fichier.close();


}


void gestionnairebasederecherhe::restaurer(index* in)
{
    ifstream fichier ("basederecherche.txt");
    string line , mot , chemin;
    vector<statistique> v;
    set<string> a;
    a=in->getbasederecherche();
    while(getline(fichier,line))
    {
        in->ajouter_fichier(line);
    }

}
