/*

You are given the positions of the minute and hour hands of an analog clock as an angle of clockwise rotation from the top (12). So a hand pointing at 9 is at an angle if 270, and a hand pointing exactly in between 12 and 1 is at an angle of 15.

Input will be two integer angles (in any order of your choice) between 0 and 359. Minute hand will be a multiple of 60, hour hand will be a multiple of 5. Output will be the time, given as two integers separated by a colon (and nothing more).

Sample data

(Hour hand first)

195 180 - 6:30
355 300 - 11:50
280 120 - 9:20
0 0 - 12:00
10 120 - 12:20

*/

fn main() {
    assert_eq!(angle2time(195, 180), "6:30");
    assert_eq!(angle2time(355, 300), "11:50");
    assert_eq!(angle2time(280, 120), "9:20");
    assert_eq!(angle2time(0, 0), "12:00");
    assert_eq!(angle2time(10, 120), "12:20");
}

fn angle2time(η: isize, μ: isize) -> String {
    let mut h = η / 30;
    let m = μ / 6;
    if h == 0 {
        h = 12;
    }
    return format!("{}:{:02}", h, m);
}
