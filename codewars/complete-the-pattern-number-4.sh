#!/bin/sh

cat << EOF >/dev/null

Task:
You have to write a function pattern which creates the following pattern upto n number of rows. If the Argument is 0 or a Negative Integer then it should return "" i.e. empty string.

Examples:
pattern(4):

1234
234
34
4
pattern(6):

123456
23456
3456
456
56
6
Note: There are no blank spaces

Hint: Use \n in string to jump to next line

EOF

pattern() {
	for i in $(seq $1 -1 1); do
		seq -s '' $(echo $1-$i+1 | bc) $1
	done
}

pattern 4
pattern 6
