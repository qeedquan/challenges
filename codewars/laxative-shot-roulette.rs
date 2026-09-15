/*

Description
Peter enjoys taking risks, and this time he has decided to take it up a notch!

Peter asks his local barman to pour him n shots, after which Peter then puts laxatives in x of them. He then turns around and lets the barman shuffle the shots. Peter approaches the shots and drinks a of them one at a time. Just one shot is enough to give Peter a runny tummy. What is the probability that Peter doesn't need to run to the loo?

Task
You are given:

n - The total number of shots.

x - The number of laxative laden shots.

a - The number of shots that peter drinks.

return the probability that Peter won't have the trots after drinking. n will always be greater than x, and a will always be less than n.

You must return the probability rounded to two decimal places i.e. 0.05 or 0.81

*/

fn main() {
    test(0.5, 2, 1, 1);
    test(0.25, 4, 1, 3);
    test(0.33, 100, 10, 10);
    test(0.04, 1000, 150, 20);
    test(0.29, 25, 5, 5);
    test(0.42, 9, 3, 2);
}

fn test(r: f64, n: isize, x: isize, a: isize) {
    let p = chance(n, x, a);
    println!("{p}");
    assert_eq!(true, (p - r).abs() < 1e-2);
}

fn chance(n: isize, x: isize, a: isize) -> f64 {
    let mut p = 1.0;
    for i in 0..a {
        p *= 1.0 - (x as f64 / (n - i) as f64);
    }
    p
}
