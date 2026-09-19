fn main() {
    assert_eq!(light(3), false);
    assert_eq!(light(6241), true);
    assert_eq!(light(8191), false);
}

fn light(n: usize) -> bool {
    let x = (n as f64).sqrt() as usize;
    x * x == n
}
