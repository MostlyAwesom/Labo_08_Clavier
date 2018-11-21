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

 But         : Permettre à l'utilisateur de tester sa dextérité au clavier en générant
               des lettres qu'il devra reproduire le plus rapidement possible
               car ces performences sont chronométrées.
               L'utilisateur est invité à choisir le nombre de lancé à faire, puis le
               jeu commence.
               Une fois terminée, le programme affiche les résultats où nous retrouvons
               le nombre de réponse correcte, le temps écoulé et une moyenne du temps
               passé par lettre en seconde.
               L'utilisteur à ensuite le choix de recommencer le programme. S'il refuse,
               le programme commencera ça procédure de fermeture

 Remarque(s) : Gestion des erreurs intégrée lors de les saisies.
               Le programme est réparti sous plusieurs fichiers afin de catégoriser ces
               multiples fonctions pour pouvoir les réutiliser dans des projets futures.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/
#include <iostream>              //cout, cin, etc.
#include <string>                //type string
#include <iomanip>               //setPrecision
#include <limits>                //numeric_limits
#include "generationAleatoire.h" //nombreAleatoire
#include "chronometre.h"         //chrono
#include "saisiesUtilisateurs.h" //saisieClavier
#include "annexes.h"             //affichage et lance


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
void affichageResultats(const int& nbReponsesCorrectes, const double& tempsTotal, const double& nbLance);

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
void lance(const char& lettre, int& nbJuste);


int main() {
   // Déclaration des variables et constantes
   const int    LANCE_MIN  = 1,
                LANCE_MAX  = 10;

   const char   LETTRE_MIN = 'a',
                LETTRE_MAX = 'z';

   int          nbLance,
                nbCorrect;

   double       tempsTotal;

   // Présentation du programme
   affichageBut();

   // Boucle pour recommencer
   do {
      // Mise à 0 du temps total et du nombre de réponses justes
      tempsTotal = 0;
      nbCorrect  = 0;

      // Saisie nombre de lancer , avec une gestion d'erreurs
      nbLance = saisieClavier("Combien de lances", LANCE_MIN, LANCE_MAX);

      //Démarrage du chrono
      chrono(true);

      // Lancement du test de dextérité
      for(int indiceLance = 0; indiceLance < nbLance; ++indiceLance) {
         lance((char)nombreAleatoire((int)LETTRE_MIN, (int)LETTRE_MAX), nbCorrect);
      }

      //Fin du chrono et lecture du temps écoulé
      tempsTotal = chrono(false);   // <<--------------------------------- Moyen de mettre ça ? dans affichageResultat(,chrono(false),);

      // Affichage des résultats du test
      affichageResultats(nbCorrect, tempsTotal, (double)nbLance);

   }while(rejouer());

    // Fin de programme
    cout << "Presser ENTER pour quitter";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    return EXIT_SUCCESS;
}





