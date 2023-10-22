#include<iostream>
#include<set>
#include<vector>
#include "BibliothequeH.h"

bibliotheque::bibliotheque(const string chemin):chemin(chemin){};

string bibliotheque::getchemin()
{
    return this->chemin;
}
bibliotheque::~bibliotheque(){};
set<string> bibliotheque::getbiblio()
{
    return this->biblio;
}

void bibliotheque::ajouter( string document)
{
    biblio.emplace(document);
}
void bibliotheque::ajouter( vector<string> document)
{
    for(vector<string>::iterator i=document.begin();i!=document.end(); ++i)
    {
        ajouter(*i);
    }
}

void bibliotheque::supprimer(string document)
{
    set<string>::iterator i;
    i=biblio.find(document);
    if(i!=biblio.end())
    {
            biblio.erase(i);
    }
}
void bibliotheque::supprimer(vector<string> document)
{
    for(vector<string>:: iterator i= document.begin(); i!=document.end();++i)
    {
        supprimer(*i);
    }
}
ostream& operator<<(ostream& flux ,set<string>& s){
 for (set<string>::iterator i =s.begin() ; i!=s.end() ; ++i )
 {
   flux<<*i<<endl;
 }
 return flux;
};
void bibliotheque:: afficher()
{
    cout<<"                bibliotheque       "<<endl;
     cout<<"_______________________________________________________"<< endl;
     cout<<"Bibliotheque contient "<<biblio.size()<<" document"<<endl;
     cout<<"_______________________________________________________"<< endl;
     if (!biblio.empty()){
        cout<<biblio;
     }else{
        cout<<"         vide   "<<endl;
     }
    cout<<"_____________________________________________________"<< endl;

}



