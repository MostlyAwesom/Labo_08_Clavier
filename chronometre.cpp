#include "chronometre.h"
#include <ctime>         //time, difftime

double chrono(const bool& active){
   static time_t tempsInitial = time(nullptr);
   time_t tempsFinal = time(nullptr);

   if(active){
      tempsInitial = time(nullptr);
      return 0.;
   } else{
      return difftime(tempsFinal,tempsInitial);
   }
}