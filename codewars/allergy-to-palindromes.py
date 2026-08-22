#!/usr/bin/env python3

"""

A friend of mine told me privately: "I don't like palindromes". "why not?" - I replied.
"Because when I want to do some programming challenges, I encounter 2 or 3 ones first related with palindromes. I'm fed up" - he confess me with anger.
I said to myself:"Thankfully, that doesn't happen in Codewars". Talking seriously, we have to count the palindrome integers.
Doing that, perhaps, it will help us to make all the flood of palindrome programming challenges more understandable.

For example all the integers of 1 digit (not including 0) are palindromes, 9 cases.
We have nine of them with two digits, so the total amount of palidromes below 100 (102) is 18.
At least, will we be able to calculate the amount of them for a certain number of digits?
Let's say for 2000 digits? Prepare a code that given the number of digits n,
may output the amount of palindromes of length equals to n and the total amount of palindromes below 10n.

You will see more examples in the box. Happy coding!!

(You don't know what palindromes are? Investigate, :))

"""

def count_pal(n):
    exact = 9 * 10**((n - 1) // 2)
    p = (n + 1) // 2
    q = n // 2
    total = 10**p + 10**q - 2
    return [exact, total]

def main():
    assert(count_pal(1) == [9, 9])
    assert(count_pal(2) == [9, 18])
    assert(count_pal(5) == [900, 1098])
    assert(count_pal(10) == [90000, 199998])
    assert(count_pal(70) == [90000000000000000000000000000000000, 199999999999999999999999999999999998])

main()

