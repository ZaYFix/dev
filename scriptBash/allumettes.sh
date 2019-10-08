#!/bin/bash

nbAllumettes=21

echo "
+----------------------+
| Jeu des Allumettes |
+----------------------+
Qui commence:
-> [J]oueur
-> [M]achine
-> [T]irage au sort"

read -r debutPartie

case $debutPartie in
    J)
        echo "J"
        while [ $nbAllumettes != "0" ]
        do
        echo "
il reste $nbAllumettes allumette(s)
Nb allumettes (1, 2 ou 3) ?" #TODO BLOCK ALLUMETTES > 3 & ==0
            read -r nbAllumettesChoisis
            let "nbAllumettes = nbAllumettes - nbAllumettesChoisis"
            allumetteAleatoire=$((1 + RANDOM % 3))
            echo "La machine a choisie $allumetteAleatoire allumettes."
            let "nbAllumettes = nbAllumettes - nbAllumettesChoisis"
        done
        ;;
    M)
        echo "M"
        ;;
    T)
        echo "T"
        ;;
    *)
        echo "Sorry"
        ;;
esac

exit 0