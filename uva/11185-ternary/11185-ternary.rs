fn main() {
    let tab = [
        0, 1, 2, 10, 11, 12, 20, 21, 22, 100, 101, 102, 110, 111, 112, 120, 121, 122, 200, 201,
        202, 210, 211, 212, 220, 221, 222, 1000, 1001, 1002, 1010, 1011, 1012, 1020, 1021, 1022,
        1100, 1101, 1102, 1110, 1111, 1112, 1120, 1121, 1122, 1200, 1201, 1202, 1210, 1211,
    ];

    assert_eq!(base3(0), 0);
    assert_eq!(base3(10), 101);
    assert_eq!(base3(100), 10201);
    assert_eq!(base3(1000), 1101001);

    for i in 0..tab.len() {
        assert_eq!(base3(i), tab[i]);
    }
}

// https://oeis.org/A007089
fn base3(mut n: usize) -> usize {
    let mut r = 0;
    let mut p = 1;
    while n > 0 {
        r += p * (n % 3);
        p *= 10;
        n /= 3;
    }
    return r;
}
