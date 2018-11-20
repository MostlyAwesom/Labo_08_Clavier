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
#include <ctime>  //A enlever avec les sous programmes


using namespace std;

void lance(const int& CAR_MIN, const int& CAR_MAX, int& nbJuste, int& tempsTotal);

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
int saisieClavier(const string message, const int& minimum = 0, const int& maximum = 0);

char saisieCaractere(const string& message);

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

   char        reponseRejouer;

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

       cout << endl
            << "Nombre de reponse correcte : " << nbCorrect  << endl
            << "Temps total : "                << tempsTotal << endl
            << "Temps par lettre : "           << tempsMoyen << endl;


       //Calcul la moyenne du temps pour chaque lancé --------------- Fonction double tempsMoyen(int nbElements, double te
   } while(false); //Message pour recommencer" : O pour recommencer - N pour quitter

    // Fin de programme
    cout << "Presser ENTER pour quitter";
    return EXIT_SUCCESS;
}

void lance(const int& CAR_MIN, const int& CAR_MAX, int& nbJuste, int& tempsTotal)
{
   //Include pour rand
   //Include pour time
   //include pour timer
   //include string

   char   lettre,
          reponse;

   string message = "Lettre : ";

   time_t tempsInitial,
          tempsFinal;

   srand(time(NULL));

   //Génération aléatoire d'une lettre minuscule
   lettre = (char)('a'+(rand() % (CAR_MAX - CAR_MIN) + CAR_MIN));

   message += lettre;

   //Temps au début de la question
   time(&tempsInitial);

   //Saisie de la réponse
   reponse = saisieCaractere(message);

   //Temps après la réponse
   time(&tempsFinal);

   //En case de bonne réponse, on incrémente le total de réponses correctes
   if(reponse == lettre){
      nbJuste++;
   }

   //Temps pour répondre est égal à la différence de l'heure entre l'énoncé et la réponse
    tempsTotal =(int)(tempsFinal - tempsInitial);
}

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

char saisieCaractere(const string& message){

   char valeur;

   cout << message;
   cin >> valeur;

   //Vide le buffer du cin
   cin.ignore(numeric_limits<streamsize>::max(),'\n');

   return valeur;
}
