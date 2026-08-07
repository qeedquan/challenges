/*

There have been a few square root challenges lately, but I think this one is different.

Challenge
Find an algorithm such that the worst case time complexity is proportional to n^2 and the best case is proportional to n where n is the size of the algorithm input. Given a value x, find the approximate square root of x by running the chosen algorithm with some number of inputs (to be decided in code) arranged to give worst case performance; rearrange the algorithm input values to give best case performance, which will approximate the square root of the worst case run time.

Psuedocode example to help explain the challenge:

input target is 9 // find square root of 9
// target time is then 9000 ms

do
{
    create array with 10000 elements
    populate array in reverse order (array[0] = 10000; array[1] = 9999; etc)
    time how long it takes to bubble sort array
    if (time to sort > 9000 ms + margin of error)
    {
        sorting took too long; decrease array size
    }
    else if (time to sort < 9000 ms - margin of error)
    {
        sorting didn't take long enough; increase array size
    }
} while (run time is outside of 9000 ms +/- margin of error)

// the number of elements it takes to sort in n^2 time is now known
create array with correct number of elements
fill array with zeros
return the amount of time it takes to bubble sort

Implementing the above in C as a rough prototype takes 110 seconds to determine the square root of 9 is 3.781.

Rules
Input is read from stdin, file, hard-coded, wherever, as long as any positive integer can be used for input, and the program will approximate the square root. For hard-coded values, changing the input constant should be the only change needed to approximate another square root.
An algorithm must be used and must have worst case time complexity of n^2 and best case time complexity of n.
When changing form worst case to best case run time, the number of inputs must be the same.
I'm assuming that measuring run time will actually be difficult and probably slightly inaccurate. Additionally, time complexity does not mean that run time is exactly equivalent to input size, therefore the answer only needs to be accurate to within +/- 25% of the actual square root. Bonus points for improved accuracy.
Any built in math functions are available for use, but the actual square root calculation must come from measuring the best case run time. That is, calculating the square root of the input and then searching for a best case run time equivalent to the square root is allowed, but somewhat discouraged. The spirit of the challenge is to find the square root by measuring worst case run times.
Program run time must be "reasonable," say, less than an hour.

*/

fn main() {
    for i in 0..101 {
        println!("{} -> {}", i, isqrt(i));
    }
}

/*

@Gerwin

It is O(n) for a = 0xFFFF..., and O(n^2) for a = 0x1000... And it returns floor(sqrt(x)), which is an approximation of sqrt(x)

*/

fn isqrt(a: isize) -> isize {
    let mut b = 0;
    let mut i = 1 << ((isize::BITS - 1) >> 1);
    while i > 0 {
        if (b + i) * (b + i) <= a {
            b += i;
        } else {
            let mut j = 1;
            while j < i {
                j <<= 1;
            }
        }

        i >>= 1;
    }
    b
}
