#!/usr/bin/env python3

r"""

A ripoff of this challenge. Go upvote it!
https://codegolf.stackexchange.com/q/207404/89459

Objective
Given a rational number amongst [0,1], apply the Cantor function to it and output the rational number that's produced.

The Cantor function
The Cantor function is continuous everywhere and constant almost everywhere, but has an average slope of 1:

https://i.sstatic.net/cauCV.png

The Cantor function f(x) can be expressed as a limit f(x)=limn→∞ fn(x) of a sequence of functions f0,f1,f2,…, which are defined recursively as:

f[0](x) = x
f[n+1](x) = 0.5*f[n]*3*x            if x in [0, 1/3]
            0.5                     if x in [1/3, 2/3]
            0.5 + 0.5*f[n](3*x - 2) if x in [2/3, 1]

https://i.sstatic.net/JpLpm.gif

Your task is to compute f(x) for the rational x∈[0,1]∩Q given as input.

How?
Though this task might seem impossible, this is actually possible, for the Cantor function is computable.

A step-by-step solution for x∈R:

Ternary-expand x to 0.t1t2t3⋯.

Write "0.".

Set n=1.

If tn=1, write "1" and halt.

Otherwise, if tn=0, write "0", increment n, then continue doing step #4.

Otherwise (tn=2), write "1", increment n, then continue doing step #4.

Parse the resulting string as a binary expansion of a real number.
As x actually is in Q in this challenge, you should exploit the fact that the ternary expansion of x repeats.
It follows that the output is also in Q.

Examples
\begin{array}{r|c|c|c|c|c|c|c|c|c|c}
x & 0 & ½ & ⅓ & ¼ & ⅕ & ⅚ & 1 \\ \hline
\text{Ternary expansion of }x & 0.\overline{0} & 0.\overline{1} & 0.1\overline{0} & 0.\overline{02} & 0.\overline{0121} & 0.2\overline{1} & 0.\overline{2}  \\ \hline
\text{Binary expansion of } f(x) & 0.\overline{0} & 0.1 & 0.1 & 0.\overline{01} & 0.01 & 0.11 & 0.\overline{1} \\ \hline
f(x) & 0 & ½ & ½ & ⅓ & ¼ & ¾ & 1
\end{array}

Rules
Invalid inputs fall in don't care situation. In particular, you don't need to deal with numbers outside of [0,1].

Input and output must be exact rational numbers. If your language doesn't natively support rational number arithmetic, use a pair of integers.

"""

"""

Ported from @fireflame241 solution

Takes and returns pairs of integers (numerator, denominator). The input pair must be relatively prime.

How it works
The program separately identifies the repeating and non-repeating portions of the ternary representation of a/b, then splits into 2 cases:

If there is a 1 in either portion, then the numerator is (converted from binary with 2→1) the concatenation of the two portions up to the 1,
and the denominator is 2 to the power of the length of that section

If there is no 1, then the number retains the repeating portion, so in base 2 (after converting 2s to 1s),

a/b = 0.x1x2 ... xky1y2...yn = 0.xy

Then

a/b = 1/(2^k) * (x + 1/(2^n - 1)*y) = [(2^n - 1)*x + y] / [(2^n - 1)*(2^k)]

"""

# Most-significant ternary digit first
def base3(x, d):
    if not d:
        return []
    return base3(x//3, d-1) + [x%3]

# Largest exponent of a power of 3 that divides x
def v3(x):
    if x%3:
        return 0
    return 1 + v3(x//3)

# Base 3 representation of a/b as 0.xyz repeating, where b contains no factors of 3
def rep3(a, b, n=1):
    if (3**n-1)%b==0:
        return n, base3((3**n-1)*a//b, n)
    return rep3(a, b, n+1)

# Base 2 to int, including converting '2's to '1's
def from_base2(l):
    return eval('0b0' + ''.join(map(str, l)).replace('2','1'))

def cantor(a, b):
    # Extract the non-repeating portion of the ternary expansion of a/b
    v = v3(b)
    b //= 3**v
    non_repeating = base3(a//b,v)
    
    # Repeating portion
    n, repeating = rep3(a%b, b)
    digs = non_repeating + repeating
    if 1 in digs:
        # Take only the part up to/including the first 1, and use it as a binary decimal
        d = digs[:digs.index(1)+1]
        return from_base2(d), 2**(len(d))
    
    x = from_base2(non_repeating)
    y = from_base2(repeating)
    # `or a` accounts for the a=b=1 case, which gets treated otherwise as 0.0
    return y+x*(2**n-1) or a, 2**v*(2**n-1)

def main():
    assert(cantor(0, 1) == (0, 1))
    assert(cantor(1, 2) == (1, 2))
    assert(cantor(1, 3) == (1, 2))
    assert(cantor(1, 4) == (1, 3))
    assert(cantor(1, 5) == (1, 4))
    assert(cantor(5, 6) == (3, 4))
    assert(cantor(1, 1) == (1, 1))
    assert(cantor(1, 787) == (7, 512))
    assert(cantor(4, 39) == (3, 14))

main()

