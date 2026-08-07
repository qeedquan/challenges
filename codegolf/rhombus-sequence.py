#!/usr/bin/env python3

"""

Imagine enumerating the elements of rhombi which grow [1],[1,3,1],[1,3,5,3,1],… (only odd numbers such that they align nicely). This would look like as follows, note that you always begin enumerating with 1:

                   01
       1        02 03 04
 1   2 3 4   05 06 07 08 09          …
       5        10 11 12
                   13
(1) (1,3,1)    (1,3,5,3,1)    (1,3,5,7,5,3,1)   …
Now if you start summing the columns ([1],[2],[1,3,5],[4],[5],[2,6,10],…) you get the rhombus sequence. These are the first 100 elements of said sequence:

1,2,9,4,5,18,35,24,9,10,33,60,91,70,45,16,17,54,95,140,189,154,115,72,25,26,81,140,203,270,341,288,231,170,105,36,37,114,195,280,369,462,559,484,405,322,235,144,49,50,153,260,371,486,605,728,855,754,649,540,427,310,189,64,65,198,335,476,621,770,923,1080,1241,1110,975,836,693,546,395,240,81,82,249,420,595,774,957,1144,1335,1530,1729,1564,1395,1222,1045,864,679,490,297,100
IO
You are free to choose one of these three input/output methods (you won't need to handle invalid inputs):

Given an integer n output the nth element in that sequence (0- or 1-indexed, your choice)
Given an integer n output first n elements of that sequence
Print/return the sequence indefinetely

Testcases
Please refer to the first 100 terms above, here are some larger examples (1-indexed):

101 -> 101
443 -> 1329
1000 -> 49000
1984 -> 164672
2017 -> 34289
2018 -> 30270
3000 -> 153000

"""

from math import *

"""

@Arnauld

A closed-form expression derived from A004737.
https://oeis.org/A004737

"""

def rhombus(n):
    if n < 1:
        return 0
    n -= 1
    m = int(sqrt(n))
    return 2*(m - abs(n - m*m - m))*(n+1) + (n+1)

def main():
    tab = [1, 2, 9, 4, 5, 18, 35, 24, 9, 10, 33, 60, 91, 70, 45, 16, 17, 54, 95, 140, 189, 154, 115, 72, 25, 26, 81, 140, 203, 270, 341, 288, 231, 170, 105, 36, 37, 114, 195, 280, 369, 462, 559, 484, 405, 322, 235, 144, 49, 50, 153, 260, 371, 486, 605, 728, 855, 754, 649, 540, 427, 310, 189, 64, 65, 198, 335, 476, 621, 770, 923, 1080, 1241, 1110, 975, 836, 693, 546, 395, 240, 81, 82, 249, 420, 595, 774, 957, 1144, 1335, 1530, 1729, 1564, 1395, 1222, 1045, 864, 679, 490, 297, 100]

    assert(rhombus(101) == 101)
    assert(rhombus(443) == 1329)
    assert(rhombus(1000) == 49000)
    assert(rhombus(1984) == 164672)
    assert(rhombus(2017) == 34289)
    assert(rhombus(2018) == 30270)
    assert(rhombus(3000) == 153000)

    for i in range(len(tab)):
        assert(rhombus(i + 1) == tab[i])

main()
