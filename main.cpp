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
#include <iostream>
#include <cstdlib>
#include <limits>  // numeric_limits   <--- pour saisieClavier();


using namespace std;

void lance(const int& CAR_MIN, const int& CAR_MAX, const int& NB_LANCE, int& nbJuste, int& chrono);

/**
\brief retourne la saisie clavier
\param[in] message le message indiquant la valeur à saisir.
\param[in] minimum valeur mimnimale à entrer.
\param[in] maximum valeur maximale à entrer.
\return la valeur saisie au clavier.
Cette fonction retourne la saisie clavier de l'utilisateur
 avce une gestion des erreurs.
 Il est aussi possible d'entrer des bornes min / max.
*/
int saisieClavier(string message, int minimum = 0, int maximum = 0);

int main() {

   //Déclaration des variables et constantes
   const int   LETTRE_MIN = 1,
               LETTRE_MAX = 26,
               LANCE_MIN = 1,
               LANCE_MAX = 10;

   int         nbLance,
               nbCorrect;

   double      tempsMoyen,
               tempsTotal;

   char        reponseLance,
               reponseRejouer;

   //Présentation programme
   cout << "Ce programme permet a l'utilisateur de tester sa dexterite au clavier" << endl
        << " en générant des lettres aléatoirement que l'utilisateur doit reproduire"
        << "au fur et à mesure.";

   //Boucle pour recommencer
   do {
       nbLance = int(saisieClavier("Combien de lances", LANCE_MIN, LANCE_MAX));  //Saisie nombre de lancer ( GESTION ERREUR )

       //Jeu ---- Boucle for avec nbLancer
       for(int indiceLance = 0; indiceLance < nbLance; ++indiceLance) {
           //Fonction Lance()
       }
       //Afficher nbCorrect
       //Affiche le temps total
       //Calcul la moyenne du temps pour chaque lancé --------------- Fonction double tempsMoyen(int nbElements, double temps)
        //affiche le temps moyen
   } while(false); //Message pour recommencer" : O pour recommencer - N pour quitter

    // Fin de programme
    cout << "Presser ENTER pour quitter";
    return EXIT_SUCCESS;
}

void lance(const int& CAR_MIN, const int& CAR_MAX, const int& NB_LANCE, int& nbJuste, int& chrono)
{
   //Générer lettre
   //Afficher lettre
   //Commencer Chrono
   //Attendre réponse
   //Vider buffer
   //Arreter chrono
   //Verifier reponse et incrément ou non nbJuste
}

int saisieClavier(string message, int minimum, int maximum){

    // Déclaration des variables
    int valeur;
    bool saisieValide;

    // Saisie de l'utilisateur avec gestion d'erreur
    do {
        // Affiche le message de saisie avec ou sans les bornes
        cout << endl << message;
        if(minimum != maximum)
            cout << " [" << minimum << "-" << maximum; // Affiche les bornes, car min/max sont différents
        cout << "] : ";

        saisieValide = bool(cin >> valeur); // Saisie de la valeur et retour de l'état du cin

        // Répare le cin si néscéssaire, puis vide le Buffer
        if(cin.fail())
            cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        // condition while -> Recommence la saisie si :
            // 1. 'cin' a dû être réparé
            // 2. 'valeur' est en dehors des bornes (min/max)
                // condition (2) active uniquement si : min != max
    } while(!saisieValide or ((valeur < minimum or valeur > maximum) and minimum != maximum));

    return valeur; // Retourne la saisie de l'utilisateur
}