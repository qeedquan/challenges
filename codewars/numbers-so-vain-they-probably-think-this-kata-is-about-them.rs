/*

Well, those numbers were right and we're going to feed their ego.

Write a function, isNarcissistic, that takes in any amount of numbers and returns true if all the numbers are narcissistic. Return false for invalid arguments (numbers passed in as strings are ok).

For more information about narcissistic numbers (and believe me, they love it when you read about them) follow this link: https://en.wikipedia.org/wiki/Narcissistic_number

*/

fn main() {
    assert_eq!(is_narcissistic(&vec![0, 1, 2, 3, 4, 5, 6, 7, 8, 9]), true);
}

fn is_narcissistic(x: &Vec<usize>) -> bool {
    for &v in x {
        if !narcissistic(v) {
            return false;
        }
    }
    return true;
}

fn digits(mut n: usize) -> Vec<usize> {
    let mut d = vec![];
    while n > 0 {
        d.push(n % 10);
        n /= 10;
    }
    d
}

// https://oeis.org/A005188
fn narcissistic(n: usize) -> bool {
    if n == 0 {
        return true;
    }

    let (mut r, d) = (0, digits(n));
    for x in &d {
        r += x.pow(d.len() as u32);
    }
    return r == n;
}
