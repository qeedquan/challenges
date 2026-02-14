/*

Just like in the "father" kata, you will have to return the last digit of the nth element in the Fibonacci sequence (starting with 1,1, to be extra clear, not with 0,1 or other numbers).

You will just get much bigger numbers, so good luck bruteforcing your way through it ;)

lastFibDigit(1) == 1
lastFibDigit(2) == 1
lastFibDigit(3) == 2
lastFibDigit(1000) == 5
lastFibDigit(1000000) == 5

*/

fn main() {
    let tab = [
        0, 1, 1, 2, 3, 5, 8, 3, 1, 4, 5, 9, 4, 3, 7, 0, 7, 7, 4, 1, 5, 6, 1, 7, 8, 5, 3, 8, 1, 9,
        0, 9, 9, 8, 7, 5, 2, 7, 9, 6, 5, 1, 6, 7, 3, 0, 3, 3, 6, 9, 5, 4, 9, 3, 2, 5, 7, 2, 9, 1,
        0, 1, 1, 2, 3, 5, 8, 3, 1, 4, 5, 9, 4, 3, 7, 0, 7, 7, 4, 1, 5, 6, 1, 7, 8, 5, 3, 8, 1, 9,
        0, 9, 9, 8, 7, 5, 2, 7, 9, 6, 5, 1, 6, 7, 3,
    ];

    for i in 0..tab.len() {
        assert_eq!(last_fib_digit(i), tab[i]);
    }

    assert_eq!(last_fib_digit(1), 1);
    assert_eq!(last_fib_digit(2), 1);
    assert_eq!(last_fib_digit(3), 2);
    assert_eq!(last_fib_digit(1000), 5);
    assert_eq!(last_fib_digit(1000000), 5);
    assert_eq!(last_fib_digit(1), 1);
    assert_eq!(last_fib_digit(21), 6);
    assert_eq!(last_fib_digit(302), 1);
    assert_eq!(last_fib_digit(4003), 7);
    assert_eq!(last_fib_digit(50004), 8);
    assert_eq!(last_fib_digit(600005), 5);
    assert_eq!(last_fib_digit(7000006), 3);
    assert_eq!(last_fib_digit(80000007), 8);
    assert_eq!(last_fib_digit(900000008), 1);
    assert_eq!(last_fib_digit(1000000009), 9);
}

// https://oeis.org/A003893
fn last_fib_digit(n: usize) -> usize {
    let mut f = vec![0, 1, 1];
    let m = n % 60;
    for i in 3..m + 1 {
        f.push((f[i - 1] + f[i - 2]) % 10);
    }
    f[m]
}
