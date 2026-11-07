#!/bin/bash

cat << EOF > /dev/null

In this challenge, we practice using the tr command because it is a useful translation tool in Linux.

In a given fragment of text, replace all parentheses ()  with box brackets [].

Input Format

A block of ASCII text.

Output Format

Output the text with all parentheses () replaced with box brackets [].

Sample Input

int i=(int)5.8
(23 + 5)*2
Sample Output

int i=[int]5.8
[23 + 5]*2

EOF

cat << EOF | tr '()' '[]'
int i=(int)5.8
(23 + 5)*2
EOF
