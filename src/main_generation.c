/* Enzo CADONI G2 */
/* TP supplementaire */
/* Fichier source contenant la fonction principale de l'exéctuable de */
/* génération de fichiers aléatoire d'accès mémoire */

#include <stdlib.h>
#include <stdio.h>
#include "erreur.h"
#include "fonctions_generation.h"
#include "utilitaire.h"

int main(int argc, char **argv){

  int nb_acces = 0, nb_page = 0;

  if(argc < 4){ /* Contrôle du nombre d'arguments */
    err_log("\n##########################################################\n");
    err_log("####  Nombre insuffisant d'argument (2 obligatoires)  ####\n");
    err_log("##########################################################\n\n");
    usage_gen(argv[0]);
  }

  /* Vérification de la cohérence du nombre d'accès */
  if(sscanf(argv[1], "%d", &nb_acces) != 1 || nb_acces < 1){
    err_log("\n#####################################\n");
    err_log("####  premier argument invalide  ####\n");
    err_log("#####################################\n\n");
    usage_gen(argv[0]);
  }

  /* Vérification de la cohérence du nombre de page max */
  if(sscanf(argv[2], "%d", &nb_page) != 1 || nb_page < 1){
    err_log("\n#####################################\n");
    err_log("####  second  argument invalide  ####\n");
    err_log("#####################################\n\n");
    usage_gen(argv[0]);
  }

  verif_fichier(argv[3]); /* Vérification du nom de fichier fourni */

  generation(nb_acces, nb_page, argv[3]);

  exit(0);
}
