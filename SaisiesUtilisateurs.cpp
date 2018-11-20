#include "SaisiesUtilisateurs.h"
#include <iostream>              //cout, cin, etc
#include <limits>                //numeric_limits

using namespace std;

int saisieClavier(const string message, const int& minimum, const int& maximum){

   // Déclaration des variables
   int valeur;
   bool saisieValide;

   // Saisie de l'utilisateur avec gestion d'erreur
   do {
      // Affiche le message de saisie avec ou sans les bornes
      cout << endl << message;

      if(minimum != maximum) {
         // Affiche les bornes, car min/max sont différents
         cout << " [" << minimum << "-" << maximum << "]";
      }
      cout << " : ";

      saisieValide = bool(cin >> valeur); // Saisie de la valeur et retour de l'état du cin

      // Répare le cin si nécessaire, puis vide le Buffer
      if(cin.fail()) {
         cin.clear();
      }

      //Vide le buffer
      cin.ignore(numeric_limits<streamsize>::max(),'\n');

      // condition while -> Recommence la saisie si :
      // 1. 'cin' a dû être réparé
      // 2. 'valeur' est en dehors des bornes (min/max)
      // condition (2) active uniquement si : min != max
   } while(!saisieValide or ((valeur < minimum or valeur > maximum) and minimum != maximum));

   return valeur; // Retourne la saisie de l'utilisateur
}