#ifndef BIBLIOTHEQUEH_H_INCLUDED
#define BIBLIOTHEQUEH_H_INCLUDED
#include<vector>
#include<set>

using namespace std;
class bibliotheque
{
private:
    string chemin;
    set<string> biblio;
public:
    bibliotheque(const string );
    void ajouter(const string);
    void ajouter (const vector<string>);
    void supprimer(const string );
    void supprimer(const vector<string> );
    void afficher();
    void sauvgarder();
    void restaurer();
    void interface();
    set<string> getbiblio();
    string getchemin();
    bool verif(string);
    friend ostream& operator<<(ostream& ,set<string>& );
    ~bibliotheque();



};


#endif // BIBLIOTHEQUEH_H_INCLUDED
