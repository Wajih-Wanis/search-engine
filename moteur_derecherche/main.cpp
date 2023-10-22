#include<list>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include<algorithm>
#include <math.h>
#include<set>
#include"BibliothequeH.h"
#include"LecteurH.h"
#include"AnalyseurH.h"
#include"indexH.h"
#include"traiteurH.h"
#include"lecteur_fichierH.h"
#include"lecteur_requeteH.h"
#include"ordonnanceurH.h"
#include <dirent.h>
#include <sys/types.h>
#include"gestionaireH.h"
#include <filesystem>
#include<cstring>
#include"moteurH.h"
#include <chrono>
#include <thread>
#include <windows.h>
#include"IndexH.h"
#include"statistiqueH.h"
#include <iomanip>
#include <ios>
#include<string.h>
#include<exception>
#include <time.h>
using namespace std;

using namespace std::chrono;
using namespace std::this_thread;



int main()
{
    clock_t t1, t2;
    lecteur_requete lr;
    lecteur_fichier lf;
    analyseur *an;
    analyseurocc anoccc;
    analyseurfreq anfrq;
    index *in;
    indexvector inv;
    indexmap inm;
    in=&inv;
    gestionnaireindex gin;
    gestionnairebasederecherhe gbd;
    ordonnanceur *ord;
    ordonnanceurscore ords;
    ordonnanceurprecis ordp;
    ordonnanceurbinaire ordb;
    moteur m;
    int e;
    int en;
    int a,b,f;
    int choix;
    double temps;


    system("color 04");
    cout<<"\t\t\t\t\t|------------BIENVENUE AU SEARCH-X-------------|\n\n\n";
    sleep_until(system_clock::now() + seconds(2));
  system("Cls");

 while(1)
  {


if (!m.exist("configuration.txt"))
{


     cout<<"\t\t\t\t\t|------------CONFIGURATION DU MOTEUR-------------|\n\n\n";

    do{
    f=0;
    cout<<"Choix d'analyseur"<<endl;
    cout<<endl;
    cout<<"Analyseur Frequence : 1"<<endl;
    cout<<"Anlayseur Occurance : 2"<<endl;
    try{
    cin>>a;

    if (!std::cin)
        throw 0;
    }
    catch(int x)
    {
    cin.clear();
    fflush(stdin);
    f=1;
    }
    } while((a!=1) &&(a!=2)&&(f==1));

    if (a==1)
    {
        an=&anfrq;
    }
    if (a==2)
    {
        an=&anoccc;
    }
    system("Cls");
    do{
    int f=0;
    cout<<"Choix de l'index"<<endl;
    cout<<endl;
    cout<<"Index Map : 1"<<endl;
    cout<<"Index Vector : 2"<<endl;
    try{
    cin>>b;
    if (!std::cin)
        throw 0;
    }
    catch(int x)
    {
    cin.clear();
    fflush(stdin);
    f=1;
    }
    } while((b!=1) &&(b!=2)&&(f==1));
    if (b==1)
    {
        in=&inm;
    }
    if (a==2)
    {
        in=&inv;
    }

ofstream file("configuration.txt");
file<<a<<endl;
file<<b<<endl;
file.close();
}
else
{
    ifstream lastfile ("configuration.txt");
    string z;
    string line;
    while (getline(lastfile,line))
    {
        z=z+line;
    }

    if (z[0]=='1')
    {
        an=&anfrq;
    }
    if (z[1]=='2')
    {
        an=&anoccc;
    }
    if (z[0]=='1')
    {
        in=&inm;
    }
    if (z[1]=='2')
    {
        in=&inv;
    }

}
gin.restaurer(in);
gbd.restaurer(in);

e=0;
while (e==0){



    cout << "\n \n \n \n\t\t******************************_____________________________*******************************\n"
    << "\t\t \t************************_______________________________************************\n"
    << "\t\t\t\t\t         _____________MENU_________________\n"
    <<"\n"
    << "\t\t\t\t 1) rechercher des fichiers \n"
    << "\t\t\t\t 2) ajouter un fichier a la base de recherche\n"
    << "\t\t\t\t 3) ajouter un repertoire a la base de recherche\n"
    << "\t\t\t\t 4) supprimer un fichier de la base de recherche\n"
    << "\t\t\t\t 5) afficher les fichiers de la base de recherche\n"
    << "\t\t\t\t 6) indexer un fichier\n"
    << "\t\t\t\t 7) afficher l'index\n"
    << "\t\t\t\t 8) information sur l'index\n"
    << "\t\t\t\t 9) reindexer un fichier\n"
    << "\t\t\t\t10) supprimer un fichier de l'index\n"
    << "\t\t\t\t11) supprimer l'index\n"
    << "\t\t\t\t12) sauvgarder\n"
    << "\t\t\t\t13) reset\n"
    << "\t\t\t\t14) quitter \n\n\n"
    << "saisissez votre choix: \n";
    try {
    cin>>choix;
    if (!std::cin)
        throw 0;
}
catch(int x)
{
cin.clear();
fflush(stdin);
choix=15;
}


    system("Cls");

    switch(choix)
    {
    case 1:
        {
             system("color 01");
            cout<<" \n\n\t\t  _______________________RECHERCHER FICHIERS_____________________\n";
            cout<<endl;
            if(in->getbasederecherche().size()==0)
                cout<<"\t\t l'votre base de recherche est vide, vous ne pouvez pas effectuez une recherche" << endl;
            else
            {
                int f;
                cout<<"\t\t Veuillez entrer votre requete"<<endl;
                string ch;
                int k;
                fflush(stdin);
                getline(cin,ch);
                vector<string> requete=lr.extracter(ch);
                vector<pair<string, double>> resultat;
                cout<<"\t\t Veuillez choisir l'ordonnanceur"<<endl;
                cout<<"orddonnaceur score   : 1"<<endl;
                cout<<"orddonnaceur precis  : 2"<<endl;
                cout<<"orddonnaceur binaire : 3"<<endl;
                do{

                f=0;

                try{
                cin>>k;
                if (!std::cin)
                throw 0;
                }
                catch(int x)
                {
                cin.clear();
                fflush(stdin);
                f=1;
                }}while((k!=1)&&(k!=2)&&(k!=3)&&(f==1));
                if(k==1)
                {
                    ord=&ords;
                }
                if(k==2)
                {
                    ord=&ordp;
                }
                if(k==3)
                {
                    ord=&ordb;
                }

                resultat=m.rechercher(requete ,in,ord);
                if(resultat.size()==0)
                {
                    cout << "\t\t aucun resultat trouve" << endl;
                }
                else
                {
                    cout<<endl<<"\t\t resultats de la recherche: " <<endl;
                    for(vector<pair<string, double>>::iterator i=resultat.begin();i!=resultat.end();++i)
                    {
                        cout<<i->first<<endl;
                        cout<<i->second<<endl;
                    }
                }
            }
            system("pause");
            system("cls");
system("color 04");
            break;

        }

    case 2:
        {
            system("color 01");
            cout<<"\n\n\t\t __________________________AJOUTER FICHIER___________________\n";
            cout<<endl;
            cout<<"\t\t Veuillez donner le chemin du fichier"<<endl;
            string nomfichier;
            cin>>nomfichier;
            if(m.exist(nomfichier))
            {
                int a=0;
                in->ajouter_fichier(nomfichier);
                if(!in->fichierexistebdr(nomfichier))
                {
                    a=1;
                    vector<fichier> f;
                    f=lf.extracter(nomfichier);
                    vector<statistique> vs;
                    vs=an->analyser(f);
                    in->indexer(vs);
                    cout<<"\t\t Votre fichier a ete ajoute avec success ! "<<endl;
                }
                if(a==0)
                    cout<<"\t\t Ce fichier est deja ajoute"<<endl;

            }
            else
            {
                cout<<endl;
                cout<<"\t\t Ce fichier n existe pas"<<endl;

            }

 sleep_until(system_clock::now() + seconds(2));
system("cls");
system("color 04");
            break;


        }
    case 3:
        {
            system("color 01");
            cout<<"\n\n \t\t______________________AJOUTER REPERTOIRE_____________________\n";
            cout<<endl;
            cout<<"\t\t Veuillez donner le chemin du repertoire"<<endl;
            string nomrep;
            cin>>nomrep;
            t1 = clock();
            vector<fichier> rep;
            rep=lf.extracterdir(nomrep);
            if(rep.size()==0)
            {
                cout<<"\t\t repertoire invalide"<<endl;
            }
            else
            {
                in->ajouter_rep(rep);
                vector<statistique> vs;
                vs=an->analyser(rep);
                in->indexer(vs);
                cout<<"\t\t Votre repertoire a ete ajoute avec success ! "<<endl;
                t2 = clock();
                temps = (float)(t2-t1)/CLOCKS_PER_SEC;
                printf("temps = %f\n", temps);

            }
            sleep_until(system_clock::now() + seconds(3));
            system("cls");
            system("color 04");
            break;
        }
    case 4:
        {
            system("color 01");
            cout<<"\n\n \t\t___________________SUPPRIMER FICHIER____________________\n";
            cout<<endl;
            if(in->bdr_vide())
            {
                cout<<"votre base de recherche est vide"<<endl;
            }
            else
            {
            cout<<"\t\t Veuillez donner le chemin du fichier à supprimer"<<endl;
            string ch;
            cin>>ch;
            if(in->fichierexistebdr(ch))
            {
                in->supprimer_fichier(ch);
                cout<<"\t\t Votre fichier a ete supprime de la base de recherche"<<endl;
            }
            else
                cout<<"\t\t le fichier n existe pas dans la base de recherche"<<endl;
            }
            sleep_until(system_clock::now() + seconds(2));
            system("cls");
            system("color 04");
            break;
        }
    case 5:
        {
            system("color 01");
            cout<<"\n\n\t\t ________________________AFFICHER FICHIERS________________________\n";
            cout<<endl;
            set<string> s;
            s=in->getbasederecherche();
            if(in->bdr_vide())
                cout<<"votre base de recherche est vide"<<endl;
            else
            {
                 for(set<string>::iterator i=s.begin();i!=s.end();++i)
            {
                cout<<*i<<endl;
            }

            }

            system("pause");
            system("cls");
            system("color 04");
            break;

        }
    case 6:
        {
            system("color 01");
            cout<<"\n\n\t\t __________________________INDEXER FICHIERS________________________\n";
            cout<<endl;
            cout<<"\t\t Veuillez donner le chemin du fichier a indexer"<<endl;
            string nomfichier;
            cin>>nomfichier;
            if(m.exist(nomfichier))
            {
                int a=0;
                if((!in->fichierexiste(nomfichier)))
                   {
                      a=1;

                vector<fichier> f;
                f=lf.extracter(nomfichier);
                vector<statistique> vs;
                vs=an->analyser(f);
                in->indexer(vs);
                cout<<"\t\t Votre fichier a ete indexe avec success ! "<<endl;
                   }
                if(a==0)
                    cout<<"ce fichier est deja indexe"<<endl;
            }
            else
                cout<<"\t\t Ce fichier n existe pas"<<endl;

            sleep_until(system_clock::now() + seconds(2));
            system("cls");
            system("color 04");
            break;


        }
    case 7:
        {
            system("color 01");
            cout<<"\n\n\t\t _______________________AFFICHER INDEX_________________________\n";
            vector<statistique> v;
            v=in->getindex();
            for(vector<statistique>::iterator it=v.begin();it!=v.end();++it)
            {
                cout<<setw(15)<<it->getmot()<<" "<<setw(10)<<it->getchemin()<<" "<<it->getstat()<<endl;
            }
            cout<<endl;
            cout<<"\t\tStatistique de l'index:\n"<<endl;
            cout<<"\t\t___________________________________________________________"<< endl;
            cout<<"\t\tNombre de document textuelles                             :"<<in->bibliotheque.size()<<endl;
            cout<<"\t\tTotal nombre de mots dans le corpus                       :"<<in->getindex().size()<<endl;
            cout<<"\t\t___________________________________________________________"<< endl;
            system("pause");
            system("cls");
            system("color 04");
            break;
        }
    case 8:
        {
            system("color 01");
            vector<statistique> v;
            v=in->getindex();
            cout<<"\t\tStatistique de l'index:\n"<<endl;
            cout<<"\t\t___________________________________________________________"<< endl;
            cout<<"\t\tNombre de document textuelles                             :"<<in->bibliotheque.size()<<endl;
            cout<<"\t\tTotal nombre de mots dans le corpus                       :"<<in->getindex().size()<<endl;
            cout<<"\t\t___________________________________________________________"<< endl;
            system("pause");
            system("cls");
            system("color 04");
            break;


        }
    case 9:
        {
            system("color 01");
            cout <<"\n\n\t\t_________________________REINDEXER FICHIER_________________________\n";
            cout<<"\t\tVeuillez donner le chemin du fichier"<<endl;
            string ch;
            cin>>ch;
            if(m.exist(ch)&& (in->fichierexiste(ch)))
            {
                vector<fichier> f;
                f=lf.extracter(ch);
                vector<statistique> vs;
                vs=an->analyser(f);
                in->reindexer(vs);
                cout<<"\t\t Votre fichier a ete reindexe avec success ! "<<endl;
            }
            else
            {
                cout<<"\t\tCe fichier n'existe pas dans l index"<<endl;
                cout<<"\t\t veuillez l indexer"<<endl;
            }
            sleep_until(system_clock::now() + seconds(3));
            system("cls");
            system("color 04");
            break;
        }
    case 10:
        {
            system("color 01");
            cout << "\n\n\t\t___________________________SUPPRIMER FICHIER INDEX_________________________\n";
            cout<<endl;
            cout<<"\t\tVeuillez donner le chemin du fichier"<<endl;
            string ch;
            cin>>ch;
            if(in->fichierexiste(ch))
            {
                in->supprimerfichierindex(ch);
                in->supprimer_fichier(ch);
                cout<<"\t\t Le fichier a ete supprime de l'index"<<endl;
            }
            else
                cout<<"\t\t le fichier n'existe pas dans l index"<<endl;

            sleep_until(system_clock::now() + seconds(3));
            system("cls");
            system("color 04");
            break;
        }
    case 11:
        {
            system("color 01");
            cout << "\n\n\t\t________________________SUPRRIMER INDEX ________________________\n";
            in->supprimerindex();
            in->supprimerbder();
            cout<<endl;
            cout<<"\t\t l'index est supprime"<<endl;
            sleep_until(system_clock::now() + seconds(3));
            system("cls");
            system("color 04");
            break;
        }
    case 12:
        {
            system("color 01");
            gin.sauvgarder(in);
            gbd.sauvgarder(in);
            cout<<" Votre travail est bien enregistre "<<endl;
            sleep_until(system_clock::now() + seconds(3));
            system("cls");
            system("color 04");
            break;
        }
    case 13:
        {
            cout<<"etes vous sur ?"<<endl;
            do
            {

            cout<<"tapez 1 pour proceder"<<endl;
            cout<<"tapez 2 pour retourner au Menu"<<endl;
            try {
            cin>>e;
            if (!std::cin)
            throw 0;
                }
            catch(int x)
            {
            cin.clear();
            fflush(stdin);
            system("cls");

            }
            }while((e!=1)&&(e!=2));
            if (e==1)
            {
                remove("configuration.txt");
                remove("index.txt");
                remove("basederecherche.txt");
                en+=1;
            }
            if(e==2)
            {

            }
            system("cls");

            break;
        }
    case 14:
        {
            exit(0);
        }

    case 15:
        {cout<<"choix invalide"<<endl;
         system("pause");
         system("cls");
         }
    }
}
}
}















