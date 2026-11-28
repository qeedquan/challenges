#!/usr/bin/env python3

"""

The first 9 prime numbers are : 2, 3, 5, 7, 11, 13, 17, 19, 23. Consider a sequence of 9 consecutive positive integers. This will be called a Special Sequence if we can associate each of these 9 prime numbers with a different integer in the sequence, such that each of the integers is divisible by the prime number associated with it. The sequence of numbers from 525 to 533 is a Special Sequence. This is illustrated in the table below.

525 7   525/7  = 75
526 2   526/2  = 263
527 17  527/17 = 31
528 11  528/11 = 48
529 23  529/23 = 23
530 5   530/5  = 106
531 3   531/3  = 177
532 19  532/19 = 28
533 13  533/13 = 41
Notice that each of the 9 integers in the sequence 525 to 533 is associated with one of the 9 prime numbers in the sequence 2 to 23 and that each of these prime numbers has been used exactly once.

Since each Special Sequence consists of 9 consecutive integers, we need only know the first number of the sequence. We will call this a Special Sequence Number, or SS Number. So the SS Number for the sequence above is 525.

A simple search shows that there are quite a large number of SS Numbers. In this problem you will be given several number ranges and are asked to find the number of SS Numbers which lie in the given range. Note that an SS Number can lie in the given range even though some of the numbers in the corresponding Special Sequence may lie outside of the range. For example, if the very last number of a given range is an SS Number we include this number in the range, even though 8 numbers of the Special Sequence lie outside of the range. Using the example above, the range 525 to 525 (a single integer) contains 1 SS Number.

Input/Output description: The first line of the input data will contain a single integer N, the number of ranges to process. N lines will follow. Each line contains two numbers n1 and n2, separated by a space. Find the number of SS Numbers in the range from n1 to n2 inclusive. Combine all answers into a single string, separated by spaces.

Example:

input:
5
525 525
2544 4799
32628 61978
60280 859346
4188113 7327194 

answer:
1 7 52 1196 4739

"""

def is_ss_number(x):
    primes = [2, 3, 5, 7, 11, 13, 17, 19, 23]
    
    # Build an adjacency list mapping each offset (0-8) 
    # to the primes that can divide it
    adj = []
    for i in range(9):
        val = x + i
        adj.append([p for p in primes if val % p == 0])
    
    # Backtracking to find a perfect matching
    used_primes = set()
    def match(idx):
        if idx == 9:
            return True
        for p in adj[idx]:
            if p not in used_primes:
                used_primes.add(p)
                if match(idx + 1):
                    return True
                used_primes.remove(p)
        return False
        
    return match(0)

def solve(n1, n2):
    count = 0
    for x in range(n1, n2 + 1):
        if is_ss_number(x):
            count += 1
    return count

def main():
    assert(solve(525, 525) == 1)
    assert(solve(2544, 4799) == 7)
    assert(solve(32628, 61978) == 52)
    assert(solve(60280, 859346) == 1196)
    assert(solve(4188113, 7327194) == 4739)

main()
