#!/usr/bin/env python3

"""

Inspired by this CMC
https://chat.stackexchange.com/transcript/message/39979766#39979766

Given a positive integer greater than 0, perform the following operation on it:

If all ten single digits (1234567890) are in the number at least once, output the count and exit the program
Otherwise, double the number and repeat, incrementing the count.
The count starts at 0 and is the number of times the input was doubled. For example, if the input were 617283945, it would need to be doubled once because 1234567890 has all 10 digits in it.

This is a code-golf so shortest code wins. Input may be taken as a string, if you want.

Test cases
input => output

617283945 => 1
2 => 67
66833 => 44
1234567890 => 0
100 => 51
42 => 55

"""

def all_digits(n):
    m = 0
    while True:
        m |= 1 << (n % 10)
        n //= 10
        if n == 0:
            break
    return m == 0x3ff

def pandigital_doubling(n):
    if n < 1:
        return 0
    
    c = 0
    while not all_digits(n):
        n *= 2
        c += 1
    return c

def main():
    assert(pandigital_doubling(617283945) == 1)
    assert(pandigital_doubling(2) == 67)
    assert(pandigital_doubling(66833) == 44)
    assert(pandigital_doubling(1234567890) == 0)
    assert(pandigital_doubling(100) == 51)
    assert(pandigital_doubling(42) == 55)

main()
