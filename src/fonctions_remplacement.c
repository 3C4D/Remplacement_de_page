/* Enzo CADONI G2 */
/* TP supplementaire */
/* Fichier source contenant les fonctions implementant les algorithmes */
/* de remplacement de page */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "erreur.h"
#include "utilitaire.h"

/* Fonction implémantant l'algorithme FIFO */
void fifo(int nb_case, int debug, char *nom_fic){

  FILE *fichier_mem = lire_fichier(nom_fic);  /* On ouvre le fichier d'accès */
  int *acces, nb_acces, nb_pages, i, page, defauts = 0, victime = 0, plein = 0;
  int *present;
  /* On alloue le tableau d'accès en fonction du nombre de case mémoire */
  acces = (int *)malloc(nb_case * sizeof(int));
  if(acces == NULL){  /* Vérification de l'allocation */
    erreur("erreur d'allocation dans la fonction fifo");
  }

  /* On saisie le nombre d'accès total */
  if(fscanf(fichier_mem, "%d", &nb_acces) != 1){
    erreur("fichier mal formatté dans la fonction fifo()");
  }
  /* On saisie le nombre de pages */
  if(fscanf(fichier_mem, "%d", &nb_pages) != 1){
    erreur("fichier mal formatté dans la fonction fifo()");
  }

  /* On alloue le tableau de présence des pages dans la mémoire */
  present = (int *)malloc(nb_pages * sizeof(int));
  if(present == NULL){  /* Vérification de l'allocation */
    erreur("erreur d'allocation dans la fonction fifo");
  }
  for(i = 0; i < nb_pages; i++){ /* Initialisation du tableau de presence */
    present[i] = 0;
  }

  if(debug){
    putchar('\n');
  }

  for(i = 0; i < nb_acces; i++){
    if(fscanf(fichier_mem, "%d", &page) != 1){  /* On saisie la page */
      erreur("accès non trouvé dans le fichier dans le fonction fifo()");
    }

    if(!present[page]){ /* Page non présente en mémoire */
      if(plein < nb_case){  /* On rempli le tableau d'accès */
          acces[plein] = page;
          present[page] = 1;
          plein++;
      }
      else{
        if(debug){
          printf("#### Defaut de page ####\n");
        }
        present[page] = 1;          /* On met le tableau de presence à 1 */
        /* La victime n'est plus présente */
        present[acces[victime]] = 0;
        acces[victime] = page;      /* On la place la ou se trouve la victime */
        victime = (victime + 1)%nb_case;  /* La victime est la page suivante */
        defauts++;                  /* Il y a un defaut de page */
      }
    }
    if(debug){  /* Mode debug, on affiche le tableau d'accès */
      affiche_acces(acces, plein);
    }
  }
  /* On affiche le nombre de défaut de page */
  printf("\n############    Algorithme FIFO    ############\n");
  printf("Il y a %d défauts de pages avec %d cases en RAM\n", defauts, nb_case);
  printf("###############################################\n\n");
  fclose(fichier_mem);  /* On ferme le fichier d'accès mémoire */
  free(acces);          /* On libère le tableau d'accès */
  free(present);        /* On libère le tableau de présence */

  /* Compléxité : Theta(nombre d'accès) */
}

