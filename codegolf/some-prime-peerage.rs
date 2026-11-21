/*

(Randomly inspired by https://mathoverflow.net/q/339890)
(Related: 1, 2)

Given an input list of distinct prime numbers (e.g., [2, 5, 7]), and a integer n, output all positive integers strictly smaller than n that contain only those primes as divisors. For input [2, 5, 7] and n=15 this means an output of [2, 4, 5, 7, 8, 10, 14].

Further Examples

[list] n | output

[2, 5, 7] 15 | [2, 4, 5, 7, 8, 10, 14]
[2, 5, 7] 14 | [2, 4, 5, 7, 8, 10]
[2] 3 | [2]
[2] 9 | [2, 4, 8]
[103, 101, 97] 10000 | [97, 101, 103, 9409, 9797, 9991]
[97, 101, 103] 104 | [97, 101, 103]
Rules and Clarifications

The input list is guaranteed non-empty, but may be only a single element
You can assume the input list is pre-sorted in whatever way is most convenient
n will always be larger than the largest element in the input list
Since, e.g., 2**0 = 1, you can optionally include 1 in your output list
Input and output can be given by any convenient method
You can print the result to STDOUT or return it as a function result
Either a full program or a function are acceptable
If applicable, you can assume the input/output integers fit in your language's native int range
Standard loopholes are forbidden
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins

*/

fn main() {
    assert_eq!(prime_peerage(&[2, 5, 7], 15), vec![2, 4, 5, 7, 8, 10, 14]);
    assert_eq!(prime_peerage(&[2, 5, 7], 14), vec![2, 4, 5, 7, 8, 10]);
    assert_eq!(prime_peerage(&[2], 3), vec![2]);
    assert_eq!(prime_peerage(&[2], 9), vec![2, 4, 8]);
    assert_eq!(
        prime_peerage(&[103, 101, 97], 10000),
        vec![97, 101, 103, 9409, 9797, 9991]
    );
    assert_eq!(prime_peerage(&[97, 101, 103], 104), vec![97, 101, 103]);
}

fn prime_peerage(primes: &[usize], limit: usize) -> Vec<usize> {
    let mut result = vec![];
    for number in 2..limit {
        if check(primes, number) {
            result.push(number);
        }
    }
    return result;
}

fn check(primes: &[usize], mut number: usize) -> bool {
    for prime in primes {
        while number % prime == 0 {
            number /= prime;
        }
        if number == 1 {
            return true;
        }
    }
    return false;
}
