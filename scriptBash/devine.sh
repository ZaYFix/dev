#!/bin/bash

echo "Veuillez choisir une difficulté, 1 pour facile, 2 pour moyen, 3 pour difficile"
read difficulte

while test $difficulte -gt 3
do
    if test $difficulte -eq 1
    then
        nombreAleatoire=$(( $RANDOM % 51 ))
        echo $nombreAleatoire
        break
    fi
    if test $difficulte -eq 2
    then
        #nombreAleatoire= 1 + $RANDOM % 50
        break
    fi
    if test $difficulte -eq 3
    then
        #nombreAleatoire= 1 + $RANDOM % 100
        break
    fi
    echo "Valeur incorrecte, veuillez réessayer"
    read difficulte
done

echo "Donnez un nombre : "
read nombre

while test "$nombre" != "$nombreAleatoire"
do
    if  test "$nombre" -lt "$nombreAleatoire"
    then
        echo "Trop petit !"
        let ++nbCoups
    else
        echo "Trop grand !"
        let ++nbCoups
    fi
    read nombre
    echo $nombreAleatoire
done

echo "Bravo vous avez decouvert le nombre mystere $nombreAleatoire en $nbCoups coups."

exit 0