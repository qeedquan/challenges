fn main() {
    assert_eq!(residence(2, 1, 10, 10), "NE");
    assert_eq!(residence(2, 1, -10, 1), "divisa");
    assert_eq!(residence(2, 1, 0, 33), "NO");

    assert_eq!(residence(-1000, -1000, -1000, -1000), "divisa");
    assert_eq!(residence(-1000, -1000, 0, 0), "NE");
    assert_eq!(residence(-1000, -1000, -2000, -10000), "SO");
    assert_eq!(residence(-1000, -1000, -999, -1001), "SE");
}

fn residence(n: isize, m: isize, x: isize, y: isize) -> &'static str {
    if x == n || y == m {
        return "divisa";
    }
    if x < n && y > m {
        return "NO";
    }
    if x > n && y > m {
        return "NE";
    }
    if x > n && y < m {
        return "SE";
    }
    return "SO";
}
