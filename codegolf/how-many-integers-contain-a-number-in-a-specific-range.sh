#!/bin/sh

cat << EOF >/dev/null

The program should take input the number, the start of the range and the end of the range, and output how many integers the number appears between the start and end of the range, inclusive. Both programs and functions are allowed.

Example Inputs
For example:

//Input example 1
3,1,100
//Input example 2
3
1
100
//Input example 3
3 1 100
//Input example 4
a(3, 1, 100);
All the above four input examples are valid and all of them mean that 3 is the number in question, 1 is the beginning of the range and 100 the the end of the range.

And then the program should output how many times 3 appears in the range from 1 to 100 inclusive. 3 appears in the integers 3, 13, 23, 30, 31, 32, 33, ..., 93 at a total of 19 times. So the program should output 19 as the output because that is how many times 3 appears in the range from 1 to 100.

Rules
Both programs and functions are allowed.
All numbers will be integers, meaning that there will not be any floats or doubles.
Note: the sought number will always be in the range 0≤x≤127. There will be no cases where it will be outside this 0≤x≤127 range.
As in the first example, with the case as 33, the number 3 will be counted as appearing only once, not twice.
The values of the start and end of the range will be between -65536 and 65535 inclusive.
The value of range's start will never exceed or equal to range's end. start < end
Also the range is inclusive. For example if the input was 8 8 10, the range would be 8≤x≤10 and hence the output will be 1.
Input can be taken in any of the ways shown in the examples. Input can be taken as a string or as a number, any way you wish.
Test Cases
3 1 100
19

3 3 93
19

12,-200,200
24          //This is because 12 appears in -129, -128, ..., -112, -12, 12, 112, 120, 121, 122, ...

123,1,3
0           //This is because all of 123's digits have to appear in the same order

3 33 34
2           //Because 3 appears in 2 numbers: 33 and 34

a(0,-1,1);
1

$ java NotVerbose 127 -12 27
0

EOF

count() {
	seq $2 $3 | grep -c $1
}

count 3 1 100
count 3 1 93
count 12 -200 200
count 123 1 3

count 3 33 34
count 0 -1 1
count 127 -12 27

