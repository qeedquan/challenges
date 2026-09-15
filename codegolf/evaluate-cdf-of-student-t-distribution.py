#!/usr/bin/env python3

"""

The goal of this codegolf is evaluating the cumulative distribution function of the student-t probability distribution. This is not trivial since there is no closed form and the function is dependent of two variables v and x. The distribution function is

https://i.stack.imgur.com/fH0ld.png

For getting the CDF you could integrate this function from -inf to x. As you can see the evaluation of this function relies much on integration as you'd also have to evaluate nontrivial values of the gamma function.

Details
You can can write a program or function that accepts a two numbers xand v as input, where x is the position (must at least accept floats from -10 upto 10) at which the CDF is evaluated and v is the number of degrees of freedom. v is a positive integer (range 1 upto 1450) but it must be possible to set it to infinity (for v=inf the student-t distribution is equal to the normal distribution). But you can specify that e.g. v = -1 should denote infinity. The output consists must be a number between 0 and 1 and must have an accuracy of at least 4 decimal places. If your language does not support runtime inputs or arguments on program call you may assume that both arguments are stored in variables (or another 'memory unit')

Restrictions
You may not use special functions like the gamma function or probability distribution functions as well as numerical integration functions or libraries (as long as you do not include their source in your code which counts for the score) etc. The idea is using only basic math functions. I tried to make a list of what I consider as 'basic' but there might be others I forgot - if so please comment.

Explicitly allowed are

+ - / *
% (modulo)
! (factorial for integers only)
&& || xor != e.t.c. (logical operators)
<< >> ^ e.t.c. (bitshift and bitwise operators)
** pow (powerfunction for floats like a^b including sqrt or and other roots)
sin cos tan arcsin arccos arctan arctan2
ln lb log(a,b)
rand() (generating pseudorandom numbers of UNIFORM distribution)
Scoring
Lowest number of bytes wins.

Entry
Please explain how your code works. Please show the output of your program for at least 5 different arguments. Among those should be the following three. For your own values please also provide 'exact' values (like from wolframalpha or what ever you prefer).

x = 0      v= (any)  (should return 0.5000)
x = 3.078  v= 1      (should return 0.9000
x = 2.5    v= 23     (should return 0.9900)
If possible, it would be great if you could provide some fancy plots of the values calculated with your program (the code for plotting does not count for the score).

(from Wikipedia):

"""

from scipy.special import *
from scipy.integrate import *
from math import *

def t_pdf(x, v):
    s = gamma((v+1)/2) / (sqrt(v*pi)*gamma(v/2))
    a = (1 + x**2/v)**(-(v+1)/2)
    return s*a

def t_cdf(x, v):
    return quad(t_pdf, -inf, x, args=(v))[0]

def test(x, v, r):
    p = t_cdf(x, v)
    print(p)
    assert(abs(p-r) < 1e-3)

def main():
    test(0, 1, 0.5)
    test(3.078, 1, 0.9)
    test(2.5, 23, 0.99)

main()
