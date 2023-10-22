#ifndef MOTEUR_H_INCLUDED
#define MOTEUR_H_INCLUDED
#include<string>
#include<vector>
#include<map>
using namespace std;
/////////////////////statistique//////////////////
class stat
{
    private:
        string mot;
        int nbrocc;
        string chemin;
    public:
        stat(string mot,int nbrocc,string chemin);
        ~stat();
        void setnbrocc(int nbrocc);
        string getmot() const;
        int getnbrocc() const;
        string getchemin() const;

};//stockage de triplet, un mot et son nombre d'statistique dans un fichier donné (chemin)

//////////////////////////////////////////////////Analyseur/////////////////////
 class analyseur
{
    public:
    analyseur();
    virtual vector<statistique> analyser(vector<string> vect)=0; // la recherche de l’existence et le calcul du nombre d’statistique de chaque mot
    ~analyseur();

};
class analyseurMap: public analyseur
{
public:
    vector<statistique> analyser(vector<string> vect)
    ~analyseurMap

};

class analyseurVector: public analyseur
{
public:
    vector<statistique> analyser(vector<string> vect)

    ~analyseurVector
};


//////////////////lecteur/////////////:
class lecteur
{
    string chemin;
    public:
        lecteur();
        void clean(string s);
};


////////////////////////////fichier/////////////////////////
class fichier
{
   private:
        string chemin;
   public:
        fichier(string chemin, analyseur *an);
        ~fichier();
        void setchemin(string chemin);
        string getchemin() const;
        int nbrmots();
};
//////////////////index/////////////
class index
{
    private:
        string chemin;
        vector<statistique> valeurs_index;
    public:
        index(string chemin);
        void setindex();
        vector<statistique> getindex() const;
        virtual  indexerFichier(fichier fich)=0;
        void supprimer_index(string chemin);
        vector<statistique> getstat(string mot); //retourner un vecteur d'occurance qui contient les fichiers qui contiennent le mot donné en parametre ainsi que leur occurance
        void sauvegarderindex(string chemin);
       ~index();

};
class indexVector : public index
{
public:
    indexVector();
    void indexerFichier(fichier fich);
};

class IndexMap: public Index
{
public:
    IndexMap();
    void indexerFichier(fichier fich);
};



///////////////ordonnanceur///////////////////////
class ordonanceur
{
public:
    ordonanceur();
    virtual map<string,int>  trier(vector<statistique>)=0;
    ~ordonanceur();
};

class ordonanceurBinaire:public  ordonanceur
{
public:
    void map<string,int>  trier(vector<statistique>);
    ~ordonanceurBinaire;
};
class ordonanceurOcc:public  ordonanceur
{
public:
    void map<string,int>  trier(vector<statistique>);
    ~ordonanceurOcc;
};

/////////////////moteur////////////
class moteur
{
private:
    analyseur *an;
    index *ind;
    ordonanceur *ord;
    bibliotheque *bib;
public:
    void ajouter_fichier(string chemin);
    void ajouter_plusfichier(vector<string> ch);
    void supprimer_fich(string s);
    void afficher_bib();
    void afficherindex();
    void reindexer(string s);
    map<string,int> rechercher(vector<string> requete);
    void getstat();

};


#endif // MOTEUR_H_INCLUDED
