//
// Created by egrem on 21.11.2018.
//

#include "annexes.h"
#include <iostream>  //cout
#include <limits>    //numeric_limits
#include <iomanip>   //setPrecision

using namespace std;

void affichageBut(){
   cout << "Ce programme permet a l'utilisateur de tester sa dexterite au clavier"   << endl
        << "en generant des lettres aleatoirement que l'utilisateur doit reproduire" << endl
        << "au fur et a mesure.";
}

void affichageResultats(const int& nbReponsesCorrectes, const double& tempsTotal, const double& nbLance){
   cout << endl
        << "Nombre de reponse correcte : " << nbReponsesCorrectes                      << endl
        << "Temps total : "                << setprecision(2) << tempsTotal            << endl
        << "Temps par lettre : "           << setprecision(2) << tempsTotal / nbLance  << endl;
}

void lance(const char& lettre, int& nbJuste){
   // Déclaration des variables
   char reponse;

   //Saisie de la réponse
   cout << "Lettre : " << lettre << " : ";
   reponse = (char)getchar();
   cin.ignore(numeric_limits<streamsize>::max(),'\n');

   //En cas de bonne réponse, on incrémente le total de réponses correctes
   if(reponse == lettre){
      ++nbJuste;
   }
}
