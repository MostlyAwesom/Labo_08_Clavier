/*
 -----------------------------------------------------------------------------------
 Laboratoire : 08_Clavier
 Fichier     : Labo_08_Becaud_Egremy.cpp
 Auteur(s)   : Arthur Bécaud & Bruno Egremy
 Date        : 19.11.2018

 But         :

 Remarque(s) :

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/
#include <iostream>              //cout, cin, etc.
#include <string>                //type string
#include <iomanip>               //setPrecision
#include "GenerationAleatoire.h" //nombreAleatoire
#include "SaisiesUtilisateurs.h" //saisieClavier


using namespace std;

void lance(const int& CAR_MIN, const int& CAR_MAX, int& nbJuste, double& tempsTotal);


int main() {

   //Déclaration des variables et constantes
   const int    LETTRE_MIN = 1,
                LETTRE_MAX = 26,
                LANCE_MIN  = 1,
                LANCE_MAX  = 10;

   const char   REJOUER = 'o',
                QUITTER = 'n';

   int          nbLance,
                nbCorrect;

   double       tempsTotal;

   char         reponseRejouer;

   //Présentation programme
   cout << "Ce programme permet a l'utilisateur de tester sa dexterite au clavier" << endl
        << " en générant des lettres aléatoirement que l'utilisateur doit reproduire"
        << "au fur et à mesure.";

   //Boucle pour recommencer
   do {
       nbLance = saisieClavier("Combien de lances", LANCE_MIN, LANCE_MAX);  //Saisie nombre de lancer ( GESTION ERREUR )

       //Jeu ---- Boucle for avec nbLancer
       for(int indiceLance = 0; indiceLance < nbLance; ++indiceLance) {
           lance(LETTRE_MIN, LETTRE_MAX, nbCorrect, tempsTotal);
       }


       //Fonction Affichage ----------------------------------------------------------------------------------------------------
       cout << endl
            << "Nombre de reponse correcte : " << nbCorrect       << endl
            << "Temps total : "                << tempsTotal      << endl
            << "Temps par lettre : "           << setprecision(2) << tempsTotal / (double)nbLance << endl;

       //Fonction rejouer ------------------------------------------------------------------------------------------------------
       do{
          cout << endl << "Voulez-vous rejouer ? [" << REJOUER << "] ou [" << QUITTER << "] :";
          reponseRejouer = (char)getchar();
       }while(reponseRejouer == REJOUER or reponseRejouer == QUITTER);
   } while(reponseRejouer == REJOUER); //Message pour recommencer" : O pour recommencer - N pour quitter

    // Fin de programme
    cout << "Presser ENTER pour quitter";
    //VIDER BUFFER


    return EXIT_SUCCESS;
}



void lance(const int& CAR_MIN, const int& CAR_MAX, int& nbJuste, double& tempsTotal){
   //Include pour rand
   //Include pour time
   //include pour timer
   //include string

   char   lettre,
          reponse;

   srand(time(NULL));

   //Génération aléatoire d'une lettre minuscule
   lettre = (char)('a'+ nombreAleatoire(CAR_MIN, CAR_MAX) - 1);

   //Démarrage du chrono
   chrono(true);

   //Saisie de la réponse
   cout << "Lettre : " << lettre << " : ";
   reponse = (char)getchar();
   //Vider Buffer ---------------------------------------------------------------------------------------------------------------

   //Fin du chrono et lecture du temps écoulé
   tempsTotal = chrono(false);

   //En case de bonne réponse, on incrémente le total de réponses correctes
   if(reponse == lettre){
      nbJuste++;
   }
}





