/*

In this kata, you should determine the values in an unknown array of numbers. You'll be given a function f, which you can call like this:

f(a, b);
where a and b are indexes of two different elements in the unknown array, 1 or 2 indexes apart. f will return the sum of those two elements.

The absolute difference between a and b must not be 0 nor greater than 2 (that is: the chosen indexes must be exactly 1 or 2 apart).

Your goal is to figure out the correct array.

The whole procedure is:

You are given f and the length of the array n.
Ask f for any element sums you want.
Create and return the correct array according to the answers.
The array will always have at least 3 elements.

Don't forget to give upvotes and feedbacks!

*/

func guess(_ f: (Int, Int) -> Double, _ n: Int) -> [Double] {
    let x01 = f(0, 1)
    let x12 = f(1, 2)
    let x02 = f(0, 2)

    var x: [Double] = []
    x.append((x01 + x02 - x12) / 2)
    x.append(x01 - x[0])
    x.append(x12 - x[1])
    for i in 3..<n {
        x.append(f(i - 1, i) - x[i - 1])
    }
    return x
}
