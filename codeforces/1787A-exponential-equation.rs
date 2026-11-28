/*

You are given an integer n.

Find any pair of integers (x,y) (1≤x,y≤n) such that x^y*y + y^x*x=n.

Input
The first line contains a single integer t (1≤t≤10^4) — the number of test cases.

Each test case contains one line with a single integer n (1≤n≤10^9).

Output
For each test case, if possible, print two integers x and y (1≤x,y≤n). If there are multiple answers, print any.

Otherwise, print -1.

Example
input
5
3
7
42
31250
20732790

output
-1
-1
2 3
5 5
3 13

Note
In the third test case, 23⋅3+32⋅2=42, so (2,3),(3,2) will be considered as legal solutions.

In the fourth test case, 55⋅5+55⋅5=31250, so (5,5) is a legal solution.

*/

fn main() {
    test(3);
    test(7);
    test(31250);
    test(20732790);
}

fn test(n: isize) {
    if n & 1 != 0 {
        println!("-1");
        assert_eq!(pairbf(n), (-1, -1));
    } else {
        let (x, y) = pair(n);
        println!("{} {}", x, y);
        assert_eq!(poweval(x, y), n);
    }
}

fn poweval(x: isize, y: isize) -> isize {
    (x.pow(y as u32) * y) + (y.pow(x as u32) * x)
}

fn pair(n: isize) -> (isize, isize) {
    if n & 1 != 0 {
        (-1, -1)
    } else {
        (1, n / 2)
    }
}

fn pairbf(n: isize) -> (isize, isize) {
    for x in 1..n + 1 {
        for y in 1..n + 1 {
            if poweval(x, y) == n {
                return (x, y);
            }
        }
    }
    return (-1, -1);
}
