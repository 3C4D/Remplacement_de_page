/* Enzo CADONI G2 */
/* TP supplementaire */
/* Fichier header contenant les prototypes des fonctions de comparaison */
/* des algorithmes de remplacement de page */

#ifndef BENCH_H_
#define BENCH_H_

/* Fonction d'usage de l'exécutable de benchmark */
void usage_benchmark(char *str);

/* Fonction de benchmark */
void benchmark(int nb_acces, int nb_page, int nb_case);

#endif
