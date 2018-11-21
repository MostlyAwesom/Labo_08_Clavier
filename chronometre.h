#ifndef LABO_08_CLAVIER_CHRONOMETRE_H
#define LABO_08_CLAVIER_CHRONOMETRE_H

/**
 *\brief   Calcul le temps passé en seconde entre les instructions chrono(true) et chrono(false).
 * @param  active Définit si l'on active le chronometre ou si on regarde le temps écoulé.
 * @return 1. si le chrono commence.
 *         0. ~ si on regarde le temps écoulé sans jamais avoir lancé le chronomètre.
 *         Sinon renvoi le temps écoulé en seconde.
 *
 *         Chaque chrono(false) renvoie le temps écoulé depuis le précédent chrono(true).
 *         Après un chrono(true) plusieurs chrono(false) sont utilisables pour donner le temps
 *         écoulé depuis l'instruction chrono(true).
 */
double chrono(const bool& active);

#endif //LABO_08_CLAVIER_CHRONOMETRE_H
