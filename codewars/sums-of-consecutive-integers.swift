/*

The sum of x consecutive integers is y. What is the consecutive integer at position n? Given x, y, and n, solve for the integer. Assume the starting position is 0.

For example, if the sum of 4 consecutive integers is 14, what is the consecutive integer at position 3?

We find that the consecutive integers are [2, 3, 4, 5], so the integer at position 3 is 5.

position(4, 14, 3) == 5
Assume there will always be a sum of x consecutive integers that totals to y and n will never be indexed out of bounds.

*/

func position(_ x: Int, _ y: Int, _ n: Int) -> Int {
    return (y / x) - ((x - 1) / 2) + n
}

assert(position(4, 14, 3) == 5)
assert(position(2, 25, 0) == 12)
assert(position(7, 749, 5) == 109)
assert(position(3, -9, 1) == -3)
assert(position(5, 0, 0) == -2)
