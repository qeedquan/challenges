fn main() {
    assert_eq!(solve("JAN", "SUN"), 8);
    assert_eq!(solve("FEB", "SUN"), 8);
    assert_eq!(solve("OCT", "THU"), 10);
}

fn solve(month: &'static str, weekday: &'static str) -> isize {
    let weekdays = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"];
    let months = [
        "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC",
    ];
    let days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];

    let a = weekdays.iter().position(|&x| x == weekday);
    let b = months.iter().position(|&x| x == month);
    if a.is_none() || b.is_none() {
        return 0;
    }

    let a = a.unwrap();
    let b = b.unwrap();
    let mut c = 0;
    for i in 0..days[b] {
        if (a + i) % 7 == 5 || (a + i) % 7 == 6 {
            c += 1;
        }
    }
    return c;
}
