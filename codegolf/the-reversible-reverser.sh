#!/bin/sh

cat << EOF >/dev/null

Your task is simple. The program reads in a line of text from the standard input, and it prints out the same text in a character-reversed form. It is not allowed to print anything else.

For example:

input: "Hello!", output: "!olleH"

The catch is, your program has to be able to do the exact same thing if the source code itself is character-reversed!

Scoring: standard code-golf scoring applies, with the following modification to limit the boring

//margorp
program//
style answers: any solution which is a palindrome will incur a +25% penalty to the score, rounded up. This penalty still applies, if you, for example, insert characters into the program which do not have any useful effects, just to break the palindrome.

EOF

rev
