/*

Output the day of the week given the year, month, and day in the Julian/Gregorian calendar.

*/

fn main() {
    assert_eq!(day(2017, 10, 30), "MONDAY");
    assert_eq!(day(2016, 2, 29), "MONDAY");
    assert_eq!(day(2015, 2, 28), "SATURDAY");
    assert_eq!(day(29, 4, 12), "THURSDAY");
    assert_eq!(day(570, 11, 30), "FRIDAY");
    assert_eq!(day(1066, 9, 25), "TUESDAY");
    assert_eq!(day(1776, 7, 4), "THURSDAY");
    assert_eq!(day(1933, 1, 30), "MONDAY");
    assert_eq!(day(1953, 3, 6), "FRIDAY");
    assert_eq!(day(2100, 10, 9), "SATURDAY");
    assert_eq!(day(2202, 12, 15), "WEDNESDAY");
    assert_eq!(day(7032, 3, 26), "MONDAY");
    assert_eq!(day(2025, 7, 13), "SUNDAY");
}

// https://en.wikipedia.org/wiki/Zeller's_congruence
fn day(mut y: usize, mut m: usize, d: usize) -> &'static str {
    let days = vec![
        "SATURDAY",
        "SUNDAY",
        "MONDAY",
        "TUESDAY",
        "WEDNESDAY",
        "THURSDAY",
        "FRIDAY",
    ];

    if m < 3 {
        y -= 1;
        m += 12;
    }

    let c = y / 100;
    let z = y % 100;
    let i = (d + ((13 * (m + 1)) / 5) + z + (z / 4) + (c / 4) + (5 * c)) % 7;
    days[i]
}
