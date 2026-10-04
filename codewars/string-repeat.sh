#!/bin/sh

cat << EOF >/dev/null

Write a function called repeatStr which repeats the given string string exactly n times.

repeatStr(6, "I") // "IIIIII"
repeatStr(5, "Hello") // "HelloHelloHelloHelloHello"

EOF

repeat() {
	python -c "print(\"$2\" * $1)"
}

repeat 6 "I"
repeat 5 "Hello"

