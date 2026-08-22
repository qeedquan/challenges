fn main() {
    assert_eq!(drop(4, 2), 12);
    assert_eq!(drop(3, 4), 7);
    assert_eq!(drop(10, 1), 512);
    assert_eq!(drop(2, 2), 3);
    assert_eq!(drop(8, 128), 255);
}

fn drop(d: isize, mut k: isize) -> isize {
    let mut r = 1;
    for _ in 1..d {
        if k % 2 != 0 {
            k = (k / 2) + 1;
            r = r * 2;
        } else {
            k = k / 2;
            r = (r * 2) + 1;
        }
    }
    r
}
