/*

A narrow street is lined with tall buildings. An x foot long ladder is rested at the base of the building on the right side of the street and leans on the building on the left side. A y foot long ladder is rested at the base of the building on the left side of the street and leans on the building on the right side. The point where the two ladders cross is exactly c feet from the ground. How wide is the street?

https://static.lightoj.com/images/problem-1062/ladder-1604094309497.png?style=centerme,haveborder

Input
Input starts with an integer T (≤ 10), denoting the number of test cases.

Each test case contains three positive floating point numbers giving the values of x, y, and c.

Output
For each case, output the case number and the width of the street in feet. Errors less than 10-6 will be ignored.

Sample
Input	Output
4
30 40 10
12.619429 8.163332 3
10 10 3
10 10 1

Case 1: 26.0328775442
Case 2: 6.99999923
Case 3: 8
Case 4: 9.797958971

*/

fn main() {
    println!("{:.8}", solve(30.0, 40.0, 10.0));
    println!("{:.8}", solve(12.619429, 8.163332, 3.0));
    println!("{:.8}", solve(10.0, 10.0, 3.0));
    println!("{:.8}", solve(10.0, 10.0, 1.0));
}

fn solve(x: f64, y: f64, c: f64) -> f64 {
    let eps = 1e-12;

    let mut l = 0.0;
    let mut r = x.min(y);
    loop {
        let d = (l + r) / 2.0;
        let dx = ((x * x) - (d * d)).sqrt();
        let dy = ((y * y) - (d * d)).sqrt();
        let tc = (dy * dx) / (dy + dx);
        if (tc - c).abs() <= eps {
            return d;
        }

        if tc > c {
            l = d;
        } else {
            r = d;
        }
    }
}
