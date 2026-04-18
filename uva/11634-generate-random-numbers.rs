/*

John von Neumann suggested in 1946 a method to create a sequence of pseudo-random numbers. His
idea is known as the “middle-square”-method and works as follows: We choose an initial value a0, which
has a decimal representation of length at most n. We then multiply the value a0 by itself, add leading
zeros until we get a decimal representation of length 2×n and take the middle n digits to form ai. This
process is repeated for each ai with i > 0. In this problem we use n = 4.
Example 1: a0 = 5555, a
2
0 = 30858025, a1 = 8580, ...
Example 2: a0 = 1111, a
2
0 = 01234321, a1 = 2343,...
Unfortunately, this random number generator is not very good. When started with an initial value
it does not produce all other numbers with the same number of digits.
Your task is to check for a given initial value a0 how many different numbers are produced.

Input
The input contains several test cases. Each test case consists of one line containing a0 (0 < a0 < 10000).
Numbers are possibly padded with leading zeros such that each number consists of exactly 4 digits.
The input is terminated with a line containing the value ‘0’.

Output
For each test case, print a line containing the number of different values ai produced by this random
number generator when started with the given value a0. Note that a0 should also be counted.
Note that the third test case has the maximum number of different values among all possible inputs.

Sample Input
5555
0815
6239
0

Sample Output
32
17
111

*/

fn main() {
    assert_eq!(cycle(5555), 32);
    assert_eq!(cycle(815), 17);
    assert_eq!(cycle(6239), 111);
}

fn cycle(seed: isize) -> isize {
    let mut count = 1;
    let mut slow = seed;
    let mut fast = seed;
    loop {
        slow = f(slow);
        fast = f(f(fast));
        if slow == fast {
            break;
        }
    }

    slow = seed;
    while slow != fast {
        slow = f(slow);
        fast = f(fast);
        count += 1;
    }

    slow = f(fast);
    while slow != fast {
        count += 1;
        slow = f(slow);
    }

    count
}

fn f(x: isize) -> isize {
    return (x * x / 100) % 10000;
}
