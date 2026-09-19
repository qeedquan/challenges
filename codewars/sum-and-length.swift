/*

Sum and Length
In this kata you must return a string value, where the first part is the sum of positive numbers and the second part is the number of negative numbers.
Knowing that the first '0' is negative, the second is positive, the third is negative, and so on...


For example :
sumLength([-1,2,3,4,0,1,0,-2,0,-3])
return '10 5' (10 = 1 + 2 + 3 + 4 and 5 = 3 + 2 => 3 negatives numbers + second 0 as negative)

*/

func sumLength(_ array: [Int]) -> String {
    var zero = 0
    var result = [0, 0]
    for value in array {
        if value > 0 {
            result[0] += value
        } else if value < 0 {
            result[1] += 1
        } else {
            zero ^= 1
            result[zero] += (zero & 1)
        }
    }
    return "\(result[0]) \(result[1])"
}

assert(sumLength([1, 2, 3, 4, -1, -2, -3]) == "10 3")
assert(sumLength([1, 2, 3, 4, 0, -1, -2, -3]) == "10 4")
assert(sumLength([-1, 2, 3, 4, 0, 1, 0, -2, 0, -3]) == "10 5")
assert(sumLength([-1, -2, -3, -4, 0, -1, 0, -2, 0, -3]) == "0 9")
assert(sumLength([1, 2, 3, 4, 1, 2, 3]) == "16 0")
assert(sumLength([0, 0, 0, 0, 0, 0, 0]) == "0 4")
assert(sumLength([]) == "0 0")
