fn main() {
    assert_eq!(optimal(vec![1, 3, 2]), 1);
    assert_eq!(optimal(vec![4, 3, 2, 1]), 6);
    assert_eq!(optimal(vec![2, 1]), 1);
}

fn optimal(a: Vec<isize>) -> isize {
    let mut c = 0;
    let n = a.len();
    for i in 0..n {
        for j in i + 1..n {
            if a[j] < a[i] {
                c += 1;
            }
        }
    }
    c
}
