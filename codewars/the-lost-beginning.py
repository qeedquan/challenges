#!/usr/bin/env python3

"""

Problem Statement
You're given a string of digits representing a sequence of consecutive natural numbers concatenated together. Your task is to find the smallest possible first number in the sequence. The sequence starts with a single or multi-digit number and continues with numbers each incremented by 1. If multiple sequences can be formed, choose the one that starts with the smallest number.

Examples
"123" -> [1, 2, 3] -> 1
"91011" -> [9, 10, 11] -> 9
"17181920" -> [17, 18, 19, 20] -> 17
"9899100" -> [98, 99, 100] -> 98
"91" -> [91] -> 91
"121122123" -> [121, 122, 123] -> 121
"1235" -> [1235] -> 1235
"101" -> [101] -> 101

Constraints
Input string length: 1 - 200 characters.
Smallest possible first number: 1 - 1,000,000,000.

Remember, the key is to form a sequence of consecutive natural numbers. If the sequence matches the input string, you've found the smallest possible first number. Experiment with different lengths for the first number until you find a match or exhaust all possibilities.

"""

def beginning(x):
    for i in range(1, len(x) + 1):
        n = int(x[:i])
        s = str(n)
        while len(s) < len(x):
            n += 1 
            s += str(n)
        if s == x:
            return int(x[:i])
    return int(x)

def main():
    assert(beginning("123") == 1)
    assert(beginning("91011") == 9)
    assert(beginning("17181920") == 17)
    assert(beginning("9899100") == 98)
    assert(beginning("91") == 91)
    assert(beginning("121122123") == 121)
    assert(beginning("1235") == 1235)
    assert(beginning("101") == 101)

main()
