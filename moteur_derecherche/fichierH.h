#ifndef FICHIERH_H_INCLUDED
#define FICHIERH_H_INCLUDED
#include<iostream>

using namespace std;

class fichier{
    public:
        fichier(string chemin, vector<string> contenu):chemin(chemin),contenu(contenu){};
        fichier(){};
        string chemin;
        vector<string> contenu;
};



#endif // FICHIERH_H_INCLUDED
