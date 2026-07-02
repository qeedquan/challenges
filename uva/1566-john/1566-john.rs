fn main() {
    assert_eq!(who(&[3, 5, 1]), "John");
    assert_eq!(who(&[1]), "Brother");
}

fn who(a: &[isize]) -> &'static str {
    let mut sg = 0;
    let mut s1 = 1;
    for &x in a {
        sg ^= x;
        s1 &= truth(x <= 1);
    }

    if s1 != 0 {
        if sg == 0 {
            return "John";
        }
        return "Brother";
    }
    if sg != 0 {
        return "John";
    }
    return "Brother";
}

fn truth(x: bool) -> isize {
    if x {
        return 1;
    }
    return 0;
}
