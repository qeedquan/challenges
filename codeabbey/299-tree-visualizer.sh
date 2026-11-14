#!/bin/sh

cat <<EOF >/dev/null

The problem about Tree Value may require careful drawing of the tree with all its nodes - and this inspired somewhat simpler task!

We get the tree, described by list of parents for every node. We want to visualize or "pretty-print" it, according to the example below. Use characters plus, minus, backslash and pipe as line segments. Order child nodes alphabetically. Hopefully you could figure out remaining details of the format.

root
|
+-mama
| |
| +-kattie
| | |
| | \-petit
| |
| \-maggie
|
+-papa
|
\-someone
Input starts with number of nodes in a tree, N.
Then N-1 lines follow, in form child parent. Root node is called root and is not listed as it doesn't have parent itself.

Answer just the beautiful tree, according to the template shown above.

Example of input data, corresponding to the tree above is:

7
mama root
someone root
petit kattie
kattie mama
maggie mama
papa root
Don't think this is completely artificial puzzle, please - have a look, for example at popular maven tool for building java-based projects - it has a command to print out the tree of dependencies (libraries) in very similar format!

EOF

cat <<EOF | tree --fromfile .
/root
/root/mama
/root/mama/kattie
/root/mama/kattie/petit
/root/mama/maggie
/root/papa
/root/someone
EOF
