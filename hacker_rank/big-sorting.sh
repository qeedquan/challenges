#!/bin/sh

cat << EOF >/dev/null

Consider an array of numeric strings where each string is a positive number with anywhere from 1 to 10^6 digits.
Sort the array's elements in non-decreasing, or ascending order of their integer values and return the sorted array.

Example

Return the array ['1', '3', '150', '200'].

Function Description

Complete the bigSorting function in the editor below.

bigSorting has the following parameter(s):

string unsorted[n]: an unsorted array of integers as strings
Returns

string[n]: the array sorted in numerical order

Input Format

The first line contains an integer, , the number of strings in .
Each of the  subsequent lines contains an integer string, .

Constraints

1 <= n <= 2*10^5
Each string is guaranteed to represent a positive integer.
There will be no leading zeros.
The total number of digits across all strings in  is between  and  (inclusive).

Sample Input 0
6
31415926535897932384626433832795
1
3
10
3
5

Sample Output 0
1
3
3
5
10
31415926535897932384626433832795

Sample Input 1

8
1
2
100
12303479849857341718340192371
3084193741082937
3084193741082938
111
200

Sample Output 1

1
2
100
111
200
3084193741082937
3084193741082938
12303479849857341718340192371

EOF

cat << EOF | sort -h
31415926535897932384626433832795
1
3
10
3
5
EOF

echo

cat << EOF | sort -h
1
2
100
12303479849857341718340192371
3084193741082937
3084193741082938
111
200
EOF
