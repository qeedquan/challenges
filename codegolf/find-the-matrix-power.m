%{

Problem
Create a program or function that can calculate the result of a matrix raised to the nth power. Your code will take an arbitrary square matrix A and a non-negative integer n, and return a matrix with the value An.

Restrictions
Built-in functions that compute the matrix power and matrix product are not allowed.

The rest of the standard rules for code-golf apply.

Explanation
Given a square matrix A, the value of An = A A ⋯ A (repeated matrix product of A with itself, n times). If n is positive, the standard just mentioned is used. When n is zero, the identity matrix with the same order of A is the result.

Goal
This is code-golf and the shortest code wins.

Test Cases
Here, A is the input matrix, n is the input integer, and r is the output matrix where r = An.

n = 0
A = 62 72
    10 34
r =  1  0
     0  1

n = 1
A = 23 61 47
    81 11 60
    42  9  0
r = 23 61 47
    81 11 60
    42  9  0

n = 2
A =  12  28 -26  3
     -3 -10 -13  0
     25  41   3 -4
    -20 -14  -4 29
r = -650 -1052  -766 227
    -331  -517   169  43
     332   469 -1158 -53
    -878  -990   574 797

n = 4
A = -42 -19  18 -38
    -33  26 -13  31
    -43  25 -48  28
     34 -26  19 -48
r = -14606833  3168904 -6745178  4491946
      1559282  3713073 -4130758  7251116
      8097114  5970846 -5242241 12543582
     -5844034 -4491274  4274336 -9196467

n = 5
A =  7  0 -3  8 -5  6 -6
     6  7  1  2  6 -3  2
     7  8  0  0 -8  5  2
     3  0  1  2  4 -3  4
     2  4 -1 -7 -4 -1 -8
    -3  8 -9 -2  7 -4 -8
    -4 -5 -1  0  5  5 -1
r =  39557  24398 -75256 131769  50575   14153  -7324
    182127  19109   3586 115176 -23305    9493 -44754
    146840  31906 -23476 190418 -38946   65494  26468
     42010 -21876  41060 -13950 -55148   19290   -406
     44130  34244 -35944  34272  22917  -39987 -54864
      1111  40810 -92324  35831 215711 -117849 -75038
    -70219   8803 -61496   6116  45247   50166   2109

%}

A = [62 72
     10 34]
A^0

A = [23 61 47
     81 11 60
     42  9  0]
A^1

A = [12  28 -26  3
     -3 -10 -13  0
     25  41   3 -4
    -20 -14  -4 29]
A^2

A = [-42 -19  18 -38
    -33  26 -13  31
    -43  25 -48  28
     34 -26  19 -48]
A^4

A = [7  0 -3  8 -5  6 -6
     6  7  1  2  6 -3  2
     7  8  0  0 -8  5  2
     3  0  1  2  4 -3  4
     2  4 -1 -7 -4 -1 -8
    -3  8 -9 -2  7 -4 -8
    -4 -5 -1  0  5  5 -1]
A^5
