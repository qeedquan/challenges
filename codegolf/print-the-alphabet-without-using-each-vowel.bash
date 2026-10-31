#!/bin/bash

cat << EOF >/dev/null

Inspiration: in 1939, a man named Ernest Vincent Wright wrote a novel called Gadsby without using the letter 'e'.

Your task is to write a set of (up to 5) programs in any language (which has a text-based syntax*) to output all 26 letters of the alphabet in order. However for each vowel aeiou, at least one of the programs must not include any occurrence of the vowel.

So there must be

a program that does not use 'a' or 'A' anywhere in the syntax of the program.
a program that does not use 'e' or 'E' anywhere in the syntax of the program.
a program that does not use 'i'  or 'I' anywhere in the syntax of the program.
a program that does not use 'o' or 'O' anywhere in the syntax of the program.
a program that does not use 'u' or 'U' anywhere in the syntax of the program.
All of them must output abcdefghijklmnopqrstuvwxyz.

The winner shall be the solution where the length of all programs is the shortest.

* since the constraint wouldn't be much of a challenge in Piet or Whitespace

EOF

$(tr c-y '\141-w'<<<'rtkpvh %s c') {b..z}
printf "\n"
