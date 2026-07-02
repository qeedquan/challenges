%{

A matrix of size n×n is given. Find the sum of all its positive elements.

Input
The first line contains a single integer n (1≤n≤100).
The next n lines contain the elements of the n×n matrix.
Each element is an integer with an absolute value not exceeding 100.

Output
Print the sum of all positive elements in the matrix.

Examples
Input #1
3
4 -2 5
1 -4 -12
0 1 -3

Answer #1
11

%}

A = [4 -2 5; 1 -4 -12; 0 1 -3];
sum(A(A > 0))
