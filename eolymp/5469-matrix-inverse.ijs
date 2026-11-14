NB. You are given a square matrix.
NB.
NB. Your task is to find its inverse.
NB.
NB. Input
NB. The first line contains a single integer N (1≤N≤100) — the size of the matrix. The next N lines each contain N real numbers, which represent the matrix.
NB.
NB. Output
NB. If the inverse of the matrix does not exist, output a single line with the word NO.
NB. Otherwise, output YES on the first line, followed by N lines, each containing N real numbers representing the inverse matrix.
NB.
NB. Examples
NB.
NB. Input #1
NB. 2
NB. 0 1.0
NB. 1 0
NB.
NB. Answer #1
NB. YES
NB. 0.00000000000000000000 1.00000000000000000000
NB. 1.00000000000000000000 0.00000000000000000000

inv =: %.

A1 =: 2 2 $ 0 1 1 0
A2 =: 3 3 $ 1 0 0 0 1 0 0 0 1

1!:2&2 inv A1
1!:2&2 inv A2

