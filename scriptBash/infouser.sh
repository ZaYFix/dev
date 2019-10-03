#!/bin/bash

echo "L'utilisateur $1 s'est connecté / fois."
echo "Ses 3 dernières connexions sont: "
last $1 | cut -c40-

exit 0
