#ifndef INDEXH_H_INCLUDED
#define INDEXH_H_INCLUDED
#include<set>
#include"statistiqueH.h"
#include<map>
#include<vector>
#include"AnalyseurH.h"
#include"lecteur_fichierH.h"
using namespace std;
class index
{
public:
    set<string> bibliotheque;
    set<string> basederecherche;

public:
    index();
     void ajouter_fichier(string chemin);//ajouter un fichier a la base de recherche
     void ajouter_rep (vector<fichier>);//ajouter un repertoire a la base de recherche
     void supprimerbder();// vider la base de recherche
     bool biblio_vide(); //verif si l'index est vide
    bool bdr_vide(); //verif si la base de recherche est vide
    void supprimer_fichier(string chemin); //supprmier un fichier de la base de recherche
    set<string> getbasederecherche(); //retourne la base de recherche
    bool fichierexistebdr(string chemin );// verif l existance d'un fichier dans la base de recherche
    bool fichierexiste(string chemin ); // verif l existance d'un fichier dans l'index
    virtual vector<statistique> getindex()=0;
    virtual void indexer(vector<statistique>)=0;
    virtual void supprimerfichierindex(string)=0; //supprmier un fichier de l'index
    virtual void reindexer(vector<statistique>)=0;
    virtual vector<statistique> getstat(string)=0; //retourne la statistique d'un mot
    set<string> getbiblio(); //retourne la bibliotheque
    virtual void supprimerindex()=0; //vider l'index
    ~index();
};
class indexvector : public index
{

    vector<statistique> bdindexv;
public:
    indexvector();
    vector<statistique> getindex();
    void indexer(vector<statistique>);
    void supprimerfichierindex(string);
    void reindexer(vector<statistique>);
    vector<statistique> getstat(string);
    friend ostream& operator<<(ostream& flux ,vector<statistique>& t);
    void supprimerindex();

};

class indexmap : public index
{
    map<string,map<string,double> >bdindexm;
public:
    indexmap(){};
    vector<statistique> getindex();
    void indexer(vector<statistique>);
    void supprimerfichierindex(string);
    void reindexer(vector<statistique>) ;
    map<string,map<string,double>> getbdindex() const {
        return bdindexm;
    };
    void supprimerindex();
    vector<statistique> getstat(string);
     friend ostream& operator<<(ostream& flux ,indexmap& index);
};



#endif // INDEXH_H_INCLUDED
