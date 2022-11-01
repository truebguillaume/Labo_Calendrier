//---------------------------------------------------------
// Demo           : ModelCpp
// Fichier        : ModelCpp.cpp
// Auteur(s)      : Trüeb Guillaume
// But            : Modèle pour démarrer un projet en C++
// Modifications  :
// Remarque(s)    : -
// Compilateur    : Apple clang version 14.0.0
// C++ version    : C++20
//---------------------------------------------------------

#include <iostream> //cout, cin
#include <iomanip>  //setprecision, setw
#include <cstdlib>  //EXIT_SUCCESS
#include <limits>   //numeric_limits
#include <string>   //string

#define VIDER_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')

using namespace std;

int  saisieUtilisateur(string, int, int);
bool estBissextille(int);
void afficherCalendrier(int,bool);


int main() {
   const int ANNEE_MIN = 1800;
   const int ANNEE_MAX = 2100;

   saisieUtilisateur("Entrer une annee [1800 et 2100] : ", ANNEE_MIN, ANNEE_MAX);

    cout << "Hello World!" ;
    return EXIT_SUCCESS;
}

bool estBissextille(int annee) {
    return (annee % 4 == 0 && annee % 100 != 0) || annee % 400 == 0;
}

int  saisieUtilisateur(string msg, int min, int max) {
    int annee;
    bool erreur;
    const string MSG_ERREUR = "/!\\ veuillez saisir une année entre 1800 et 2100 ..."s;
    do {
        // message et saisie
        cout << msg;
        erreur = not(cin >> annee) or annee < min or annee > max;

        if (erreur) {
            cout << MSG_ERREUR << endl;
            cin.clear();
        }
    }while(erreur);
}

void afficherCalendrier(int annee, bool bissextile) {
    for (int mois = 1; mois <= 12; mois++)
    {
        cout << "Janvier " << annee << endl;
        cout << "Lun Mar Mer Jeu Ven Sam Dim" << endl;
        for(int jour = 1; jour <= 31; jour++)
        {
            cout << setw(2) << jour << "/" << setw(2) << mois << "/" << annee << endl;
        }
    }
}