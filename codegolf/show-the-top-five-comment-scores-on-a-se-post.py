#!/usr/bin/env python3

"""

A Stack Exchange script determines which five comments on questions or answers are initially seen on the main page of sites through the number of upvotes on them; the five comments with the highest number of votes are displayed. Your task is to recreate this behavior.

Write a full program or function taking input through STDIN, command-line args, or function arguments and prints or returns the top five comment scores. Input will be an array of integers representing the number of upvotes on the comments of some post. For instance, an input of

0, 2, 5, 4, 0, 1, 0
means that the first comment has no votes, the second one has two votes, the third has five, the fourth had four, etc. The order of the comment scores should remain the same in the output.

If the input contains five or fewer comment scores, then the output should contain nothing more than the ones given. If two or more comment scores are the same, the first score(s) should be displayed. You may assume that the input array will contain at least one comment score.

The numbers in the output should be easily distinguished (so 02541 for case 1 is invalid). Otherwise there are no restrictions on output format; the numbers may be separated by a space or newline, or they may be in list format, etc.

Test cases:

[0, 2, 5, 4, 0, 1, 0] -> [0, 2, 5, 4, 1]
[2, 1, 1, 5, 3, 6] -> [2, 1, 5, 3, 6]
[0, 4, 5] -> [0, 4, 5]
[1, 1, 5, 1, 1, 5] -> [1, 1, 5, 1, 5]
[0, 2, 0, 0, 0, 0, 0, 0] -> [0, 2, 0, 0, 0]
[0, 0, 0, 0, 1, 0, 0, 0, 0] -> [0, 0, 0, 0, 1]
[5, 4, 2, 1, 0, 8, 7, 4, 6, 1, 0, 7] -> [5, 8, 7, 6, 7]
[6, 3, 2, 0, 69, 22, 0, 37, 0, 2, 1, 0, 0, 0, 5, 0, 1, 2, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 2] -> [6, 69, 22, 37, 5]
The last example was taken from this Stack Overflow question.

If possible, please provide a link in your post where your submission can be run online.

This is code golf, so the shortest code in bytes wins. Good luck!

"""

"""

@Dennis

How it works
list.remove removes the first occurrence if its argument from the specified list.
By reversing the list x, we essentially achieve that it removes the last occurrence instead.

Thus, it suffices to keep removing the comment with the minimal amount of upvotes until a list of no more than five comments is reached.
Afterwards, we reverse the list once more to restore the original order.

"""

def order(x):
    x = x[::-1]
    while len(x[5:]) > 0:
        x.remove(min(x))
    return x[::-1]

def main():
    assert(order([0, 2, 5, 4, 0, 1, 0]) == [0, 2, 5, 4, 1])
    assert(order([2, 1, 1, 5, 3, 6]) == [2, 1, 5, 3, 6])
    assert(order([0, 4, 5]) == [0, 4, 5])
    assert(order([1, 1, 5, 1, 1, 5]) == [1, 1, 5, 1, 5])
    assert(order([0, 2, 0, 0, 0, 0, 0, 0]) == [0, 2, 0, 0, 0])
    assert(order([0, 0, 0, 0, 1, 0, 0, 0, 0]) == [0, 0, 0, 0, 1])
    assert(order([5, 4, 2, 1, 0, 8, 7, 4, 6, 1, 0, 7]) == [5, 8, 7, 6, 7])
    assert(order([6, 3, 2, 0, 69, 22, 0, 37, 0, 2, 1, 0, 0, 0, 5, 0, 1, 2, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 2]) == [6, 69, 22, 37, 5])

main()
