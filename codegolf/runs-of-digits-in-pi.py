#!/usr/bin/env python3

"""

Your goal is to output the strictly increasing sequence of consecutive, identical digits of pi (π). Each term in the sequence must be one digit longer than the previous. So 3 (0th digit of pi) is the first time a run of digits occurs (length 1). The next to occur is 33 (digits 24 and 25 of pi). Of course, this sequence requires the digits of pi to be in base 10.

The ones known so far, and the first six all occur within the first 800 digits:

3
33
111
9999
99999
999999
3333333
44444444
777777777
6666666666
... (not in first 2 billion digits)
Note that the consecutive nines all occur together, in the same run, so if the next larger run you found happened to be 1000 consecutive 0s, this would fill in multiple terms of the sequence.

I have not found any more terms with my program. I know there are no more terms within the first 50000 digits or more. My program was taking too long with 500000 digits, so I gave up.

Reference Implementation

def p():
	q,r,t,j = 1,180,60,2
	while True:
		u,y = 3*(3*j+1)*(3*j+2),(q*(27*j-12)+5*r)//(5*t)
		yield y
		q,r,t,j = 10*q*j*(2*j-1),10*u*(q*(5*j-2)+r-y*t),t*u,j+1
p=p()

LIM = 5000

d=L = [p.next()]
#print 0,
print 3

n=1
while n<LIM:
	x = p.next()
	if d[-1]==x:
		d.append(x)
		if len(d)>len(L):
			#print n,
			print "".join(str(i)for i in d)
			L.append(long("".join(str(i)for i in d)))
	else:
		d=[x]
	n += 1

#print
#for i in L:print str(i),
#print

You may:

Output the sequence forever
Take an integer n and find the first n numbers in the sequence
Take an integer n and find the numbers in the sequence contained in the first n digits of pi.
Make sure to specify which one your code does. The number n may be zero or one indexed.

Inspired by this mathoverflow question.

https://mathoverflow.net/questions/23547/does-pi-contain-1000-consecutive-zeroes-in-base-10

"""

import sys

# ported from @primo solution
def solve(n):
    r = []
    x = p = (7 * n) | 1
    while p > 1:
        x = p//2 * x//p + 2*(10**n)
        p -= 2
    
    l = m = 0
    for c in str(x):
        if p == c:
            l += 1
        else:
            l = 1

        p = c
        if l > m:
            m = l
            r.append(int(p * l))

    return r

def main():
    n = 10000
    if len(sys.argv) >= 2:
        n = int(sys.argv[1])
    sys.set_int_max_str_digits(n)

    print(solve(n))

main()
