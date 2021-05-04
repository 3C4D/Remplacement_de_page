/* Enzo CADONI G2 */
/* TP supplementaire */
/* Fichier source contenant les  fonctions de generation */
/* de fichiers aléatoires d'accès mémoire */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "utilitaire.h"

/* Fonction d'usage de l'exécutable de génération */
void usage_gen(char *str){
  fprintf(stderr, "\nUsage : %s <nb_acces> <nbpage> <nom_fic>\n", str);
  fprintf(stderr, "\t<nb_acces> : entier positif non nul\n");
  fprintf(stderr, "\t<nb_page> : entier positif non nul\n");
  fprintf(stderr, "\t<nom_fic> : nom de fichier avec extension valide\n");
  fprintf(stderr, "\t\textensions valides : .dat, .txt, .log\n\n");
  exit(-2);
}

/* Fonction de génération de fichier d'accès mémoire aléatoire */
void generation(int nb_acces, int nb_page, char *nom_fic){

  FILE *fic = ecrire_fichier(nom_fic); /* On essaye de saisir le fichier */
  int i;

  srand(time(NULL));                  /* initialisation de l'horloge */

  fprintf(fic, "%d\n", nb_acces);     /* Placement du nombre d'accès */
  fprintf(fic, "%d\n", nb_page);      /* Placement du nombre de page max */

  for(i = 0; i < nb_acces; i++){      /* On place les accès */
    fprintf(fic, "%d\n", rand()%nb_page);
  }

  fclose(fic);                        /* On ferme le fichier */
}
