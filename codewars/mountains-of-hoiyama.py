#!/usr/bin/env python3

"""

In the planet named Hoiyama, scientists are trying to find the weights of the mountains.
They managed to find the weights of some mountains.
But calculating them manually takes a really long time.
That's why they hired you to develop an algorithm and easily calculate the weights of the mountains.
Your function has only one parameter which is the width of the mountain and you need to return the weight of that mountain.
The widths of the mountains are only odd numbers.
They gave you some information about calculating the weight of a mountain.
Examine the information given below and develop a solution accordingly.

width = 3

          3          ->  3
        1,2,1        ->  4
                      +___
               weight:   7

width = 5

          5          ->  5
        3,4,3        -> 10
      1,2,3,2,1      ->  9
                      +___
               weight:  24

width = 7

          7          ->  7
        5,6,5        -> 16
      3,4,5,4,3      -> 19
    1,2,3,4,3,2,1    -> 16
                      +___
               weight:  58

width = 9

          9          ->  9
        7,8,7        -> 22
      5,6,7,6,5      -> 29
    3,4,5,6,5,4,3    -> 30
  1,2,3,4,5,4,3,2,1  -> 25
                      +___
               weight: 115

width = 17

                   17                  ->  17
                15,16,15               ->  46
             13,14,15,14,13            ->  69
          11,12,13,14,13,12,11         ->  86
        9,10,11,12,13,12,11,10,9       ->  97
       7,8,9,10,11,12,11,10,9,8,7      -> 102
      5,6,7,8,9,10,11,10,9,8,7,6,5     -> 101
     3,4,5,6,7,8,9,10,9,8,7,6,5,4,3    ->  94
    1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2,1  ->  81
                                        +____
                                  weight: 693

"""

# https://oeis.org/A235355
def hoiyama(n):
    return -((-1 + (-1)**n - 2*n) * (2 + n + n**2)) // 16

def main():
    tab = [
        0, 1, 2, 7, 11, 24, 33, 58, 74, 115, 140, 201, 237, 322, 371, 484, 548,
        693, 774, 955, 1055, 1276, 1397, 1662, 1806, 2119, 2288, 2653, 2849,
        3270, 3495, 3976, 4232, 4777, 5066, 5679, 6003, 6688, 7049, 7810, 8210,
        9051, 9492, 10417, 10901, 11914, 12443, 13548
    ]

    for i in range(len(tab)):
        assert(hoiyama(i) == tab[i])

main()
