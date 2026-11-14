%{

In this challenge I will ask you to find a QR decomposition of a square matrix. The QR decomposition of matrix A is two Matrices Q and R such that A = QR. In particular we are looking for Q to be an orthogonal matrix (that is QTQ=QQT=I where I is the multiplicative identity and T is the transpose) and R to be a upper triangular matrix (every value below its diagonal must be zero).

You will write code that takes a square matrix by any reasonable method and outputs a QR decomposition by any method. Many matrices have multiple QR decompositions however you only ever need output one.

Elements of your resultant matrices should be within two decimal places of an actual answer for every entry in the matrix.

This is a code-golf competition so answers will be scored in bytes with fewer bytes being a better score.

Test Cases
These are only possible outputs, your outputs need not match all of these as long as they are valid.

0 0 0     1 0 0   0 0 0
0 0 0 ->  0 1 0   0 0 0
0 0 0     0 0 1 , 0 0 0

1 0 0     1 0 0   1 0 0
0 1 0 ->  0 1 0   0 1 0
0 0 1     0 0 1 , 0 0 1

1 2 3     1 0 0   1 2 3
0 3 1 ->  0 1 0   0 3 1
0 0 8     0 0 1 , 0 0 8

0 0 1     0 0 1   1 1 1
0 1 0 ->  0 1 0   0 1 0
1 1 1     1 0 0 , 0 0 1

0 0 0 0 1     0 0 0 0 1   1 0 0 0 1
0 0 0 1 0     0 0 0 1 0   0 1 1 1 0
0 0 1 0 0 ->  0 0 1 0 0   0 0 1 0 0
0 1 1 1 0     0 1 0 0 0   0 0 0 1 0
1 0 0 0 1     1 0 0 0 0 , 0 0 0 0 1

%}

[Q1, R1] = qr([0 0 0
               0 0 0
               0 0 0])

[Q2, R2] = qr([1 0 0
               0 1 0
               0 0 1])

[Q3, R3] = qr([1 2 3
               0 3 1
               0 0 8])

[Q4, R4] = qr([0 0 1
               0 1 0
               1 1 1])

[Q5, R5] = qr([0 0 0 0 1
               0 0 0 1 0
               0 0 1 0 0
    	       0 1 1 1 0
               1 0 0 0 1])
