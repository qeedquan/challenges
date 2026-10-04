{-

Given array a of length n. Find the sum of its elements.

Implement the function:

long long solve(int n, vector <int> arr); // C++

function solve(const n :integer; const arr: array of integer) : integer; // Pascal

public static int solve(int n, int []arr); // Java

def solve(n, arr); // Python

static long solve(long n, long [] arr); // C#

n - size of array;

a - array of integers;

function must return one integer - the sum of all array elements.

Input
First line contains number of elements n (1≤n≤10^5) in array.

Second line contains n integers a1, a2, ..., an (1≤ai≤10^6) - the array elements.

Output
One integer will be printed - the sum of array elements.

Examples

Input #1
5
2 3 8 1 3

Answer #1
17

Input #2
1
7

Answer #2
7

Scoring
(5 points) n≤1;
(15 points) n≤100, ai≤100;
(30 points) n≤10^4, ai≤10^4;
(50 points) without additional restrictions.

-}

import Data.Bits

solve :: [Int] -> Int
solve list = sum list

