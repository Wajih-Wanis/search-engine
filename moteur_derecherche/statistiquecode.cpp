#include<iostream>
#include<set>
#include<string>
#include <fstream>
#include <iterator>
#include <vector>
#include<map>
#include<set>
#include<cmath>
#include <string>
#include"statistiqueH.h"

using namespace std;

statistique::statistique(){}
statistique::statistique(string mot,double stat,string chemin){
    this->mot = mot;
    this->chemin = chemin;
    this->stat = stat;
}
string statistique::getchemin() const{
    return chemin;
}
string statistique::getmot() const{
    return mot;
}
double statistique::getstat() const{
    return stat;
}


statistique& statistique::operator=(statistique s){

    if(&s!=this){
        mot = s.mot;
        stat = s.stat;
        chemin=s.chemin;
    }
    return *this;
}

