#!/usr/bin/env python3

"""

The digital root (also repeated digital sum) of a positive integer is the (single digit) value obtained by an iterative process of summing digits, on each iteration using the result from the previous iteration to compute a digit sum. The process continues until a single-digit number is reached.

For example, the digital root of 65536 is 7, because 6 + 5 + 5 + 3 + 6 = 25 and 2 + 5 = 7.

Sorting all digital roots doesn't make much sense, since it would just start with infinitely many 1s.

Instead, we'll create lists of all the single digits integers along with their digital roots, then all double digit numbers along with their digital roots, then the triple, quadruple and so on.

Now, for each of those lists, we'll sort it so that all the integers with digital roots of 1 appear first, then all integers with digital roots of 2 and so on. The sorting will be stable, so that the list of integers with a certain digital roots should be in ascending order after the sorting.

Finally we'll concatenate these lists into one single sequence. This sequence will start with all single digit numbers, then all double digit numbers (sorted by their digital root), then all triple digit numbers and so on.

Challenge:
Take a positive integer n as input, and output the n'th number in the sequence described above. You may choose if the list is 0-indexed of 1-indexed.

The sequence goes like this:

1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 19, 28, 37, 46, 55, 64, 73, 82, 91, 11, 20, 29 ...
72, 81, 90, 99, 100, 109, 118, ...
981, 990, 999, 1000, 1009, 1018, 1027, ...
Test cases:
The test cases are 1-indexed.

   n   f(n)
   9      9
  10     10
  11     19
  40     13
  41     22
  42     31
  43     40
  44     49
  45     58
 600    105
 601    114
 602    123
 603    132
 604    141
 605    150
4050   1453
4051   1462
4052   1471
4053   1480
4054   1489
4055   1498
Easier to copy:

n =    9, 10, 11, 40, 41, 42, 43, 44, 45, 600, 601, 602, 603, 604, 605, 4050, 4051, 4052, 4053, 4054, 4055,
f(n) = 9, 10, 19, 13, 22, 31, 40, 49, 58, 105, 114, 123, 132, 141, 150, 1453, 1462, 1471, 1480, 1489, 1498
Clarifications:
You may not output all n first elements. You shall only output the n'th.
The code must theoretically work for all integers up to 10^9, but it's OK if it times out on TIO (or other interpreters with time restrictions) for inputs larger than 999.
Explanations are encouraged.
It's code-golf, so the shortest code in each language wins! Don't be discouraged by other solutions in the language you want to golf in, even if they are shorter than what you can manage!

"""

"""

ported from @ovs solution

https://en.wikipedia.org/wiki/Digital_root#Significance_and_formula_of_the_digital_root
https://www.wolframalpha.com/input?i=sum+of+72*10**d-1+for+d+from+0+to+n
https://www.wolframalpha.com/input?i=simplify+r%2B%28n-1%29*9-%28n%2F10**%28k-1%29-1%29*%289*10**%28k-1%29-1%29-%28-k%2B2**%28k%2B4%29*5**%28k-1%29-9%29

"""
def seq(n):
    if n < 0:
        return 0
    b = 10**(len(str(n)) - 1)
    return b + n//b + 9*(n%b) - 1

def main():
    x = [9, 10, 11, 40, 41, 42, 43, 44, 45, 600, 601, 602, 603, 604, 605, 4050, 4051, 4052, 4053, 4054, 4055]
    y = [9, 10, 19, 13, 22, 31, 40, 49, 58, 105, 114, 123, 132, 141, 150, 1453, 1462, 1471, 1480, 1489, 1498]
    for i in range(len(x)):
        assert(seq(x[i]) == y[i])

main()
