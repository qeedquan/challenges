/*

Description:
Give you an array arr that contains some numbers(arr.length>=2), and give you a positive integer k. Find such two numbers m,n: m and n at least a difference of k, and their index is the most distant.

Returns their distance of index. If no such number found, return -1.

Some Examples
furthestDistance([8,7,1,9],5) === 2

The difference of 8 and 1, 1 and 9 is more than 5;
The index distance of (8,1) is 2;
The index distance of (1,9) is 1;
So 2 is the furthest distance of index.

furthestDistance([8,7,1,9],100) === -1
furthestDistance([1,2,3,4],1) === 3 (1 and 4)
furthestDistance([3,4,1,2],2) === 2 (3 and 1 or 4 and 2)

*/

func furthest(_ a: [Int], _ k: Int) -> Int {
    var d = -1
    let n = a.count
    for i in 0..<n {
        for j in i + 1..<n {
            if abs(a[i] - a[j]) >= k {
                d = max(d, j - i)
            }
        }
    }
    return d
}

assert(furthest([8, 7, 1, 9], 5) == 2)
assert(furthest([8, 7, 1, 9], 100) == -1)
assert(furthest([1, 2, 3, 4], 1) == 3)
assert(furthest([3, 4, 1, 2], 2) == 2)
