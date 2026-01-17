/*

Introduction
The first century spans from the year 1 up to and including the year 100, the second century - from the year 101 up to and including the year 200, etc.

Task
Given a year, return the century it is in.

Examples
1705 --> 18
1900 --> 19
1601 --> 17
2000 --> 20
2742 --> 28

Note: this kata uses strict construction as shown in the description and the examples, you can read more about it here

*/

fn main() {
    assert_eq!(century(100), 1);
    assert_eq!(century(101), 2);
    assert_eq!(century(1705), 18);
    assert_eq!(century(1900), 19);
    assert_eq!(century(1601), 17);
    assert_eq!(century(2000), 20);
    assert_eq!(century(2742), 28);
}

fn century(y: usize) -> usize {
    if y == 0 {
        return 0;
    }
    return ((y - 1) / 100) + 1;
}
