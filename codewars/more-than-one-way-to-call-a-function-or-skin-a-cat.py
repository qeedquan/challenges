#!/usr/bin/env python3

"""

Write a single function that can be invoked by either

```javascript

sum(2,3); //5 //or sum(2)(3); //5```

clojure (sum 2 3) ;; 5 ;;or ((sum 2) 3) ;; 5

Both of these examples should return the sum of the 2 numbers.

"""

def sum(*args):
    if len(args) == 1:
        return lambda n: args[0] + n
    
    total = 0
    for value in args:
        total += value
    return total

def main():
    print(sum(2, 3))
    print(sum(2)(3))

main()
