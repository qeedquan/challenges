#!/bin/sh

cat << EOF >/dev/null

Description

Johann Carl Friedrich Gauß (1777 – 1855) was one of the most important German mathematicians. For those of you who remember the Deutsche Mark, a picture of him was printed on the 10 – DM bill. In elementary school, his teacher J. G. Büttner tried to occupy the pupils by making them add up the integers from 1 to 100. The young Gauß surprised everybody by producing the correct answers (5050) within seconds.

Can you write a computer program that can compute such sums really quickly?

Given two integers n and m, you should compute the sum of all the integers from n to m. In other words, you should compute

http://poj.org/images/2924_1.gif

Input

The first line contains the number of scenarios. Each scenario consists of a line containing the numbers n and m (−109 ≤ n ≤ m ≤ 109).


Output

The output for every scenario begins with a line containing “Scenario #i:”, where i is the number of the scenario starting at 1. Then print the sum of all integers from n to m. Terminate the output for the scenario with a blank line.

Sample Input

3
1 100
-11 10
-89173 938749341
Sample Output

Scenario #1:
5050

Scenario #2:
-11

Scenario #3:
440625159107385260
Source

TUD Programming Contest 2006, Darmstadt, Germany

EOF

sum() {
	n=$1
	m=$2
	if [ $m -lt $n ]; then
		n=$2
		m=$1
	fi
	echo "($n + $m) * ($m - $n + 1) / 2" | bc
}

sum 1 100
sum -11 10
sum -89173 938749341
