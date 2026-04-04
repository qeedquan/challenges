/*

Surprisingly we haven't had a simple "find the highest digit" challenge yet, but I think that's a little too trivial.

Given input of a non-negative integer, return the highest unique (ie not repeated) digit found in the integer. If there are no unique digits, your program can do anything (undefined behaviour), other than the numbers that are non unique in the input of course.

The input can be taken as a single integer, a string, or a list of digits.

Test cases
12         -> 2
0          -> 0
485902     -> 9
495902     -> 5
999999     -> Anything
999099     -> 0
1948710498 -> 7
This is code-golf so fewest bytes in each language wins!

*/

fn main() {
    assert_eq!(highest_unique(12), 2);
    assert_eq!(highest_unique(0), 0);
    assert_eq!(highest_unique(485902), 9);
    assert_eq!(highest_unique(495902), 5);
    assert_eq!(highest_unique(999999), -1);
    assert_eq!(highest_unique(999099), 0);
    assert_eq!(highest_unique(1948710498), 7);
}

fn highest_unique(mut x: usize) -> isize {
    let mut d: [usize; 10] = [0; 10];
    loop {
        d[x % 10] += 1;
        x /= 10;
        if x == 0 {
            break;
        }
    }

    for i in (0..10).rev() {
        if d[i] == 1 {
            return i as isize;
        }
    }
    return -1;
}
