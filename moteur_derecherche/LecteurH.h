#ifndef LECTEURH_H_INCLUDED
#define LECTEURH_H_INCLUDED
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
class lecteur
{
public:
    set<char> symbole={'.' ,':',',',';' , '?' , '!','(',')','\n','\t','"','-'};
    set<string> MotVide={"the","a","with","for","le","la","in","for","to","is","and","et","il","elle"};
    lecteur();
    void nettoyer(string&);//suppression des caracteres symboles qui n'ont aucun sens
    virtual vector<string> extracter(string)=0;
    ~lecteur();
};

class LecteurFichier : public lecteur
{
public:
    LecteurFichier();
    vector<string> extracter(string); //extraction des mots d'un fichier ou son chemin est passe comme parametre
    friend ostream& operator<<(ostream& flux ,vector<string>& );
};

class LecteurRequete : public lecteur
{
public:
    LecteurRequete();
    vector<string> extracter(string);//extraction des mots a partir d'une chaine de caractere passee comme parametre

};

#endif // LECTEURH_H_INCLUDED
