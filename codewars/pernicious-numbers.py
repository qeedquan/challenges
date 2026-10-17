#!/usr/bin/env python3

"""

A pernicious number ( https://en.wikipedia.org/wiki/Pernicious_number ) is a positive integer whose binary digit sum (or Hamming weight ( https://en.wikipedia.org/wiki/Hamming_weight )) is a prime number.

25 = 11001  -->  digit sum = 3 --> 3 is prime --> therefore 25 is a pernicious number

75 = 1001011  -->  digit sum = 4 --> 4 is not prime --> therefore 75 is not a pernicious number

#Task

Your job is to create a function that will list all of the pernicious numbers up to the given value (inclusive). The values given will increase in size, meaning the list will be very large.

For example:

pernicious(5) should return [3, 5]

pernicious(12) should return [3, 5, 6, 7, 9, 10, 11, 12]

If there are no pernicious numbers in the given range, your function should return "No pernicious numbers". This means when given a negative value, it should still recieve this output.

pernicious(0) should return "No pernicious numbers"

pernicious(-1) should return "No pernicious numbers"

Also, if given a floating point number, return the list of pernicious numbers with the number floored (rounded down).

pernicious(17.546456) should return [3, 5, 6, 7, 9, 10, 11, 12, 13, 14, 17]

You will only be given integers and floats.

Remember:

1 is not a prime number and 2 is a prime number.

"""

from sympy import isprime

# https://oeis.org/A052294
def pernicious(n):
    return isprime(n.bit_count())

def gen(n):
    r = []
    for i in range(2, int(n + 1)):
        if pernicious(i):
            r.append(i)
    if len(r) == 0:
        return "No pernicious numbers"
    return r

def main():
    tab = [
        3, 5, 6, 7, 9, 10, 11, 12, 13, 14, 17, 18, 19, 20, 21, 22, 24, 25, 26,
        28, 31, 33, 34, 35, 36, 37, 38, 40, 41, 42, 44, 47, 48, 49, 50, 52, 55,
        56, 59, 61, 62, 65, 66, 67, 68, 69, 70, 72, 73, 74, 76, 79, 80, 81, 82,
        84, 87, 88, 91, 93, 94, 96, 97, 98, 100
    ]

    assert(gen(5) == [3, 5])
    assert(gen(12) == [3, 5, 6, 7, 9, 10, 11, 12])
    assert(gen(17.546456) == [3, 5, 6, 7, 9, 10, 11, 12, 13, 14, 17])
    assert(gen(0) == "No pernicious numbers")
    assert(gen(-1) == "No pernicious numbers")
    assert(gen(max(tab)) == tab)

main()
