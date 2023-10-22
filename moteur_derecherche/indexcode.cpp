#include<iostream>
#include<vector>
#include<set>
#include"IndexH.h"
#include"statistiqueH.h"
#include <iomanip>
#include <ios>
#include<string.h>
#include <algorithm>
#include"gestionaireH.h"

using namespace std;


index::index(){};
index::~index(){};

indexvector::indexvector(){};

bool index ::biblio_vide()
{
    if(bibliotheque.size()==0)
        return true;
    else
        return false;
}

void indexvector::indexer(vector<statistique> v)
{

    for(vector<statistique>::iterator i=v.begin();i!=v.end();++i)
    {
     bdindexv.push_back(*i);
       bibliotheque.insert(i->getchemin());
    }
}


void indexvector::supprimerfichierindex(string chemin){
    for(vector<statistique> ::iterator i=bdindexv.begin();i!=bdindexv.end();i++)
    {
        string ch;
        ch=i->getchemin();
        if (chemin==ch)
        {
            bdindexv.erase(i);
            bibliotheque.erase(ch);
            basederecherche.erase(ch);
            i--;
        }

    }

};
void indexvector:: reindexer(vector<statistique> v)
{
    string a;
    a=v.at(0).getchemin();
    supprimerfichierindex(a);
    indexer(v);
};




ostream& operator<<(ostream& flux ,vector<statistique>& t){
  for (vector<statistique>::iterator it =t.begin() ; it!=t.end() ; ++it )
  {
    flux<<setw(15)<<it->getmot()<<" "<<setw(10)<<it->getchemin()<<" "<<it->getstat()<<endl;
  }
  return flux;
}



vector<statistique> indexvector:: getstat(string mot)
{
    vector<statistique> v;


    for(unsigned int i=0;i<=bdindexv.size();i++)
    {

        if(bdindexv[i].getmot()==mot)
        {
            v.push_back(bdindexv[i]);

        }
    }
    return v;
}





void indexmap:: indexer(vector<statistique> vect){


    for(vector<statistique>::iterator i = vect.begin();i != vect.end(); i++)
    {
        bdindexm[i->getmot()].insert(pair<string,double>(i->getchemin(),i->getstat()));
        bibliotheque.insert(i->getchemin());
    }
};


void indexmap::supprimerfichierindex(string chemin)
{
    auto iter = bibliotheque.find(chemin);
    if (iter != bibliotheque.end()){
        bibliotheque.erase(iter);
        basederecherche.erase(chemin);
        for(map<string,map<string,double>>::iterator i = bdindexm.begin(); i != bdindexm.end(); i++){
            i->second.erase(chemin);
            if(i->second.empty()){
                bdindexm.erase(i);

            }
        };
    };
};




ostream& operator<<(ostream& flux ,indexmap& index){
    map<string,map<string,double>> bdindex = index.getbdindex();
    vector<statistique> v;
    for(map<string,map<string,double>>::iterator i = bdindex.begin(); i != bdindex.end(); i++){
        for (map<string,double>::iterator it =i->second.begin() ; it!= i->second.end() ; ++it ){
                statistique stat(i->first,it->second,it->first);
                v.push_back(stat);
        }
    };
    struct {
        bool operator()(statistique a, statistique b) const { return a.getchemin() < b.getchemin(); }
    } customLess;
    sort(v.begin(),v.end(),customLess);
    for (vector<statistique> ::iterator it =v.begin() ; it!=v.end() ; ++it ){
        flux<<setw(15)<<it->getmot()<<" "<<setw(10)<<it->getchemin()<<" "<<it->getstat()<<endl;
    }
    return flux;
};





vector<statistique> indexmap::getstat(string mot){
    vector<statistique> vstats;
    vstats.clear();
    statistique s;
    auto motstat = bdindexm.find(mot);
    if( motstat != bdindexm.end()){
        for(map<string,double>::iterator i = motstat->second.begin() ; i != motstat->second.end() ; ++i){
            s = statistique(mot, i->second, i->first);
            vstats.push_back(s);
        }

    }
    return vstats;

};

vector<statistique> indexmap:: getindex()
{
      map<string,map<string,double>> bdindex =getbdindex();
    vector<statistique> v;
    for(map<string,map<string,double>>::iterator i = bdindex.begin(); i != bdindex.end(); i++){
        for (map<string,double>::iterator it =i->second.begin() ; it!= i->second.end() ; ++it ){
                statistique stat(i->first,it->second,it->first);
                v.push_back(stat);
        }
    }
    return v;

}

vector<statistique> indexvector:: getindex(){return bdindexv;}

bool index::fichierexiste(string chemin)
{
    if (bibliotheque.size()!=0)
    {
        for(set<string> :: iterator i=bibliotheque.begin();i!=bibliotheque.end();++i)
        {
            if(*i==chemin)
                return true;
            else
                return false;
        }
    }
return false;
}
void indexvector::supprimerindex()
{
     bdindexv.clear();
     bibliotheque.clear();
}
void indexmap::supprimerindex()
{
     bdindexm.clear();
     bibliotheque.clear();
}

void indexmap::reindexer(vector<statistique> vect) {
    supprimerfichierindex(vect[0].getchemin());
    indexer(vect);
};

void index::ajouter_fichier(string chemin)
{
    basederecherche.insert(chemin);
}
void index ::supprimer_fichier(string chemin)
{
    basederecherche.erase(chemin);
}

set<string> index::getbasederecherche()
{
    return basederecherche;
}

void index::ajouter_rep(vector<fichier> v)
{
    for(vector<fichier>::iterator i=v.begin();i!=v.end();++i)
    {
        basederecherche.insert(i->chemin);
    }

}
bool index::fichierexistebdr(string chemin )
    {
    if (basederecherche.size()!=0)
    {
        for(set<string> :: iterator i=basederecherche.begin();i!=basederecherche.end();++i)
        {
            if(*i==chemin)
                return true;
            else
                return false;
        }
    }
    return false;
    }

bool index::bdr_vide()
{
    if(basederecherche.size()==0)
        return true;
    else
        return false;
}

void index::supprimerbder()
{
    basederecherche.clear();
}
