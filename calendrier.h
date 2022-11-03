//---------------------------------------------------------
// Demo           : ModelCpp
// Fichier        : calendrier.h
// Auteur(s)      : Trüeb Guillaume & Vasques Dario
// But            : Modèle pour démarrer un projet en C++
// Modifications  :
// Remarque(s)    : -
// Compilateur    : Apple clang version 14.0.0
// C++ version    : C++20
//---------------------------------------------------------

#ifndef LABO_CALENDRIER_CALENDRIER_H
#define LABO_CALENDRIER_CALENDRIER_H

bool estBissextille(int);
void afficherCalendrier(int);
void detailsMois(int, bool, int&, std::string&);

#endif //LABO_CALENDRIER_CALENDRIER_H