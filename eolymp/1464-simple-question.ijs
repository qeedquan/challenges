NB. Given an integer n, calculate the sum of all integers from 1 to n (inclusive).
NB.
NB. Input
NB. Each line contains a single integer n (∣n∣≤10000). The last line contains 0 and should not be processed.
NB.
NB. Output
NB. For each value of n, print the answer on a separate line.
NB.
NB. Examples
NB. Input #1
NB. 1
NB. 10
NB. 0
NB.
NB. Answer #1
NB. 1
NB. 55

triangular =: {{ y * (y + 1) % 2 }}

1!:2&2 triangular 1
1!:2&2 triangular 10

