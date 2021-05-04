# Enzo CADONI G2
# TP supplementaire
# Script d'experience

#!/usr/bin/env bash

make  # Compilation

ram=1;
for((i=0; i < 5; i++));do
  pages=$(expr $ram \* 10);
  for((j=$i; j < 5; j++));do
    echo -n "RAM : $ram , "
    echo  "PAGES : $pages :"

    # On récupère le résultat du programme de benchmark
    defauts=$(echo $(./bin/benchmark 100000 $pages $ram))

    # On récupère les defauts de pages des differents algorithmes
    defauts_fifo=$(echo $defauts | cut -d ' ' -f22)
    defauts_lru=$(echo $defauts | cut -d ' ' -f30)
    defauts_horloge=$(echo $defauts | cut -d ' ' -f38)
    defauts_optimal=$(echo $defauts | cut -d ' ' -f46)

    # On les écrit
    echo "  $defauts_fifo defauts de pages pour FIFO"
    echo "  $defauts_lru defauts de pages pour LRU"
    echo "  $defauts_horloge defauts de pages pour Horloge"
    echo "  $defauts_optimal defauts de pages pour Optimal"
    # pages multipliées par 10
    pages=$(expr $pages \* 10 )
  done
  echo ""
  echo "#############################################"
  echo ""
  # case en ram multipliées par 10
  ram=$(expr $ram \* 10)
done
