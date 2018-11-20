#include <string>                            //string
#ifndef LABO_08_CLAVIER_SAISIESUTILISATEURS_H
#define LABO_08_CLAVIER_SAISIESUTILISATEURS_H

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
int saisieClavier(const std::string message, const int& minimum = 0, const int& maximum = 0);

#endif //LABO_08_CLAVIER_SAISIESUTILISATEURS_H

