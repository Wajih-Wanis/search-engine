#ifndef STATISTIQUEH_H_INCLUDED
#define STATISTIQUEH_H_INCLUDED
using namespace std;
class statistique
{
    private:
        string mot;
        double stat;
        string chemin;
    public:
        statistique();
        statistique(string mot,double stat,string chemin);
        string getmot() const;
        double getstat() const;
        string getchemin() const;
        statistique& operator=(statistique s);
};//stockage de triplet, un mot et son nombre d'statistique dans un fichier donné (chemin)

#endif // STATISTIQUEH_H_INCLUDED
