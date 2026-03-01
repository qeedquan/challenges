/*

Objective
Given a number n we will define it's sXORe to be 0 XOR 1 XOR 2 ... XOR n where XOR is the bitwise XOR operator ( https://en.wikipedia.org/wiki/Bitwise_operation#XOR ).

Write a function that takes n and returns it's sXORe.

Examples
n                     sXORe n
0                     0
1                     1
50                  51
1000000         1000000

*/

func sxore(_ n: Int) -> Int {
    if n < 0 {
        return 0
    }

    switch n & 3 {
    case 0:
        return n
    case 1:
        return 1
    case 2:
        return n + 1
    default:
        return 0
    }
}

func sxorebf(_ n: Int) -> Int {
    if n < 0 {
        return 0
    }

    var r = 0
    for i in 0...n {
        r ^= i
    }
    return r
}

assert(sxore(0) == 0)
assert(sxore(1) == 1)
assert(sxore(50) == 51)
assert(sxore(1_000_000) == 1_000_000)

for i in -100...100000 {
    assert(sxore(i) == sxorebf(i))
}
