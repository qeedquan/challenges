#!/bin/bash

cat << EOF > /dev/null

Description

Background
Raymond Babbitt drives his brother Charlie mad. Recently Raymond counted 246 toothpicks spilled all over the floor in an instant just by glancing at them. And he can even count Poker cards. Charlie would love to be able to do cool things like that, too. He wants to beat his brother in a similar task.

Problem
Here's what Charlie thinks of. Imagine you get a sequence of N numbers. The goal is to move the numbers around so that at the end the sequence is ordered. The only operation allowed is to swap two adjacent numbers. Let us try an example:
Start with: 2 8 0 3
swap (2 8) 8 2 0 3
swap (2 0) 8 0 2 3
swap (2 3) 8 0 3 2
swap (8 0) 0 8 3 2
swap (8 3) 0 3 8 2
swap (8 2) 0 3 2 8
swap (3 2) 0 2 3 8
swap (3 8) 0 2 8 3
swap (8 3) 0 2 3 8

So the sequence (2 8 0 3) can be sorted with nine swaps of adjacent numbers. However, it is even possible to sort it with three such swaps:
Start with: 2 8 0 3
swap (8 0) 2 0 8 3
swap (2 0) 0 2 8 3
swap (8 3) 0 2 3 8

The question is: What is the minimum number of swaps of adjacent numbers to sort a given sequence?Since Charlie does not have Raymond's mental capabilities, he decides to cheat. Here is where you come into play. He asks you to write a computer program for him that answers the question. Rest assured he will pay a very good prize for it.
Input

The first line contains the number of scenarios.
For every scenario, you are given a line containing first the length N (1 <= N <= 1000) of the sequence,followed by the N elements of the sequence (each element is an integer in [-1000000, 1000000]). All numbers in this line are separated by single blanks.
Output

Start the output for every scenario with a line containing "Scenario #i:", where i is the number of the scenario starting at 1. Then print a single line containing the minimal number of swaps of adjacent numbers that are necessary to sort the given sequence. Terminate the output for the scenario with a blank line.
Sample Input

4
4 2 8 0 3
10 0 1 2 3 4 5 6 7 8 9
6 -42 23 6 28 -100 65537
5 0 0 0 0 0
Sample Output

Scenario #1:
3

Scenario #2:
0

Scenario #3:
5

Scenario #4:
0
Source

TUD Programming Contest 2003, Darmstadt, Germany

EOF

swaps() {
	x=("$@")
	n=${#x[@]}
	c=0
	for i in $(seq 0 $((n-1))); do
		for j in $(seq $((i+1)) $((n-1))); do
			if [[ ${x[$i]} -gt ${x[$j]} ]]; then
				c=$((c + 1))
			fi
		done
	done
	echo $c
}

a=(2 8 0 3)
b=(0 1 2 3 4 5 6 7 8 9)
c=(-42 23 6 28 -100 65537)
d=(0 0 0 0 0)

swaps ${a[@]}
swaps ${b[@]}
swaps ${c[@]}
swaps ${d[@]}
