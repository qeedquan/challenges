#!/usr/bin/env python3

"""

I found this task here.

https://www.spoj.com/problems/FIBOSUM

Given the ith (1<=i<=35) Fibonacci number F(i) calculate the sum of the ith till i+9th number F(i)+F(i+1)+...+F(i+9) and the last digit of the i+246th one F(i+246)

I have been trying to solve this using python and some tricks(Binnet's formula and a tricky recurrence):

 f=lambda n:((1+5**.5)**n-(1-5**.5)**n)/(2**n*5**.5)
 exec"n=input();print int(55*f(n)+88*f(n+1)+f(n+6)%10);"*input()
but I didn't yet managed to squeeze thought the give source code limit which is 111 and mine is 115,any hints how to improve my solution?

I am a rather newbie to python so any sort of help resulting in a successful solution will be much appreciated.

Thanks,

PS:After posting the same question in stackoverflow I thought that this should be more appropriate here as this site is precisely for Puzzles and Codegolf.

"""

def fib(n):
    a, b = 0, 1
    for i in range(n):
        a, b = b, a+b
    return a

"""

@Timwi

This makes use of my observation that

the sum of F(i) to F(i+9) is equal to F(i+11) − F(i+1) — proof:

   F(i) + F(i+1) + F(i+2) + F(i+3) + F(i+4) + F(i+5) + F(i+6) + F(i+7) + F(i+8) + F(i+9)
=      F(i+2)    +     F(i+4)      +     F(i+6)      +     F(i+8)      +    F(i+10)
=      F(i+2)    - F(i+3) + F(i+5) +     F(i+6)      +     F(i+8)      +    F(i+10)
=           -F(i+1)       +      F(i+7)              +     F(i+8)      +    F(i+10)
=           -F(i+1)       +              F(i+9)                        +    F(i+10)
=           -F(i+1)       +                           F(i+11)
F(i+246) mod 10 is equal to (F(i+11) − F(i+1)) mod 10 (discovered by experimentation; no idea how to prove this)

"""

def solve(n):
    x = fib(n + 11) - fib(n + 1) 
    return x + (x % 10)

def main():
    for i in range(1, 36):
        print(i, solve(i))

main()
