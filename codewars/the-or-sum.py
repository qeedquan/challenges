#!/usr/bin/env python3

"""

Introduction
In a parallel universe not too distant from our own, Julius Caesar finds himself locked in a fierce conflict with Genghis Khan.

Legend has it that Khan's armies were renowned for their mastery of horseback archery, a formidable advantage in battle. To level the playing field, divine intervention granted Caesar a helping hand.

With divine assistance, Big Jul gained the ability to impart his knowledge to his troops, a boon bestowed upon all of his men. He could impart any skill he possessed to those who lacked it.

Skills, in this universe, are represented by the binary representation of an integer. Each bit corresponds to a specific skill, with 1 denoting proficiency and 0 representing ignorance.

Using his wisdom, Caesar could transform any 0 to a 1 if he himself possessed the corresponding skill.

Armed with the value n, representing his own skills, Caesar sets out to enhance the abilities of his troops, numbering from 1 to n. Time is of the essence as the threat of the approaching Asian cavalry looms ever closer.

Task
Given a positive integer n, return the sum of the Bitwise OR operation between n and all integers from 1 to n (both inclusive). In fancy math terms: 
Sum[i=1, n] n∣i, where | is the Bitwise OR operation.

Performance
Brute force solutions, yielding a time complexity of O(n), won't work.

The expected time complexity is O(logn). Most solutions with a time complexity equal or close to that should pass with ease.

Random Tests: 100
Integer Size: 1 to 10 ** 100
Examples
1 -> 1
2 -> 5
3 -> 9
4 -> 22
10 -> 121
100 -> 11302

"""

# https://oeis.org/A001196
def A001196(n):
    return 3*int(bin(n)[2:], 4)

# https://oeis.org/A350093
def A350093(n):
    return ((3*n + 2)*n + A001196(n)) // 4

def orsum(n):
    return A350093(n) - n

def main():
    assert(orsum(1) == 1)
    assert(orsum(2) == 5)
    assert(orsum(3) == 9)
    assert(orsum(4) == 22)
    assert(orsum(10) == 121)
    assert(orsum(100) == 11302)

main()
