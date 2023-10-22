#include<iostream>

#include"AnalyseurH.h"
#include"statistiqueH.h"
#include<unordered_map>


vector<statistique> analyseurocc :: analyser(vector<fichier> vect){
    unordered_map<string,double> occurences;
    vector<statistique> statistiques;
    for(vector<fichier>::iterator i = vect.begin();i != vect.end();i++){
        for(unsigned int j = 0; j < i->contenu.size(); j++)
        {
            occurences[i->contenu.at(j)] += 1;
        }
        for(auto doc : occurences)
        {
        statistique stat(doc.first,doc.second,i->chemin);
        statistiques.push_back(stat);
        }
        occurences.clear();
    }
    return statistiques;
};
vector<statistique> analyseurfreq :: analyser(vector<fichier> vect){
    unordered_map<string,double> occurences;
    vector<statistique> statistiques;
    for(vector<fichier>::iterator i = vect.begin();i != vect.end();i++){
        for(unsigned int j = 0; j < i->contenu.size(); j++)
        {
            occurences[i->contenu.at(j)] += 1.0/(double)(i->contenu.size());
        }
        for(auto doc : occurences)
        {
            statistique stat(doc.first,doc.second,i->chemin);
            statistiques.push_back(stat);
        }
        occurences.clear();
    }
    return statistiques;
};
