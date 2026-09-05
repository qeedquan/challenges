/*

The Fibonacci numbers are defined recursively as

f(0) = 0
f(1) = 1
f(n) = f(n-2) + f(n-1)

Find the last eight digits of f( 1018 ).

If you have some computer science and/or discrete math training, this is not very difficult, but if you don't it can be really tricky. You can't just write a for-loop to calculate Fibonacci numbers one by one (and you certainly can't simply implement the recursive definition directly). That for-loop would have to run a quintillion times, and by the time it's finished, the sun will probably have exploded. You have to be more clever than that.

I should add that the identity you need to solve this problem is on the Wikipedia page for Fibonacci numbers. Using that identity and another algorithm solves the problem instantly (my Python program gives the answer in less than 0.1 seconds).

submitted by oskar_s in /r/dailyprogrammer_ideas

Edit : Note the "Intermediate" challenge #30 has been changed. Thank you!

*/

func fibmod(_ k: UInt128, _ n: UInt128) -> (UInt128, UInt128, UInt128) {
    if k == 1 {
        return (0, 1, 1)
    }

    var (a, b, c) = fibmod(k / 2, n)

    (a, b, c) = (a * a + b * b, a * b + b * c, b * b + c * c)
    if k % 2 != 0 {
        (a, b, c) = (b, c, b + c)
    }
    return (a % n, b % n, c % n)
}

func solve(_ n: UInt128) -> UInt128 {
    let (_, b, _) = fibmod(n, 100_000_000)
    return b
}

assert(solve(1_000_000_000_000_000_000) == 60_546_875)
