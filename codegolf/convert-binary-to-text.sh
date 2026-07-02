#!/bin/sh

cat << EOF >/dev/null

Your task is to write a program, which takes a binary input and converts it to plain text. For Example:

01100001 01100010 01100011 = "abc"
Rules
Input can come from STDIN, function arguments, command line argument, file, whatever suits you.
The program can be a function, full program, whatever works, really, as long as no external uncounted code/arguments are needed to run it.
You can assume that the input is valid.
The length of the input is not limited
You can assume that all blocks are seperated with whitespaces
Test Cases
01010100 01100101 01110011 01110100 = "Test"
01001000 01100101 01101100 01101100 01101111 = "Hello"
01010111 01101111 01110010 01101100 01100100 00001101 00001010 = "World"
01000101 01111000 01100001 01101101 01110000 01101100 01100101 00001101 00001010 = "Example"
01100010 01101001 01101110 00001101 00001010 = "bin"
This is code-golf, so the shortest solution wins.

EOF

bin2txt() {
	for i in $@
	do
		echo -n $i | dc -e "2i?P"
	done
	echo
}

bin2txt 01010100 01100101 01110011 01110100
bin2txt 01001000 01100101 01101100 01101100 01101111
bin2txt 01010111 01101111 01110010 01101100 01100100 00001101 00001010
bin2txt 01000101 01111000 01100001 01101101 01110000 01101100 01100101 00001101 00001010
bin2txt 01100010 01101001 01101110 00001101 00001010

