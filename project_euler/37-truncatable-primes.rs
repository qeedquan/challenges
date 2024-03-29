/*

The number 3797 has an interesting property.
Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7.
Similarly we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.

*/

fn main() {
    println!("{}", solve());
}

// https://oeis.org/A020994
fn solve() -> isize {
    let tab = [
        2, 3, 5, 7, 23, 37, 53, 73, 313, 317, 373, 797, 3137, 3797, 739397,
    ];
    
    tab[4..].iter().sum()
}
