/*

Write a function, which takes a non-negative integer (seconds) as input and returns the time in a human-readable format (HH:MM:SS)

HH = hours, padded to 2 digits, range: 00 - 99
MM = minutes, padded to 2 digits, range: 00 - 59
SS = seconds, padded to 2 digits, range: 00 - 59
The maximum time never exceeds 359999 (99:59:59)

You can find some examples in the test fixtures.

*/

fn main() {
    println!("{}", readable(0));
    println!("{}", readable(5));
    println!("{}", readable(60));
    println!("{}", readable(86399));
    println!("{}", readable(359999));
}

fn readable(sec: isize) -> String {
    let hh = sec / 3600;
    let mm = (sec - (hh * 3600)) / 60;
    let ss = sec - (hh * 3600) - (mm * 60);
    format!("{:02}:{:02}:{:02}", hh, mm, ss)
}
