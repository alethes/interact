interact
========

Simple tool for SSH interaction within shell scripts

Example
======

```
#!/bin/sh
cd ~/gitdir
git commit -am "commit"
git push origin master
interact user@43.23.129.102 "
cd ~/gitdir
git pull origin master
exit
"
echo "Remote updated"
```
