#include<iostream>
#include"lecteur_fichierH.h"
#include <fstream>
#include <iterator>
#include <vector>
#include<map>
#include<set>
#include<cmath>
#include <string>
#include"traiteurH.h"
#include <dirent.h>
#include <sys/types.h>
#include"fichierH.h"
#include"AnalyseurH.h"
#include<sstream>


using namespace std;


vector<fichier> lecteur_fichier::extracter(string cheminfichier)
{

    vector<fichier> vectfichiers;
    vector<string> mots;
    vector<string> mots1;
    string mot;

    ifstream Fich(cheminfichier);
    ch_min ch;
    supp_symbole s;
    while (getline(Fich,mot) ){
        mot=ch.nettoyer(mot);
        string one;
        mot=s.nettoyer(mot);
        stringstream iss(mot);
        while (iss >> one){
            mots1.push_back(one);
        }
    }
    Fich.close();
    for(vector<string>::iterator j = mots1.begin(); j != mots1.end(); j++){
        set<string>:: iterator i = MotVide.find(*j);
        if (i == MotVide.end()){
            mots.push_back(*j);
        }
    }
    fichier fi(cheminfichier,mots);
    vectfichiers.push_back(fi);


    return vectfichiers ;
}

vector<fichier> lecteur_fichier::extracterdir(string repertoire)
{
    if (!(repertoire[repertoire.length()-1] == '\\')){
        repertoire += '\\';
    }
    vector<fichier> fichiers;
    const char * c = repertoire.c_str();
    DIR *dr;
    struct dirent *en;
    dr = opendir(c);
    if (!dr){
        cout << "No such directory !" << endl;
    }
    else {
        while ((en = readdir(dr)) != NULL) {
            if((string(en->d_name).find(".TXT",string(en->d_name).length()-4)!=std::string::npos)
                ||(string(en->d_name).find(".txt",string(en->d_name).length()-4)!=std::string::npos)){
                string chemin = repertoire + en->d_name;
                vector<fichier> vectfich;
                vectfich = extracter(chemin);
                fichiers.push_back(vectfich.back());

            }
        }
        closedir(dr);
    }
    return  fichiers;
};
