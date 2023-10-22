#ifndef ANALYSEURH_H_INCLUDED
#define ANALYSEURH_H_INCLUDED
#include"statistiqueH.h"
#include<iostream>
#include<vector>
#include"fichierH.h"


using namespace std;


class analyseur
{
    public:
        virtual vector<statistique> analyser(vector<fichier> vect)=0; // la recherche de l’existence et le calcul du nombre d’statistique de chaque mot
};
class analyseurocc: public analyseur
{
public:
    vector<statistique> analyser(vector<fichier> vect);
};

class analyseurfreq: public analyseur
{
public:
    vector<statistique> analyser(vector<fichier> vect);
};
#endif // ANALYSEURH_H_INCLUDED
