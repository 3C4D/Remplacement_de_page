/* Enzo CADONI G2 */
/* TP supplementaire */
/* Fichier header contenant les prototypes des fonctions utlitaires */

#ifndef UTILITAIRE_H_
#define UTILITAIRE_H_

/* Fonction d'aide rappellant l'usage correct étendu du programme */
void help(char *str);

/* Fonction rappellant l'usage correct du programme */
void usage(char *str);

/* Fonction vérifiant l'extension et la cohérence d'un fichier */
void verif_fichier(char *nom_fic);

/* Fonction permettant d'ouvrir un fichier en lecture */
FILE *lire_fichier(char *nom_fic);

/* Fonction permettant d'ouvrir un fichier en ecriture */
FILE *ecrire_fichier(char *nom_fic);

/* Fonction permettant d'affcher un tableau d'accès (debug mode)*/
void affiche_acces(int *acces, int nb_case);

#endif
