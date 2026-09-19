%{

A sequence of n integers is given. Print all its odd elements.

Input
The first line contains the integer n (n≤100). The second line contains n integers, each of which does not exceed 100 in absolute value.

Output
Print all the odd elements of the sequence in the order they appear in the input.

Examples

Input #1
7
14 17 16 3 7 19 9

Answer #1
17 3 7 19 9

%}

A = [14, 17, 16, 3, 7, 19, 9];
A(mod(A, 2) ~= 0)

