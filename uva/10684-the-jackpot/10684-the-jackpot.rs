fn main() {
    assert_eq!(streak(vec![12, -4, -10, 4, 9]), "The maximum winning streak is 13.");
    assert_eq!(streak(vec![-2, -1, -2]), "Losing streak.");
}

fn streak(a: Vec<isize>) -> String {
    let mut c = 0;
    let mut m = 0;
    for v in a {
        c += v;
        if c < 0 {
            c = 0;
        }
        if m < c {
            m = c;
        }
    }
    if m <= 0 {
        return format!("Losing streak.");
    }
    return format!("The maximum winning streak is {}.", m);
}
