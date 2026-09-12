/*

Your function takes two arguments:

current father's age (years)
current age of his son (years)
Сalculate how many years ago the father was twice as old as his son (or in how many years he will be twice as old). The answer is always greater or equal to 0, no matter if it was in the past or it is in the future.

*/

fn main() {
    assert_eq!(agediff(36, 7), 22);
    assert_eq!(agediff(55, 30), 5);
    assert_eq!(agediff(42, 21), 0);
    assert_eq!(agediff(22, 1), 20);
    assert_eq!(agediff(29, 0), 29);
}

fn agediff(f: isize, s: isize) -> isize {
    (f - (s * 2)).abs()
}
