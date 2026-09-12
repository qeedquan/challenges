/*

Create a function that takes in the sum and age difference of two people, calculates their individual ages,
and returns a pair of values (oldest age first) if those exist or null/None or {-1, -1} in C if:

sum < 0
difference < 0
Either of the calculated ages come out to be negative

*/

fn main() {
    assert_eq!(ages(24.0, 4.0), (14.0, 10.0));
    assert_eq!(ages(30.0, 6.0), (18.0, 12.0));
    assert_eq!(ages(70.0, 10.0), (40.0, 30.0));
    assert_eq!(ages(18.0, 4.0), (11.0, 7.0));
    assert_eq!(ages(63.0, 14.0), (38.5, 24.5));
    assert_eq!(ages(80.0, 80.0), (80.0, 0.0));
    assert_eq!(ages(63.0, -14.0), (-1.0, -1.0));
    assert_eq!(ages(-22.0, 15.0), (-1.0, -1.0));
}

fn ages(sum: f64, difference: f64) -> (f64, f64) {
    let first = (sum / 2.0) + (difference / 2.0);
    let second = (sum / 2.0) - (difference / 2.0);
    if sum < 0.0 || difference < 0.0 || first < 0.0 || second < 0.0 {
        return (-1.0, -1.0);
    }
    return (first, second);
}
