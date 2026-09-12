%{

The fraction m/n is called regular irreducible if 0<m<n and gcd(m,n)=1. Find the number of regular irreducible fractions with the denominator n.

Input
Each line is a separate test case and contains one integer n (n<10^9). The last line contains 0 and is not processed. The number of test cases does not exceed 100.

Output
For each value of n, print in a separate line the number of regular irreducible fractions with the denominator n.

Examples

Input #1
12
123456
7654321
0

Answer #1
4
41088
7251444

%}

function t = eulerphi(n)
    if n <= 0 || n ~= floor(n)
        error('Input must be a positive integer.');
    end
    
    p = unique(factor(n));
    t = floor(n * prod(1 - 1./p));
end

format long

eulerphi(12)
eulerphi(123456)
eulerphi(7654321)

