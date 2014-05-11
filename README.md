interact
========

Simple tool for facilitating SSH interaction within shell scripts.

It's written in C++ for Unix-like operating systems.

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

Installation
============

Make sure you have `expect` installed on your system. Clone the repository and compile `interact.cpp` (eg. with `sudo g++ interact.cpp -o /usr/local/bin/interact`).
