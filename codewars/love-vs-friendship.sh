#!/bin/sh

cat << EOF >/dev/null

If　a = 1, b = 2, c = 3 ... z = 26

Then l + o + v + e = 54

and f + r + i + e + n + d + s + h + i + p = 108

So friendship is twice stronger than love :-)

The input will always be in lowercase and never be empty.

EOF

ord() { 
	printf "%d\n" "'$1"
}

lettersum() {
	r=0
	for c in $(echo -n $1 | sed 's/./&\n/g'); do
		r=$(echo "$r + $(ord $c) - $(ord a) + 1" | bc)
	done
	echo $r
}

lettersum love
lettersum friendship
