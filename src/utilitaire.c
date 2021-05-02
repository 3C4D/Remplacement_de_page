/* Enzo CADONI G2 */
/* TP supplementaire */
/* Fichier source contenant les fonctions utlitaires */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "erreur.h"

/* Fonction d'aide rappellant l'usage correct étendu du programme */
void help(char *str){
  printf("\n%s <algo> <nbCase> <mode> <fic>\n\n", str);
  puts("<algo> : -f -l -h -o");
  puts("-f : FIFO, -l : LRU, -h : Horloge, -o : Optimal");
  putchar('\n');
  puts("<nbCase> : entier positif et non nul");
  putchar('\n');
  puts("<mode> : 1 ou 2 (debug ou classique)");
  putchar('\n');
  puts("<fic> : fichier contenant les accès mémoire\n");
  exit(0);
}

/* Fonction rappellant l'usage correct du programme */
void usage(char *str){
  fprintf(stderr,
          "\nUsage : %s [-h | -help] [<algo> <nbCase> <mode> <fic>]\n\n",
          str);
  exit(-1);
}

/* Fonction vérifiant l'extension et la cohérence d'un fichier */
void verif_fichier(char *nom_fic){
  char *ext[3] = {".dat", ".txt", ".log"};
  int i = 0, len;

  if((len = strlen(nom_fic)) < 5){  /* Fichier trop court pour être cohérent */
    err_log("Fichier sans extension ou incohérent\n");
    err_log("Extensions autorisées : .dat, .txt, .log\n");
    exit(-1);
  }

  /* On compare avec les extensions avec celle du nom du fichier */
  while(i < 3 && strcmp(ext[i], (nom_fic+len-4))){
    i++;
  }

  if(i == 3){ /* Aucune extension ne correspond, on retourne une erreur */
    err_log("Fichier sans extension ou incohérent\n");
    err_log("Extensions autorisées : .dat, .txt, .log\n");
    exit(-1);
  }
}

/* Fonction permettant d'ouvrir un fichier en lecture */
FILE *lire_fichier(char *nom_fic){
  FILE *fic = NULL;

  verif_fichier(nom_fic);     /* On vérifie la cohérence du fichier */

  fic = fopen(nom_fic, "r");  /* On essaye d'ouvrir le fichier */

  if(fic == NULL){  /* Le fichier est introuvable */
    erreur("Fichier introuvable ou permission non accordée en lecture\n");
  }
  return fic;
}

/* Fonction permettant d'ouvrir un fichier en ecriture */
FILE *ecrire_fichier(char *nom_fic){
  FILE *fic = NULL;

  verif_fichier(nom_fic);     /* On vérifie la cohérence du fichier */

  fic = fopen(nom_fic, "w");  /* On essaye d'ouvrir le fichier */

  if(fic == NULL){  /* Le fichier est introuvable */
    erreur("Fichier introuvable ou permission non accordée en lecture\n");
  }
  return fic;       /* On retourne le flux ouvert */
}

/* Fonction permettant d'affcher un tableau d'accès (debug mode)*/
void affiche_acces(int *acces, int nb_case){
  int i;
  printf("Acces : [");
  for(i = 0; i < nb_case-1; i++){ /* Affichage case par case du tableau */
    printf("%d, ", acces[i]);
  }
  printf("%d]\n", acces[i]);
}

/* Vérifie une allocation */
void verif_alloc(void *ptr){
  if (ptr == NULL) {
    erreur("Erreur: Échec de l'allocation");
  }
}
