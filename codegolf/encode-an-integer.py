#!/usr/bin/env python3

"""

Given positive integer n > 2. We convert it to an array as follows:

If it is equal to 2 return an empty array
Otherwise create array of all n's prime factors sorted ascending, then each element replace with its index in prime numbers sequence and finally convert each element to array
For example, lets convert number 46 to array. Firstly, convert it to array of its prime factors:

[2, 23]
Number 23 is 9th prime, so replace 2 with empty array and 23 with [9]. Array now becomes:

[[], [9]]
Prime factors of 9 are 3 and 3, so:

[[], [3, 3]]
Do the same for both 3:

[[], [[2], [2]]]
And finally:

[[], [[[]], [[]]]]
Now, to encode it, we simply replace each open bracket with 1 and each closing bracket with 0, then remove all ending zeros and drop one 1 from the end. This is our binary number. Using the above example:

[ ] [ [ [ ] ] [ [ ] ] ]

| | | | | | | | | | | |
| | | | | | | | | | | |
V V V V V V V V V V V V

1 0 1 1 1 0 0 1 1 0 0 0
Now simply drop the last three zeros and the last 1. The number becomes 10111001 which is 185 in decimal. That is the expected output. Notice that in array to binary conversion brackets of the main array are not included.

Input
Positive integer n greater than 2.

Output
Encoded integer n.

Rules and IO format
Standard rules apply.
Input can be string or number (but in case of string it must be in base 10).
Output can be string or number (but in case of string it must be in base 10).
This is code-golf, the shortest answer in bytes wins!
Test cases
More test cases upon request.

3 ---> 1
4 ---> 2
5 ---> 3
6 ---> 5
7 ---> 6
8 ---> 10
9 ---> 25
10 ---> 11
10000 ---> 179189987
10001 ---> 944359
10002 ---> 183722
10003 ---> 216499
10004 ---> 2863321
10005 ---> 27030299
10006 ---> 93754
10007 ---> 223005
10008 ---> 1402478

"""

from sympy import isprime

def prime_factor_indices(n):
    prime_count = 0
    divisor = 1
    while n > 1:
        divisor += 1
        prime_count += int(isprime(divisor))
        while n % divisor == 0:
            yield prime_count
            n //= divisor

def bits(n):
    inner = "".join(bits(index) for index in prime_factor_indices(n))
    return f"1{inner}0"

def encode(n):
    return int(bits(n).rstrip("0")[1:-1], 2)

def main():
    assert(encode(3) == 1)
    assert(encode(4) == 2)
    assert(encode(5) == 3)
    assert(encode(6) == 5)
    assert(encode(7) == 6)
    assert(encode(8) == 10)
    assert(encode(9) == 25)
    assert(encode(10) == 11)
    assert(encode(10000) == 179189987)
    assert(encode(10001) == 944359)
    assert(encode(10002) == 183722)
    assert(encode(10003) == 216499)
    assert(encode(10004) == 2863321)
    assert(encode(10005) == 27030299)
    assert(encode(10006) == 93754)
    assert(encode(10007) == 223005)
    assert(encode(10008) == 1402478)

main()
