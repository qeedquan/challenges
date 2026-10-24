/*

Description
In mathematics the regular paperfolding sequence, also known as the dragon curve sequence, is an infinite automatic sequence of 0s and 1s. At each stage an alternating sequence of 1s and 0s is inserted between the terms of the previous sequence. The first few generations of the sequence look like this:

1
1 1 0
1 1 0 1 1 0 0
1 1 0 1 1 0 0 1 1 1 0 0 1 0 0
The sequence takes its name from the fact that it represents the sequence of left and right folds along a strip of paper that is folded repeatedly in half in the same direction. If each fold is then opened out to create a right-angled corner, the resulting shape approaches the dragon curve fractal.

Challenge Input
Your challenge today is to implement a regular paperfold sequence generator up to 8 cycles (it gets lengthy quickly).

Challenge Output
(With line breaks for readability)

110110011100100111011000110010011101100111001000110110001100100111011001110010
011101100011001000110110011100100011011000110010011101100111001001110110001100
100111011001110010001101100011001000110110011100100111011000110010001101100111
001000110110001100100111011001110010011101100011001001110110011100100011011000
110010011101100111001001110110001100100011011001110010001101100011001000110110
011100100111011000110010011101100111001000110110001100100011011001110010011101
1000110010001101100111001000110110001100100

*/

fn main() {
    assert_eq!(paperfold(0), vector("1"));
    assert_eq!(paperfold(1), vector("110"));
    assert_eq!(paperfold(2), vector("1101100"));
    assert_eq!(paperfold(3), vector("110110011100100"));
    assert_eq!(paperfold(8), vector("1101100111001001110110001100100111011001110010001101100011001001110110011100100111011000110010001101100111001000110110001100100111011001110010011101100011001001110110011100100011011000110010001101100111001001110110001100100011011001110010001101100011001001110110011100100111011000110010011101100111001000110110001100100111011001110010011101100011001000110110011100100011011000110010001101100111001001110110001100100111011001110010001101100011001000110110011100100111011000110010001101100111001000110110001100100"));
}

fn paperfold(loops: usize) -> Vec<isize> {
    let turn = 1;
    let mut values = vec![turn];
    for _ in 0..loops {
        values.push(turn);
        for i in (0..values.len() - 1).rev() {
            values.push(values[i] ^ 1);
        }
    }
    values
}

fn vector(bits: &'static str) -> Vec<isize> {
    let mut vec = vec![];
    for ch in bits.chars() {
        if ch == '1' {
            vec.push(1);
        } else if ch == '0' {
            vec.push(0);
        }
    }
    vec
}
