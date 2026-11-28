/*

My preferred way to approximate a derivative is the central difference, its more accurate than forward difference or backward difference, and I'm too lazy to go higher-order. But the central difference requires a data point on either side of point you are evaluating. Normally this means you end up not having a derivative at either endpoint. To solve it, I want you to switch to forward and backward difference at the edges:

Specifically, I want you to use a forward difference for the first point, a backward difference for the last point, and a central difference for all the points in the middle. Also, you can assume x values are evenly spaced, and focus only on y. Use these formulas:

Central Difference:  f'[i] = (f[i+1] - f[i-1]) / 2
Forward Difference:  f'[i] = f[i+1] - f[i]
Backward Difference: f'[i] = f[i] - f[i-1]

Good luck, I'm looking forward to seeing if someone comes up with a simple rule which reproduces all 3 derivatives in the right places!

EX INPUT:

0.034  9.62    8.885   3.477   2.38
I will use FD, CD, and BD to denote which algorithm to use in which spot, so above 5 points are used to approximate derivatives using

FD     CD      CD      CD     BD
And then the calculated values would be:

9.586  4.4255 -3.0715 -3.2525 -1.097
You can assume that there will always be at least 3 input points, and you can calculate using single or double precision.

And as always, shortest answer wins.

*/

fn main() {
    test(
        vec![0.034, 9.62, 8.885, 3.477, 2.38],
        vec![9.586, 4.4255, -3.0715, -3.2525, -1.097],
    );
}

fn test(x: Vec<f64>, r: Vec<f64>) {
    let d = derivative(x);
    let n = d.len();

    assert_eq!(d.len(), r.len());
    for i in 0..n {
        assert_eq!((d[i] - r[i]).abs() < 1e-3, true);
    }
}

fn derivative(x: Vec<f64>) -> Vec<f64> {
    let (mut r, n) = (vec![], x.len());
    for i in 0..n {
        if i == 0 && i + 1 < n {
            r.push(x[i + 1] - x[i]);
        } else if i > 0 && i + 1 < n {
            r.push((x[i + 1] - x[i - 1]) / 2.0);
        } else if i > 0 && i + 1 == n {
            r.push(x[i] - x[i - 1]);
        }
    }
    r
}
