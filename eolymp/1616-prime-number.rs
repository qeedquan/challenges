/*

Check if the given number is a prime number. A number is considered prime if it has exactly two divisors: 1 and the number itself.

Input
One positive signed 32-bit integer n.

Output
Print Yes if n is a prime number, and No otherwise.

Examples

Input #1
5

Answer #1
Yes

Input #2
12

Answer #2
No

*/

fn main() {
    assert_eq!(isprime(5), "Yes");
    assert_eq!(isprime(12), "No");
    assert_eq!(isprime(997), "Yes");
}

fn isprime(n: usize) -> &'static str {
    if n <= 1 {
        return "No";
    }
    if n == 2 {
        return "Yes";
    }
    if n % 2 == 0 {
        return "No";
    }

    let f = n as f64;
    let l = f.sqrt() as usize;
    for i in (3..l + 1).step_by(2) {
        if n % i == 0 {
            return "No";
        }
    }
    return "Yes";
}
