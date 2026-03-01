/*

You need to swap the head and the tail of the specified array:

the head (the first half) of array moves to the end, the tail (the second half) moves to the start. The middle element (if it exists) leaves on the same position.

Return new array.

For example:

   [ 1, 2, 3, 4, 5 ]   =>  [ 4, 5, 3, 1, 2 ]
    \----/   \----/
     head     tail

   [ -1, 2 ]  => [ 2, -1 ]
   [ 1, 2, -3, 4, 5, 6, -7, 8 ]   =>  [ 5, 6, -7, 8, 1, 2, -3, 4 ]

*/

func swapHeadAndTail(_ array: inout [Int]) -> [Int] {
    let length = array.count
    let offset = (length / 2) + (length % 2)
    for index in 0..<length / 2 {
        (array[index], array[index + offset]) = (array[index + offset], array[index])
    }
    return array
}

var array = [1, 2, 3, 4, 5]
assert(swapHeadAndTail(&array) == [4, 5, 3, 1, 2])

array = [-1, 2]
assert(swapHeadAndTail(&array) == [2, -1])

array = [1, 2, -3, 4, 5, 6, -7, 8]
assert(swapHeadAndTail(&array) == [5, 6, -7, 8, 1, 2, -3, 4])
