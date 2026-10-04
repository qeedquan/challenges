#!/bin/sh

cat << EOF > /dev/null

On Github, there is a list of the 10,000 most common passwords. I've also generated my own list of random passwords.

Your job is to identify the difference between the two lists (with 100% accuracy).

Therefore, your program needs to accept a string, and return:

A truthy value if the password is on the common passwords list
A falsy value if the password is on the random passwords list
Anything you'd like if the password isn't on either
For those that are interested, my program generates passwords between 5-10 characters in length, and each character is either a lowercase letter or a digit.

Note: You should not use these passwords in anything secure. My generation algorithm is not secure at all, and the results are posted online for all to see

EOF

COM="10k-most-common.txt"
RND="generated_passwords.txt"

if [ $# -eq 2 ]; then
	COM=$1
	RND=$2
fi

check() {
	WORD=$1
	echo -n "$WORD | "
	if [ $(grep -x $WORD $COM) ]; then
		echo true
	elif [ $(grep -x $WORD $RND) ]; then
		echo false
	else
		od -An -N1 -i /dev/urandom | awk '{print $1}'
	fi
}

check "hello"
check "123"
check "123456"
check "21g4mzy25"
check "0ufog"
check "god"
check "john"
check "outer"
check "time"
check "9999"
