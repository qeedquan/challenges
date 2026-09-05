#!/usr/bin/env sage

"""

Level-index is a system of representing numbers which has been proposed as an alternative to floating-point formats. It claims to virtually eliminate overflow (and underflow, in its symmetric form) from the vast majority of computations.

The usual floating-point format internally represents a number x in terms of a mantissa m∈[1,2) and an integer exponent e, where x=m×2^e.
In contrast, level-index represents a number by an integer level l≥0 and an index i∈[0,1), defined by
l+i=ψ(x)={x,1+ψ(logx),x<1otherwise.

Equivalently, l and i together represent the power tower number x=ψ−1(l+i)=expl(i). Accordingly, ψ−1 grows very fast; ψ−1(5) has more than a million digits to the left of the decimal point.

Task
Given two numbers ψ(a),ψ(b), compute their level-index sum ψ(a+b). You may choose to input or output the level and index together or separately.

Your solution should be accurate to at least six digits after the decimal point and terminate in a reasonable time for all ψ(a+b)<8, and may not assume your floating-point representation has infinite precision.

Test cases
ψ(a)    ψ(b)    ψ(a+b)              a           b           a+b
0       0       0.0000000000000000  0           0           0
1       1       1.6931471805599453  1           1           2
2       2       2.5265890341390445  2.718281828 2.718281828 5.436563657
3       3       3.2046791426805201  1.5154262e1 1.5154262e1 3.0385245e1
4       4       4.0161875057657443  3.8142791e6 3.8142791e6 7.6285582e6
5       5       5.0000000044114734  2.3e1656520 2.3e1656520 4.7e1656520
1.70879 2.44303 2.6490358380192970  2.031531618 4.746554831 6.778086449
0.8001  3.12692 3.1367187876590184  0.8001      2.2470167e1 2.3270267e1
2.71828 3.14159 3.2134989633416356  7.774915755 2.368508064 3.1459996e1
4.6322  4.6322  4.6322790036002559  1.79455e308 1.79455e308 3.58910e308
4.80382 4.80382 4.8038229252940133  5.9037e4932 5.9037e4932 1.1807e4933

"""

def lilog(x):
	if x > 1:
		return 1 + lilog(log(x))
	return x

def liexp(x):
	if x > 1:
		return exp(liexp(x - 1))
	return x

# https://en.wikipedia.org/wiki/Symmetric_level-index_arithmetic
# ported from @Noodle9 solution
def liadd(x, y):
	e = lilog(liexp(x) + liexp(y))
	v = e.n()
	return v

def test(x, y, r):
	v = liadd(x, y)
	print(v)
	assert(abs(v - r) < 1e-12)

def main():
	test(0, 0, 0.0000000000000000)
	test(1, 1, 1.6931471805599453)
	test(2, 2, 2.5265890341390445)
	test(3, 3, 3.2046791426805201)
	test(4, 4, 4.0161875057657443)
	test(5, 5, 5.0000000044114734)
	test(1.70879, 2.44303, 2.6490358380192970)
	test(0.8001, 3.12692, 3.1367187876590184)
	test(2.71828, 3.14159, 3.2134989633416356)
	test(4.6322, 4.6322, 4.6322790036002559)
	test(4.80382, 4.80382, 4.8038229252940133)

main()
