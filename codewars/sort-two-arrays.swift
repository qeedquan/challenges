/*

Description:
Give you two arrays arr1 and arr2. They have the same length(length>=2). The elements of two arrays always be integer.

Sort arr1 according to the ascending order of arr2; Sort arr2 according to the ascending order of arr1. Description is not easy to understand, for example:

arr1=[5,4,3,2,1],
arr2=[6,5,7,8,9]
Let us try to sorting arr1. First, we need know the ascending order of arr2:

[5,6,7,8,9]
We can see, after sorting arr2 to ascending order, some elements' index are changed:

unsort arr2      ascending order arr2
[6,5,7,8,9]--->      [5,6,7,8,9]

index0(6)  --->      index1
index1(5)  --->      index0
index2(7)            index2(no change)
index3(8)            index3(no change)
index4(9)            index4(no change)
So, we need to sort arr1 according to these changes:

unsort arr1          sorted arr1
[5,4,3,2,1]--->      [4,5,3,2,1]

index0(5)  --->      index1
index1(4)  --->      index0
index2(3)            index2(no change)
index3(2)            index3(no change)
index4(1)            index4(no change)

So: sorted arr1= [4,5,3,2,1]
And then, we're sorting arr2 with the same process:

unsort arr1      ascending order arr1
[5,4,3,2,1]--->      [1,2,3,4,5]

index0(5)  --->      index4
index1(4)  --->      index3
index2(3)            index2(no change)
index3(2)  --->      index1
index4(1)  --->      index0

unsort arr2          sorted arr2
[6,5,7,8,9]--->      [9,8,7,5,6]

index0(6)  --->      index4
index1(5)  --->      index3
index2(7)            index2(no change)
index3(8)  --->      index1
index4(9)  --->      index0

So: sorted arr2= [9,8,7,5,6]
Finally, return sorted arrays as a 2D array: [sorted arr1, sorted arr2]

Note: In ascending order sorting process(not the final sort), if some elements have same value, sort them according to their index; You can modify the original array, but I advise you not to do that. ;-)

Some Examples and explain
sortArrays([5,4,3,2,1],[6,5,7,8,9]) should return
[[4,5,3,2,1],[9,8,7,5,6]]

sortArrays([2,1,3,4,5],[5,6,7,8,9]) should return
[[2,1,3,4,5],[6,5,7,8,9]]

sortArrays([5,6,9,2,6,5],[3,6,7,4,8,1]) should return
[[5,5,2,6,9,6],[4,3,1,6,8,7]]

*/

import Foundation

func rank(_ array: [Int]) -> [[Int]] {
    var result = [[Int]]()
    for index in 0..<array.count {
        result.append([index, array[index]])
    }
    return result.sorted { $0[1] < $1[1] || ($0[1] == $1[1] && $0[0] < $1[0]) }
}

func sortArray(_ array1: [Int], _ array2: [Int]) -> ([Int], [Int]) {
    let rank1 = rank(array1)
    let rank2 = rank(array2)
    var result1 = [Int](repeating: 0, count: array1.count)
    var result2 = [Int](repeating: 0, count: array2.count)
    for index in 0..<array1.count {
        result1[index] = array1[rank2[index][0]]
        result2[index] = array2[rank1[index][0]]
    }
    return (result1, result2)
}

assert(sortArray([5, 4, 3, 2, 1], [6, 5, 7, 8, 9]) == ([4, 5, 3, 2, 1], [9, 8, 7, 5, 6]))
assert(sortArray([2, 1, 3, 4, 5], [5, 6, 7, 8, 9]) == ([2, 1, 3, 4, 5], [6, 5, 7, 8, 9]))
assert(sortArray([5, 6, 9, 2, 6, 5], [3, 6, 7, 4, 8, 1]) == ([5, 5, 2, 6, 9, 6], [4, 3, 1, 6, 8, 7]))