/* Fonction implémentant l'algorithme LIFO */
void lifo(int nb_case, int debug, char *nom_fic){

  FILE *fichier_mem = lire_fichier(nom_fic);  /* On ouvre le fichier d'accès */
  int nb_acces, nb_pages, i, page, defauts = 0, plein = 0;
  int *present;
  /* On alloue le tableau d'accès en fonction du nombre de case mémoire */
  int *acces = (int *)malloc(nb_case * sizeof(int));
  if(acces == NULL){  /* Vérification de l'allocation */
    erreur("erreur d'allocation dans la fonction lifo");
  }

  /* On saisie le nombre d'accès total */
  if(fscanf(fichier_mem, "%d", &nb_acces) != 1){
    erreur("fichier mal formatté dans la fonction lifo()");
  }

  /* On saisie le nombre de pages */
  if(fscanf(fichier_mem, "%d", &nb_pages) != 1){
    erreur("fichier mal formatté dans la fonction lifo()");
  }

  /* On alloue le tableau de présence des pages dans la mémoire */
  present = (int *)malloc(nb_pages * sizeof(int));
  if(present == NULL){  /* Vérification de l'allocation */
    erreur("erreur d'allocation dans la fonction lifo");
  }
  for(i = 0; i < nb_pages; i++){ /* Initialisation du tableau de presence */
    present[i] = 0;
  }

  if(debug){
    putchar('\n');
  }

  for(i = 0; i < nb_acces; i++){
    if(fscanf(fichier_mem, "%d", &page) != 1){  /* On saisie la page */
      erreur("accès non trouvé dans le fichier dans le fonction lifo()");
    }

    if(!present[page]){ /* Page non présente en mémoire */
      if(plein < nb_case){  /* On rempli le tableau d'accès */
          acces[plein] = page;
          present[page] = 1;
          plein++;
      }
      else{
        if(debug){
          printf("#### Defaut de page ####\n");
        }
        present[page] = 1;              /* On met le tableau de presence à 1 */
        present[acces[nb_case-1]] = 0;  /* La victime n'est plus présente */
        acces[nb_case-1] = page;        /* On remplace la victime */
        defauts++;                      /* Il y a un defaut de page */
      }
    }
    if(debug){  /* Mode debug, on affiche le tableau d'accès */
      affiche_acces(acces, plein);
    }
  }
  /* On affiche le nombre de défaut de page */
  printf("\n############    Algorithme LIFO    ############\n");
  printf("Il y a %d défauts de pages avec %d cases en RAM\n", defauts, nb_case);
  printf("###############################################\n\n");
  fclose(fichier_mem);  /* On ferme le fichier d'accès mémoire */
  free(acces);          /* On libère le tableau d'accès */
  free(present);        /* On libère le tableau de présence */

  /* Compléxité : Theta(nombre d'accès) */
}

/* Fonction implementant l'algorithme de l'horloge */
void horloge(int nb_case, int debug, char *nom_fic){

  FILE *fichier_mem = lire_fichier(nom_fic);  /* On ouvre le fichier d'accès */
  int nb_acces, nb_pages, i, j, page, plein = 0, pointeur = 0, defauts = 0;
  int *acces, *valide, *present;

  /* On saisie le nombre d'accès total */
  if(fscanf(fichier_mem, "%d", &nb_acces) != 1){
    erreur("fichier mal formatté dans la fonction horloge()");
  }

  /* On saisie le nombre de pages */
  if(fscanf(fichier_mem, "%d", &nb_pages) != 1){
    erreur("fichier mal formatté dans la fonction horloge()");
  }

  /* Le tableau acces contiendra les pages chargées en mémoire */
  acces = (int *)malloc(nb_case * sizeof(int));

  /* On alloue le tableau de présence des pages dans la mémoire */
  present = (int *)malloc(nb_pages * sizeof(int));
  for(i = 0; i < nb_pages; i++){ /* Initialisation du tableau de presence */
    present[i] = 0;
  }

  /* On alloue le tableau contenant les bits de validité */
  valide = (int *)malloc(nb_case * sizeof(int));
  for(i = 0; i < nb_pages; i++){ /* Initialisation du tableau de presence */
    present[i] = 0;
  }

  if(debug){
    putchar('\n');
  }

  for(i = 0; i < nb_acces; i++){  /* On parcours les accès */
    if(fscanf(fichier_mem, "%d", &page) != 1){  /* On saisie la page */
      erreur("accès non trouvé dans le fichier dans le fonction lifo()");
    }

    if(!present[page]){             /* La page n'est pas présente en mémoire */
      if(plein < nb_case){                /* Il reste de la place */
        acces[plein] = page;              /* On place la page */
        present[page] = 1;                /* La page est désormais présente */
        pointeur = (plein+1)%nb_case;     /* Le pointeur avance */
        valide[plein] = 1;                /* La case est valide */
        plein++;                          /* On enlève une place vide */
      }
      else{                               /* La mémoire est pleine */
        if(debug){
          printf("#### Defaut de page ####\n");
        }
        defauts++;                        /* Defaut de page */
        present[acces[pointeur]] = 0;     /* La page n'est plus présente */
        acces[pointeur] = page;           /* On insère la page */
        present[page] = 1;                /* La nouvelle page est présente */
        valide[pointeur] = 1;             /* La case devient valide */
        pointeur = (pointeur+1)%nb_case;  /* Le pointeur avance */
      }
    }
    else{                           /* La page est présente */
      j = 0;
      while(acces[j] != page){            /* On cherche la page en question */
        j++;
      }
      valide[j] = 1;                      /* La page est valide */
    }
    while(valide[pointeur] == 1){       /* On cherche la prochaine victime */
      valide[pointeur] = 0;               /* La case n'est plus valide*/
      pointeur = (pointeur+1)%nb_case;    /* Le pointeur avance */
    }
    if(debug){
      affiche_acces(acces, nb_case);
    }
  }
  printf("\n############    Algorithme de l'horloge   ############\n");
  printf("Il y a %d défauts de pages avec %d cases en RAM\n", defauts, nb_case);
  printf("######################################################\n\n");
  free(acces);    /* On libère les tableaux utilisés */
  free(valide);
  free(present);
}

