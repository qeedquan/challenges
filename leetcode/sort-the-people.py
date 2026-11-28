#!/usr/bin/env python3

"""

You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.

For each index i, names[i] and heights[i] denote the name and height of the ith person.

Return names sorted in descending order by the people's heights.

Example 1:

Input: names = ["Mary","John","Emma"], heights = [180,165,170]
Output: ["Mary","Emma","John"]
Explanation: Mary is the tallest, followed by Emma and John.

Example 2:

Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
Output: ["Bob","Alice","Bob"]
Explanation: The first Bob is the tallest, followed by Alice and the second Bob.

Constraints:

    n == names.length == heights.length
    1 <= n <= 10^3
    1 <= names[i].length <= 20
    1 <= heights[i] <= 10^5
    names[i] consists of lower and upper case English letters.
    All the values of heights are distinct.

"""

class Person:
    def __init__(self, name, height):
        self.name = name
        self.height = height
    
    def __repr__(self):
        return "(%s, %d)" % (self.name, self.height)

def sort_people(names, heights):
    people = []
    for i in range(len(names)):
        people.append(Person(names[i], heights[i]))
    people.sort(key=lambda x: x.height, reverse=True)

    result = []
    for p in people:
        result.append(p.name)
    return result

def main():
    assert(sort_people(["Mary", "John", "Emma"], [180, 165, 170]) == ["Mary", "Emma", "John"])
    assert(sort_people(["Alice", "Bob", "Bob"], [155, 185, 150]) == ["Bob", "Alice", "Bob"])

main()
