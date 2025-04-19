#!/usr/bin/env sage

"""

Task
Here is an interesting math problem:

Let's say that there are n indistinguishable unlabeled objects in a bin. For every "round", pull k objects randomly out of the bin with equal probability, and apply a label on each object (Nothing happens to objects already having a label). Then put these k objects, now all labelled, back into the bin and repeat the process until all objects have a label applied to them. What is the expected number of rounds needed to label all the objects, given n and k?

Your task is to write a program that solves this exact math problem. Turns out, this is quite hard to calculate by hand and is better left for computers to bash out. I will list three methods of solving this problem below. You do not have to follow any of these three methods.

Methods
Method 1
I have asked this question on Math SE recently as I was also stumped on how to do this problem. One answer suggests the following formula:

\sum_{j=1}^n (-1)^{j+1} \binom{n}{j} \frac{1}{1-\binom{n-j}{k}/\binom{n}{k}}

from math import comb

def E(n,k):
 ans = 0
 for j in range(1,n+1):
  ans += (-1)**(j+1) * comb(n,j)/(1-comb(n-j,k)/comb(n,k))
 return ans

print(E(10,3))

I have implemented this formula in Python: Try it online!

Method 2
Another answer from the same question provides the following formula:

{\bf e_1}^T \left(I_n - \left({\mathcal{1}}_{j\geq i} {\frac{ {{n-i \choose j-i}} {i \choose k-j+i} }{n\choose k}} \right)_{i=0,j=0}^{n-1} \right)^{-1} {\bf 1}

where "In is the n×n identity matrix, e1 is the first standard basis vector of Rn and 1 is the n-vector of all ones. And in the definition of the other matrix 1 is the indicator function, i.e. the i,j-element is 0 if j<i and otherwise that quotient of binomials...," quoting from the linked answer.

I have implemented this formula in Mathematica: Try it online!

f[n_,k_] := N[Total[Inverse[Table[If[i==j, 1, 0]-If[j>=i, Binomial[n-i, j-i]*Binomial[i, k-j+i]/Binomial[n,k], 0], {i, 0, n-1}, {j, 0, n-1}]][[1]]]]
Print[f[10,3]]

Method 3
(This is very likely not the golfiest way for any language, but this is what I used to generate the larger test cases.)

Another way is to utilize the recursive nature of this problem, as the results of each round depends on the results of all the previous rounds. The recursive formula is as follows (E
 is the function that actually calculates the expected value):

\begin{align}E(n,k)&=f(n,k,n)\\f(n,k,u)&=\begin{cases}0&\text{if }u=0\\\frac{\displaystyle\binom nk+\sum_{i=1}^{\min(u,k)}{\binom ui\binom{n-u}{k-i}}f(n,k,u-i)}{\displaystyle\binom nk-\binom{n-u}k}&\text{otherwise}\end{cases}\end{align}

I have implemented this formula in Python: Try it online!

from math import comb

def E(n,k):
 l = [0]
 for u in range(1,n+1):
  l += [(comb(n,k) + sum(comb(u,i) * comb(n-u,k-i) * l[u-i] for i in range(1,min(u+1,k+1))))/(comb(n,k) - comb(n-u,k))]
 return l[-1]

print(E(10,3))

I/O format and other rules
Your program or function should take in two positive integer values n,k with n≥k and output the expected value corresponding to those values. The output can be a floating point value with an absolute/relative error under 10−6 from the true value, though the algorithm should theoretically work for arbitrarily large n and k. In practice, it is acceptable if the program is limited by time, memory, or data-type size. This means that although your program may output inaccurate floating point values for certain inputs (as long as the outputs are within the allowed error as mentioned earlier), it should still theoretically be calculating the exact value of the true output.

Because the expected value is always going to be a rational number, you can also output as an exact fraction (does not need to be simplified and can be improper), if your language supports such a data type, or if you want to output a pair of numbers, the numerator and the denominator. If in doubt, always refer back to the default I/O methods.

Your program should also be deterministic, meaning it should always produce the same value when ran. Namely, no "running a gazillion simulations to get the experimental expected value."

Test Cases
n,k -> output
1,1 -> 1
4,2 -> 3.8
6,2 -> 6.928571428571429
7,4 -> 3.7794117647058822
7,7 -> 1
8,1 -> 21.742857142857137
8,5 -> 3.458181818181818
10,3 -> 9.046212999306306
12,7 -> 4.212148576244657
20,2 -> 35.304734857894836
100,7 -> 72.28020367501058
1000,69 -> 105.24478042247509
1256,5 -> 1934.8934423952992

This is code-golf, so the shortest program in bytes wins!

"""

def rounds(n, k):
	r = 0
	for j in range(1, n+1):
		r += (-1)**(j+1) * binomial(n, j)/(1 - binomial(n-j, k)/binomial(n, k))
	return r

def test(n, k, r):
	eps = 1e-11
	v = rounds(n, k)
	assert(abs(v-r) < eps)

def main():
	test(1, 1, 1)
	test(4, 2, 3.8)
	test(6, 2, 6.928571428571429)
	test(7, 4, 3.7794117647058822)
	test(7, 7, 1)
	test(8, 1, 21.742857142857137)
	test(8, 5, 3.458181818181818)
	test(10, 3, 9.046212999306306)
	test(12, 7, 4.212148576244657)
	test(20, 2, 35.304734857894836)
	test(100, 7, 72.28020367501058)
	test(1000, 69, 105.24478042247509)
	test(1256, 5, 1934.8934423952992)

main()
