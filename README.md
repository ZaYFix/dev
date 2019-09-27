# Prerequisites

### Generate an ssh key
```
ssh-keygen -o
```

### Start the ssh agent
```
eval "$(ssh-agent -s)"
```

### Copy the ssh key in the ssh agent
```
ssh-add ~/.ssh/id_rsa
```

### Copy your ssh key
```
gedit ~/.ssh/id_rsa.pub
```

### Add the ssh key to your Github account
[Check here](https://help.github.com/en/enterprise/2.15/user/articles/adding-a-new-ssh-key-to-your-github-account)

## Adding a repo

```
git init
```

```
git add "path"
```

```
git remote add origin git@github.com:yourname/name.git 
```

## Commit and push

### git commit
```
git commit -a -m "this is a comment"
```

### git push
```
git push origin master
```
