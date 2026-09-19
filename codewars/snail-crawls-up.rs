/*

The snail crawls up the column. During the day it crawls up some distance. During the night she sleeps, so she slides down for some distance (less than crawls up during the day).

Your function takes three arguments:

    The height of the column (meters)
    The distance that the snail crawls during the day (meters)
    The distance that the snail slides down during the night (meters)

Calculate number of day when the snail will reach the top of the column.

*/

fn main() {
    assert_eq!(snail(3, 2, 1), 2);
    assert_eq!(snail(10, 3, 1), 5);
    assert_eq!(snail(10, 3, 2), 8);
    assert_eq!(snail(100, 20, 5), 7);
    assert_eq!(snail(5, 10, 3), 1);
}

fn snail(column: isize, day: isize, night: isize) -> isize {
    let mut position = night;
    let mut count = 0;
    while position < column {
        position -= night;
        count += 1;
        position += day;
    }
    count
}
