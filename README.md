# Remplacement

## Compilation

Afin de compiler l'exécutable de remplacement de page, faite la commande :

```
make bin/remplacement
```

Afin de compiler l'exécutable de comparaison :

```
make bin/remplacement
```

Afin de compiler l'exécutable de génération de fichier aléatoire :

```
make bin/generation_fichier
```

Afin de tout compiler : `make all` ou bien `make`

Afin de nettoyer les fichiers objet : `make clean`

Afin de nettoyer tous les fichiers objets/exécutables : `make clean_all`

## Remplacement de page

Le chemin pour accéder à l'exécutable est : `./bin/remplacement`

Les arguments sont, dans l'ordre :
  - L'algorithme :
    - -f : FIFO.
    - -l : LIFO.
    - -h : Horloge.
    - -o : Optimal.
  - Le nombre de case.
  - Le mode (0 : classique, 1 : debug*)
  - Le nom du fichier, il doit avoir une des extensions valides**

  *debug : le mode debug affiche les accès et les défauts de page au fur et à
           mesure de l'algorithme

  **extensions valides : .dat, .txt, .log.

Pour afficher l'usage, il suffit de ne rentrer aucun paramètre.

Pour afficher un manuel plus complet rentrer :
  `./bin/remplacement -h` ou bien `./bin/remplacement --help`

La sortie de ce programme est le nombre de defaut de page que produit
l'algorithme en fonction du nombre de cases de RAM disponible et des accès
mémoire fournis dans le fichier.

## Generation

Le chemin pour accéder à l'exécutable est : `./bin/generation_fichier`

Cet exécutable permet de créer aléatoirement des fichiers d'accès mémoire.

L'usage correct de ce programme s'affiche lorsque aucun paramètre n'est passé
en ligne de commande ou que l'un d'eux est incorrect/absent.

les arguments sont, dans l'ordre :
  - Le nombre d'accès mémoire.
  - Le nombre de page max.
  - Le nom du fichier, il doit avoir une extension valide (les mêmes que
    celles décrites dans la partie précédente).

En guise d'exemple, la commande `./bin/generation_fichier 2000 30 gen.dat`
fournira un fichier nommé gen.dat qui contiendra 2000 accès mémoire.
les pages pourront aller de 0 à 29 soit 30 pages maximum.

## Benchmark

Le chemin

## Complexité

complexité FIFO : Theta(nb_acces)
complexité LIFO : Theta(nb_acces)
complexité horloge : Theta(nb_acces)
complexité optimal : Theta(nb_acces)
