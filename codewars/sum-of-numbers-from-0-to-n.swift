/*

Description:

We want to generate a function that computes the series starting from 0 and ending until the given number.

Example:

Input:

> 6

Output:

0+1+2+3+4+5+6 = 21

Input:

> -15

Output:

-15<0

Input:

> 0

Output:

0=0

*/

func triangular(n: Int) -> Int {
    if n < 0 {
        return 0
    }
    return n * (n + 1) / 2
}

assert(triangular(n: 6) == 21)
assert(triangular(n: 7) == 28)
assert(triangular(n: -15) == 0)
assert(triangular(n: 0) == 0)
for n in 0...10 {
    print(n, triangular(n: n))
}
