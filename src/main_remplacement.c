/* Enzo CADONI G2 */
/* TP supplementaire */
/* Fichier source contenant la fonction principale permettant de  */
/* tester les fonctions implementant les algorithmes de remplacement de page */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fonctions_remplacement.h"
#include "erreur.h"
#include "utilitaire.h"

int main(int argc, char **argv){

  int nb_case = -1, mode = -1, i = 0;
  char *algo[4] = {"-f","-l","-h","-o"};

  if(argc < 4){
    if(argc > 1 && (!strcmp(argv[1], "-h") || !strcmp(argv[1], "-help"))){
      help(argv[0]);
    }
    else{
      usage(argv[0]);
    }
  }

  /* Vérification de la cohérence de l'algorithme choisi */
  while(i < 4 && strcmp(argv[1], algo[i])){
    i++;
  }
  if(i == 4){
    err_log("\n##############################\n");
    err_log("####  Mauvais algorithme  ####\n");
    err_log("##############################\n");
    usage(argv[0]);
  }

  /* Vérification de la cohérence du nombre de case choisi */
  if(sscanf(argv[2], "%d", &nb_case) != 1 || nb_case < 0){
    err_log("\n###################################\n");
    err_log("#####  Mauvais nombre de case #####\n");
    err_log("###################################\n");
    usage(argv[0]);
  }

  /* Vérification de la cohérence du mode choisi */
  if(sscanf(argv[3], "%d", &mode) != 1 || (mode != 0 && mode != 1)){
    err_log("\n##################################\n");
    err_log("####  Mode choisi non reconnu ####\n");
    err_log("##################################\n");
    usage(argv[0]);
  }

  choix_algo(i, nb_case, mode, argv[4]);  /* Choix de l'algorithme */

  exit(0);
}
