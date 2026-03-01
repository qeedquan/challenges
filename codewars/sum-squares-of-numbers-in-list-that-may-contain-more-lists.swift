/*

Write a function that sums squares of numbers in list that may contain more lists
Example:

var l = [1,2,3]
SumSquares(l) == 14

var l = [[1,2],3]
SumSquares(l) == 14

var l = [[[[[[[[[1]]]]]]]]]
SumSquares(l) == 1

var l = [10,[[10],10],[10]]
SumSquares(l) == 400

Note: your solution must NOT modify the original list

*/

func sumsquares(_ l: Any) -> Int {
    var r = 0
    switch l {
    case let x as Int:
        r += x * x
    case let x as [Any]:
        for v in x {
            r += sumsquares(v)
        }
    default:
        break
    }
    return r
}

assert(sumsquares([1, 2, 3]) == 14)
assert(sumsquares([[1, 2], 3]) == 14)
assert(sumsquares([[[[[[[[[1]]]]]]]]]) == 1)
assert(sumsquares([10, [[10], 10], [10]]) == 400)
