# Prérequis

### Générer une clé ssh
```
ssh-keygen -o
```

### Copie de la clé ssh dans l'agent ssh
```
ssh-add ~/.ssh/id_rsa
```

### Copiez votre clé ssh
```
gedit ~/.ssh/id_rsa.pub
```

### Ajoutez la clé ssh à votre compte Github
[Lien](https://help.github.com/en/enterprise/2.15/user/articles/adding-a-new-ssh-key-to-your-github-account)

## Ajout d'un repo

```
git init
```

```
git add "chemin_vers_le_dossier"
```

```
git remote add origin git@github.com:yourname/repo_name.git 
```

## Commit et push

### git commit
```
git commit -a -m "un commentaire"
```

### git push
```
git push origin master
```
