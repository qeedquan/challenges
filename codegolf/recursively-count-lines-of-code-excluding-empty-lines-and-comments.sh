#!/bin/sh

cat << EOF >/dev/null

Requirement: Write a program (in any language) that counts the number of lines of code in files matching *.sh in the directory tree starting from the directory that the program is executed in, excluding lines that are empty, only contain whitespace, or are just single-line comments (a line which the first character that is not a whitespace character is #). Files will only contain printable ASCII characters.

Output: A single integer representing the total count (can be followed by a newline too).

Here is an expanded solution in Python:

import os, sys

def recurse(dir = './'):
    count = 0

    for file in os.listdir(dir):
        if not os.path.isfile(dir + file):
            count += recurse(dir + file + '/')
        elif file.endswith('.sh'):
            with open(dir + file, 'r') as f:
                for line in f.read().split('\n'):
                    if (not line.strip().startswith('#')) and (not line.strip() == ''):
                        count += 1

    return count

sys.stdout.write(recurse())

EOF

count() {
	cat $(find $1 -name \*.sh) | tr -d " \t" | grep . | grep -v "^#" | wc -l
}

count "."

