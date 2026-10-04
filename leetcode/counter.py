#!/usr/bin/env python3

"""

Given an integer n, return a counter function. This counter function initially returns n and then returns 1 more than the previous value every subsequent time it is called (n, n + 1, n + 2, etc).

Example 1:

Input:
n = 10
["call","call","call"]
Output: [10,11,12]
Explanation:
counter() = 10 // The first time counter() is called, it returns n.
counter() = 11 // Returns 1 more than the previous time.
counter() = 12 // Returns 1 more than the previous time.
Example 2:

Input:
n = -2
["call","call","call","call","call"]
Output: [-2,-1,0,1,2]
Explanation: counter() initially returns -2. Then increases after each sebsequent call.


Constraints:

-1000 <= n <= 1000
At most 1000 calls to counter() will be made

Hint:
In Javascript, a function can return a clojure. A clojure is defined as a function that can access variables declared above it (it's lexical environment).
A count variable can be initialized in the outer function and mutated in the inner function.

"""

def counter(n):
    count = n
    def increment():
        nonlocal count
        value = count
        count += 1
        return value
    return increment

def main():
    c1 = counter(10)
    c2 = counter(-2)
    for i in range(3):
        print(c1())
    for i in range(5):
        print(c2())

main()
