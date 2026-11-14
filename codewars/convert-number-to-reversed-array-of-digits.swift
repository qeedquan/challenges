/*

Given a random non-negative number, you have to return the digits of this number within an array in reverse order.

Example:
348597 => [7,9,5,8,4,3]

*/

func digitize(_ n: UInt) -> [UInt] {
    var r: [UInt] = []
    var x = n
    while true {
        r.append(x % 10)
        x /= 10
        if x == 0 {
            break
        }
    }
    return r
}

assert(digitize(348597) == [7, 9, 5, 8, 4, 3])
