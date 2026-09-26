#!/usr/bin/env python3

"""

Given two positive integers, add them.

Both inputs and output are in Tally marks form, which can be expressed as:

T(n) = n            if n <= 5
       5||T(n - 5)  if n > 5

and for n=1 to 15, T(n) are 1,2,3,4,5,51,52,53,54,55,551,552,553,554,555, respectively.

Shortest code win.

Test cases:

1 + 1 = 2
4 + 2 = 51
51 + 5552 = 55553
5 + 5 = 55
52 + 53 = 555

Note
Technically U+1D360-U+1D378 𝍠 𝍡 𝍢 𝍣 𝍤 𝍥 𝍦 𝍧 𝍨 𝍩 𝍪 𝍫 𝍬 𝍭 𝍮 𝍯 𝍰 𝍱 𝍲 𝍳
𝍴 𝍵 𝍶 𝍷 𝍸 are used, but U+0031-U+0035 1 2 3 4 5 should be more friendly to most languag
a, and you can get a font to make them display as you want XD

"""

def tallyadd(a, b):
    c = sum(a + b)
    r = [5] * (c//5)
    if c%5 != 0:
        r.append(c % 5)
    return r

def main():
    assert(tallyadd([1], [1]) == [2])
    assert(tallyadd([4], [2]) == [5, 1])
    assert(tallyadd([5, 1], [5, 5, 5, 2]) == [5, 5, 5, 5, 3])
    assert(tallyadd([5], [5]) == [5, 5])
    assert(tallyadd([5, 2], [5, 3]) == [5, 5, 5])

main()
