/*

Take an array of pairs [L, R]. Count the number of unique intersecting pairs.

A pair [L1, R1] intersects with the pair [L2, R2] if L1 <= L2 <= R1 or L2 <= L1 <= R2. L is guaranteed to be <= R for a single pair.

You may write a full program or a function. Input is the array in any reasonable form. The array is not guaranteed to be sorted.

Sample test:

1 2
5 6
1 5
4 7
Output:

4
[1, 2] intersects with [1, 5]. +1

[1, 5] intersects with [5, 6] and [4, 7]. +2 (already counted [1, 2])

[4, 7] intersects with [5, 6]. +1 (already counted the others)

This is code-golf, so shortest code wins! (In bytes.)

*/

func overlap(_ X: [Int], _ Y: [Int]) -> Bool {
    let (L1, R1) = (X[0], X[1])
    let (L2, R2) = (Y[0], Y[1])
    return (L1 <= L2 && L2 <= R1) || (L2 <= L1 && L1 <= R2)
}

func intersections(_ L: [[Int]]) -> Int {
    var c = 0
    let n = L.count
    for i in 0..<n {
        for j in i + 1..<n {
            if overlap(L[i], L[j]) {
                c += 1
            }
        }
    }
    return c
}

assert(intersections([[1, 2], [5, 6], [1, 5], [4, 7]]) == 4)
