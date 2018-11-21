#include "saisiesUtilisateurs.h"
#include <iostream>              //cout, cin, etc
#include <limits>                //numeric_limits

using namespace std;

int saisieClavier(const string& message, const int& minimum, const int& maximum){

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

        // Saisie de la valeur et retour de l'état du cin
        saisieValide = bool(cin >> valeur);

        // Répare le cin si nécessaire, puis vide le Buffer
        if(cin.fail()) {
            cin.clear();
        }
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        // Condition while -> Recommence la saisie si :
        // 1. 'cin' a dû être réparé
        //    OU
        // 2.   'valeur' est en dehors des bornes (min/max)
        //     ET
        //      'min' != 'max'
    } while(!saisieValide or (minimum != maximum and (valeur < minimum or valeur > maximum)));

    // Retourne la saisie de l'utilisateur
    return valeur;
}

bool rejouer(){

    // Déclaration des constantes et variables
    const char REJOUER = 'o',
               QUITTER = 'n';
    char       reponse;

    // Demande de saisie
    do {
        cout << endl << "Voulez-vous rejouer ? [" << REJOUER << "] ou [" << QUITTER << "] :";
        reponse = (char)getchar();

        // Vide le Buffer
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    } while(reponse != REJOUER and reponse != QUITTER);

    // Retourne la réponse de l'utilisateur
    return reponse == REJOUER;
}