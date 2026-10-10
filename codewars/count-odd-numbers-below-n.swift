/*

Given a number **n**, return the number of positive odd numbers below **n**, EASY!

oddCount(7) //=> 3, i.e [1, 3, 5]
oddCount(15) //=> 7, i.e [1, 3, 5, 7, 9, 11, 13]

Expect large Inputs!

*/

func oddCount(_ n: Int) -> Int {
    return n / 2
}

assert(oddCount(7) == 3)
assert(oddCount(15) == 7)
assert(oddCount(15023) == 7511)
