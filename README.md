interact
========

A simple tool for facilitating SSH interactions within shell scripts.

It's written in C++ for Unix-like operating systems.

Example
======

The following shell script can be used to commit and push to a git repository from one end and then pull the changes over SSH from another. The `interact` command accepts a script with first line determining the user and the hostname to establish a connection with, and subsequent lines to be executed on a remote machine.

```
#!/bin/sh
cd ~/gitdir
git commit -am "$1"
git push origin master
interact "user@43.23.129.102
cd ~/gitdir
git pull origin master
exit
"
echo "Remote updated"
```

Installation
============

Make sure you have `expect` installed on your system. You should be able to do it using your OS' package management utility (eg. `sudo yum install expect` or `sudo apt-get install expect`). Clone this repository and compile `interact.cpp` (eg. with `sudo g++ interact.cpp -o /usr/local/bin/interact`).
