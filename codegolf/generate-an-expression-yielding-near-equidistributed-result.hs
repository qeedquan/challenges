{-

Create a program (any language) which, given positive integer m, outputs a valid C expression that:

Uses a single variable x assumed of 32-bit unsigned type (i.e. uint32_t)
Would evaluate to range [0, m) for any of the 2³² possible x, reaching any of the m possible outcomes either 2³² / m or 2³² / m + 1 times (where / rounds down).
Is limited to use of
variable x as operand
constants from 0 to 2³²-1, in decimal (42) or hexadecimal (0x2a)
operators among (listed by groups of decreasing priority in C)
+ -  restricted to addition or subtraction of two operands
<< >>  restricted to right argument constant in range [0, 31]
&  restricted to bitwise and
^  bitwise xor
|  bitwise or
parenthesis for  (expression)
sequence idiom  (x=expression1),expression2  which evaluates expression1, assigns it to x, then evaluates to expression2. The sequence idiom can only be used to form the overall expression or expression2 in a sequence. , and = do not account as operator.
It is assumed all arithmetic is such that all quantities are truncated to 32-bit, and that right shift >> introduce zeroes.

When given input m, the first output of the program must be an expression valid for m, aiming at a minimal operator count. Further output, if any, should be expressions for incremental m.

Example outputs (believed optimum) for first few inputs m:

output                     m  count  alternative output
0                          1    0    (0)
x&1                        2    1    x>>31
(x-(x>>1)+(x>>2))>>30      3    5    (x=x-(x>>2)),(x=x-(x>>31)),x>>30
x&3                        4    1    x>>30
Following comment, this is a code challenge. Ranking criteria:

Producing conforming expressions with minimum operator count up to the highest m. Expressions posted or linked in other answers are used to assess minimum, after verification.
Minimal expression depth up to the highest m. Depth is 0 for x or constant. The result of an operator has the maximum depth of the two operands when they differ or in a sequence, or 1 more otherwise. Expressions in the example output have depth 1, except for 0. The expression x+1&x+2^x+3&x+4 has depth 3, and any shorter expression has lower depth.
Programs that convincingly produce minimal output (as defined above) are preferred.
Programs which can be evaluated at compile time by a C/C++ compiler for constant m, so that use of R(x,m) generates the same object code as the expression for m does, are preferred. Nice-to-have: not requiring C++, not requiring inline.
Motivation: starting from x uniformly random, we want to restrict it to [0, m) with a distribution comparable to the expression x%m, in a way that is fast and constant-time. Count and depth match instruction and register count on LEG Brain M0, an imaginary 32-bit CPU.

Modifying the following C program changing E and M, then compiling and running it on a compiler with 32-bit int, exhaustively checks an expression against requirement 2, assuming that it is a well-formed C expression that matches requirements 1 and 3. Try it online!

// Verify an expression for requirement 2

// expression under test
#define E (x=x-(x>>2)),(x=x-(x>>31)),x>>30
#define M 3                     // value of m matching that expression

#define T uint32_t              // type for x (change at your own risk!)
#define N 32                    // number of bits in type T
#define C (T)                   // cast to type T; use in E only!

#include <stdint.h>
typedef T t;                    // type for x
#include <inttypes.h>
#if N==32
    #define pPRIuTN "%"PRIu32
    #define pPRIxTN "%08"PRIx32 
#elif N==16
    #define pPRIuTN "%"PRIu16
    #define pPRIxTN "%04"PRIx16 
#elif N==8
    #define pPRIuTN "%"PRIu8
    #define pPRIxTN "%02"PRIx8  
#endif
#include <stdio.h>
#include <string.h>

#define m ((t)M)     // m per our type
#define R(z) #z      // stringizer
#define S(z) R(z)

t c[m];              // counter array (initialized to 0)

int main(void) {
    t fail = sizeof(t)*8!=N || (t)(-1)<0 || ((t)(-1)>>(N-1))!=1,
        lo, hi, xlo, xhi, v, x, y = 0;
    if (fail) 
        printf("### fail, please check T: "S(T)" versus N: "S(N)"\n");
    else
        {
    // laboriously show the expression tested, without extra parenthesis
        #define LEN (sizeof(S((E)))-3)  // length of the expression
        char exp[LEN+1];                // the expression, NUL-terminated
        memcpy(exp,S((E))+1,LEN);
        exp[LEN]=0;
        printf("Testing expression %s for m="pPRIuTN"\n",exp,m);
    // compute counts
        do {
            x = y;
            x = (E);
            if (x<m)
                ++c[x];
            else if (!fail) {
                fail = 1;
                printf("### fail, value "pPRIuTN" at input x="pPRIuTN"=0x"pPRIxTN" should be less than m="pPRIuTN"\n",x,y,y,m);
            }
        } while(++y);
    // find minimum and maximum count, and where it occurs
        hi = xlo = xhi = 0;
        lo = (t)-1;
        v = m;
        do {
            y = c[--v];
            if (y>hi)
                hi = y, xhi = v;
            else if (y<lo)
                lo = y, xlo = v;
        } while(v);
    // show results
        if (hi==0 && m>1) // can occur if there was overflow or other error
            fail=1, printf("### fail, only the value "pPRIuTN" occurs\n",x);
        else {
            x = (t)(-m)/m+1;   // lower limit
            y = (t)(-1)/m+1;   // upper limit
            if (lo<x)
                fail=1, printf("### fail, value "pPRIuTN" occurs "pPRIuTN" times, minimum "pPRIuTN"\n",xlo,lo,x);
            if (hi>y)
                fail=1, printf("### fail, value "pPRIuTN" occurs "pPRIuTN" times, maximum "pPRIuTN"\n",xhi,hi,y);
            if (!fail)
                printf("### pass!\n");
            }
        }
    return fail;
}

-}

