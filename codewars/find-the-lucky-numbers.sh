#!/bin/sh

cat << EOF >/dev/null

Write a function filterLucky/filter_lucky() that accepts a list of integers and filters the list to only include the elements that contain the digit 7.

For example,

ghci> filterLucky [1,2,3,4,5,6,7,68,69,70,15,17]
[7,70,17]
Don't worry about bad input, you will always receive a finite list of integers.

EOF

lucky() {
	for i in $@; do
		if echo $i | grep -q "7"; then
			echo -n "$i "
		fi
	done
	echo
}

lucky 1 2 3 4 5 6 7 68 69 70 15 17
