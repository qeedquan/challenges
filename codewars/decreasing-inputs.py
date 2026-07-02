#!/usr/bin/env python3

"""

This kata is all about adding numbers.

You will create a function named add. It will return the sum of all the arguments. Sounds easy, doesn't it?

Well Here's the Twist. The inputs will gradually decrease with their index as parameter to the function.

  add(3,4,6);
  /*
  returns ( 3 / 1 ) + ( 4 / 2 ) + ( 6 / 3 ) = 7
  */
Remember the function will return 0 if no arguments are passed and it must round the result if sum is a float.

Example

  add(); //=> 0
  add(1,2,3); //=> 3
  add(1,4,-6,20); //=> 6

"""

def add(*a):
    r = 0
    for i in range(len(a)):
        r += a[i] / (i + 1)
    return round(r)

def main():
    assert(add() == 0)
    assert(add(1, 2, 3) == 3)
    assert(add(1, 4, -6, 20) == 6)

main()
