#!/usr/bin/env python3

"""

Introduction:
I think we've all heard of it, but here a very brief summary: Noah gathered two of every species of animal on the planet, male and female, to save in his Ark during a great flood. The actual quote from the Bible is:

Genesis 7:2-3
You must take with you seven of every kind of clean animal, the male and its mate, two of every kind of unclean animal, the male and its mate, and also seven of every kind of bird in the sky, male and female, to preserve their offspring on the face of the earth.
source

But for the sake of this challenge we will ignore the clean/unclean part and the part where he took seven of each animal. This challenge is only about this part:

two of every kind of unclean animal, the male and its mate

Challenge:
Input:

You are given a list of positive integers (in random order).

Output:

Two distinct values indicating whether it's a 'List of Noah' or not. This doesn't necessary have to be a truthy/falsey value, so could also be 0/1 in Java/C#, or 'A'/'B' in any language, to give some examples.

When is a list a 'List of Noah'? When there are exactly two of every integer in the list.

Challenge rules:
I/O is flexible. Input can be a list/array/stream of integers/floats/strings, or read one by one from STDIN. Output can be any two distinct values, returned from a function or output to STDOUT / a file.
The integers in the input-list are in random order, and are guaranteed to be positive within the range  1≤n≤100000
 .
The input-list is guaranteed to be non-empty.
Having an integer a multiple of two times present above 2 (i.e. 4, 6, 8, etc.) will be falsey. I.e. [6,4,4,6,4,7,4,7] is falsey, although you could still create equal pairs like this: [[4,4],[4,4],[6,6],[7,7]].
General rules:
This is code-golf, so shortest answer in bytes wins.
Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.
Standard rules apply for your answer with default I/O rules, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters and return-type, full programs. Your call.
Default Loopholes are forbidden.
If possible, please add a link with a test for your code (i.e. TIO).
Also, adding an explanation for your answer is highly recommended.
Test cases:
Truthy:
[7,13,9,2,10,2,4,10,7,13,4,9]
[1,2,3,1,2,3]
[10,100,1000,1,100,10,1000,1]
[123,123]
[8,22,57189,492,22,57188,8,492,57188,57189,1,1]

Falsey:
[6,4,4,6,4,7,4,7]
[2,2,2,2,2,2]
[5,1,4,5,1,1,4]
[77,31,5,31,80,77,5,8,8]
[1,2,3,2,1]
[44,4,4]
[500,30,1]
[1,2,1,1]
[2,4,6,4,4,4]
[2,23,34,4]
[2,23,3,3,34,4]

"""

def noah(animals):
    return {*map(animals.count, animals)} == {2}

def main():
    assert(noah([7, 13, 9, 2, 10, 2, 4, 10, 7, 13, 4, 9]) == True)
    assert(noah([1, 2, 3, 1, 2, 3]) == True)
    assert(noah([10, 100, 1000, 1, 100, 10, 1000, 1]) == True)
    assert(noah([123, 123]) == True)
    assert(noah([8, 22, 57189, 492, 22, 57188, 8, 492, 57188, 57189, 1, 1]) == True)

    assert(noah([6, 4, 4, 6, 4, 7, 4, 7]) == False)
    assert(noah([2, 2, 2, 2, 2, 2]) == False)
    assert(noah([5, 1, 4, 5, 1, 1, 4]) == False)
    assert(noah([77, 31, 5, 31, 80, 77, 5, 8, 8]) == False)
    assert(noah([1, 2, 3, 2, 1]) == False)
    assert(noah([44, 4, 4]) == False)
    assert(noah([500, 30, 1]) == False)
    assert(noah([1, 2, 1, 1]) == False)
    assert(noah([2, 4, 6, 4, 4, 4]) == False)
    assert(noah([2, 23, 34, 4]) == False)
    assert(noah([2, 23, 3, 3, 34, 4]) == False)

main()
