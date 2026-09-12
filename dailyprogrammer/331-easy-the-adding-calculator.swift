/*

Description
Make a calculator that lets the user add, subtract, multiply and divide integers.
It should allow exponents too. The user can only enter integers and must expect the result to be integers.
The twist is that YOU, the programmer, can only let the program calculate expressions using addition.
Only addition. The user can enter 3*2 however you cannot calculate it using multiplication.

Basically, the programmer is not allowed to multiply, divide and subtract using the operations provided by a programming language.
To the programmer, the only accessible direct operation is addition.

Your calculator should be able to handle addition, subtraction, division, multiplication and exponents.
No modulo operation (to obtain the remainder for two given operands) too.

Please note that

You are not allowed to use any functions (other than user-defined functions) to work with exponents.
Basically, don't cheat by allowing pre-defined functions from a library for the dirty work.

You can use logical operators.

The only binary arithmetic operator that you can use is + (addition).

The only unary operator that you can use is ++ (increment operator).

No bitwise operations are allowed.

Input description
Allow the user to enter two integers and the operation symbol.

Let's use ^ for exponents i.e. 2^3 = 23 = 8

Output description
If the answer is an integer, display the answer. If the answer is not an integer, display a warning message. Handle errors like 1/0 appropriately.

Challenge Inputs and Outputs
Input	Output
12 + 25	37
-30 + 100	70
100 - 30	70
100 - -30	130
-25 - 29	-54
-41 - -10	-31
9 * 3	27
9 * -4	-36
-4 * 8	-32
-12 * -9	108
100 / 2	50
75 / -3	-25
-75 / 3	-25
7 / 3	Non-integral answer
0 / 0	Not-defined
5 ^ 3	125
-5 ^ 3	-125
-8 ^ 3	-512
-1 ^ 1	-1
1 ^ 1	1
0 ^ 5	0
5 ^ 0	1
10 ^ -3	Non-integral answer

Bonus
Modify your program such that it works with decimals (except for ^ operation) with a minimum precision of 1 decimal place.

*/

func add(_ a: Int16, _ b: Int16) -> Int16 {
    return a + b
}

func sub(_ a: Int16, _ b: Int16) -> Int16 {
    var c = Int32(Int16.min)
    while Int32(b) + c != 0 {
        c += 1
    }
    return a + Int16(c)
}

func mul(_ a: Int16, _ b: Int16) -> Int16 {
    if a > 0 && b < 0 {
        return mul(b, a)
    }
    if a < 0 && b < 0 {
        return mul(sub(0, a), sub(0, b))
    }

    var r: Int16 = 0
    for _ in 0..<b {
        r = add(r, a)
    }
    return r
}

func div(_ a: Int16, _ b: Int16) -> Int16 {
    if a == 0 {
        return 0
    }
    if b == 0 {
        return -1
    }

    if a < 0 && b > 0 {
        return sub(0, div(sub(0, a), b))
    }
    if a > 0 && b < 0 {
        return sub(0, div(a, sub(0, b)))
    }
    if a < 0 && b < 0 {
        return div(sub(0, a), sub(0, b))
    }

    var (a, n) = (a, Int16(0))
    while true {
        a = sub(a, b)
        if a == 0 {
            return n + 1
        }
        if a < 0 {
            return -1
        }
        n += 1
    }
}

func exp(_ a: Int16, _ b: Int16) -> Int16 {
    var r = Int16(1)
    for _ in 0..<b {
        r = mul(r, a)
    }
    return r
}

assert(add(12, 25) == 37)
assert(add(-30, 100) == 70)
assert(sub(100, 30) == 70)
assert(sub(100, -30) == 130)
assert(sub(-25, 29) == -54)
assert(sub(-41, -10) == -31)
assert(mul(9, 3) == 27)
assert(mul(9, -4) == -36)
assert(mul(-4, 8) == -32)
assert(mul(-12, -9) == 108)
assert(div(100, 2) == 50)
assert(div(75, -3) == -25)
assert(div(-75, 3) == -25)
assert(exp(5, 3) == 125)
assert(exp(-5, 3) == -125)
assert(exp(-8, 3) == -512)
assert(exp(-1, 1) == -1)
assert(exp(1, 1) == 1)
assert(exp(0, 5) == 0)
assert(exp(5, 0) == 1)
