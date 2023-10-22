#ifndef ORDONNANCEURH_H_INCLUDED
#define ORDONNANCEURH_H_INCLUDED
#include<iostream>
using namespace std;


class ordonnanceur
{
    public:

    ordonnanceur(){};
     virtual vector<pair<string, double>> ordonnancer(vector<string> requete,index*)=0;


~ordonnanceur(){};

};

class ordonnanceurscore:public ordonnanceur
{
    public:
     vector<pair<string, double>> ordonnancer(vector<string>,index*);
};
class ordonnanceurprecis :public ordonnanceur
{
public:

ordonnanceurprecis(){};
vector<pair<string, double>> ordonnancer(vector<string>,index*);

};

class ordonnanceurbinaire :public ordonnanceur
{
public:
ordonnanceurbinaire(){};
vector<pair<string, double>> ordonnancer(vector<string>,index*);

};


#endif // ORDONNANCEURH_H_INCLUDED
