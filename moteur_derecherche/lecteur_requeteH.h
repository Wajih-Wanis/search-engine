#ifndef LECTEUR_REQUETEH_H_INCLUDED
#define LECTEUR_REQUETEH_H_INCLUDED
#include<iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include<map>
#include<set>
#include<cmath>
#include <string>
#include <algorithm>

class lecteur_requete
{
public:
    set<string> MotVide={"the","a","with","for","le","la","in","for","to","is","and","et","il","elle","a","b","c","d","e","f","g","h","i","j","k","l","g","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
    lecteur_requete(){};
    vector<string> extracter(string requete);//extraction des mots a partir de le chemin passee comme parametre

};

#endif // LECTEUR_REQUETEH_H_INCLUDED
