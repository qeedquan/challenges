%{

In the examples below, A and B will be 2-by-2 matrices, and the matrices are one-indexed.

A Kronecker product has the following properties:

A⊗B =  A(1,1)*B   A(1,2)*B
        A(2,1)*B   A(2,2)*B

     =  A(1,1)*B(1,1)   A(1,1)*B(1,2)   A(1,2)*B(1,1)   A(1,2)*B(1,2)
        A(1,1)*B(2,1)   A(1,1)*B(2,2)   A(1,2)*B(2,1)   A(1,2)*B(2,2)
        A(2,1)*B(1,1)   A(2,1)*B(1,2)   A(2,2)*B(1,1)   A(2,2)*B(1,2)
        A(2,2)*B(2,1)   A(2,2)*B(1,2)   A(2,2)*B(2,1)   A(2,2)*B(2,2)
A Kronecker sum has the following properties:

A⊕B = A⊗Ib + Ia⊗B
Ia and Ib are the identity matrices with the dimensions of A and B respectively. A and B are square matrices. Note that A and B can be of different sizes.

A⊕B =  A(1,1)+B(1,1)  B(1,2)         A(1,2)         0
        B(2,1)         A(1,1)+B(2,2)  0              A(1,2)
        A(2,1)         0              A(2,2)+B(1,1)  B(1,2)
        0              A(2,1)         B(2,1)         A(2,2)+B(2,2)
Given two square matrices, A and B, calculate the Kronecker sum of the two matrices.

The size of the matrices will be at least 2-by-2. The maximum size will be whatever your computer / language can handle by default, but minimum 5-by-5 input (5 MB output).
All input values will be non-negative integers
Builtin functions that calculate the Kronecker sum or Kronecker products are not allowed
In general: Standard rules regarding I/O format, program & functions, loopholes etc.
Test cases:

A =
     1     2
     3     4
B =
     5    10
     7     9

A⊕B =
     6    10     2     0
     7    10     0     2
     3     0     9    10
     0     3     7    13

----

A =
    28    83    96
     5    70     4
    10    32    44
B =
    39    19    65
    77    49    71
    80    45    76

A⊕B =
    67    19    65    83     0     0    96     0     0
    77    77    71     0    83     0     0    96     0
    80    45   104     0     0    83     0     0    96
     5     0     0   109    19    65     4     0     0
     0     5     0    77   119    71     0     4     0
     0     0     5    80    45   146     0     0     4
    10     0     0    32     0     0    83    19    65
     0    10     0     0    32     0    77    93    71
     0     0    10     0     0    32    80    45   120

----

A =
    76    57    54
    76     8    78
    39     6    94
B =
    59    92
    55    29

A⊕B =
   135    92    57     0    54     0
    55   105     0    57     0    54
    76     0    67    92    78     0
     0    76    55    37     0    78
    39     0     6     0   153    92
     0    39     0     6    55   123

%}

function r = kronsum(A, B)
	r = kron(A, eye(length(B))) + kron(eye(length(A)), B);
end

kronsum([1 2; 3 4], [5 10; 7 9])
kronsum([28 83 96; 5, 70, 4; 10 32 44], [39 19 65; 77 49 71; 80 45 76])
kronsum([76 57 54; 76, 8, 78; 39 6 94], [59 92; 55 29])
