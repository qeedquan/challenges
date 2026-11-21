/*

Get the number n (n>0) to return the reversed sequence from n to 1.

Example : n=5 >> [5,4,3,2,1]

*/

func reverse(_ n: Int) -> [Int] {
    var r: [Int] = []
    for i in (1...n).reversed() {
        r.append(i)
    }
    return r
}

assert(reverse(5) == [5, 4, 3, 2, 1])
