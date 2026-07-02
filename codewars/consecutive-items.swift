/*

You are given a list of unique integers arr, and two integers a and b. Your task is to find out whether or not a and b appear consecutively in arr, and return a boolean value (true if a and b are consecutive, false otherwise).

It is guaranteed that a and b are both present in arr.

*/

func consecutive(_ arr: [Int], _ a: Int, _ b: Int) -> Bool {
    for i in 0..<arr.count - 1 {
        if arr[i] == a && arr[i + 1] == b {
            return true
        }
        if arr[i] == b && arr[i + 1] == a {
            return true
        }
    }
    return false
}

assert(consecutive([1, 3, 5, 7], 3, 7) == false)
assert(consecutive([1, 3, 5, 7], 3, 1) == true)
assert(consecutive([1, 6, 9, -3, 4, -78, 0], -3, 4) == true)
assert(consecutive([1, 2, 3, 4, 5, 6, 7, 8, 9], 2, 8) == false)
assert(consecutive([1, 2, 3, 4, 5, 6, 7, 8, 9], 2, 3) == true)
assert(consecutive([1, 4, 5, 3, 2, 7, 6, 23, 76, 11, 0], 2, 3) == true)
assert(consecutive([1, -4, -5, 3, -2, 11, 23, -76, 6, -7, 2], 2, 3) == false)
assert(consecutive([1, 2, 3, 4, 5], 1, 5) == false)
assert(consecutive([1, 2, 3, 4, 5], 5, 1) == false)
