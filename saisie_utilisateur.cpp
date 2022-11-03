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

// Cette méthode permet de demander à l'utilisateur une valeur, ensuite elle effectuera un contrôle de cette dernière
int saisieUtilisateur(const std::string& msg, int min, int max, const std::string& MSG_ERREUR) {
    int saisie;
    bool erreur;

    do {
        // message et saisie
        std::cout << msg;
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