#!/usr/bin/env python3

"""

Note: This is #2 in a series of array challenges. For the previous challenge, click here.

Separating Nested Lists
To separate values in a nested list, flatten it, and then wrap each value so it is at the same nested depth as before.

That is to say, this list:

[1, [2, 3], [4, 4, [5, 2], 1]]
Would become:

[1, [2], [3], [4], [4], [[5]], [[2]], [1]]
The Challenge
Your task is to write a program which takes any nested list of positive integers (within your language's limits) and performs this separation operation.

You may submit a function which takes the list as an argument, or a full program which performs I/O.

As this is code-golf, the shortest submission (in bytes) wins!*

*Standard golfing loopholes are banned. You know the drill.

Test Cases
Input lists will only ever contain integers in your language's standard integer size. To avoid languages' constraints preventing them from competing, values will not be nested at depths of more than 10.

You may assume that input will not have empty sub-lists: for example - [[5, []]] will not be given. However, the main list could be empty.

[]            ->  []

[[1, 2]]      ->  [[1], [2]]
[3, [4, 5]]   ->  [3, [4], [5]]
[3, [3, [3]]] ->  [3, [3], [[3]]]
[[6, [[7]]]]  ->  [[6], [[[7]]]]
[[5, 10], 11] ->  [[5], [10], 11]
Don't hesitate to leave a comment if I've missed out a corner case.

Example
I threw together a quick (ungolfed) Python 3 solution as an example - you can test it on repl.it.

"""

def recurse(item, depth):
    result = []
    if isinstance(item, int):
        for _ in range(1, depth):
            item = [item]
        result.append(item)
    elif isinstance(item, list):
        for value in item:
            result += recurse(value, depth + 1)
    return result

def separate(item):
    return recurse(item, 0)

def main():
    assert(separate([1, [2, 3], [4, 4, [5, 2], 1]]) == [1, [2], [3], [4], [4], [[5]], [[2]], [1]])
    assert(separate([]) == [])
    assert(separate([[1, 2]]) == [[1], [2]])
    assert(separate([3, [4, 5]]) == [3, [4], [5]])
    assert(separate([3, [3, [3]]]) == [3, [3], [[3]]])
    assert(separate([[6, [[7]]]]) == [[6], [[[7]]]])
    assert(separate([[5, 10], 11]) == [[5], [10], 11])

main()
