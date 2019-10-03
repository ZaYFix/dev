#!/bin/bash

note=0
total=0
nbNotes=0

while test $note != '.'
do
	read -p "note : " note
	if test $note != '.'
	then
		let "total=total+note"
		let "++nbNotes"
	fi
done
if test $nbNotes != '0'
then
	echo "Somme = $total"
	printf "Moyennne = "
	echo "scale=2; $total/$nbNotes" | bc -lq
	exit 0
fi

exit 0
