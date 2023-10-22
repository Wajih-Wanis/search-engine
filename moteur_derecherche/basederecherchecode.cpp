#include<iostream>
#include<set>
#include"basederecherhceH.h"

using namespace std;

basederecherche::basederecherche(){};

void basederecherche::ajouter_basederecherche(string chemin)
{
    sup_occ occ;
    chemin=occ.nettoyer(chemin);
    base.insert(chemin);
}

void basederecherche::supprimer_basederecherche(string chemin){
    auto iter = base.find(chemin);
    if (iter != base.end()){
        base.erase(iter);
    }
}

set<string> basederecherche:: getbase()
{
    return base;
}
