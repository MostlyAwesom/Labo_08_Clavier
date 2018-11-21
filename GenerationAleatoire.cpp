#include "GenerationAleatoire.h"
#include <cstdlib>               //rand
#include <ctime>                 //time

int nombreAleatoire(const int& min, const int& max){
   static bool premiereFois = true;
   if(premiereFois){
      srand(time(NULL));
      premiereFois = false;
   }
   return rand() % (max - min + 1) + min;
}