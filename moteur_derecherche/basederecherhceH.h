#ifndef BASEDERECHERHCEH_H_INCLUDED
#define BASEDERECHERHCEH_H_INCLUDED
#include<iostream>
#include"traiteurH.h"
#include<set>

using namespace std;

class basederecherche
{
    set<string> base;
public:
    basederecherche();
    set<string> getbase();
    void ajouter_basederecherche(string chemin);
    void supprimer_basederecherche(string chemin);
};

#endif // BASEDERECHERHCEH_H_INCLUDED
