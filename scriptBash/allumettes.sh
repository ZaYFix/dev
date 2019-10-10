#!/bin/bash

readonly MIN=1
readonly MAX=3
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
		allumettesTirerJoueur=0
		allumettesTirerMachine=0
        while [ $nbAllumettes != "0" ]
        do
        echo "Il reste $nbAllumettes allumette(s)"
		echo "Nb allumettes (1, 2 ou 3) ?"
        read -r nbAllumettesChoisis
		let "test = nbAllumettes - nbAllumettesChoisis"
		while [ -z $nbAllumettesChoisis ] || [ $nbAllumettesChoisis -gt 3 ] || [ $nbAllumettesChoisis -eq 0 ] || [ $nbAllumettesChoisis -gt $nbAllumettes ] || [ $test -lt 0 ] 
		do
			echo "Impossible"
			read -r nbAllumettesChoisis
		done
		let "++allumettesTirerJoueur"
        let "nbAllumettes = nbAllumettes - nbAllumettesChoisis"
		if [ $nbAllumettes -eq 0 ]
		then
			break;
		fi
        allumetteAleatoire=$((MIN + RANDOM % MAX))
		while [ $allumetteAleatoire -gt $nbAllumettes ]
		do
			allumetteAleatoire=$((MIN + RANDOM % MAX))
		done
		let "++allumettesTirerMachine"
        echo "La machine a choisie $allumetteAleatoire allumettes."
        let "nbAllumettes = nbAllumettes - allumetteAleatoire"
        done
		if [ $allumettesTirerJoueur -gt $allumettesTirerMachine ]
		then
			echo "La machine a gagnée !"
			exit 0
		else
			echo "Le joueur a gagné !"
			exit 0
		fi
        ;;
    M)
		allumettesTirerJoueur=0
		allumettesTirerMachine=0
        while [ $nbAllumettes != "0" ]
        do
			allumetteAleatoire=$((MIN + RANDOM % MAX))
			while [ $allumetteAleatoire -gt $nbAllumettes ]
			do
				allumetteAleatoire=$((MIN + RANDOM % MAX))
			done
			let "++allumettesTirerMachine"
        	echo "La machine a choisie $allumetteAleatoire allumette(s)."
        	let "nbAllumettes = nbAllumettes - allumetteAleatoire"
			if [ $nbAllumettes -eq 0 ]
			then
				break;
			fi
        	echo "Il reste $nbAllumettes allumette(s)"
			echo "Nb allumettes (1, 2 ou 3) ?"
        	read -r nbAllumettesChoisis
			let "test = nbAllumettes - nbAllumettesChoisis"
			while [ -z $nbAllumettesChoisis ] || [ $nbAllumettesChoisis -gt 3 ] || [ $nbAllumettesChoisis -eq 0 ] || [ $nbAllumettesChoisis -gt $nbAllumettes ] || [ $test -lt 0 ] 
			do
				echo "Impossible"
				read -r nbAllumettesChoisis
			done
        	let "nbAllumettes = nbAllumettes - nbAllumettesChoisis"
			if [ $nbAllumettes -eq 0 ]
			then
				break;
			fi
			let "++allumettesTirerJoueur"
        done
		echo $allumettesTirerJoueur
		echo $allumettesTirerMachine
		if [ $allumettesTirerJoueur - $allumettesTirerMachine ]
		then
			echo "La machine a gagnée !"
			exit 0
		else
			echo "Le joueur a gagné !"
			exit 0
		fi
        ;;
    T)
        echo "T"
        ;;
    *)
        echo "Sorry"
        ;;
esac

exit 0
