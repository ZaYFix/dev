#!/bin/bash

echo -n "L'utilisateur $1 s'est connecté "
echo -n $(last $1 | sed '/^$\|wtmp/d' | wc -l)
echo " fois."
echo "Ses 3 dernières connexions sont: "
last $1 | cut -c40-

exit 0
