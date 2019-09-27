# dev

###Prerequisites

## Generate an ssh key
```
ssh-keygen -t rsa -b 4096 -C "your_email@example.com"
```

## Start the ssh agent
```
eval "$(ssh-agent -s)"
```

## Copy the ssh key in the ssh agent
```
ssh-add ~/.ssh/id_rsa
```

### Adding a repo
```
git add "path"
```

### Commit and push
## git commit
```
git commit -a -m "this is a comment"
```

## git push
```
git push origin master
```
