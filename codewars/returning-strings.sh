#!/bin/sh

cat << EOF >/dev/null

Make a function that will return a greeting statement that uses an input; your program should return, "Hello, <name> how are you doing today?".

[Make sure you type the exact thing I wrote or the program may not execute properly]

EOF

greet() {
	echo "Hello, $1 how are you doing today?"
}

greet "John"
greet "James"

