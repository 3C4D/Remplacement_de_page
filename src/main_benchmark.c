/* Enzo CADONI G2 */
/* TP supplementaire */
/* Fichier source contenant la fonction principale permettant d'effectuer */
/* un test empirique sur les algorithmes de remplacement de page */

#include <stdlib.h>
#include <stdio.h>
#include "erreur.h"
#include "fonctions_benchmark.h"

int main(int argc, char **argv){

  int nb_acces = 0, nb_page = 0, nb_case = 0;

  if(argc < 3){ /* Contrôle du nombre d'argument */
    err_log("\n##########################################################\n");
    err_log("####  Nombre insuffisant d'argument (2 obligatoires)  ####\n");
    err_log("##########################################################\n\n");
    usage_benchmark(argv[0]);
  }

  /* Vérification de la cohérence du nombre d'accès */
  if(sscanf(argv[1], "%d", &nb_acces) != 1 || nb_acces < 1){
    err_log("\n#####################################\n");
    err_log("####  premier argument invalide  ####\n");
    err_log("#####################################\n\n");
    usage_benchmark(argv[0]);
  }

  /* Vérification de la cohérence du nombre de page max */
  if(sscanf(argv[2], "%d", &nb_page) != 1 || nb_page < 1){
    err_log("\n#####################################\n");
    err_log("####  second  argument invalide  ####\n");
    err_log("#####################################\n\n");
    usage_benchmark(argv[0]);
  }

  /* Vérification de la cohérence du nombre de case */
  if(sscanf(argv[3], "%d", &nb_case) != 1 || nb_case < 1){
    err_log("\n########################################\n");
    err_log("####  troisieme  argument invalide  ####\n");
    err_log("########################################\n\n");
    usage_benchmark(argv[0]);
  }

  benchmark(nb_acces, nb_page, nb_case);

  exit(0);
}
