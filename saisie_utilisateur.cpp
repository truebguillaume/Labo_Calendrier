//---------------------------------------------------------
// Demo           : ModelCpp
// Fichier        : saisie_utilisateur.cpp
// Auteur(s)      : Trüeb Guillaume & Vasques Dario
// But            : Modèle pour démarrer un projet en C++
// Modifications  :
// Remarque(s)    : -
// Compilateur    : Apple clang version 14.0.0
// C++ version    : C++20
//---------------------------------------------------------

#include <iostream> //cout, cin


#include "saisie_utilisateur.h"

#define VIDER_BUFFER std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')

// Cette fonction permet de demander à l'utilisateur une valeur et de la contrôler
// Explication des paramètres :
// MSG --> correspond au message de demande de saisie
// min --> correspond à la valeur de saisie minimum
// max --> correspond à la valeur de saisie maximum
// MSG_ERREUR --> correspond au message d'erreur à afficher si l'entrée est fausse
int saisieUtilisateur(const std::string& MSG, int min, int max, const std::string& MSG_ERREUR) {
    int saisie;
    bool erreur;

    do {
        // message et saisie
        std::cout << MSG;
        // Vérifie si le flux est cassé ou si la valeur est en dehors des valeurs minimum et maximum
        erreur = not(std::cin >> saisie) or saisie < min or saisie > max;

        if (erreur) {
            std::cout << MSG_ERREUR << std::endl;
            std::cin.clear();
        }

        VIDER_BUFFER;

    }while(erreur);


    return saisie;
}