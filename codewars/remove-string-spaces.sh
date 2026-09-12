#!/bin/sh

cat << EOF >/dev/null

Simple, remove the spaces from the string, then return the resultant string.

EOF

nospaces() {
	echo $@ | tr -d [:space:]
	echo
}

nospaces "hello     world a n d such"

