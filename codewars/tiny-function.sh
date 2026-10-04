#!/bin/sh

cat << EOF >/dev/null

Our universe is so huge, possibly even infinite and it makes us feel so tiny, isn't that so?

Task
Write a tiny function f that outputs 'tiny' without using the letters t, i, n, y anywhere in your code

Code Limit
Your code is limited to less than 34 characters

Buffer and unicode escapes \ are banned to avoid cheesy solutions :)

EOF

echo "74696e790a" | xxd -r -p

