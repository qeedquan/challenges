#!/usr/bin/env pwsh

<#

The Fibonacci numbers are defined as follows:

F(1)=1,
F(2)=1,
F(n)=F(n−1)+F(n−2),n≥3.

Compute the n-th Fibonacci number.

Input
The first line contains the number of test cases t (1≤t≤10^3).
Each of the next t lines contains one integer n (1≤n≤10^4).

Output
For each test case, print the corresponding Fibonacci number on a separate line.

Examples
Input #1
5
1
2
3
4
5

Answer #1
1
1
2
3
5

#>

function Fibonacci ([int] $n) {
    if ($n -le 0) {
        return 0
    }
    if ($n -le 1) {
        return $n
    }
    return (Fibonacci ($n - 1)) + (Fibonacci ($n - 2))
}

Fibonacci 1
Fibonacci 2
Fibonacci 3
Fibonacci 4
Fibonacci 5
