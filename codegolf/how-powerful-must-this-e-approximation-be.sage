#!/usr/bin/env sage

"""

This challenge was inspired by this non-challenge about the natural logarithm base e and the following pandigital approximation to e appearing on a Math Magic page:

| (1 + 9^(-4^(7*6)))**(3**(2**85)) - e | ~ 2.01*10^-18457734525360901453873570

It is fairly well-known that e = lim n->oo (1+1/n)^n
It is less well-known that the limit expression is strictly monotonically increasing over the positive real numbers.
These facts together imply that for every nonnegative integer d there is a least positive integer n=f(d) such that the first d decimal places of (1+1/n)n agree with those of e. f(d) is OEIS A105053.

For example, (1+1/73)73=2.69989… and (1+1/74)74=2.70013…, so f(1)=74.

Task
Given a nonnegative integer d, output n=f(d) as described above. Your code must theoretically be able to give the correct answer for any value of d.

This is code-golf; fewest bytes wins.

Test cases
The corresponding digits of e are given for reference.

    d, n
(2. 0, 1
(7) 1, 74
(1) 2, 164
(8) 3, 4822
(2) 4, 16609
(8) 5, 743325
(1) 6, 1640565
(8) 7, 47757783
(2) 8, 160673087
(8) 9, 2960799523
(4) 10, 23018638268
(5) 11, 150260425527
(9) 12, 30045984061852
(0) 13, 30045984061852
(4) 14, 259607904633050
(5) 15, 5774724907212535

"""

# https://oeis.org/A105053
def f(n):
	if n < 0:
		return 0
	
	p = max(n**2 + 100, 1)
	R = RealField(p)
	s = str(R(e))

	k = 1
	n += 2
	while True:
		x = (1 + 1/k)**k
		t = str(R(x))
		if s[:n] == t[:n]:
			return k
		k += 1
	return -1

def main():
	tab = [1, 74, 164, 4822, 16609, 743325, 1640565, 47757783, 160673087, 2960799523, 23018638268, 150260425527, 30045984061852, 30045984061852, 259607904633050, 5774724907212535]
	for i in range(5):
		assert(f(i) == tab[i])

main()
