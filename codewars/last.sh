#!/bin/sh

cat << EOF >/dev/null

Find the last element of the given argument(s).

Examples
last([1, 2, 3, 4] ) // =>  4
last("xyz")         // => "z"
last(1, 2, 3, 4)    // =>  4
In javascript and CoffeeScript a list will be an array, a string or the list of arguments.

(courtesy of haskell.org)

EOF

last() {
	for i; do
		true
	done
	echo $i
}

last 1 2 3 4
last x y z
last "a" "b" "c"
