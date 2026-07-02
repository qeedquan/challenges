fn main() {
    solve(1234567890);
}

fn solve(n: u128) {
    let mut i = 1;
    while i * n <= 9876543210 {
        let j = i * n;
        if valid(j) && valid(i) {
            println!("{} / {} = {}", j, i, n);
        }
        i += 1;
    }
    println!();
}

fn valid(mut n: u128) -> bool {
    let mut d = [false; 10];
    while n > 0 {
        let i = (n % 10) as usize;
        if d[i] {
            return false;
        }
        d[i] = true;
        n /= 10;
    }
    return true;
}
