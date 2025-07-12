#!/usr/bin/env sage

"""

Write a program or function that given n ≥ 1 returns the number of solutions to ±1 ± 2 ± 3 ± ... ± n = 0.

For n = 6 there are no solutions, so the answer is 0. For n = 4 there are two solutions, so the answer is 2 (the two solutions are 1 - 2 - 3 + 4 = -1 + 2 + 3 - 4 = 0).

This is OEIS sequence A063865. Some example input/outpus are:

n       a(n)
1       0
2       0
3       2
4       2
5       0
6       0
7       8
8       14
9       0
10      0
11      70
12      124
13      0
14      0
15      722
16      1314

Shortest code in bytes wins.

"""

# https://oeis.org/A063865
def zcs(n):
	r = 0**n
	if n < 1:
		return r

	p = 1
	for k in range(1, n+1):
		p *= 2**(n*k) + 2**(-n*k)
	p = floor(p) % 2**n
	return r + p

def main():
	tab = [1, 0, 0, 2, 2, 0, 0, 8, 14, 0, 0, 70, 124, 0, 0, 722, 1314, 0, 0, 8220, 15272, 0, 0, 99820, 187692, 0, 0, 1265204, 2399784, 0, 0, 16547220, 31592878, 0, 0, 221653776, 425363952, 0, 0, 3025553180, 5830034720, 0, 0, 41931984034, 81072032060, 0, 0]

	for i in range(len(tab)):
		assert(zcs(i) == tab[i])

main()
