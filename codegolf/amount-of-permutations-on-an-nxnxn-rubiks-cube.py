#!/usr/bin/env python3

"""

Introduction:
A 3x3x3 Rubik's Cube has 43,252,003,274,489,856,000 possible permutations, which is approximately 43 quintillion.
You may have heard about this number before, but how is it actually calculated?

A 3x3x3 Rubik's Cube has six sides, each with nine stickers.
Looking at the (external) pieces instead of stickers however, we have six center pieces; eight corners pieces; and twelve edge pieces.
Since the centers can't be moved, we can ignore those in the calculations. As for the corners and edges:

There are 8! (40,320) ways to arrange the eight corners.
Each corner has three possible orientations, although only seven (of the eight) can be oriented independently; the orientation of the eighth/final corner depends on the preceding seven, given 3^7 (2,187) possibilities.
There are 12!/2 (239,500,800) ways to arrange the twelve edges.
The halve from 12! is because edges must always be in an even permutation exactly when the corners are.
Eleven edges can be flipped independently, with the flip of the twelfth/final edge depending on the preceding eleven, given 2^11 (2,048) possibilities.
Putting this together, we have the following formula:

8!×3^7×12!/2×2^11=43,252,003,274,489,856,000

Source: Wikipedia - Rubik's Cube Permutations

Although this may already look pretty complex, it's still rather straight-forward for a 3x3x3 Cube. For even cubes the formula is slightly different; this is the formula for a 4x4x4 Cube for example:

8!×3^7×24!^2/24^7=7,401,196,841,564,901,869,874,093,974,498,574,336,000,000,000

Which is approximately 7.40 quattuordecillion on the short scale.

And for larger NxNxN Cubes (i.e. the current World Record 33x33x33) the formula will be extended quite a bit.
To not make this introduction too long however, I put these links here instead, where the permutations of the 4x4x4 Cube and some other sized NxNxN Cubes are explained with a resulting formula:

2x2x2
4x4x4
5x5x5
6x6x6
7x7x7
33x33x33
You may be wondering by now: is there a general formula based on N for any NxNxN Cube? There certainly is. Here are three completely different algorithms, all giving the exact same results based on N:

1: Chris Hardwick's Formula:

((24*2^10*12!)^Mod[n, 2] 7!3^6 24!^Floor[(n^2 - 2 n)/4])/4!^(6 Floor[(n - 2)^2/4])

2: Christopher Mowla's trig Formula:

8!*3^7*((24!)/(4!)^6)^(1/4*((n-1)*(n-3)+cos^2((n*pi)/2)))*(24!)^(1/2*(n-2-sin^2((n*pi)/2)))*(12!*2^10)^(sin^2((n*pi)/2))*1/24^(cos^2((n*pi)/2))

3: Christopher Mowla's primes Formula:

2^((2n(n+7)-17-11(-1)^n)/2)3^(n(n+1)+2)5^((2n(n-2)+1+(-1)^n)/2)7^((6n(n-2)+3+5(-1)^n)/8)11^((2n(n-2)-1+(-1)^n)/4)96577^((2n(n-2)-3+3(-1)^n)/8)

where 96577 is (13×17×19×23).

Source: Cubers-reddit - Mathematical Counting Formulas of Number of Positions, God's Number, etc.
https://www.reddit.com/r/Cubers/comments/43xzov/mathematical_counting_formulas_for_number_of/

Challenge:
Choose and implement one of these three formulas (or your own derivative), which given an input-integer N in the range [2,100], outputs the correct result.

Challenge rules:
You are free to use another formula besides these three, but keep in mind that these three are proven to be correct.
If you use another formula, please add a link of where you got it from (or if you come up with it yourself add an in-depth explanation).
And I will check for all integers in the range if the output is correct. Perhaps inspiration could be found in the oeis for this sequence: A075152.
If your language automatically outputs a scientific output (i.e. 1.401...×10^45 instead of the number after the 4x4x4 formula) this is allowed.
But please add additional code to your answer to convert this scientific rounding to an exact output so the results can be verified,
since rounding errors due to floating point precision during the execution of the formula in your code is not allowed - the actual result should be exact.
Your program/function should be correct for at least the inputs in the range [2,100] (although, since N=100 already results in a huge-ass number, any larger N will probably work as well if you're able to output this one correctly).
You are not allowed to loop over all possible permutations with a counter, since that would never output anything in a reasonable amount of time.
Only the implementation of a formula (either one of the three provided, a derivative of one of those, or a completely new formula), or another method that will give the correct results in a reasonable amount of time (without hard-coding of course) is allowed.
I thought about adding a restricted-time to enforce this, but I'm personally against restricted-time in combination with code-golf, so I won't.
Still, please make sure your program gives the answers, and if it's too slow for TIO for some reason, add some screenshots with the output from your local machine as verification.

General rules:
This is code-golf, so shortest answer in bytes wins.
Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.
Standard rules apply for your answer with default I/O rules, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters and return-type, full programs. Your call.
Default Loopholes are forbidden.
If possible, please add a link with a test for your code (i.e. TIO).
Also, adding an explanation for your answer is highly recommended.
Test cases:
Here the test cases for N in the range [2,10] (feel free to use the WolframAlpha links above for larger test cases):

n=2
3674160

n=3
43252003274489856000

n=4
7401196841564901869874093974498574336000000000

n=5
282870942277741856536180333107150328293127731985672134721536000000000000000

n=6
157152858401024063281013959519483771508510790313968742344694684829502629887168573442107637760000000000000000000000000

n=7
19500551183731307835329126754019748794904992692043434567152132912323232706135469180065278712755853360682328551719137311299993600000000000000000000000000000000000

n=8
35173780923109452777509592367006557398539936328978098352427605879843998663990903628634874024098344287402504043608416113016679717941937308041012307368528117622006727311360000000000000000000000000000000000000000000000000

n=9
14170392390542612915246393916889970752732946384514830589276833655387444667609821068034079045039617216635075219765012566330942990302517903971787699783519265329288048603083134861573075573092224082416866010882486829056000000000000000000000000000000000000000000000000000000000000000

n=10
82983598512782362708769381780036344745129162094677382883567691311764021348095163778336143207042993152056079271030423741110902768732457008486832096777758106509177169197894747758859723340177608764906985646389382047319811227549112086753524742719830990076805422479380054016000000000000000000000000000000000000000000000000000000000000000000000000000000000
NOTE: Since this is a code-golf challenge, it basically boils down to: implement one of these three formulas (or a derivative / your own method that still produces the correct results) as short as possible.

"""

