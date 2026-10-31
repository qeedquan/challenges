/*

Given a positive input n>0, output the amout of two types based on their rarity. The two types are called A and B, we know the followings:

n is a limited input and the maximum is nmax
At the start B is twice as rare as A
As the presence of A increase the rarity of B decreases
When n = nmax, A will be equal to B
When n is not nmax, A cannot be equal to B
The value of A and B cannot be decimal.

Example
nmax = 10

n = 1, output = [1A, 0B]
n = 2, output = [2A, 0B]
n = 3, output = [2A, 1B]
n = 4, output = [3A, 1B]
n = 5, output = [3A, 2B]
n = 6, output = [4A, 2B]
n = 7, output = [4A, 3B]
n = 8, output = [5A, 3B]
n = 9, output = [5A, 4B]
n = 10, output = [5A, 5B]

Shortest code win.

*/

fn main() {
    let nmax = 10;
    assert_eq!(rarity(nmax, 1), (1, 0));
    assert_eq!(rarity(nmax, 2), (2, 0));
    assert_eq!(rarity(nmax, 3), (2, 1));
    assert_eq!(rarity(nmax, 4), (3, 1));
    assert_eq!(rarity(nmax, 5), (3, 2));
    assert_eq!(rarity(nmax, 6), (4, 2));
    assert_eq!(rarity(nmax, 7), (4, 3));
    assert_eq!(rarity(nmax, 8), (5, 3));
    assert_eq!(rarity(nmax, 9), (5, 4));
    assert_eq!(rarity(nmax, 10), (5, 5));
}

fn rarity(nmax: isize, n: isize) -> (isize, isize) {
    let m = n / 2 + truth(n < nmax);
    (m, n - m)
}

fn truth(x: bool) -> isize {
    if x {
        1
    } else {
        0
    }
}
