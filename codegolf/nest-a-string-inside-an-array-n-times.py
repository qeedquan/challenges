#!/usr/bin/env python3

r"""

You must produce a function which nests a string s inside an array, n times

>>> N("stackoverflow",2)
[['stackoverflow']]
Parameters:
s - An ascii string
n - An integer >= 0
Rules
Shortest code wins.
The output will be a nested array, list or tuple (or similar type based off an array)
Test Cases
>>> N("stackoverflow",0)
'stackoverflow'
>>> N("stackoverflow",1)
['stackoverflow']
>>> N("stackoverflow",5)
[[[[['stackoverflow']]]]]
Inspired by: Nesting a string inside a list n times ie list of a list of a list

"""

def nest(s, n):
    if n < 1:
        return s
    return [nest(s, n - 1)]

def main():
    print(nest("stackoverflow", 0))
    print(nest("stackoverflow", 1))
    print(nest("stackoverflow", 5))

main()

