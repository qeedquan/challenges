#!/usr/bin/env sage

"""

Background
From Wikipedia: An Egyptian fraction is the sum of distinct unit fractions. That is, each fraction in the expression has a numerator equal to 1 and a denominator that is a positive integer, and all the denominators differ from each other. The value of an expression of this type is a positive rational number a/b. Every positive rational number can be represented by an Egyptian fraction.

Task
Write a function that given n, outputs the longest sequence of Egyptian fractions (that sum up to 1) where n is the largest denominator.

Rules
If no solution exists, you may output anything or nothing except any real number
If there are two or more solutions, output any one of them
Assume n is not two and is a natural number
Your output must be in descending order
You must not output duplicates
Each individual fraction must be separated by a plus symbol (+). Spaces are optional. However the plus symbol should not come after the last fraction.
Your code does not need to practically handle very high n, but it must work in theory for all n for which a solution exists
You may use any standard I/O method
Standard loopholes are forbidden

Examples
6 ⟶ 1/2 + 1/3 + 1/6

15 ⟶ 1/3 + 1/4 + 1/6 + 1/10 + 1/12 + 1/15

20:

1/4 + 1/5 + 1/6 + 1/9 + 1/10 + 1/15 + 1/18 + 1/20
or

1/3 + 1/5 + 1/9 + 1/10 + 1/12 + 1/15 + 1/18 + 1/20
2016:

1/15 + 1/22 + 1/24 + 1/25 + 1/30 + 1/32 + 1/33 + 1/39 + 1/40 + 1/42 + 1/44 + 1/45 + 1/48 + 1/55 + 1/56 + 1/60 + 1/63 + 1/64 + 1/65 + 1/66 + 1/70 + 1/72 + 1/78 + 1/80 + 1/84 + 1/85 + 1/88 + 1/90 + 1/91 + 1/96 + 1/99 + 1/104 + 1/110 + 1/112 + 1/119 + 1/120 + 1/130 + 1/132 + 1/135 + 1/136 + 1/150 + 1/154 + 1/156 + 1/160 + 1/165 + 1/168 + 1/170 + 1/171 + 1/175 + 1/180 + 1/182 + 1/184 + 1/189 + 1/190 + 1/195 + 1/198 + 1/200 + 1/208 + 1/210 + 1/220 + 1/225 + 1/230 + 1/238 + 1/240 + 1/260 + 1/270 + 1/272 + 1/275 + 1/288 + 1/299 + 1/300 + 1/306 + 1/320 + 1/324 + 1/325 + 1/330 + 1/340 + 1/345 + 1/368 + 1/400 + 1/405 + 1/434 + 1/459 + 1/465 + 1/468 + 1/476 + 1/480 + 1/495 + 1/496 + 1/527 + 1/575 + 1/583 + 1/672 + 1/765 + 1/784 + 1/795 + 1/810 + 1/840 + 1/875 + 1/888 + 1/900 + 1/918 + 1/920 + 1/975 + 1/980 + 1/990 + 1/1000 + 1/1012 + 1/1050 + 1/1088 + 1/1092 + 1/1100 + 1/1104 + 1/1113 + 1/1125 + 1/1196 + 1/1200 + 1/1224 + 1/1258 + 1/1309 + 1/1330 + 1/1386 + 1/1395 + 1/1425 + 1/1440 + 1/1470 + 1/1480 + 1/1484 + 1/1488 + 1/1512 + 1/1620 + 1/1650 + 1/1680 + 1/1728 + 1/1729 + 1/1800 + 1/1824 + 1/1836 + 1/1840 + 1/1848 + 1/1850 + 1/1870 + 1/1890 + 1/1950 + 1/1980 + 1/1995 + 1/2000 + 1/2016
or

...
Criteria

For first place: shortest code in bits wins

For second place: fastest code wins.

So if a code is the shortest and fastest, the second fastest code will be given 2nd place

P.S: The background definition and some rules are taken from this and this question respectively.

"""

def decompose(n):
	r = []
	for i in range(1<<n):
		x = []
		v = 0
		for j in range(n):
			if i&(1<<j) != 0:
				v += 1 / (j + 1)
				x.append(j + 1)
		
		if v == 1 and len(x) > len(r):
			r = x
	return r

def main():
	assert(decompose(6) == [2, 3, 6])
	assert(decompose(15) == [3, 4, 6, 10, 12, 15])
	assert(decompose(20) == [4, 5, 6, 9, 10, 15, 18, 20])

main()
