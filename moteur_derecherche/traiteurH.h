#ifndef TRAITEURH_H_INCLUDED
#define TRAITEURH_H_INCLUDED

#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include<map>
#include<set>
#include<cmath>
#include <string>
#include <fstream>
#include <iterator>
#include <vector>
#include<map>
#include<set>
#include<cmath>
#include <string>
#include <algorithm>


using namespace std;
class traiteur
{
public:
    set<char> symbole={'.' ,':',',',';' , '?' , '!','(',')','\n','\t','"','-','/','}','{','&','=','[','['};
    set<string> MotVide={"the","a","with","for","le","la","in","for","to","is","and","de","et","il","elle","a","b","c","d","e","f","g","h","i","j","k","l","g","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
    traiteur(){};
    virtual string nettoyer(string&)=0;//suppression des caracteres symboles qui n'ont aucun sens

};

class ch_maj : public traiteur // rendre la chaine majuscule
{
public:

    string nettoyer(string&);

};

class ch_min : public traiteur// rendre la chaine miniscule
{
public:

    string nettoyer(string&);

};


class supp_symbole : public traiteur //supprime les symboles
{
    public:
    string nettoyer(string&);

};
class remplacer : public traiteur //remplace '/' par '\'
{
public:
    string nettoyer(string&);
};
class sup_occ : public traiteur // suprrimer plusierus "\" succesives
{
public:
    string nettoyer(string&);
} ;
class supp_espace : public traiteur // supprimer les espaces entres les mots
{
    public:
    string nettoyer(string&);
};




#endif // TRAITEURH_H_INCLUDED
