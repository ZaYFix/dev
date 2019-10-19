#!/bin/bash

readonly MIN=1

echo "Veuillez choisir une difficulté, 1 pour facile (1-10), 2 pour moyen (1-50), 3 pour difficile (1-100)."
read -r difficulte

while [ -z $difficulte ] || [ $difficulte -gt 3 ]
do
    echo "Valeur incorrecte, veuillez réessayer."
    read -r difficulte
done

if  [ $difficulte -eq 1 ]
    then
        readonly MAX=10
elif [ $difficulte -eq 2 ]
    then
        readonly MAX=50
elif [ $difficulte -eq 3 ]
    then
        readonly MAX=100
fi

nombreAleatoire=$(($MIN + RANDOM % $MAX))

echo "Donnez un nombre : "
read -r nombre

while [ -z $nombre ]
do
    echo "Valeur incorrecte, veuillez réessayer."
    echo "Donnez un nombre : "
    read -r nombre
done

((++nbCoups))

while [ $nombre -ne $nombreAleatoire ]
do
    if  [ $nombre -lt $nombreAleatoire ]
    then
        echo "Trop petit !"
        ((++nbCoups))
    else
        echo "Trop grand !"
        ((++nbCoups))
    fi
    read -r nombre
done

echo "Bravo vous avez decouvert le nombre mystere $nombreAleatoire en $nbCoups coups."

exit 0