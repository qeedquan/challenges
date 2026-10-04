#!/bin/sh

cat << EOF >/dev/null

Implement a function which behaves like the uniq command in UNIX.

It takes as input a sequence and returns a sequence in which all duplicate elements following each other have been reduced to one instance.

Example:

["a", "a", "b", "b", "c", "a", "b", "c"]  =>  ["a", "b", "c", "a", "b", "c"]

EOF

solve() {
	echo $@ | sed 's/ /\n/g' | uniq | tr '\n' ' '
	echo
}

solve "a a b b c a b c"
