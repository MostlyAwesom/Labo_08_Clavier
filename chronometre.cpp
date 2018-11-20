#include "chronometre.h"
#include <ctime>;          //time, difftime

double chrono(const bool& active){
   static time_t tempsInitial = time(NULL);
   time_t tempsFinal = time(NULL);

   if(active){
      tempsInitial = time(NULL);
      return 0.;
   } else{
      tempsFinal = time(NULL);
      return difftime(tempsInitial, tempsFinal);
   }
}