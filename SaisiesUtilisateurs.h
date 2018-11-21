#include <string>                            //string
#ifndef LABO_08_CLAVIER_SAISIESUTILISATEURS_H
#define LABO_08_CLAVIER_SAISIESUTILISATEURS_H

/**
\brief Retourne la saisie clavier
\param[in] message Le message indiquant la valeur à saisir.
\param[in] minimum Valeur mimnimale à entrer.
\param[in] maximum Valeur maximale à entrer.
\return La valeur saisie au clavier.
Cette fonction retourne la saisie clavier de l'utilisateur
avec une gestion des erreurs.
Il est aussi possible d'entrer des bornes min / max.
*/
int saisieClavier(const std::string message, const int& minimum = 0, const int& maximum = 0);

/**
 * \brief Demande à l'utilisateur s'il souhaite rejouer.
 * @return Retourne la réponse de l'utilisateur en booléen.
 */
bool rejouer();

#endif //LABO_08_CLAVIER_SAISIESUTILISATEURS_H

