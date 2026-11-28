/*

And here is Fibonacci again. This time we want to go one step further. Our fib() function must be faster! Can you do it?

In case you don't know, what the Fibonacci number is:

The nth Fibonacci number is defined by the sum of the two previous Fibonacci numbers. In our case: fib(1) := 0 and fib(2) := 1. With these initial values you should be able to calculate each following Fibonacci number.

Examples:

fib(1) // === 0
fib(2) // === 1
fib(3) // === 1
fib(4) // === 2
fib(5) // === 3

*/

import Foundation

func fib(_ n: Int) -> Int {
    if n < 0 {
        return 0
    }

    let x0 = (1.0 + sqrt(5)) / 2.0
    let x1 = pow(x0, Double(n) - 1)
    let x2 = round(x1 / sqrt(5))
    return Int(x2)
}

for i in 1..<20 {
    print(fib(i))
}
