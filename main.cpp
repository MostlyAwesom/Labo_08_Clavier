/*
 -----------------------------------------------------------------------------------
 Laboratoire : 08_Clavier
 Fichier     : Labo_08_Becaud_Egremy.cpp
               chronometre.cpp
               chronometre.h
               generationAleatoire.cpp
               generationAleatoire.h
               saisiesUtilisateurs.cpp
               saisiesUtilisateurs.h
 Auteur(s)   : Arthur Bécaud & Bruno Egremy
 Date        : 21.11.2018

 But         :

 Remarque(s) :

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/
#include <iostream>              //cout, cin, etc.
#include <string>                //type string
#include <iomanip>               //setPrecision
#include <limits>                //numeric_limits
#include "GenerationAleatoire.h" //nombreAleatoire
#include "chronometre.h"         //chrono
#include "SaisiesUtilisateurs.h" //saisieClavier


using namespace std;

/**
 * \brief Message de présentaion spécifique à cette l'application.
 */
void affichageBut();

/**
 * \brief Affiche les résultats des lancés.
 * \param[in] nbReponsesCorrectes Nombre de réponse(s) correcte(s).
 * \param[in] tempsTotal Temps total du test de dextérité.
 * \param[in] nbLance Nombre de lancé(s) effectué(s).
 *
 * Affiche les statistiques du test de dextérité à l'utilisateurs. On retrouve le nombre
 * de réponse(s) correcte(s), le temps effectuté, le nombre de lancé et une moyenne de temps en seconde par lancé.
 */
void affichageResultats(const int& nbReponsesCorrectes, const double& tempsTotal, const int& nbLance);

/**
 * \brief Génère un lancé, enregistre la réponse et le temps utilisé.
 * \param[in] CAR_MIN Caractère minimum (recommandé : 1).
 * \param[in] CAR_MAX Caractère maximum (recommandé : 26).
 * \param[in] nbJuste Nombre de réponse juste jusqu'à maintenant.
 * \param[in] tempsTotal Temps total utilisé depuis le début du test.
 *
 * Génère une lettre minuscule aléatoirement, l'utilisateur doit ensuite entré cette lettre le plus rapidement
 * possible dans la console car le temps est chronométré.
 */
void lance(const int& CAR_MIN, const int& CAR_MAX, int& nbJuste, double& tempsTotal);


int main() {

   // Déclaration des variables et constantes
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

   // Présentation du programme
   affichageBut();

   // Boucle pour recommencer
   do {
      // Saisie nombre de lancer , avec une gestion d'erreurs
      nbLance = saisieClavier("Combien de lances", LANCE_MIN, LANCE_MAX);

      // Lancement du test de dextérité
      for(int indiceLance = 0; indiceLance < nbLance; ++indiceLance) {
         lance(LETTRE_MIN, LETTRE_MAX, nbCorrect, tempsTotal);
      }

      // Affichage des résultats du test
      affichageResultats(nbCorrect, tempsTotal, nbLance);

   }while(rejouer());

    // Fin de programme
    cout << "Presser ENTER pour quitter";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    return EXIT_SUCCESS;
}

void affichageBut(){
   cout << "Ce programme permet a l'utilisateur de tester sa dexterite au clavier" << endl
        << " en générant des lettres aléatoirement que l'utilisateur doit reproduire"
        << "au fur et à mesure.";
}

void affichageResultats(const int& nbReponsesCorrectes, const double& tempsTotal, const int& nbLance){
   cout << endl
        << "Nombre de reponse correcte : " << nbReponsesCorrectes       << endl
        << "Temps total : "                << tempsTotal      << endl
        << "Temps par lettre : "           << setprecision(2) << tempsTotal / (double)nbLance << endl;
}

void lance(const int& CAR_MIN, const int& CAR_MAX, int& nbJuste, double& tempsTotal){

   // Déclaration des variables
   char   lettre,
          reponse;

   //Génération aléatoire d'une lettre minuscule
   lettre = (char)('a'+ nombreAleatoire(CAR_MIN, CAR_MAX) - 1);

   //Démarrage du chrono
   chrono(true);

   //Saisie de la réponse
   cout << "Lettre : " << lettre << " : ";
   reponse = (char)getchar();
   cin.ignore(numeric_limits<streamsize>::max(),'\n');

   //Fin du chrono et lecture du temps écoulé
   tempsTotal = chrono(false);

   //En cas de bonne réponse, on incrémente le total de réponses correctes
   if(reponse == lettre){
      nbJuste++;
   }
}





