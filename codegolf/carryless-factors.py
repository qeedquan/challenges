#!/usr/bin/env python3

"""

Carryless multiplication is an operation similar to binary long multiplication, but with XOR instead of addition:

  1011    11
×  101     5
 -----
  1011
    0
1011
------
100111    39
In this challenge, you'll be given a positive integer >= 2, and must return a list of all positive integers which are carryless factors of that number, meaning that they can be carryless-multiplied by another number to get the input. For example, for 39, 5 and 11 would be two of those.

Rules:

You may choose whether or not to include 1 and/or the input itself
You may output the factors in any order, and may include duplicates
You may choose how to represent the numbers (binary strings are allowed)
Test cases:

2       (1) (2)
4       (1) 2 (4)
5       (1) 3 (5)
6       (1) 2 3 (6)
25      (1) (25)
39      (1) 3 5 11 29 (39)
42      (1) 2 7 14 21 (42)
100     (1) 2 4 25 50 (100)
574     (1) 2 3 5 6 7 9 10 11 14 15 18 22 27 29 30 39 45 49 54 58 78 83 90 98 105 166 210 245 287 490 (574)
5040    (1) 2 3 4 6 7 8 9 12 13 14 16 18 21 23 24 26 28 35 36 42 46 48 52 56 63 70 72 84 92 101 104 112 126 140 144 168 184 202 208 233 252 280 315 336 368 404 466 504 560 630 808 932 1008 1260 1616 1864 2520 3728 (5040)
848640  (1) 2 3 4 5 6 7 8 9 10 12 14 15 16 17 18 20 21 24 27 28 30 32 34 36 40 42 45 48 51 54 56 60 63 64 65 68 72 80 84 85 90 96 102 108 112 119 120 126 128 130 136 144 153 160 168 170 180 192 195 204 216 224 238 240 252 255 256 260 272 288 306 320 325 336 340 360 384 390 408 427 432 448 476 480 504 510 520 544 576 612 640 650 672 680 720 765 768 780 816 854 864 896 952 960 975 1008 1020 1040 1088 1105 1152 1224 1280 1300 1344 1360 1440 1530 1560 1632 1708 1728 1792 1904 1920 1950 2016 2040 2080 2176 2210 2304 2448 2600 2688 2720 2880 3060 3120 3264 3315 3416 3456 3808 3840 3900 4032 4080 4160 4352 4420 4896 5200 5376 5440 5760 6120 6240 6528 6630 6832 6912 7616 7800 8064 8160 8320 8840 9792 10400 10880 11520 12240 12480 13056 13260 13664 15232 15600 16128 16320 16640 17680 19584 20800 21760 24480 24960 26520 27328 30464 31200 32640 35360 39168 41600 48960 49920 53040 54656 62400 65280 70720 83200 97920 106080 109312 124800 141440 195840 212160 249600 282880 424320 (848640)
This is code-golf, shortest answer in bytes (per language) wins!

"""

"""

@xnor

Prints the factors backwards, excluding the input itself.

The idea is to test divisibility using a carryless analogue of long-division to compute the remainder and see if it's zero.

The number k is a factor of n if we can xor some collection of leftward bit-shifts of k onto n to get zero. It suffices to use the greedy strategy of making n as small as possible at each step, which is achieved by clearing the leftmost bit of n (without introducing larger-valued bits) by taking the bit-shift of k whose leftmost bit aligns with that of n.

The code achieves this by taking the bit-shifts k<<i for some large i counting down to 0, and checking if xor-ing this value onto n makes n smaller.

An alternative approach to repeatedly try to clear the rightmost bit of n while shifting k leftward.

"""
def clf(n):
    if n < 1:
        return []

    r = [n]
    for k in range(n - 1, -1, -1):
        m = n
        for i in range(n - 1, -1, -1):
            m = min((k << i) ^ m, m)
        if m < 1:
            r.append(k)

    return r[::-1]

def main():
    assert(clf(2) == [1, 2])
    assert(clf(4) == [1, 2, 4])
    assert(clf(5) == [1, 3, 5])
    assert(clf(6) == [1, 2, 3, 6])
    assert(clf(25) == [1, 25])
    assert(clf(39) == [1, 3, 5, 11, 29, 39])
    assert(clf(42) == [1, 2, 7, 14, 21, 42])
    assert(clf(100) == [1, 2, 4, 25, 50, 100])
    assert(clf(574) == [1, 2, 3, 5, 6, 7, 9, 10, 11, 14, 15, 18, 22, 27, 29, 30, 39, 45, 49, 54, 58, 78, 83, 90, 98, 105, 166, 210, 245, 287, 490, 574])
    assert(clf(5040) == [1, 2, 3, 4, 6, 7, 8, 9, 12, 13, 14, 16, 18, 21, 23, 24, 26, 28, 35, 36, 42, 46, 48, 52, 56, 63, 70, 72, 84, 92, 101, 104, 112, 126, 140, 144, 168, 184, 202, 208, 233, 252, 280, 315, 336, 368, 404, 466, 504, 560, 630, 808, 932, 1008, 1260, 1616, 1864, 2520, 3728, 5040])
    assert(clf(848640) == [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 15, 16, 17, 18, 20, 21, 24, 27, 28, 30, 32, 34, 36, 40, 42, 45, 48, 51, 54, 56, 60, 63, 64, 65, 68, 72, 80, 84, 85, 90, 96, 102, 108, 112, 119, 120, 126, 128, 130, 136, 144, 153, 160, 168, 170, 180, 192, 195, 204, 216, 224, 238, 240, 252, 255, 256, 260, 272, 288, 306, 320, 325, 336, 340, 360, 384, 390, 408, 427, 432, 448, 476, 480, 504, 510, 520, 544, 576, 612, 640, 650, 672, 680, 720, 765, 768, 780, 816, 854, 864, 896, 952, 960, 975, 1008, 1020, 1040, 1088, 1105, 1152, 1224, 1280, 1300, 1344, 1360, 1440, 1530, 1560, 1632, 1708, 1728, 1792, 1904, 1920, 1950, 2016, 2040, 2080, 2176, 2210, 2304, 2448, 2600, 2688, 2720, 2880, 3060, 3120, 3264, 3315, 3416, 3456, 3808, 3840, 3900, 4032, 4080, 4160, 4352, 4420, 4896, 5200, 5376, 5440, 5760, 6120, 6240, 6528, 6630, 6832, 6912, 7616, 7800, 8064, 8160, 8320, 8840, 9792, 10400, 10880, 11520, 12240, 12480, 13056, 13260, 13664, 15232, 15600, 16128, 16320, 16640, 17680, 19584, 20800, 21760, 24480, 24960, 26520, 27328, 30464, 31200, 32640, 35360, 39168, 41600, 48960, 49920, 53040, 54656, 62400, 65280, 70720, 83200, 97920, 106080, 109312, 124800, 141440, 195840, 212160, 249600, 282880, 424320, 848640])

main()
