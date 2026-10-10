fn main() {
    assert_eq!(emoogle_balance(vec![3, 4, 0, 0, 1]), 1);
    assert_eq!(emoogle_balance(vec![2, 0, 0, 0]), -2);
    assert_eq!(emoogle_balance(vec![1, 2, 3, 4, 5, 0, 0]), 3);
}

fn emoogle_balance(a: Vec<isize>) -> isize {
    let mut c = 0;
    for v in a {
        if v <= 0 {
            c -= 1;
        } else {
            c += 1;
        }
    }
    c
}