from math import *

def perm(n):
    a = (24 * 2**10 * factorial(12)) ** (n%2)
    b = factorial(7) * 3**6
    c = factorial(24)**((n**2 - 2*n)//4)
    d = factorial(4)**(6 * ((n-2)**2//4))
    return a*b*c // d

def main():
    assert(perm(2) == 3674160)
    assert(perm(3) == 43252003274489856000)
    assert(perm(4) == 7401196841564901869874093974498574336000000000)
    assert(perm(5) == 282870942277741856536180333107150328293127731985672134721536000000000000000)
    assert(perm(6) == 157152858401024063281013959519483771508510790313968742344694684829502629887168573442107637760000000000000000000000000)
    assert(perm(7) == 19500551183731307835329126754019748794904992692043434567152132912323232706135469180065278712755853360682328551719137311299993600000000000000000000000000000000000)
    assert(perm(8) == 35173780923109452777509592367006557398539936328978098352427605879843998663990903628634874024098344287402504043608416113016679717941937308041012307368528117622006727311360000000000000000000000000000000000000000000000000)
    assert(perm(9) == 14170392390542612915246393916889970752732946384514830589276833655387444667609821068034079045039617216635075219765012566330942990302517903971787699783519265329288048603083134861573075573092224082416866010882486829056000000000000000000000000000000000000000000000000000000000000000)
    assert(perm(10) == 82983598512782362708769381780036344745129162094677382883567691311764021348095163778336143207042993152056079271030423741110902768732457008486832096777758106509177169197894747758859723340177608764906985646389382047319811227549112086753524742719830990076805422479380054016000000000000000000000000000000000000000000000000000000000000000000000000000000000)

main()
