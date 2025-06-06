/*

Issue
Looks like some hoodlum plumber and his brother has been running around and damaging your stages again.

The pipes connecting your level's stages together need to be fixed before you receive any more complaints. Each pipe should be connecting, since the levels ascend, you can assume every number in the sequence after the first index will be greater than the previous and that there will be no duplicates.

Task
Given the a list of numbers, return the list so that the values increment by 1 for each index up to the maximum value.

Example
Input: 1,3,5,6,7,8

Output: 1,2,3,4,5,6,7,8

*/

fn main() {
    assert_eq!(
        pipefix(&vec![1, 3, 5, 6, 7, 8]),
        vec![1, 2, 3, 4, 5, 6, 7, 8]
    );

    assert_eq!(
        pipefix(&vec![1, 2, 3, 12]),
        vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12],
    );

    assert_eq!(pipefix(&vec![6, 9]), vec![6, 7, 8, 9],);
    assert_eq!(pipefix(&vec![-1, 4]), vec![-1, 0, 1, 2, 3, 4],);
    assert_eq!(pipefix(&vec![1, 2, 3]), vec![1, 2, 3],);
    assert_eq!(pipefix(&vec![1]), vec![1],);
}

fn pipefix(a: &Vec<isize>) -> Vec<isize> {
    let mut r = vec![];
    let n = a.len();
    if n == 0 {
        return r;
    }

    for i in 0..a[n - 1] - a[0] + 1 {
        r.push(a[0] + i);
    }
    return r;
}
