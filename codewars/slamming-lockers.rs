/*

Johnny is a boy who likes to open and close lockers. He loves it so much that one day, when school was out, he snuck in just to play with the lockers.

Each locker can either be open or closed. If a locker is closed when Johnny gets to it, he opens it, and vice versa.

The lockers are numbered sequentially, starting at 1.

Starting at the first locker, Johnny runs down the row, opening each locker.

Then he runs all the way back to the beginning and runs down the row again, this time skipping to every other locker. (2,4,6, etc)

Then he runs all the way back and runs through again, this time skipping two lockers for every locker he opens or closes. (3,6,9, etc)

He continues this until he has finished running past the last locker (i.e. when the number of lockers he skips is greater than the number of lockers he has).

The equation could be stated as follows:

Johnny runs down the row of lockers n times, starting at the first locker each run and skipping i lockers as he runs, where n is the number of lockers there are in total and i is the current run.

The goal of this kata is to determine which lockers are open at the end of Johnny's running.

The program accepts an integer giving the total number of lockers, and should output an array filled with the locker numbers of those which are open at the end of his run.

*/

fn main() {
    assert_eq!(lockers(1), vec![1]);
    assert_eq!(lockers(10), vec![1, 4, 9]);
    assert_eq!(lockers(50), vec![1, 4, 9, 16, 25, 36, 49]);
    assert_eq!(lockers(100), vec![1, 4, 9, 16, 25, 36, 49, 64, 81, 100]);
    assert_eq!(lockers(100), vec![1, 4, 9, 16, 25, 36, 49, 64, 81, 100]);
    assert_eq!(
        lockers(500),
        vec![
            1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225, 256, 289, 324, 361, 400,
            441, 484
        ]
    );
}

fn lockers(l: usize) -> Vec<usize> {
    let mut r = vec![];
    let n = (l as f64).sqrt() as usize;
    for i in 1..n + 1 {
        r.push(i * i);
    }
    r
}