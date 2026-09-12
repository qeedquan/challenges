/*

You will have a list of rationals in the form

lst = [ [numer_1, denom_1] , ... , [numer_n, denom_n] ]
or

lst = [ (numer_1, denom_1) , ... , (numer_n, denom_n) ]
where all numbers are positive integers. You have to produce their sum N / D in an irreducible form: this means that N and D have only 1 as a common divisor.

Return the result in the form:

[N, D] in Ruby, Crystal, Python, Clojure, JS, CS, PHP, Julia, Pascal
Just "N D" in Haskell, PureScript
"[N, D]" in Java, CSharp, TS, Scala, PowerShell, Kotlin
"N/D" in Go, Nim
{N, D} in C, C++, Elixir, Lua
Some((N, D)) in Rust
Some "N D" in F#, Ocaml
c(N, D) in R
(N, D) in Swift
'(N D) in Racket
If the result is an integer (D evenly divides N) return:

an integer in Ruby, Crystal, Elixir, Clojure, Python, JS, CS, PHP, R, Julia
Just "n" (Haskell, PureScript)
"n" Java, CSharp, TS, Scala, PowerShell, Go, Nim, Kotlin
{n, 1} in C, C++, Lua
Some((n, 1)) in Rust
Some "n" in F#, Ocaml,
(n, 1) in Swift
n in Racket
(n, 1) in Swift, Pascal, Perl
If the input list is empty, return

nil/None/null/Nothing
{0, 1} in C, C++, Lua
"0" in Scala, PowerShell, Go, Nim
O in Racket
"" in Kotlin
[0, 1] in C++, "[0, 1]" in Pascal
[0, 1] in Perl
Example:
[ [1, 2], [1, 3], [1, 4] ]  -->  [13, 12]
1/2  +  1/3  +  1/4     =      13/12

Note
See sample tests for more examples and form of results.

*/

fn main() {
    assert_eq!(
        sum_fractions(&[[1, 2], [2, 9], [3, 18], [4, 24], [6, 48]]),
        (85, 72),
    );
    assert_eq!(sum_fractions(&[[1, 2], [1, 3], [1, 4]]), (13, 12));
    assert_eq!(sum_fractions(&[[1, 3], [5, 3]]), (2, 1));
    assert_eq!(sum_fractions(&[]), (0, 1));
}

fn sum_fractions(f: &[[isize; 2]]) -> (isize, isize) {
    let (mut n, mut d) = (0, 1);
    for &[x, y] in f {
        (n, d) = ((n * y) + (x * d), (d * y));
        if n != 0 && d != 0 {
            let m = gcd(n, d);
            (n, d) = (n / m, d / m);
        }
    }
    (n, d)
}

fn gcd(mut n: isize, mut m: isize) -> isize {
    while m != 0 {
        if m < n {
            (m, n) = (n, m);
        }
        m %= n;
    }
    n
}
