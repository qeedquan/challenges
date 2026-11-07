#!/bin/bash

cat << EOF > /dev/null

Code Golf
Totally real backstory: I'm a contractor working on a website www.Sky.Net and one of our tasks it to create some self-aware program or something, I don't know I wasn't really listening to the boss. Anyways in an effort to make our code more self-aware we need IT to be able to know what code is on each line-number.

Challenge
Create a program or function that takes an input n and returns the code of said program or function on line n.

Rules
➊ Your program or function must be at least 4 lines long. Each line must be unique.

➋ You may assume the input will always be a positive integer greater than or equal to 1 and less than or equal to the number of lines in your program/function.

➌ The first line in your program/function is line 1, not line 0.

➍ You can not access the file that your program is on. (If someone has to ask "Isn't this technically breaking rule #4"; it probably is)

➎ Lines can-not be empty (this includes a space if spaces don't do anything in your language)

➏ Lines can-not be //comments (/* of any <!--style)

This is a quine-like challenge
This is code-golf, so the submission with the fewest bytes wins!

EOF

if [[ "$#" != "2" ]]; then
	echo "usage: <line> <file>"
	exit 2
fi

awk "NR==$1, NR==$1" $2
