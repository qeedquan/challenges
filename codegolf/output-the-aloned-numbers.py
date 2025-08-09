#!/usr/bin/env python3

"""

Consider the natural sequence up-to 6 (disregard 1):

2,3,4,5,6
We start scanning from the left (in this case from 2), search for a number divisible by 2 (here 4) and then remove both the numbers from the list (here 2 & 4), such that the list reduces to:

3,5,6
We continue the same process, here leftmost is 3, so we search for number divisible by 3. 6 is surely that number and thus 3 and 6 are removed,

5
Now, no further such searches can be made Thus, this becomes the list of ALONED numbers for n=6.

OBJECTIVE

Given a number n greater than 1, print all the corresponding aloned numbers.
INPUT
2
6
15
20
22

OUTPUT
2
5
8,9,11,12,13,15
11,12,13,15,17,19,20
12,13,15,17,19,20,21

YET ANOTHER WORKED OUT EXAMPLE

For n= 22

=>2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22
=>3,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22 (remove 2 & 4)
=>5,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22 (remove 3 & 6)
=>7,8,9,11,12,13,14,15,16,17,18,19,20,21,22 (remove 5 & 10)
=>8,9,11,12,13,15,16,17,18,19,20,21,22 (remove 7 & 14)
=>9,11,12,13,15,17,18,19,20,21,22 (remove 8 & 16)
=>11,12,13,15,17,19,20,21,22 (remove 9 & 18)
=>12,13,15,17,19,20,21 (remove 11 & 22) (OUTPUT)
This is code-golf, so the shortest code in bytes wins.

"""

"""

ported from @DLosc solution

Explanation
We construct the initial list from the input number and store it in L. Next, loop while the last number is greater than or equal to 2 times the first number and remove 2 times the first number from the list.
This will always be the next number divisible by L[0]. L=L[1:] takes off the first number as well. When the condition is no longer true, no further removals can be made, and the list is printed.

"""

def aloned(n):
    if n < 2:
        return []

    L = list(range(2, n + 1))
    while L[0]*2 <= L[-1]:
        L.remove(L[0]*2)
        L = L[1:]
    return L

def main():
    assert(aloned(2) == [2])
    assert(aloned(6) == [5])
    assert(aloned(15) == [8, 9, 11, 12, 13, 15])
    assert(aloned(20) == [11, 12, 13, 15, 17, 19, 20])
    assert(aloned(22) == [12, 13, 15, 17, 19, 20, 21])

main()
