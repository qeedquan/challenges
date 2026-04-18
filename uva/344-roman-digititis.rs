/*

Many persons are familiar with the Roman numerals for relatively small numbers. The symbols “i”,
“v”, “x”, “l”, and “c” represent the decimal values 1, 5, 10, 50, and 100 respectively. To represent
other values, these symbols, and multiples where necessary, are concatenated, with the smaller-valued
symbols written further to the right. For example, the number 3 is represented as “iii”, and the value
73 is represented as “lxxiii”. The exceptions to this rule occur for numbers having units values of 4
or 9, and for tens values of 40 or 90. For these cases, the Roman numeral representations are “iv” (4),
“ix” (9), “xl” (40), and “xc” (90). So the Roman numeral representations for 24, 39, 44, 49, and 94
are “xxiv”, “xxxix”, “xliv”, “xlix”, and “xciv”, respectively.
The preface of many books has pages numbered with Roman numerals, starting with “i” for the
first page of the preface, and continuing in sequence. Assume books with pages having 100 or fewer
pages of preface. How many “i”, “v”, “x”, “l”, and “c” characters are required to number the pages in
the preface? For example, in a five page preface we’ll use the Roman numerals “i”, “ii”, “iii”, “iv”,
and “v”, meaning we need 7 “i” characters and 2 “v” characters.

Input
The input will consist of a sequence of integers in the range 1 to 100, terminated by a zero. For each
such integer, except the final zero, determine the number of different types of characters needed to
number the prefix pages with Roman numerals.

Output
For each integer in the input, write one line containing the input integer and the number of characters
of each type required. The examples shown below illustrate an acceptable format.

Sample Input
1
2
20
99
0

Sample Output
1: 1 i, 0 v, 0 x, 0 l, 0 c
2: 3 i, 0 v, 0 x, 0 l, 0 c
20: 28 i, 10 v, 14 x, 0 l, 0 c
99: 140 i, 50 v, 150 x, 50 l, 1

*/

#![allow(non_snake_case)]

fn main() {
    assert_eq!(roman(1), (1, 0, 0, 0, 0));
    assert_eq!(roman(2), (3, 0, 0, 0, 0));
    assert_eq!(roman(20), (28, 10, 14, 0, 0));
    assert_eq!(roman(99), (140, 50, 150, 50, 10));
}

fn roman(n: usize) -> (usize, usize, usize, usize, usize) {
    let (mut i, mut v, mut x, mut l, mut c) = (0, 0, 0, 0, 0);
    for a in 1..=n {
        i += I(a);
        v += V(a);
        x += X(a);
        l += L(a);
        c += C(a);
    }
    (i, v, x, l, c)
}

fn I(mut n: usize) -> usize {
    n %= 5;
    if n == 4 {
        return 1;
    }
    return n;
}

fn V(mut n: usize) -> usize {
    n %= 10;
    if n >= 4 && n <= 8 {
        return 1;
    }
    return 0;
}

fn X(mut n: usize) -> usize {
    n %= 50;
    if n <= 8 {
        return 0;
    } else if n >= 9 && n <= 18 {
        return 1;
    } else if n >= 19 && n <= 28 {
        return 2;
    } else if n >= 29 && n <= 38 {
        return 3;
    } else if n == 39 {
        return 4;
    } else if n >= 40 && n <= 48 {
        return 1;
    }
    return 2;
}

fn L(n: usize) -> usize {
    if n >= 40 && n <= 89 {
        return 1;
    }
    return 0;
}

fn C(n: usize) -> usize {
    if n >= 90 {
        return 1;
    }
    return 0;
}
