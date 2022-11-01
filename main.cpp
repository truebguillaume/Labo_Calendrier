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

int  saisieUtilisateur(const string&, int, int, const string&);
bool estBissextille(int);
void afficherCalendrier(int);
void detailsMois(int, bool, int&, string&);

int main() {
   const int ANNEE_MIN = 1800;
   const int ANNEE_MAX = 2100;
   const string MSG_ERREUR = "/!\\ veuillez saisir une année entre 1800 et 2100 ...";
   const string MSG = "Entrer une annee [1800 et 2100] : ";
   int annee = saisieUtilisateur(MSG, ANNEE_MIN, ANNEE_MAX, MSG_ERREUR);

   afficherCalendrier(annee);

    return EXIT_SUCCESS;
}

bool estBissextille(int annee) {
    return (annee % 4 == 0 && annee % 100 != 0) || annee % 400 == 0;
}

int saisieUtilisateur(const string& msg, int min, int max, const string& MSG_ERREUR) {
    int annee;
    bool erreur;

    do {
        // message et saisie
        cout << msg;
        erreur = not(cin >> annee) or annee < min or annee > max;

        if (erreur) {
            cout << MSG_ERREUR << endl;
            cin.clear();
        }
    }while(erreur);
    VIDER_BUFFER;

    return annee;
}

void detailsMois(int numMois, bool bissextille, int& nbJours, string& mois){

    switch (numMois) {
        case 1:
            mois = "Janvier";
            nbJours = 31;
            break;
        case 2:
            mois = "Fevrier";
            nbJours = 28+bissextille;
            break;
        case 3:
            mois = "Mars";
            nbJours = 31;
            break;
        case 4:
            mois = "Avril";
            nbJours = 30;
            break;
        case 5:
            mois = "Mai";
            nbJours = 31;
            break;
        case 6:
            mois = "Juin";
            nbJours = 30;
            break;
        case 7:
            mois = "Juillet";
            nbJours = 31;
            break;
        case 8:
            mois = "Aout";
            nbJours = 31;
            break;
        case 9:
            mois = "Septembre";
            nbJours = 30;
            break;
        case 10:
            mois = "Octobre";
            nbJours = 31;
            break;
        case 11:
            mois = "Novembre";
            nbJours = 30;
            break;
        case 12:
            mois = "Decembre";
            nbJours = 31;
            break;
        default:
            mois = "Inconnu";
            nbJours = 0;
            break;
   }
}


void afficherCalendrier(int annee) {
    int nbJours = 0, position = 1;
    string nomMois;

    for (int mois = 1; mois <= 12; mois++)
    {

        detailsMois(mois, estBissextille(annee), nbJours, nomMois);

        cout << endl << nomMois << " " << annee << endl;
        cout    << setw(4) << "Lun"
                << setw(4) << "Mar"
                << setw(4) << "Mer"
                << setw(4) << "Jeu"
                << setw(4) << "Ven"
                << setw(4) << "Sam"
                << setw(4) << "Dim" << endl;

        for (int i = 1; i < position; i++)
            cout << setw(4) << " ";

        for(int jour = 1; jour <= nbJours; jour++)
        {
            cout << setw(4) << jour;
            if(position % 7 == 0)
            {
                position = 1;
                cout << endl;
            }
            else
            {
                position++;
            }
        }

        cout << endl;
    }
}