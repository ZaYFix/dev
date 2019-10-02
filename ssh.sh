#!/bin/bash

ssh-keygen -o # Generate the key
ssh-add ~/.ssh/id_rsa # Add the key in the ssh agent
gedit ~/.ssh/id_rsa.pub # Open the public key, copy everything in it
firefox "https://github.com/settings/ssh/new" # Paste everything here
