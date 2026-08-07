/*

Complete the function that takes two numbers as input, num and nth and return the nth digit of num (counting from right to left).

Note
If num is negative, ignore its sign and treat it as a positive value
If nth is not positive, return -1
Keep in mind that 42 = 00042. This means that findDigit(42, 5) would return 0

Examples(num, nth --> output)

5673, 4 --> 5
129, 2 --> 2
-2825, 3 --> 8
-456, 4 --> 0
0, 20 --> 0
65, 0 --> -1
24, -8 --> -1

*/

func findDigit(_ num: Int, _ nth: Int) -> Int {
    if nth < 1 {
        return -1
    }

    var num = abs(num)
    var cnt = 0
    while num > 0 {
        cnt += 1
        if cnt >= nth {
            break
        }
        num /= 10
    }
    return num % 10
}

assert(findDigit(5673, 4) == 5)
assert(findDigit(129, 2) == 2)
assert(findDigit(-2825, 3) == 8)
assert(findDigit(-456, 4) == 0)
assert(findDigit(0, 20) == 0)
assert(findDigit(65, 0) == -1)
assert(findDigit(24, -8) == -1)
assert(findDigit(42, 5) == 0)
