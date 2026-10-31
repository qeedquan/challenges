/*

In many fonts (specifically in the Consolas font), 5 out of the 10 decimal digits have "holes" in them. We will call these holy digits:

46890
The 5 unholy digits are thus:

12357
An integer may thus be classified as "holy" if it only contains holy digits, and "unholy" otherwise. Because - is unholy, no negative integers can be holy.

Holy integers may be further classified based on how many holes they have. For example, the following digits have a holiness of 1:

469
And these digits have a holiness of 2:

80
We say that the overall holiness of an integer is the sum of the holiness of its digits. Therefore, 80 would have a holiness of 4, and 99 would have a holiness of 2.

The Challenge
Given two integers n > 0 and h > 0, output the nth holy integer whose holiness is at least h. You may assume that the inputs and outputs will be no greater than the maximum representable integer in your language or 2^64 - 1, whichever is less.

Here is a list of the first 25 holy integers with holiness h >= 1, for reference:

0, 4, 6, 8, 9, 40, 44, 46, 48, 49, 60, 64, 66, 68, 69, 80, 84, 86, 88, 89, 90, 94, 96, 98, 99
The first 25 holy integers with holiness h >= 2 are:

0, 8, 40, 44, 46, 48, 49, 60, 64, 66, 68, 69, 80, 84, 86, 88, 89, 90, 94, 96, 98, 99, 400, 404, 406

*/

fn main() {
    assert_eq!(
        gen(25, 1),
        vec![
            0, 4, 6, 8, 9, 40, 44, 46, 48, 49, 60, 64, 66, 68, 69, 80, 84, 86, 88, 89, 90, 94, 96,
            98, 99
        ]
    );
    assert_eq!(
        gen(25, 2),
        vec![
            0, 8, 40, 44, 46, 48, 49, 60, 64, 66, 68, 69, 80, 84, 86, 88, 89, 90, 94, 96, 98, 99,
            400, 404, 406
        ]
    );
}

fn gen(n: usize, h: usize) -> Vec<usize> {
    let mut r = vec![];
    let mut i = 0;
    while r.len() < n && i < usize::MAX {
        if holiness(i) >= h {
            r.push(i);
        }
        i += 1;
    }
    return r;
}

fn holiness(mut n: usize) -> usize {
    let tab = vec![2, 0, 0, 0, 1, 0, 1, 0, 2, 1];

    let mut r = 0;
    loop {
        let h = tab[n % 10];
        if h == 0 {
            return 0;
        }

        r += h;
        n /= 10;
        if n == 0 {
            break;
        }
    }
    return r;
}
