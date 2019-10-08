#!/bin/bash

echo "Veuillez choisir une difficulté, 1 pour facile, 2 pour moyen, 3 pour difficile."
read -r difficulte

while [ $difficulte -gt 3 ] || [ -z $difficulte ]
do
    echo "Valeur incorrecte, veuillez réessayer."
    read -r difficulte
done

if  [ "$difficulte" -eq 1 ]
    then
        nombreAleatoire=$((1 + RANDOM % 10))
elif [ "$difficulte" -eq 2 ]
    then
        nombreAleatoire=$((1 + RANDOM % 50))
elif [ "$difficulte" -eq 3 ]
    then
        nombreAleatoire=$((1 + RANDOM % 100))
fi

echo "Donnez un nombre : "
read -r nombre

while [ -z $nombre ]
do
    echo "Caractère incorrect !"
    echo "Donnez un nombre : "
    read -r nombre
done

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