/*

DESCRIPTION:

Your strict math teacher is teaching you about right triangles, and the Pythagorean Theorem: a^2 + b^2 = c^2 whereas a and b are the legs of the right triangle and c is the hypotenuse of the right triangle. On the test however, the question asks: What are the possible integer lengths for the other side of the triangle given two sides a and b, but since you never learned anything about that in class, you realize she meant What are the possible integer lengths for the other side of the right triangle given two sides a and b.

Because you want to address the fact that she asked the wrong question and the fact that you're smart at math, you've decided to answer all the possible values for the third side EXCLUDING the possibilities for a right triangle in increasing order.

EXAMPLES:

side_len(1, 1) --> [1]
side_len(3, 4) --> [2, 3, 4, 6]
side_len(4, 6) --> [3, 4, 5, 6, 7, 8, 9]

RETURN:

Return your answer as a list of all the possible third side lengths of the triangle without the right triangles in increasing order.

By the way, after finishing this kata, please try some of my other katas: Here ( https://www.codewars.com/collections/tonylicodings-authored-katas )

NOTE:

When given side_len(x, y), y will always be greater than or equal to x. Also, if a right triangle's legs are passed in, exclude the hypotenuse. If a right triangle's leg and hypotenuse are passed in, exclude the other leg.

*/

func square(_ x: Int) -> Int {
    return x * x
}

func sidelen(_ x: Int, _ y: Int) -> [Int] {
    var r: [Int] = []
    for i in 0..<(2 * x) - 1 {
        let z = i + 1 + y - x
        if square(x) + square(min(y, z)) != square(max(y, z)) {
            r.append(z)
        }
    }
    return r
}

assert(sidelen(1, 1) == [1])
assert(sidelen(3, 4) == [2, 3, 4, 6])
assert(sidelen(4, 6) == [3, 4, 5, 6, 7, 8, 9])
assert(sidelen(5, 12) == [8, 9, 10, 11, 12, 14, 15, 16])
assert(sidelen(8, 10) == [3, 4, 5, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17])
