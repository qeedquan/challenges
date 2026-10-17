#!/usr/bin/env python3

"""

Background
In some possible futures, the world will convert their numerical systems from decimal (base 10 or b10) to some other base (binary b2, octal b8, hexadecimal b16, or even unary b1, in which case we're screwed!). Thus, in preparation for this possible world-changing event, you decide to base-proof all of your programs. This can be done by using only singular 0s and 1s in conjunction with operators to replace the existing number constants.

However, there's just one problem: You have a ton of programs to change, and manually converting each number to an expression would take weeks! Thus, you decide to write a program (or function) to decide for you what expression should replace each number.

Input
The input will be a positive integer. Your code must be able to handle any integer up to 1000.

(If your code supports decimals and/or negative inputs, see Scoring below.)

Output
Your code must output an expression that evaluates to the input in at least one language. This may be any language; it does not have to be the same one your program or function is written in. Also, this expression does not need to be a full program or function.

For clarity, the output may contain any of these operations:

increment / decrement
add / sum
subtract / negate
multiply / double (only if it doesn't directly involve the number 2!)
divide / modulo
exponents / logarithms
square / sqrt (again, only if these don't directly involve the number 2!)
bitwise operations (bOR, bAND, bNOT, bXOR, bit-shifts)
setting / getting variables
stack manipulation
You may not use eval() or any similar functions in the output. You may also not use in the output any functions that perform an action(s) other than the ones mentioned above.

Oh, and one more thing: since we want the output to be valid in as many bases as possible, the only number constants it may contain are 0 and 1. Numbers such as 10 (ten) are disallowed, unless the language interprets it as a 1 and a 0. Using strings to contain numbers is not allowed either, as is using characters such as CJam's A-K (which represent 10-20).

Test-cases
(All outputs are in JavaScript, but may work in other languages.)

Input 1:

2
Possible output 1:

1+1
Input 2:

13
Possible output 2:

(a=1+1+1)*a+a+1
Input 3:

60
Possible output 3:

(b=(a=1+1+1+1)*a)*a-a
Input 4:

777
Possible output 4:

(c=(b=((a=1+1+1+1)*a-a+1)*a)*a+b)+c+c-a+1
Input 5:

1000
Possible output 5:

Math.pow((a=1+1+1)*a+1,a)
Scoring
The goal of this challenge is to shorten your code's output as much as possible. Your score will be calculated in this way:

Base score: The average byte-count of all outputs for integers 1 to 1000.

Decimal score: If your code supports at least 3 decimal places, this is the average byte-count of all outputs of the sequence of numbers starting at 0.001 and ending at 1000, increasing by 1.001 each time. 0.001, 1.002, 2.003...998.999, 1000.000 Then take 50% off of this score.

Negative score: If your code supports negative numbers and zero, this is the average byte-count of the outputs of all integers from -1000 to 0. Then take 10% off of this score.

(The easiest way to calculate these would likely be a loop with your program/function inside.)

Your final score is the average of whichever of the above formulas apply.

If the output is non-deterministic (i.e. somewhat random; multiple runs with the same input produces multiple unique outputs), then the score for each input is determined by the largest output over ten runs on my CPU.

Also, as you don't know how precious computer data will be in the future, the byte-count of your generator code must be less than 512 bytes.

Lowest score in two weeks (on Sep 30) will be declared the winner. Congratulations to your winner, @ThomasKwa!

"""

import numpy as np
import math

def decompose(n):
    if n == 0:
        return []
    if n < 0:
        return -decompose(-n)

    e = int(math.log(n, 2))
    if n >= 5/3 * 2**e:
        return np.append(2**(e + 1), -decompose(2**(e+1)-n))
    return np.append(2**e, decompose(n - 2**e))

r"""

@lirtosiast

Assumes that the hl register pair initially holds 0, and returns the result in hl.

Only these three instructions are used:

ASCII   Hex    Instruction
--------------------------
#       23     inc hl
)       29     add hl,hl
+       2B     dec hl
We use a small modification of the minimum-weight balanced binary representation BBR2. Since BBR2 minimizes the weight (number of nonzero digits), but we want to minimize the weight plus the number of bit shifts, we change a constant in the algorithm from 3/2 to 5/3.

Example output:

strR(486)
         '#)))))+)+))+)'

Or in assembly:

inc hl \ add hl,hl \ add hl,hl \ add hl,hl \ add hl,hl \ add hl,hl \ dec hl \ add hl,hl \ dec hl \ add hl,hl \ add hl,hl \ dec hl \ add hl,hl
More example programs:

-256  +))))))))
-255  +))))))))#
-254  +)))))))#)
-253  +)))))))#)#
-252  +))))))#))
-251  +))))))#))#
-250  +))))))#)#)
-249  +)))))#)))+
-248  +)))))#)))
-247  +)))))#)))#
-246  +)))))#))#)
-245  +)))))#))#)#
-244  +)))))#)#))
-243  +)))))#)#))#
-242  +))))#)))+)
-241  +))))#))))+

  -5  +))+
  -4  +))
  -3  +)+
  -2  +)
  -1  +
   0  
   1  #
   2  #)
   3  #)#
   4  #))
   5  #))#

Possible optimizations: OP rules that the inc h and dec h instructions, which directly change the upper byte of hl, are illegal, but sla h and the undocumented sl1 h (left bit shifts by 1 on h that shift in a 0 and 1 respectively) are permitted. sla h and sl1 h are two bytes each, but they can sometimes shorten the output.irtosiast

"""

def number(n):
    b = decompose(n)
    s = ""
    if n == 0:
        return s

    e = max(abs(b))
    while e:
        if e in b:
            s += "#"
        elif -e in b:
            s += "+"
        s += ")"
        e //= 2
    return s[:-1]

def verify(n):
    v = 0
    for c in number(n):
        if c == "#":
            v += 1
        elif c == "+":
            v -= 1
        else:
            v *= 2
    return v == n

def main():
    for i in range(-10000, 10000):
        assert(verify(i))

main()
