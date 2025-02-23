#!/bin/bash

cat << EOF > /dev/null

Given a sentence, identify and display its fourth word. Assume that the space (' ') is the only delimiter between words.

Input Format

A text file with lines of ASCII text only. Each line has exactly one sentence.

Constraints

(N is the number of lines of text in the input file)

Output Format

The output should contain N lines.

For each input sentence, identify and display its fourth word. Assume that the space (' ') is the only delimiter between words.

Sample Input

Hello
World
how are you

Sample Output

Hello
World

EOF

cat << EOF | cut -d ' ' -f4 | sed 's/^ *//; s/ *$//; /^$/d'
Hello
World
how are you
EOF
