#include<iostream>
#include<vector>
#include<set>
#include"IndexH.h"
#include"statistiqueH.h"
#include <iomanip>
#include <ios>
#include<string.h>
#include"ordonnanceurH.h"
#include<algorithm>
#include<string>
#include <bits/stdc++.h>

using namespace std;

vector<string> intersection(vector<string> &v1,vector<string> &v2){
    vector<std::string> v3;
    if (v2.empty() || v1.empty())
    {
       v2.clear();
       return v2;
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(v3));
    return v3;
}
 bool cmp(pair<string, double>& a,pair<string, double>& b){
        return a.second > b.second;
    };

 vector<pair<string, double>> ordonnanceurscore :: ordonnancer(vector<string> e,index* ind){
    map<string,double> m;
    vector<statistique> v;
    for (vector<string> ::iterator i = e.begin();i!= e.end();i++){
        v=ind->getstat(*i);
        for (vector<statistique> ::iterator  j=v.begin();j!=v.end();j++){

            m[j->getchemin()]+=j->getstat();
        }
    }
    vector<pair<string, double>> A;
    for (auto& it : m) {
        A.push_back(it);
    };
    sort(A.begin(),A.end(), cmp);
    return A;
}

vector<pair<string, double>> ordonnanceurprecis::ordonnancer(vector<string> V, index *ind){
    vector<pair<string, double>> Vect;
    vector<statistique> v1,v2;
    vector<string> v,tempor,vr;
    string word;
    word=V[0];
    v1=ind->getstat(word);
    for (vector<statistique> ::iterator  j=v1.begin();j!=v1.end();j++){
        v.push_back(j->getchemin());
    }
    for (unsigned int itr=1;itr<V.size();itr++){
        v2=ind->getstat(V[itr]);

        if(v2.size()==0)
        {
            Vect.clear();
            return Vect;
        }
        unsigned int j=0;
        while(j<v2.size()){
            tempor.push_back(v2[j].getchemin());
            j++;
        }
    v=intersection(v,tempor);
    }
    for (vector<string> ::iterator i = v.begin();i!= v.end();i++){
        Vect.push_back(make_pair(*i,1));
    }
    return Vect;
}



vector<pair<string,double>> ordonnanceurbinaire :: ordonnancer(vector<string> e,index* ind)
{

    vector<pair<string,double>> vect;
    map<string,double> m;
    vector<statistique> v,v1;
    for (vector<string> ::iterator i = e.begin();i!= e.end();i++){
        v=ind->getstat(*i);
        for (vector<statistique> ::iterator  j=v.begin();j!=v.end();j++){
       		m[j->getchemin()]+=1;
        }
    }

    for (auto& it : m) {
        vect.push_back(it);
        }

    sort(vect.begin(),vect.end(), cmp);

    map<string,double> M1;
    bool test=true;
    for (vector<string> ::iterator i = e.begin();i!= e.end();i++){
        v=ind->getstat(*i);
        for (vector<statistique> ::iterator  j=v.begin();j!=v.end();j++){

            M1[j->getchemin()]+=j->getstat();
        }
    }
    while(test){
        test=false;

        for(vector<pair<string,double>>::iterator i=vect.begin();i!=vect.end()-1;i++){
            map<string,double> ::iterator a=M1.find((i)->first);
            map<string,double> ::iterator b=M1.find((i+1)->first);
            if(((i->second) ==((i+1)->second))&&((a->second) < (b->second)))
                {
                test=true;
                i->swap(*(i+1));
                }
        }
    }
    return vect;
}


