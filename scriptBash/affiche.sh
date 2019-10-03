#!/bin/bash

if [ -z "$2" ]
then
	echo "==== fichier : $1"
	cat $1 -n
else
	echo "Ligne : $2"
	sed -n $2p $1
fi

exit 0
