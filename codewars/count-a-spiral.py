#!/usr/bin/env python3

r"""

Your task is to return the amount of white rectangles in a `NxN` spiral. Your font may differ, if we talk of white rectangles, we talk about
the symbols in the top row.

#### Notes:

* As a general rule, the white snake cannot touch itself.
* The size will be at least 5.
* The test cases get very large, it is not feasible to calculate the solution with a loop.

## Examples

For example, a spiral with size 5 should look like this:

⬜⬜⬜⬜⬜\
⬛⬛⬛⬛⬜\
⬜⬜⬜⬛⬜\
⬜⬛⬛⬛⬜\
⬜⬜⬜⬜⬜

And return the value 17 because the total amount of white rectangles is 17.

---

A spiral with the size 7 would look like this:

⬜⬜⬜⬜⬜⬜⬜\
⬛⬛⬛⬛⬛⬛⬜\
⬜⬜⬜⬜⬜⬛⬜\
⬜⬛⬛⬛⬜⬛⬜\
⬜⬛⬜⬜⬜⬛⬜\
⬜⬛⬛⬛⬛⬛⬜\
⬜⬜⬜⬜⬜⬜⬜

And return the value 31 because the total amount of white rectangles is 31.

---

A spiral with the size 8 would look like this:

⬜⬜⬜⬜⬜⬜⬜⬜\
⬛⬛⬛⬛⬛⬛⬛⬜\
⬜⬜⬜⬜⬜⬜⬛⬜\
⬜⬛⬛⬛⬛⬜⬛⬜\
⬜⬛⬜⬛⬛⬜⬛⬜\
⬜⬛⬜⬜⬜⬜⬛⬜\
⬜⬛⬛⬛⬛⬛⬛⬜\
⬜⬜⬜⬜⬜⬜⬜⬜

And return the value 39 because the total amount of white rectangles is 39.

---

A spiral with the size 9 would look like this:

⬜⬜⬜⬜⬜⬜⬜⬜⬜\
⬛⬛⬛⬛⬛⬛⬛⬛⬜\
⬜⬜⬜⬜⬜⬜⬜⬛⬜\
⬜⬛⬛⬛⬛⬛⬜⬛⬜\
⬜⬛⬜⬜⬜⬛⬜⬛⬜\
⬜⬛⬜⬛⬛⬛⬜⬛⬜\
⬜⬛⬜⬜⬜⬜⬜⬛⬜\
⬜⬛⬛⬛⬛⬛⬛⬛⬜\
⬜⬜⬜⬜⬜⬜⬜⬜⬜

And return the value 49 because the total amount of white rectangles is 49.

---

A spiral with the size 10 would look like this:

⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜\
⬛⬛⬛⬛⬛⬛⬛⬛⬛⬜\
⬜⬜⬜⬜⬜⬜⬜⬜⬛⬜\
⬜⬛⬛⬛⬛⬛⬛⬜⬛⬜\
⬜⬛⬜⬜⬜⬜⬛⬜⬛⬜\
⬜⬛⬜⬛⬛⬜⬛⬜⬛⬜\
⬜⬛⬜⬛⬛⬛⬛⬜⬛⬜\
⬜⬛⬜⬜⬜⬜⬜⬜⬛⬜\
⬜⬛⬛⬛⬛⬛⬛⬛⬛⬜\
⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜

And return the value 59 because the total amount of white rectangles is 59.

"""

# https://oeis.org/A047838
def count(n):
    if n < 2:
        return 0
    return ((n * n) // 2) - 1

def solve(n):
    return count(n + 1)

def main():
    tab = [
        1, 3, 7, 11, 17, 23, 31, 39, 49, 59, 71, 83, 97, 111, 127, 143, 161,
        179, 199, 219, 241, 263, 287, 311, 337, 363, 391, 419, 449, 479, 511,
        543, 577, 611, 647, 683, 721, 759, 799, 839, 881, 923, 967, 1011, 1057,
        1103, 1151, 1199, 1249, 1299, 1351, 1403
    ]

    for i in range(len(tab)):
        assert(solve(i + 1) == tab[i])

    assert(solve(5) == 17)
    assert(solve(10) == 59)
    assert(solve(1000) == 500999)

main()
