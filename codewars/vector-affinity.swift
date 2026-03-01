/*

Calculate the number of items in a vector that appear at the same index in each vector, with the same value.

```
 ([1 2 3 4 5], [1 2 2 4 3]) => 0.6
 ([1 2 3], [1 2 3]) => 1.0
```

Affinity value should be realized on a scale of 0.0 to 1.0, with 1.0 being absolutely identical. Two identical sets should always be
evaluated as having an affinity of 1.0.

Hint: The last example test case holds a significant clue to calculating the affinity correctly.

*/

func affinity(_ a: [Int], _ b: [Int]) -> Double {
    let n = min(a.count, b.count)
    let m = max(a.count, b.count)
    var c = 0.0
    for i in 0..<n {
        if a[i] == b[i] {
            c += 1
        }
    }
    return c / Double(m)
}

print(affinity([0], [0]))
print(affinity([1, 2, 3, 4, 5], [1, 2, 2, 4, 3]))
print(affinity([1, 2, 3], [1, 2, 3]))
print(affinity([1, 2, 3], [1, 2, 3, 4, 5]))
print(affinity([1, 2, 3, 4], [1, 2, 3, 5]))
print(affinity([6, 6, 6, 6, 6, 6], [6]))
