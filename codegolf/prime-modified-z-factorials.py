#!/usr/bin/env python3

"""

Let me explain one by one the above terms...

We will call Z-Factorial(n) of a positive integer n, n! (i.e. n factorial) without any trailing zeros. So, Z-Factorial(30) is 26525285981219105863630848 because 30!=265252859812191058636308480000000

We will call Modified Z-Factorial of n, the Z-Factorial(n) mod n.So, Modified Z-Factorial of 30, is Z-Factorial(30)mod30 which is 26525285981219105863630848 mod 30=18

We are interested in those n
's for which the Modified Z-Factorial of n is a Prime Number

Example

The number 545 is PMZ because Z-Factorial(545) mod 545=109 which is prime

Here is a list of the first values of n that produce Prime Modified Z-Factorial (PMZ)

5,15,35,85,545,755,815,1135,1165,1355,1535,1585,1745,1895,1985,2005,2195,2495,2525,2545,2615,2705,2825,2855,3035,3085,3155,3205,3265,3545,3595,3695,3985,4135,4315,4385,4415,4685,4705,4985,5105,5465,5965,6085,6155,6185,6385,6415,6595...         
Task

The above list goes on and your task is to find the k
th PMZ

Input

A positive integer k

Output

The kth PMZ

Test Cases

Here are some 1-indexed test cases.
Please state which indexing system you use in your answer to avoid confusion.
Your solutions need only work within the bounds of your language's native integer size.

input -> output     
 1        5     
 10       1355       
 21       2615     
 42       5465     
 55       7265      
 100      15935
 500      84815

This is code-golf, so the lowest score in bytes wins.

"""

from sympy import isprime

"""

@Manish Kundu

Explanation: Keep dividing by 10 as long as the current factorial is divisible by 10, and then check the factorial modulo current number for primality.

"""

def pmzf(n):
    if n < 1:
        return 0

    r = 0
    x = 2
    m = 2
    while r < n:
        m += 1
        x *= m
        while x%10 == 0:
            x //= 10

        if isprime(x%m):
            r += 1
    return m

def main():
    tab = [5, 15, 35, 85, 545, 755, 815, 1135, 1165, 1355, 1535, 1585, 1745, 1895, 1985, 2005, 2195, 2495, 2525, 2545, 2615, 2705, 2825, 2855, 3035, 3085, 3155, 3205, 3265, 3545, 3595, 3695, 3985, 4135, 4315, 4385, 4415, 4685, 4705, 4985, 5105, 5465, 5965, 6085, 6155, 6185, 6385, 6415, 6595]

    for i in range(len(tab)):
        assert(pmzf(i + 1) == tab[i])

    assert(pmzf(42) == 5465)
    assert(pmzf(55) == 7265)
    assert(pmzf(100) == 15935)
    assert(pmzf(500) == 84815)

main()
