#!/usr/bin/env python3

"""

Task
You're given an integer n (0 <= n <= 10000). You need to create a function which returns:

Fizz when n is divisible by 3
Buzz when n is divisible by 5
Fizz Buzz when n is divisible by both 3 and 5
Otherwise it should return the string representation of n

Restrictions
Your code mustn't contain:

if
== or !=
+ or -
str (including strip, lstrip, rstrip)
def
eval or exec
return
import
The check for restricted words is case-insensitive.

Note:
Feel free to rate the kata when you finish it :)

"""

def fizzbuzz(n):
    s = ['Fizz Buzz', 'Fizz', 'Buzz', f'{n}']
    a = ((n % 3 > 0) << 1)
    b = (n%5 > 0)
    return s[a | b]

def main():
    for i in range(1, 100):
        print(i, fizzbuzz(i))

main()
