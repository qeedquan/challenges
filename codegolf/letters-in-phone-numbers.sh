#!/bin/sh

cat << EOF >/dev/null

Problem:

You are making a new phone where people can type in specialized phone numbers, for example, 1-800-program, and they would be converted automatically to a usable phone number, like 1-800-7764726 (for the previous example).

Your program will recieve a string if any length with numbers, letters and dashes, and convert all the letters to their corresponding numbers.

Here is a keypad, for reference:

https://i.stack.imgur.com/7TKsb.png

Rules:

Your program will receive a string
It will process it and return/print another string
Any language is accepted
Since it is code-golf, the shortest code wins

EOF

translate() {
	echo $@ | tr a-z 22233344455566677778889
}

translate "1-800-program" 
translate "hello-world"
