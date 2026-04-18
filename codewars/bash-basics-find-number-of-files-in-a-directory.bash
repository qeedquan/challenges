#!/bin/bash

cat << EOF >/dev/null

Your task is to write a script that finds the number of type 'f' files in a given directory (argument 1) to stdout. If there is no arguments, print "Nothing to find".

Examples:

run_shell        --> prints: "Nothing to find"
run_shell dir1         --> prints: "There are 5 files in /home/codewarrior/shell/dir1"
run_shell doesNotExist --> prints: "Directory not found"

EOF

[ $1 ] || echo "Nothing to find" || exit 1
cd $1 || echo "Directory not found" || exit 1
echo "There are $(find . -maxdepth 1 -type f | wc -l) files in $(pwd)"

