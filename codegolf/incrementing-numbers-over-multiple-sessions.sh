#!/bin/sh

cat << EOF >/dev/null

Good Evening Golf Agents,

Your mission is on behalf of notorious entertainment giant Eviltronic Arts. As part of their nefarious plan for world enslavement and entertainment, they must sell as many copies of SimStation V as possible. This means that the software must mysteriously stop working, after starting it a few times.

Your goal is to write a program that counts the amount of times it has been run. The program must do nothing other then write the integer to stdout. The first time it is run, it should return "1". The next "2" and so on. The program must be able to at least reach the number "14", but there is no required upper limit.

However, your program must not write any new files. Accessing itself, or the registry, or even the internet is absolutely OK. But some of our users are suspicious of new files, and will merely overwrite them! The nerve! Defeating the limitations on software they legitimately purchased!

The program can not assume a stable interpreter or shell - the program must still work if the entire interpreter nay shell nay computer is restarted between running.

As it must be as undetectable as possible, the shortest source code will win.

Good luck agents. The entertainment industry is counting on you.

EOF

wc -l $0
echo >> $0
