/* Enzo CADONI G2 */
/* TP supplementaire */
/* Fichier source contenenant les fonctions d'erreur */

#include <stdlib.h>
#include <stdio.h>

/* Fonction permettant d'interrompre le programme en affichant une erreur */
void erreur(char *erreur){
  fprintf(stderr, "%s", erreur);
  exit(-1);
}

/* Fonction permettant d'afficher une erreur sans arreter le programme */
void err_log(char *erreur){
  fprintf(stderr, "%s", erreur);
}
