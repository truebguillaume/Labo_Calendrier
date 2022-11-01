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

int  saisieUtilisateur(string);
bool estBissextille(int);
void afficherCalendrier(int,bool);


int main() {

    cout << "Hello World!" ;
    return EXIT_SUCCESS;
}

