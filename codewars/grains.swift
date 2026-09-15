/*

Grains
Write a program that calculates the number of grains of wheat on a specific square of chessboard given that the number on each square is double the previous one.

There are 64 squares on a chessboard.

#Example: square(1) = 1 square(2) = 2 square(3) = 4 square(4) = 8 etc...

Write a program that shows how many grains were on each square.

*/

func grains(_ n: UInt) -> UInt {
    if n == 0 {
        return 0
    }
    return 1 << (n - 1)
}

assert(grains(1) == 1)
assert(grains(2) == 2)
assert(grains(3) == 4)
assert(grains(4) == 8)
