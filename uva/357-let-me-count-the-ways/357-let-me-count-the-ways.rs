fn main() {
    assert_eq!(solve(17), "There are 6 ways to produce 17 cents change.");
    assert_eq!(solve(11), "There are 4 ways to produce 11 cents change.");
    assert_eq!(solve(4), "There is only 1 way to produce 4 cents change.");
}

// https://oeis.org/A001300
fn solve(n: usize) -> String {
    let c = [1, 5, 10, 25, 50];

    let mut p = vec![0; n + 1];
    p[0] = 1;
    for i in 0..c.len() {
        for j in c[i]..p.len() {
            p[j] += p[j - c[i]];
        }
    }

    if p[n] != 1 {
        format!("There are {} ways to produce {} cents change.", p[n], n)
    } else {
        format!("There is only 1 way to produce {} cents change.", n)
    }
}
