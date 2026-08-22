#!/bin/sh

cat << EOF >/dev/null

Task
Given an array, arr, of n integers, calculate and print the standard deviation.
Your answer should be in decimal form, rounded to a scale of 1 decimal place (i.e., 12.3 format).
An error margin of +-0.1 will be tolerated for the standard deviation.

Example

arr=[2, 5, 2, 7, 4]

The sum of the array values is 20 and there are 5 elements. The mean is 4.0.
Subtract the mean from each element, square each result, and take their sum.

(2-4)^2 = 4
(5-4)^2 = 1
(2-4)^2 = 4
(7-4)^2 = 9
(4-4)^2 = 0

Their sum is 18. Take the square root of 18/5 to get 1.8, the standard deviation.

Function Description

Complete the stdDev function in the editor below.

stdDev has the following parameters:
- int arr[n]: an array of integers

Prints
- float: the standard deviation to 1 place after the decimal

Input Format

The first line contains an integer, , denoting the size of arr.
The second line contains  space-separated integers that describe .

Constraints

Output Format

Print the standard deviation on a new line, rounded to a scale of  decimal place (i.e.,  format).

Sample Input

STDIN           Function
-----           --------
5               arr[] size n = 5
10 40 30 50 20  arr=[10, 40, 30, 50, 20]

Sample Output

14.1

EOF

stddev() {
	echo "$@" | tr " " "\n" | awk '{ sum += $1; sumsq += $1*$1 } END { print sqrt(sumsq/NR - (sum/NR)**2) }'
}

stddev 2 5 2 7 4
stddev 10 40 30 50 20
