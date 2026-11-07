/*

In this kata you should simply determine, whether a given year is a leap year or not. In case you don't know the rules, here they are:

years divisible by 4 are leap years
but years divisible by 100 are not leap years
but years divisible by 400 are leap years
Additional Notes:

Only valid years (positive integers) will be tested, so you don't have to validate them
Examples can be found in the test fixture.

*/

fn main() {
    assert_eq!(isleap(2020), true);
    assert_eq!(isleap(2015), false);
    assert_eq!(isleap(2100), false);
}

fn isleap(year: isize) -> bool {
    if year % 4 != 0 {
        return false;
    }
    if year % 100 == 0 && year % 400 != 0 {
        return false;
    }
    return true;
}
