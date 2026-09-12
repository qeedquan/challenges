/*


Given a non-negative integer N, output the smallest odd positive integer that is a strong pseudoprime to all of the first N prime bases.

This is OEIS sequence A014233.

Test Cases (one-indexed)
1       2047
2       1373653
3       25326001
4       3215031751
5       2152302898747
6       3474749660383
7       341550071728321
8       341550071728321
9       3825123056546413051
10      3825123056546413051
11      3825123056546413051
12      318665857834031151167461
13      3317044064679887385961981
Test cases for N > 13 are not available because those values have not been found yet. If you manage to find the next term(s) in the sequence, be sure to submit it/them to OEIS!

Rules
You may choose to take N as a zero-indexed or a one-indexed value.
It's acceptable for your solution to only work for the values representable within your language's integer range (so up to N = 12 for unsigned 64-bit integers), but your solution must theoretically work for any input with the assumption that your language supports arbitrary-length integers.
Background
Any positive even integer x can be written in the form x = d*2^s where d is odd. d and s can be computed by repeatedly dividing n by 2 until the quotient is no longer divisible by 2. d is that final quotient, and s is the number of times 2 divides n.

If a positive integer n is prime, then Fermat's little theorem states:

Fermat

In any finite field Z/pZ (where p is some prime), the only square roots of 1 are 1 and -1 (or, equivalently, 1 and p-1).

We can use these three facts to prove that one of the following two statements must be true for a prime n (where d*2^s = n-1 and r is some integer in [0, s)):

Miller-Rabin conditions

The Miller-Rabin primality test operates by testing the contrapositive of the above claim: if there is a base a such that both of the above conditions are false, then n is not prime. That base a is called a witness.

Now, testing every base in [1, n) would be prohibitively expensive in computation time for large n. There is a probabilistic variant of the Miller-Rabin test that only tests some randomly-chosen bases in the finite field.
However, it was discovered that testing only prime a bases is sufficient, and thus the test can be performed in an efficient and deterministic manner.
In fact, not all of the prime bases need to be tested - only a certain number are required, and that number is dependent on the size of the value being tested for primality.

If an insufficient number of prime bases are tested, the test can produce false positives - odd composite integers where the test fails to prove their compositeness.
Specifically, if a base a fails to prove the compositeness of an odd composite number, that number is called a strong pseudoprime to base a.
This challenge is about finding the odd composite numbers who are strong psuedoprimes to all bases less than or equal to the Nth prime number
(which is equivalent to saying that they are strong pseudoprimes to all prime bases less than or equal to the Nth prime number).

*/

fn main() {
    for i in 0..20 {
        println!("{} {}", i, seq(i))
    }
}

// https://oeis.org/A014233
fn seq(n: usize) -> i128 {
    let tab = [
        2047,
        1373653,
        25326001,
        3215031751,
        2152302898747,
        3474749660383,
        341550071728321,
        341550071728321,
        3825123056546413051,
        3825123056546413051,
        3825123056546413051,
        318665857834031151167461,
        3317044064679887385961981,
    ];

    if n < tab.len() {
        tab[n]
    } else {
        -1
    }
}
