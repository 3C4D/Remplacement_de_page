/* Enzo CADONI G2 */
/* TP supplementaire */
/* Fichier source contenant les fonctions de comparaison des algorithmes de */
/* remplacement de page */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "fonctions_remplacement.h"
#include "fonctions_generation.h"

/* Fonction d'usage de l'exécutable de benchmark */
void usage_benchmark(char *str){
  fprintf(stderr, "\nUsage : %s <nb_acces> <nb_page> <nb_case>\n", str);
  fprintf(stderr, "\t<nb_acces> : entier positif non nul\n");
  fprintf(stderr, "\t<nb_page> : entier positif non nul\n");
  fprintf(stderr, "\t<nb_case> : entier positif non nul\n\n");
  exit(-1);
}

/* Fonction de benchmark */
void benchmark(int nb_acces, int nb_page, int nb_case){
  int defauts_fifo, defauts_lru, defauts_horloge, defauts_optimal;
  clock_t begin, end;
  double duree_fifo, duree_lru, duree_horloge, duree_optimal;

  generation(nb_acces, nb_page, "benchmark.dat"); /* Génération du fichier */

  /* FIFO */
  begin = clock();  /* Démarrage du chronomètre */
  defauts_fifo = fifo(nb_case, 2, "benchmark.dat");
  end = clock();    /* Fin du chronomètre */
  duree_fifo = ((float) end - begin) / CLOCKS_PER_SEC;

  /* LRU */
  begin = clock();  /* Démarrage du chronomètre */
  defauts_lru = lru(nb_case, 2, "benchmark.dat");
  end = clock();    /* Fin du chronomètre */
  duree_lru = ((float) end - begin) / CLOCKS_PER_SEC;

  /* Horloge */
  begin = clock();  /* Démarrage du chronomètre */
  defauts_horloge = horloge(nb_case, 2, "benchmark.dat");
  end = clock();    /* Fin du chronomètre */
  duree_horloge = ((float) end - begin) / CLOCKS_PER_SEC;

  /* Optimal */
  begin = clock();  /* Démarrage du chronomètre */
  defauts_optimal = optimal(nb_case, 2, "benchmark.dat");
  end = clock();    /* Fin du chronomètre */
  duree_optimal = ((float) end - begin) / CLOCKS_PER_SEC;

  /* Affichage du résultat */

  puts("\n#################################");
  puts("#########  BENCHMARK  ###########");
  puts("#################################\n");
  printf("Pour %d case en RAM, %d acces en mémoire et %d pages maximum : \n",
        nb_case,
        nb_acces,
        nb_page
        );
  printf("\nFIFO : %d defauts de pages, %f secondes\n",
        defauts_fifo,
        duree_fifo
        );
  printf("LRU : %d defauts de pages, %f secondes\n",
        defauts_lru,
        duree_lru
        );
  printf("Horloge : %d defauts de pages, %f secondes\n",
        defauts_horloge,
        duree_horloge
        );
  printf("Optimal : %d defauts de pages, %f secondes\n\n",
        defauts_optimal,
        duree_optimal
        );
}
