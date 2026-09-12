%{

The characteristic polynomial of a square matrix A is defined as the polynomial pA(x)=det(Ix−A) where I is the identity matrix and det the determinant.
Note that this definition always gives us a monic polynomial such that the solution is unique.

Your task for this challenge is to compute the coefficients of the characteristic polynomial for an integer valued matrix, for this you may use built-ins but it is discouraged.

Rules
input is an N×N (N≥1) integer matrix in any convenient format your program/function will output/return the coefficients in either increasing or decreasing order (please specify which) the coefficients are normed such that the coefficient of xN is 1 (see test cases) you don't need to handle invalid inputs

Testcases
Coefficients are given in decreasing order (ie. xN,xN−1,...,x2,x,1):

[0] -> [1 0]
[1] -> [1 -1]
[1 1; 0 1] -> [1 -2 1]
[80 80; 57 71] -> [1 -151 1120] 
[1 2 0; 2 -3 5; 0 1 1] -> [1 1 -14 12]
[4 2 1 3; 4 -3 9 0; -1 1 0 3; 20 -4 5 20] -> [1 -21 -83 559 -1987]
[0 5 0 12 -3 -6; 6 3 7 16 4 2; 4 0 5 1 13 -2; 12 10 12 -2 1 -6; 16 13 12 -4 7 10; 6 17 0 3 3 -1] -> [1 -12 -484 3249 -7065 -836601 -44200]
[1 0 0 1 0 0 0; 1 1 0 0 1 0 1; 1 1 0 1 1 0 0; 1 1 0 1 1 0 0; 1 1 0 1 1 1 1; 1 1 1 0 1 1 1; 0 1 0 0 0 0 1] -> [1 -6 10 -6 3 -2 0 0]

%}

function r = charpoly(x)
	r = poly(eig(x));
end

charpoly([0])
charpoly([1])
charpoly([1 1; 0 1])
charpoly([80 80; 57 71])
charpoly([1 2 0; 2 -3 5; 0 1 1])
charpoly([4 2 1 3; 4 -3 9 0; -1 1 0 3; 20 -4 5 20])
charpoly([0 5 0 12 -3 -6; 6 3 7 16 4 2; 4 0 5 1 13 -2; 12 10 12 -2 1 -6; 16 13 12 -4 7 10; 6 17 0 3 3 -1])
charpoly([1 0 0 1 0 0 0; 1 1 0 0 1 0 1; 1 1 0 1 1 0 0; 1 1 0 1 1 0 0; 1 1 0 1 1 1 1; 1 1 1 0 1 1 1; 0 1 0 0 0 0 1])
