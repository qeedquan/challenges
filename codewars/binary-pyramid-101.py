#!/usr/bin/env python3

"""

Given two numbers m and n, such that 0 ≤ m ≤ n :

convert all numbers from m to n (inclusive) to binary
sum them as if they were in base 10
convert the result to binary
return as a string

Example
1, 4  -->  1111010

because:
    1  // 1 in binary is 1
+  10  // 2 in binary is 10
+  11  // 3 in binary is 11
+ 100  // 4 in binary is 100
-----
  122  // 122 in binary is 1111010


"""

# https://oeis.org/A067894
def pyramid(m, n):
    r = 0
    for i in range(m, n + 1):
        r += int(bin(i)[2:])
    return bin(r)[2:]

def main():
    tab = [0, 1, 11, 22, 122, 223, 333, 444, 1444, 2445, 3455, 4466, 5566, 6667, 7777, 8888, 18888, 28889, 38899, 48910, 59010, 69111, 79221, 89332, 100332, 111333, 122343, 133354, 144454, 155555, 166665, 177776, 277776, 377777, 477787, 577798, 677898, 777999, 878109]

    assert(pyramid(1, 4) == "1111010")

    for i in range(len(tab)):
        x = int(pyramid(0, i), 2)
        assert(x == tab[i])

main()
