#ifndef MOTEURH_H_INCLUDED
#define MOTEURH_H_INCLUDED

#include<iostream>
#include<vector>
#include"IndexH.h"
#include"ordonnanceurH.h"

using namespace std;
class moteur
{
public:
    moteur();
    bool exist(string chemin);
    vector<pair<string, double>> rechercher(vector<string> requete, index* , ordonnanceur*);
};

#endif // MOTEURH_H_INCLUDED
