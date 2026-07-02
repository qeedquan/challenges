/*

Lunar Mathematics, otherwise known as 'Dismal Mathematics' (a play on 'decimal mathematics'), was created as an alternate way to view mathematics interacts with numbers. Here, we will create the addition function.

On the moon, there is no need to carry over numbers into the next column. Instead, we take the largest value of each column, and set that as our total.

Examples:

        8
      + 7
      ----
        8 <- Since 8 is the larger number of the two, it is the one used.


      234
    + 180
    -----
      284 <- the larger values of each number are used for each potion.

      50
     +59
    ------
      59 <- If a number in two columns match, either one of the numbers can be used.

      465
     + 72
    -----
      475 <- You must handle situations where numbers are not of equal length

Assume all numbers given are valid, nonnegative integers (as there are no negative numbers on the moon).

*/

func add(_ a: Int, _ b: Int) -> Int {
    var (s, p, x, y) = (0, 1, a, b)
    while x > 0 || y > 0 {
        s += p * max(x % 10, y % 10)
        x /= 10
        y /= 10
        p &*= 10
    }
    return s
}

assert(5 == add(4, 5))
assert(5 == add(5, 5))
assert(6 == add(6, 3))
assert(5 == add(5, 0))
assert(20 == add(10, 20))
assert(31 == add(30, 11))
assert(59 == add(58, 19))
assert(51 == add(50, 1))
assert(51 == add(1, 50))
assert(99 == add(91, 19))
assert(100 == add(100, 0))
assert(120 == add(100, 20))
assert(11099 == add(99, 11085))
assert(987_656_789 == add(123_456_789, 987_654_321))
assert(Int.max == add(Int.max, 0))
assert(Int.max == add(Int.max, Int.max))
