#include "generationAleatoire.h"
#include <cstdlib>               //rand
#include <ctime>                 //time

int nombreAleatoire(const int& min, const int& max){

    // Initialise le générateur de nombre aléatoire
    static bool premiereFois = true;
    if(premiereFois){
        srand(time(nullptr));
        premiereFois = false;
    }

    // Retourne le nombre aléatoire dans les bornes
    return rand() % (max - min + 1) + min;
}