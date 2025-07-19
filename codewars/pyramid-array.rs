/*

Write a function that when given a number >= 0, returns an Array of ascending length subarrays.

pyramid(0) => [ ]
pyramid(1) => [ [1] ]
pyramid(2) => [ [1], [1, 1] ]
pyramid(3) => [ [1], [1, 1], [1, 1, 1] ]
Note: the subarrays should be filled with 1sq

*/

fn main() {
    for i in 0..4 {
        println!("{:?}", pyramid(i));
    }
}

fn pyramid(n: usize) -> Vec<Vec<usize>> {
    let mut r = vec![];
    for i in 0..n {
        let mut x = vec![];
        for _ in 0..i + 1 {
            x.push(1);
        }
        r.push(x);
    }
    r
}
