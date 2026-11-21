#!/usr/bin/env python3

"""

Frequency encoding replaces each category with the proportion of input positions containing that category. If a category appears c times in a list of n values, its encoding is

f = c/n
 
Here, c is the category count and n is len(values). Return one floating-point frequency for every input position in the same order.

Examples
Input: values = ["a", "b", "a", "c", "a"]

Output: [0.6, 0.2, 0.6, 0.2, 0.6]

Explanation: Category a occurs three times out of five, while b and c each occur once.

Input: values = ["cat", "dog", "cat", "cat", "dog"]

Output: [0.6, 0.4, 0.6, 0.6, 0.4]

Hint 1
Build a count dictionary in one pass over values.

Hint 2
Map each original value to its count divided by the total length.

Requirements
Count each distinct value in the complete input.
Divide each count by len(values).
Preserve the original value order.
Return a list of floats.
Constraints
values is nonempty.
Values are hashable strings or integers.
Time limit: 300 ms.

"""

def solve(values):
    count = {}
    for value in values:
        if value not in count:
            count[value] = 0
        count[value] += 1
    
    result = []
    for value in values:
        result.append(count[value]/len(values))

    return result

def main():
    print(solve(["a", "b", "a", "c", "a"]))
    print(solve(["cat", "dog", "cat", "cat", "dog"]))

main()
