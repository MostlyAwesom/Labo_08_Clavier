#ifndef LABO_08_CLAVIER_ANNEXES_H
#define LABO_08_CLAVIER_ANNEXES_H

/**
 * \brief Message de présentaion spécifique à cette l'application.
 */
void affichageBut();

/**
 * \brief Affiche les résultats des lancés.
 * \param[in] nbReponsesCorrectes Nombre de réponse(s) correcte(s).
 * \param[in] tempsTotal Temps total du test de dextérité.
 * \param[in] nbLance Nombre de lancé(s) effectué(s).
 *
 * Affiche les statistiques du test de dextérité à l'utilisateurs. On retrouve le nombre
 * de réponse(s) correcte(s), le temps effectuté, le nombre de lancé et une moyenne de temps en seconde par lancé.
 */
void affichageResultats(const int& nbReponsesCorrectes, const double& tempsTotal, const double& nbLance);

/**
 * \brief Génère un lancé, enregistre la réponse et le temps utilisé.
 * \param[in] CAR_MIN Caractère minimum (recommandé : 1).
 * \param[in] CAR_MAX Caractère maximum (recommandé : 26).
 * \param[in] nbJuste Nombre de réponse juste jusqu'à maintenant.
 * \param[in] tempsTotal Temps total utilisé depuis le début du test.
 *
 * Génère une lettre minuscule aléatoirement, l'utilisateur doit ensuite entré cette lettre le plus rapidement
 * possible dans la console car le temps est chronométré.
 */
void lance(const char& lettre, int& nbJuste);

#endif //LABO_08_CLAVIER_ANNEXES_H
