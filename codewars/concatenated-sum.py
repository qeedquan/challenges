#!/usr/bin/env python3

"""

The number 198 has the property that 198 = 11 + 99 + 88, i.e., if each of its digits is concatenated twice and then summed, the result will be the original number. It turns out that 198 is the only number with this property. However, the property can be generalized so that each digit is concatenated n times and then summed.

Examples
original number =2997 , n=3
2997 = 222+999+999+777 and here each digit is concatenated three times.

original number=-2997 , n=3

-2997 = -222-999-999-777 and here each digit is concatenated three times.

Task
Write a function named checkConcatenatedSum that tests if a number has this generalized property.

"""

def digits(n):
    r = []
    n = abs(n)
    while True:
        r.append(n % 10)
        n //= 10
        if n == 0:
            break
    return r

def check_concatenated_sum(x, n):
    if n < 1:
        return False

    s = 1
    if x < 0:
        s = -s

    y = 0
    for d in digits(x):
        y += int(str(d) * n) * s
    return x == y

def main():
    assert(check_concatenated_sum(2997, 3) == True)
    assert(check_concatenated_sum(-2997, 3) == True)
    assert(check_concatenated_sum(-198, 2) == True)
    assert(check_concatenated_sum(-13332, 4) == True)
    assert(check_concatenated_sum(-9, 1) == True)
    assert(check_concatenated_sum(198, 0) == False)
    assert(check_concatenated_sum(123, 2) == False)
    assert(check_concatenated_sum(123456789, 2) == False)

main()

