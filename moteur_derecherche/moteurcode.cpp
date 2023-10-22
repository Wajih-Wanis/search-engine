#include<iostream>
#include<string>
#include"moteurH.h"
#include<vector>
#include<map>
#include"IndexH.h"
#include"lecteur_fichierH.h"
#include"lecteur_requeteH.h"
#include"ordonnanceurH.h"
#include"traiteurH.h"
#include"AnalyseurH.h"
#include"gestionaireH.h"

using namespace std;

bool moteur::exist(string chemin)
{
    FILE *file;
    const char* c;
    c=chemin.c_str();

    if (file = fopen(c, "r"))
    {
        fclose(file);
        return true;
    }
    else
    {
        return false;
    }

}



moteur::moteur(){};

vector<pair<string, double>> moteur::rechercher(vector<string> requete, index* in , ordonnanceur* ordd)
{

     vector<pair<string,double>> vect=ordd->ordonnancer(requete,in);
     vector<pair<string,double>> resultat;
     set<string> s=in->getbasederecherche();
     for(set<string>::iterator itr=s.begin();itr!=s.end();itr++){
        for(vector<pair<string,double>>::iterator it=vect.begin();it!=vect.end();it++){
            if(it->first==(*itr)){
                resultat.push_back(make_pair(it->first,it->second));
            }
        }
     }
     return resultat;



}





