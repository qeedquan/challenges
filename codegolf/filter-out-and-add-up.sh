#!/bin/sh

cat << EOF > /dev/null

Task
The task is very simple. Given a non-empty string containing numbers, uppercase and lowercase letters, output the sum of the remaining numbers. For example:

a1wAD5qw45REs5Fw4eRQR33wqe4WE
Filtering out all the letters would result into:

 1   5  45   5  4    33   4
The sum of these numbers is 1 + 5 + 45 + 5 + 4 + 33 + 4 = 97. So the output would be 97.

Test Cases
a > 0
0 > 0
5 > 5
10 > 10
a0A > 0
1a1 > 2
11a1 > 12
4dasQWE65asAs5dAa5dWD > 79
a1wAD5qw45REs5Fw4eRQR33wqe4WE > 97
This is code-golf, so the submission with the least amount of bytes wins!

EOF

filtersum() {
	tot=$(echo $1 | grep -o '[0-9]\+' | awk '{ sum += $1 } END { print sum }')
	if [ -z $tot ]; then
		tot=0
	fi
	echo $tot
}

filtersum "a"
filtersum "0"
filtersum "5"
filtersum "10"
filtersum "a0A"
filtersum "1a1"
filtersum "11a1"
filtersum "4dasQWE65asAs5dAa5dWD"
filtersum "a1wAD5qw45REs5Fw4eRQR33wqe4WE"
