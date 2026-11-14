/*

Task
You draw 2 cards from a standard 52-card deck without replacing them. What is the probability that both cards are of the same suit?

*/

fn main() {
    println!("{:?}", solve());
}

/*

First card has the probability of 13/52
Second card has the probability of 12/51 since we drew without replacement
There are 4 suits so:

13/52 * 12/51 * 4 = 12/51 = 4/17

*/

fn solve() -> (isize, isize) {
    let suits = vec!['C', 'D', 'H', 'S'];
    let cards = vec![
        '2', '3', '4', '5', '6', '7', '8', '9', 'X', 'J', 'Q', 'K', 'A',
    ];

    let (mut p, mut t) = (0, 0);
    for s0 in &suits {
        for c0 in &cards {
            for s1 in &suits {
                for c1 in &cards {
                    if *s0 == *s1 && *c0 != *c1 {
                        p += 1;
                    }
                    if *s0 != *s1 || *c0 != *c1 {
                        t += 1;
                    }
                }
            }
        }
    }
    let l = gcd(p, t);
    (p / l, t / l)
}

fn gcd(mut a: isize, mut b: isize) -> isize {
    while b != 0 {
        (a, b) = (b, a % b);
    }
    a
}
