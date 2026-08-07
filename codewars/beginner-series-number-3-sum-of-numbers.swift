/*

Given two integers a and b, which can be positive or negative, find the sum of all the numbers between including them too and return it. If the two numbers are equal return a or b.

**Note:** a and b are not ordered!

## Examples


GetSum(1, 0) == 1   // 1 + 0 = 1
GetSum(1, 2) == 3   // 1 + 2 = 3
GetSum(0, 1) == 1   // 0 + 1 = 1
GetSum(1, 1) == 1   // 1 Since both are same
GetSum(-1, 0) == -1 // -1 + 0 = -1
GetSum(-1, 2) == 2  // -1 + 0 + 1 + 2 = 2

*/

func getsum(_ a: Int, _ b: Int) -> Int {
    return (a + b) * (abs(a - b) + 1) / 2
}

assert(getsum(0, -1) == -1)
assert(getsum(0, 1) == 1)
assert(getsum(1, 0) == 1)
assert(getsum(1, 2) == 3)
assert(getsum(0, 1) == 1)
assert(getsum(1, 1) == 1)
assert(getsum(-1, 0) == -1)
assert(getsum(-1, 2) == 2)