{-

Ported from @Anders Kaseorg solution

How it works:

The expression being computed is equivalent to floor((m*x + m - c(m)) / 2^32), where c(m) satisfies

0 < c(m) <= m. The specific choice of c(m) made for golfing reasons is

c(2^(i+2)*k + 2^i)           = 1   (k >= 0, i >= 0)
c(2^i - 2^j)                 = 1   (i > j >= 0)
c(2^(h+1) + 2^h + 2^i - 2^j) = 2^h (k >= 0, h > i > j + 1 >= 1)

The equivalence can be shown by repeated use of the identity

-floor(k / 2^i) = floor((2^i - 1 - k) / 2^i)

-}

import Data.Bits

bitLen :: Int -> Int
bitLen n = finiteBitSize n - countLeadingZeros n

expr' :: Maybe Int -> Int -> String
expr' sh m =
  case sh of
    Nothing
      | m == 1 -> "0"
      | n == 0 -> "x" ++ s
      | o == 0 -> "x-(x-(x>>1)>>" ++ show (i - j - 1) ++ ")" ++ s
      | otherwise ->
        "x-(x-(" ++ expr' (Just j) o ++ ")>>" ++ show (i - j) ++ ")" ++ s
      where s
              | i == 32 = ""
              | otherwise = ">>" ++ show (32 - i)
    Just h
      | n == 0 -> "x>>" ++ show (h - i)
      | o == 0 -> "(x-(x>>" ++ show (i - j) ++ ")>>" ++ show (h - i) ++ ")-1"
      | otherwise ->
        "x-(x-(" ++
        expr' (Just j) o ++ ")>>" ++ show (i - j) ++ ")>>" ++ show (h - i)
  where
    i = bitLen (m - 1)
    n = bit i - m
    j = bitLen (n - 1)
    o = bit j - n

expr :: Int -> String
expr = expr' Nothing

main :: IO ()
main = mapM_ (\m -> putStrLn (show m ++ "\t" ++ expr m)) [1 .. 256]