/* Fonction implementant l'algorithme optimal */
void optimal(int nb_case, int debug, char *nom_fic){

  FILE *fichier_mem = lire_fichier(nom_fic);  /* On ouvre le fichier d'accès */
  int *acces, *all_acces, *present, i, j, nb_acces, nb_pages, plein = 0;
  int *apparition, victime = -1, defauts = 0;

  /* On saisie le nombre d'accès total */
  if(fscanf(fichier_mem, "%d", &nb_acces) != 1){
    erreur("fichier mal formatté dans la fonction optimal()");
  }

  /* On saisie le nombre de pages */
  if(fscanf(fichier_mem, "%d", &nb_pages) != 1){
    erreur("fichier mal formatté dans la fonction optimal()");
  }

  /* Le tableau acces contiendra les pages chargées en mémoire */
  acces = (int *)malloc(nb_case * sizeof(int));

  /* Le tableau apparition contiendra les apparition dans les accès des pages */
  apparition = (int *)malloc(nb_pages * sizeof(int));

  /* le tableau all_acces contiendra tous les accès mémoire */
  all_acces = (int *)malloc(nb_acces * sizeof(int));
  for(i = 0; i < nb_acces; i++){
    if(fscanf(fichier_mem, "%d", &all_acces[i]) != 1){
      erreur("fichier mal formatté dans la fonction optimal()");
    }
  }

  /* On alloue le tableau de présence des pages dans la mémoire */
  present = (int *)malloc(nb_pages * sizeof(int));
  for(i = 0; i < nb_pages; i++){ /* Initialisation du tableau de presence */
    present[i] = 0;
  }

  if(debug){
    putchar('\n');
  }

  for(i = 0; i < nb_acces; i++){
    if(!present[all_acces[i]]){         /* Page non présente en mémoire */
      if(plein < nb_case){              /* Il reste de la place */
        acces[plein] = all_acces[i];    /* On place la page */
        present[all_acces[i]] = 1;      /* La page est désormais présente */
        plein++;                        /* On enlève une place vide */
      }
      else{                             /* La mémoire est pleine */
        if(debug){
          printf("#### Defaut de page ####\n");
        }
        /* On regarde la page qui apparait le plus loin dans les accès */
        for(j = 0; j < nb_pages; j++){
          apparition[j] = 0;
        }
        for(j = i+1; j < nb_acces; j++){
          if(present[all_acces[j]]){    /* la page est en mémoire */
            victime = all_acces[j];     /* elle devient la victime */
            apparition[victime] = 1;    /* elle apparait */
          }
        }
        for(j = 0; j < nb_pages; j++){
          if(!apparition[j] && present[j]){ /* Si une page n'apparait plus */
            victime = j;                    /* Elle devient la victime */
          }
        }
        j = 0;
        while(acces[j] != victime){  /* On cherche la victime */
          j++;
        }
        present[acces[j]] = 0;    /* La page n'est plus présente en mémoire */
        acces[j] = all_acces[i];  /* On la remplace par la page courante */
        present[all_acces[i]] = 1;/* La page actuelle est présente en mémoire */
        defauts++;
      }
    }
    if(debug){                    /* On affiche si le debug mode est activé */
      affiche_acces(acces, plein);
    }
  }
  printf("\n############    Algorithme Optimal   ############\n");
  printf("Il y a %d défauts de pages avec %d cases en RAM\n", defauts, nb_case);
  printf("#################################################\n\n");
  free(apparition);   /* On libère les tableaux utilisés */
  free(present);
  free(all_acces);
  free(acces);
}

/* Fonction déterminant quel algorithme l'utilisateur a choisi et le lance */
void choix_algo(int algo, int nb_case, int debug, char *nom_fic){
  switch(algo){
    case 0:   /* FIFO */
      fifo(nb_case, debug, nom_fic);
      break;
    case 1:   /* LIFO */
      lifo(nb_case, debug, nom_fic);
      break;
    case 2:   /* Horloge */
      horloge(nb_case, debug, nom_fic);
      break;
    case 3:   /* Optimal */
      optimal(nb_case, debug, nom_fic);
      break;
    default:
      erreur("\nMauvais algorithme dans la fonction choix_algo()\n\n");
      break;
  }
}
