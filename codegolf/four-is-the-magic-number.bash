#!/bin/bash

cat << EOF >/dev/null

I didn't check the sandbox before posting this challenge - it looks like this challenge was proposed by Cᴏɴᴏʀ O'Bʀɪᴇɴ.

Given an integer input, write a program that prints the "four is a magic number" riddle

Four is the magic number
Five is four and four is the magic number
Six is three and three is five and five is four and four is the magic number
Eleven is six and six is three and three is five and five is four and four is the magic number
Five Hundred is eleven and eleven is six and six is three and three is five and five is four and four is the magic number
If you already know the riddle, or are too lazy to solve it anxious to find out what the riddle is, here's an explanation

The next number is the number of letters in the previous number. So, for example, five has four letters, so the next number is four.

six has three letters, so the next number is 3, and three has five letters, so the next number is 5, and five has four letters, so the next number is 4

The reason the riddle ends at four is because four has four letters, and four is four and four is four and four is four... (four is the magic number)

Test Cases
0 =>
  Zero is four and four is the magic number
1 =>
  One is three and three is five and five is four and four is the magic number
2 =>
  Two is three and three is five and five is four and four is the magic number
3 =>
  Three is five and five is four and four is the magic number
4 =>
  Four is the magic number
5 =>
  Five is four and four is the magic number
6 =>
  Six is three and three is five and five is four and four is the magic number
7 =>
  Seven is five and five is four and four is the magic number
8 =>
  Eight is five and five is four and four is the magic number
9 =>
  Nine is four and four is the magic number
10 =>
  Ten is three and three is five and five is four and four is the magic number
17 =>
  Seventeen is nine and nine is four and four is the magic number
100 =>
  One Hundred is ten and ten is three and three is five and five is four and four is the magic number
142 =>
  One Hundred Forty Two is eighteen and eighteen is eight and eight is five and five is four and four is the magic number
1,000 =>
  One Thousand is eleven and eleven is six and six is three and three is five and five is four and four is the magic number
1,642 =>
  One Thousand Six Hundred Forty Two is twenty nine and twenty nine is ten and ten is three and three is five and five is four and four is the magic number
70,000 =>
  Seventy Thousand is fifteen and fifteen is seven and seven is five and five is four and four is the magic number
131,072 =>
  One Hundred Thirty One Thousand Seventy Two is thirty seven and thirty seven is eleven and eleven is six and six is three and three is five and five is four and four is the magic number
999,999 =>
  Nine Hundred Ninety Nine Thousand Nine Hundred Ninety Nine is fifty and fifty is five and five is four and four is the magic number
Rules
The input may either be taken from STDIN or as an argument to a function
The input will be a positive number between 0 and 999,999
The input will only contain numbers (it will follow the regex ^[0-9]+$)
The input can either be taken as an integer or a string
When converted to a word string, spaces and hyphens should not be included in the count (100 [One Hundred] is 10 characters, not 11. 1,742 [One thousand Seven hundred Forty-Two] is 31 characters, not 36)
When converted to a string, 100 should be One Hundred, not A Hundred or Hundred, 1000 should be One Thousand, not A Thousand or Thousand.
When converted to a string 142 should be One Hundred Forty Two, not One Hundred and Forty Two
The output is case-insensitive, and should follow the format "N is K and K is M and M is ... and four is the magic number" (unless the input is 4, in which case the output should simply be "four is the magic number")
The output can use numbers instead of letters ("5 is 4 and 4 is the magic number" instead of "five is four and four is the magic number") as long as your program is always consistent
The output can either be the return value of a function, or printed to STDOUT
Standard loopholes apply
This is code-golf, so the shortest program in bytes wins. Good luck!
Bonus
-30 bytes if the program works when the input is between -999,999 and 999,999.

Negative numbers, when converted to words, just have "negative" in front of them. For example -4 is "Negative Four", Negative Four is twelve and twelve is six and six is three and three is five and five is four and four is the magic number

-150 bytes if the program does not use any built-in functions for generating the string representation of the number

EOF

# ported from @Digital Trauma solution
gen() {
	s=""
	for ((n=$1; n-4; n=m)) {
		m=$(number -l -- $n | sed 's/nus/&&/;s/\W//g')
		s+="$n is $[m=${#m}] and "
	}
	echo $s 4 is the magic number
}

gen 131072
gen -4
gen 4
