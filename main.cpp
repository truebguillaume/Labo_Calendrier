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
#include <cstdlib>  //EXIT_SUCCESS
#include <limits>   //numeric_limits
#include <iomanip>  //setprecision, setw

#define VIDER_BUFFER while (cin.ignore(numeric_limits<streamsize>::max(), '\n'))

using namespace std;

int main() {

    cout << "Hello World!" ;
    return EXIT_SUCCESS;
}

