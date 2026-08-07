fn main() {
    assert_eq!(byteswap(123456789), 365779719);
    assert_eq!(byteswap(-123456789), -349002504);
    assert_eq!(byteswap(1), 16777216);
    assert_eq!(byteswap(16777216), 1);
    assert_eq!(byteswap(20034556), -55365375);
}

fn byteswap(mut x: i32) -> i32 {
    let mut r = 0;
    for _ in 0..4 {
        r = (r << 8) | (x & 0xff);
        x >>= 8;
    }
    r
}
