#!/usr/bin/env python3

"""

Given any 3 finite integers

a :: abs(a) < 50
b :: abs(b) < 50
n :: 0 <= n < 25
Please calculate the product of these 2 powers :

a^fib(n) * b^(fib(n) + lucas(n))
without ever knowing fib(n) or lucas(n), and also

without using direct exponentiation of any form, such as pow(), a^n, a**n, exp(), etc. ditto with operator overloading. a and b may very well be the same number..

Side by side calculations, e.g. fib(n) and a^fib(n), are perfectly fine as long as they stay synchronized at all times. This also means if fib(n) + lucas(n) and b^(fib(n) + lucas(n)) are handled separately, no information exchange can occur between the groups, since that would constitute knowing.

Sample output for a := -2, b := -2, n := 1 to 8

 1  -8
 2  -32
 3  256
 4  -8192

 5  -2097152
 6  17179869184
 7  -36028797018963968
 8  -618970019642690137449562112
Sample output of right-most decimal digits for a := 7, b := 11, n := 1 to 16

 1  847: 7 11^2
 2  102487: 7 11^4
 3  86806489: 7^2 11^6
 4  8896536638143: 7^3 11^10

 5  772277109817057309927: 7^5 11^16
 6  6870591602286635461815115800745561: 7^8 11^26
 7  0625347267715958812555514343738446309611646484047: 7^13 11^42
 8  5415884068323020968678265965672868526406892565367: 7^21 11^68

 9  374057906060693541425634693464192116589670200249: 7^34 11^110
10  292965800868558585984558225977930045788212176383: 7^55 11^178
11  858872623946726105253357385638809519463718519367: 7^89 11^288
12  10187224191574690257351172579654671365405509561: 7^144 11^466

13  47237747425025009003978861343126278171082167887: 7^233 11^754
14  6834417877982234290951844379460868549785667607: 7^377 11^1220
15  4684129562671531494891098516346549407151536409: 7^610 11^1974
16  0529456812207146045490477674360516837832403263: 7^987 11^3194
Standard loopholes apply. This is cold-golf, so shortest code-size wins, calculated by min(ceil(bytes_per_chr), 1) on a per-character basis.

For locales and codepages, including custom designs, that already have non-negative integral sizes for its characters, such as UTF-8, ASCII, Latin-1 etc this makes no difference whatsoever. A 3-byte UTF-8 code point is still 3 bytes, not 9.

Only languages that allocate fractional bytes will be impacted. e.g. 6 characters, each previously allocated 0.275 bytes per character, 1.650 bytes in total. The new figure is not 2 bytes, but 6 bytes total.

One exception will be made to honor fractionally allocated bytes - all extra portions of code used to compress/decompress/encode/decode them will be added to the total size.

Good luck everyone.

ps : It sounds really complicated but the algo is shockingly simplistic.

==================

You literally need nothing other than a linear decrement of n back to zero, and a bunch of nonstop b *= a *= b. The output answer doesn't even require a * b, just pick the correct one based on odd/even-ness of n. Here's what the loop unrolled at 8x speed looks like.

This is identical to the most basic algorithm for fib(n) - by having them keep += into each other, only to replace them with *= instead. And yes, you'll actually SLOW yourself down by attempting to first calculate fib(n) and/or lucas(n), then to pow(a, fib_n) * pow(b, fib_n + lucas_n), because += has same speed as *=. At no time has the code bothered to even emulate fib(n) via alternative approaches, because it's a waste of time.

gawk -Mbe '{
                a = +$1
           b *= b = +$2
    while (_++ < 2) {

        _8_ = b *= _7_ = a *= _6_ = b *= _5_ = a *= \
        _4_ = b *= _3_ = a *= _2_ = b *= _1_ = a *= b

        print _1_, _2_, _3_, _4_,
              _5_, _6_, _7_, _8_
    }
}' <<< '7 11' | gfactor -h | rev | gcut -c 1-61 | rev

     1  847: 7 11^2
     2  102487: 7 11^4
     3  86806489: 7^2 11^6
     4  8896536638143: 7^3 11^10

     5  772277109817057309927: 7^5 11^16
     6  6870591602286635461815115800745561: 7^8 11^26
     7  0625347267715958812555514343738446309611646484047: 7^13 11^42
     8  5415884068323020968678265965672868526406892565367: 7^21 11^68

     9  374057906060693541425634693464192116589670200249: 7^34 11^110
    10  292965800868558585984558225977930045788212176383: 7^55 11^178
    11  858872623946726105253357385638809519463718519367: 7^89 11^288
    12  10187224191574690257351172579654671365405509561: 7^144 11^466

    13  47237747425025009003978861343126278171082167887: 7^233 11^754
    14  6834417877982234290951844379460868549785667607: 7^377 11^1220
    15  4684129562671531494891098516346549407151536409: 7^610 11^1974
    16  0529456812207146045490477674360516837832403263: 7^987 11^3194

"""

from sympy import *

def f(a, b, n):
    return a**fibonacci(n) * b**(fibonacci(n) + lucas(n))

def main():
    for i in range(1, 9):
        print(i, f(-2, 2, i))

    print()

    for i in range(1, 17):
        print(i, f(7, 11, i))

main()
