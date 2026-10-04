/*

Write a function, persistence, that takes in a positive parameter num and returns its multiplicative persistence, which is the number of times you must multiply the digits in num until you reach a single digit.

For example (Input --> Output):

39 --> 3 (because 3*9 = 27, 2*7 = 14, 1*4 = 4 and 4 has only one digit, there are 3 multiplications)
999 --> 4 (because 9*9*9 = 729, 7*2*9 = 126, 1*2*6 = 12, and finally 1*2 = 2, there are 4 multiplications)
4 --> 0 (because 4 is already a one-digit number, there is no multiplication)

*/

func digprod(_ n: Int) -> Int {
    if n < 1 {
        return 0
    }

    var (p, n) = (1, n)
    while n > 0 {
        p *= n % 10
        n /= 10
    }
    return p
}

// https://oeis.org/A031346
func persistence(_ n: Int) -> Int {
    if n < 1 {
        return 0
    }

    var (c, n) = (0, n)
    while n > 9 {
        n = digprod(n)
        c += 1
    }
    return c
}

let tab = [
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 2, 2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 1, 1, 1, 2, 2, 2, 2, 3,
    2, 3, 1, 1, 2, 2, 2, 3, 2, 3, 2, 3, 1, 1, 2, 2, 2, 2, 3, 2, 3, 3, 1, 1,
    2, 2, 3, 3, 2, 4, 3, 3, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 1, 1, 2, 3, 3, 3,
    3, 3, 3, 2,
]

for i in 0..<tab.count {
    assert(persistence(i) == tab[i])
}

assert(persistence(39) == 3)
assert(persistence(999) == 4)
assert(persistence(4) == 0)
