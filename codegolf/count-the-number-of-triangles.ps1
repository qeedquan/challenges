#!/usr/bin/env pwsh

<#

Given a list of positive integers, find the number of triangles we can form such that their side lengths are represented by three distinct entries of the input list.

(Inspiration comes from CR.)

Details
A triangle can be formed if all permutations of the three side lengths a,b,c satisfy the strict triangle inequality a+b>c.
(This means a+b>c, a+c>b and b+c>a must all hold.)
The three side lengths a,b,c must appear at distinct positions in the list, but do not necessarily have to be pairwise distinct.
The order of the three numbers in the input list does not matter. If we consider a list a and the three numbers a[i], a[j], a[k] (where i,j,k are pairwise different), then (a[i],a[j],a[k]), (a[i],a[k],a[j]), (a[j], a[i], a[k]) etc. all are considered as the same triangle.
The input list can assumed to contain at least 3 entries.
You can assume that the input list is sorted in ascending order.
Examples
A small test program can be found here on Try it online!

Input, Output:
[1,2,3]  0
[1,1,1]  1
[1,1,1,1] 4
[1,2,3,4] 1
[3,4,5,7] 3
[1,42,69,666,1000000] 0
[12,23,34,45,56,67,78,89] 34
[1,2,3,4,5,6,7,8,9,10] 50
For the input of [1,2,3,...,n-1,n] this is A002623.

For the input of [1,1,...,1] (length n) this is A000292.

For the input of the first n Fibonacci numbers (A000045) this is A000004.

#>

function count($a) {
	$n = $a.Count
	$c = 0
	for ($i = 0; $i -lt $n; $i += 1) {
		for ($j = $i + 1; $j -lt $n; $j += 1) {
			for ($k = $j + 1; $k -lt $n; $k += 1) {
				if ($a[$i] + $a[$j] -gt $a[$k]) {
					$c += 1
				}
			}
		}
	}
	return $c
}

function main() {
	count(@(1, 2, 3))
	count(@(1, 1, 1))
	count(@(1, 1, 1, 1))
	count(@(1, 2, 3, 4))
	count(@(3, 4, 5, 7))
	count(@(1, 42, 69, 666, 1000000))
	count(@(12, 23, 34, 45, 56, 67, 78, 89))
	count(@(1, 2, 3, 4, 5, 6, 7, 8, 9, 10))
}

main
