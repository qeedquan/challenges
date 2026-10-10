/*

The function 'fibonacci' should return an array of fibonacci numbers. The function takes a number as an argument to decide how many no. of elements to produce. If the argument is less than or equal to 0 then return empty array

Example:

fibonacci(4) // should return  [0,1,1,2]
fibonacci(-1) // should return []

*/

func fibonacci(_ n: Int) -> [Int] {
    if n < 1 {
        return []
    }
    if n == 1 {
        return [0]
    }

    var r = [0, 1]
    for i in 2..<n {
        r.append(r[i - 1] + r[i - 2])
    }
    return r
}

assert(fibonacci(4) == [0, 1, 1, 2])
assert(fibonacci(-1) == [])
