#!/bin/bash

if test $1 -le '2'
	then
	echo "Petit voyage"
	else
	if test $1 -gt '40'
		then
		echo "Grand voyage"
	else
		echo "Moyen voyage"
	fi
fi
exit 0
