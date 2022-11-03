//
// Created by Guillaume Trüeb on 03.11.22.
//

#include <string>
#include <iomanip>  //setprecision, setw
#include <iostream> //cout, cin

#include "calendrier.h"

using namespace std;

bool estBissextille(int annee) {
    return (annee % 4 == 0 && annee % 100 != 0) || annee % 400 == 0;
}

void detailsMois(int numMois, bool bissextille, int& nbJours, std::string& mois){

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
    std::string nomMois;

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