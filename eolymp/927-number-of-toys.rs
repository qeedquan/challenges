/*

A store offers an assortment of toys of various types.
For each type, the number of toys and the price of one toy are known.
Determine the total number of toys with a price less than 50 hryvnias.

Input
The first line contains an integer n (0≤n≤1000) — the number of toy types in the price list.
Each of the following n lines contains two integers:

a (0≤a≤1000) — the number of toys of this type, and

b (0<b≤10000) — the price of one toy of this type, in hryvnias.

Output
Print the total number of toys with a price less than 50 hryvnias.

Examples

Input #1
3
2 100.00
5 23.00
10 22.50

Answer #1
15

*/

fn main() {
    assert_eq!(solve(&[(2, 100.00), (5, 23.00), (10, 22.50)]), 15);
}

fn solve(toys: &[(isize, f64)]) -> isize {
    let mut total = 0;
    for &(amount, price) in toys {
        if price < 50.0 {
            total += amount;
        }
    }
    total
}
