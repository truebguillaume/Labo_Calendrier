//---------------------------------------------------------
// Demo           : ModelCpp
// Fichier        : calendrier.cpp
// Auteur(s)      : Trüeb Guillaume & Vasques Dario
// But            : Modèle pour démarrer un projet en C++
// Modifications  :
// Remarque(s)    : -
// Compilateur    : Apple clang version 14.0.0
// C++ version    : C++20
//---------------------------------------------------------

#include <string>
#include <iomanip>  //setprecision, setw
#include <iostream> //cout, cin

#include "calendrier.h"

using namespace std;

// Cette fonction permet de vérifier si l'année est bissextile ou non
// Explication des paramètres :
// annne = correspond à l'année saisie par l'utilisateur
bool estBissextille(int annee) {
    return (annee % 4 == 0 && annee % 100 != 0) || annee % 400 == 0;
}

// Cette fonction permet de récupérer le mois à afficher lors du résultat du calendrier
// Explication des paramètres :
// numMois --> correspond au numéro du mois à afficher
// bissextille --> indique si l'année est bissextile ou non
// nbJours --> correspond au nombre de jours du mois numMois
// mois --> nom du mois à afficher
void detailsMois(int numMois, bool bissextille, int& nbJours, string& mois){

    switch (numMois) {
        case 1:
            mois = "Janvier";
            nbJours = 31;
            break;
        case 2:
            mois = "Fevrier";
            // Par rapport au résultat de si l'année est bissectixle, le nombre de jours peut être égal à 28 ou 29
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

// Fonction permettant de construire l'affichage du calendrier
// int& nbJours         : contient le nombre de jours pour le mois à afficher
// int& position        : contient la position du premier jour du mois (L/M/M/..)
void afficherCalendrier(int& nbJours, int& position) {

    // Décale la position du premier jour
    for (int i = 1; i < position; i++)
    {
        cout << setw(4) << " ";
    }

    //
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

void calculerCalendrier(int annee) {

    int nbJours = 0, position = 1;
    string nomMois, joursSemaine = "LMMJVSD";

    for(int mois = 1; mois <= 12; mois++)
    {
        detailsMois(mois, estBissextille(annee), nbJours, nomMois);
        cout << endl << nomMois << " " << annee << endl;

        for(char c : joursSemaine)
        {
            cout << setw(4) << c;
        }

        cout << endl;

        afficherCalendrier(nbJours, position);

    }
}

