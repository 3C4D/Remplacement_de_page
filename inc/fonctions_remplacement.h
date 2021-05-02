/* Enzo CADONI G2 */
/* TP supplementaire */
/* Fichier header contenant les prototypes des fonctions implementant */
/* les algorithmes de remplacement de page */

#ifndef PAGE_H_
#define PAGE_H_

/* Fonction implémantant l'algorithme FIFO */
int fifo(int nb_case, int debug, char *nom_fic);

/* Fonction implémentant l'algorithme LIFO */
int lru(int nb_case, int debug, char *nom_fic);

/* Fonction implementant l'algorithme de l'horloge */
int horloge(int nb_case, int debug, char *nom_fic);

/* Fonction implementant l'algorithme optimal */
int optimal(int nb_case, int debug, char *nom_fic);

/* Fonction déterminant quel algorithme l'utilisateur a choisi et le lance */
void choix_algo(int algo, int nb_case, int debug, char *nom_fic);

#endif
