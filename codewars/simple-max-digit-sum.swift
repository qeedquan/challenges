/*

In this Kata, you will be given an integer n and your task will be to return the r integer that is <= n and has the highest digit sum.

For example:

solve(100) = 99. Digit Sum for 99 = 9 + 9 = 18. No other number <= 100 has a higher digit sum.
solve(10) = 9
solve(48) = 48. Note that 39 is also an option, but 48 is larger.
Input range is 0 < n < 1e11

More examples in the test cases.

Good luck!

*/

func ipow(_ base: Int, _ exp: Int) -> Int {
    var (exp, base, result) = (exp, base, 1)
    while true {
        if (exp & 1) != 0 {
            result *= base
        }
        exp >>= 1
        if exp == 0 {
            break
        }
        base *= base
    }

    return result
}

func digsum(_ n: Int) -> Int {
    var (r, x) = (0, n)
    while x > 0 {
        r += x % 10
        x /= 10
    }
    return r
}

func solvebf(_ n: Int) -> Int {
    var (m, r) = (0, 0)
    for i in 0...n {
        let d = digsum(i)
        if d >= m {
            (m, r) = (d, i)
        }
    }
    return r
}

func solve(_ n: Int) -> Int {
    var (n, m, r, i) = (n, digsum(n), n, 1)
    while n > 0 {
        n = n - (n % ipow(10, i)) - 1
        i += 1

        let d = digsum(n)
        if d > m {
            (m, r) = (d, n)
        }
    }
    return r
}

assert(solve(1) == 1)
assert(solve(2) == 2)
assert(solve(18) == 18)
assert(solve(48) == 48)
assert(solve(100) == 99)
assert(solve(10) == 9)
assert(solve(110) == 99)
assert(solve(2090) == 1999)

for i in 0...10000 {
    assert(solve(i) == solvebf(i))
}
