#!/bin/bash

note=0
total=0
nbNote=0
moyenne=0

until [ $note == '.' ]
do

	let "total = total + note"
	read -p "Entrez une note : " note
	let "nbNote++"

done

	let "nbNote--"
	echo "Le total est : $total"
	let "moyenne = total / nbNote"
	echo "La moyenne est de : $moyenne"

exit 0
