#ifndef LECTEUR_FICHIERH_H_INCLUDED
#define LECTEUR_FICHIERH_H_INCLUDED

#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include<map>
#include<set>
#include<cmath>
#include <string>
#include <algorithm>
#include"traiteurH.h"
#include"lecteur_fichierH.h"
#include <dirent.h>
#include <sys/types.h>
#include"fichierH.h"


class lecteur_fichier
{
    public:
    set<string> MotVide={"the","a","with","for","le","la","in","for","to","is","and","de","et","il","elle","a","b","c","d","e","f","g","h","i","j","k","l","g","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
        lecteur_fichier(){};
        vector<fichier> extracter(string chemin ); //extraction des mots d'un fichier ou son chemin est passe comme parametre
        vector<fichier> extracterdir(string repertoire);
};





#endif // LECTEUR_FICHIERH_H_INCLUDED
