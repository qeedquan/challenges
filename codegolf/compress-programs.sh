#!/bin/bash

cat << EOF >/dev/null

Write a program/script that decompresses and passes any compressed data appended at the end of the binary/file as standard input to a program specified as arguments.

$ gzip --to-stdout input >> your_solution
$ your_solution program args...
should have the same effects as:

$ program args... < input

EOF

tail -n+3 "$0" | zcat | "$@"
