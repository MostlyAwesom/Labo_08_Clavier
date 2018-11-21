#include "chronometre.h"
#include <ctime>         //time, difftime

double chrono(const bool& active){
   // Initialisation du temps de initial de référence en cas de mauvaise utilisation
   static time_t tempsInitial = time(nullptr);

   time_t tempsFinal;

   if(active) {
      // Définit le temps au lancement du chronomètre
      tempsInitial = time(nullptr);
      // Retourne 1. car le chronomètre se lance
      return 1.;
   } else {
      // Définit le temps à l'arrêt du chronomètre
      tempsFinal = time(nullptr);
      // Retourne la différence de temps entre le lancement et l'arrêt du chronomètre
      return difftime(tempsFinal,tempsInitial);
   }
}