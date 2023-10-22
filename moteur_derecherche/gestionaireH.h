#ifndef GESTIONAIREH_H_INCLUDED
#define GESTIONAIREH_H_INCLUDED

#include<iostream>
#include"IndexH.h"
#include<set>
#include<string>
#include <fstream>
#include <iterator>
#include <vector>
#include<map>
#include<set>
#include<cmath>
#include <string>
#include <sstream>

class gestionnaire
{
public:
    gestionnaire(){};
    virtual void sauvgarder(index*)=0;
    virtual void restaurer(index *)=0;
};

class gestionnaireindex : public gestionnaire
{
public:
    gestionnaireindex(){};
    void sauvgarder(index *);
    void restaurer(index*) ;
};
class gestionnairebasederecherhe: public gestionnaire
{
public:
    gestionnairebasederecherhe(){};
    void sauvgarder(index *);
    void restaurer(index*) ;
};

#endif // GESTIONAIREH_H_INCLUDED
