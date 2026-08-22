#!/usr/bin/env pwsh

<#

Description

The binomial coefficient C(n, k) has been extensively studied for its importance in combinatorics. Binomial coefficients can be recursively defined as follows:

C(n, 0) = C(n, n) = 1 for all n > 0;
C(n, k) = C(n − 1, k − 1) + C(n − 1, k) for all 0 < k < n.

Given n and k, you are to determine the parity of C(n, k).

Input

The input contains multiple test cases. Each test case consists of a pair of integers n and k (0 ≤ k ≤ n < 2^31, n > 0) on a separate line.

End of file (EOF) indicates the end of input.

Output

For each test case, output one line containing either a “0” or a “1”, which is the remainder of C(n, k) divided by two.

Sample Input

1 1
1 0
2 1

Sample Output

1
1
0

Source

PKU Local 2007 (POJ Monthly--2007.04.28), Ikki

#>

function binomial($n, $k) {
	if ($n -lt 1) {
		return 0
	}
	if ($k -eq 0 -or $k -eq $n) {
		return 1
	}
	return (binomial ($n - 1) ($k - 1)) + (binomial ($n - 1) ($k))
}

function parity($n) {
	return $n % 2
}

parity (binomial 1 1)
parity (binomial 1 0)
parity (binomial 2 1)
