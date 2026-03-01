#!/usr/bin/env python3

"""

In pancake sorting the only allowed operation is to reverse the elements of some prefix of the sequence. Or, think of a stack of pancakes: We insert a spatula somewhere in the stack and flip all the pancakes above the spatula.

For example, the sequence 6 5 4 1 2 3 can be sorted by first flipping the first 6 elements (the whole sequence), yielding the intermediate result 3 2 1 4 5 6, and then flipping the first 3 elements, arriving at 1 2 3 4 5 6.

As there is only one operation, the whole sorting process can be described by a sequence of integers, where each integer is the number of elements/pancakes to include pr flip. For the example above, the sorting sequence would be 6 3.

Another example: 4 2 3 1 can be sorted with 4 2 3 2. Here's the intermediate results:

         4 2 3 1
flip 4:  1 3 2 4
flip 2:  3 1 2 4
flip 3:  2 1 3 4
flip 2:  1 2 3 4
The task:
Write a program which takes a list of integers and prints a valid pancake sorting sequence.

The list to sort can either be a space separated list from stdin, or command line arguments. Print the list however it is convenient, as long as it's somewhat readable.

This is codegolf!

Edit:
As I said in the comments, you don't need to optimize the output (finding the shortest sequence is NP-hard). However, I just realized that a cheap solution would be to throw out random numbers until you get the desired result (a [new?] type of bogosort). None of the answers so far have done this, so I now declare that your algorithm should not rely on any (pseudo-)randomness.

While you're all kicking yourselves, here's a bogopancakesort variant in Ruby 2.0 (60 characters), to rub it in:

a=$*.map &:to_i
a=a[0,p(v=rand(a.size)+1)].reverse+a[v..-1]while a!=a.sort

"""

"""

ported from @Keith Randall solution

Flip the biggest pancake to the top, then flip the whole stack. Remove the biggest pancake from the bottom and repeat.
i is the index of the biggest pancake. L=L[:i:-1]+L[:i] flips i+1 pancakes, flips len(L) pancakes, then drops the last pancake.

"""

def pancake(x):
    r = []
    while len(x) > 0:
        m = max(x)
        i = x.index(m)
        r.append(i + 1)
        x = x[:i:-1] + x[:i]
    return r

def main():
    print(pancake([6, 5, 4, 1, 2, 3]))
    print(pancake([4, 2, 3, 1]))
    print(pancake([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]))

main()
