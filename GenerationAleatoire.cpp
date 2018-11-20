#include "GenerationAleatoire.h"
#include <cstdlib>               //rand()

int nombreAleatoire(const int& min, const int& max){
   return rand() % ((max - min + 1) + min);
}