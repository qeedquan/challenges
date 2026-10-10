/*

Give the summation of all even numbers in a Fibonacci sequence up to, but not including, the number passed to your function. Or, in other words, sum all the even Fibonacci numbers that are lower than the given number n (n is not the nth element of Fibonnacci sequence) without including n.

The Fibonacci sequence is a series of numbers where the next value is the addition of the previous two values. The series starts with 0 and 1:

0 1 1 2 3 5 8 13 21...

For example:

Kata.Fibonacci(0) // returns 0
Kata.Fibonacci(33) // returns 10
Kata.Fibonacci(25997544) // returns 19544084

*/

func solve(_ n: UInt) -> UInt {
    var r: UInt = 0
    var x: UInt = 0
    var y: UInt = 1
    while y < n {
        if (y & 1) == 0 {
            r += y
        }
        (x, y) = (y, x + y)
    }
    return r
}

func main() {
    assert(solve(0) == 0)
    assert(solve(1) == 0)
    assert(solve(2) == 0)
    assert(solve(3) == 2)
    assert(solve(5) == 2)
    assert(solve(8) == 2)
    assert(solve(10) == 10)
    assert(solve(33) == 10)
    assert(solve(100) == 44)
    assert(solve(1000) == 798)
    assert(solve(25_997_544) == 19_544_084)
    assert(solve(1_000_000) == 1_089_154)
    assert(solve(100_000_000) == 82_790_070)
    assert(solve(1_000_000_000) == 350_704_366)
    assert(solve(2_147_483_647) == 1_485_607_536)
}

main()
