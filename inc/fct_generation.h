/* Enzo CADONI G2 */
/* TP supplementaire */
/* Fichier header contenant les prototypes des fonctions de generation */
/* de fichiers aléatoires d'accès mémoire */

#ifndef GENERATION_H_
#define GENERATION_H_

/* Fonction d'usage de l'exécutable de génération */
void usage_gen(char *str);

/* Fonction de génération de fichier d'accès mémoire aléatoire */
void generation(int nb_acces, int nb_page, char *nom_fic);

#endif
