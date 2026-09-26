/*

Description
Given a number, print the amount of 1s it has in binary representation.

Input
A number >= 0 in base 10 that won't exceed the highest number your language is able to handle.

Output
The amount of 1s in binary representation.

Winning condition
The shortest code wins.

Disallowed
Bitwise operators. Other operators, like addition and multiplication, are allowed.
Built-in base conversion functions.
Examples
Input:     Ouput:

56432      8


Input:     Output:

45781254   11


Input:     Output:

0          0

*/

func ones(_ n: Int) -> Int {
    var (c, n) = (0, n)
    while n != 0 {
        c += n % 2
        n /= 2
    }
    return c
}

assert(ones(0x0) == 0)
assert(ones(0x2) == 1)
assert(ones(0x3) == 2)
assert(ones(0x7) == 3)
assert(ones(0xf) == 4)
assert(ones(56432) == 8)
assert(ones(45_781_254) == 11)
