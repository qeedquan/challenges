/*

Given an array (or list) of scores, return the array of ranks for each value in the array. The largest value has rank 1, the second largest value has rank 2, and so on. Ties should be handled by assigning the same rank to all tied values. For example:

ranks([9,3,6,10]) = [2,4,3,1]
and

ranks([3,3,3,3,3,5,1]) = [2,2,2,2,2,1,7]
because there is one 1st place value, a five-way tie for 2nd place, and one in 7th place.

*/

fn main() {
    assert_eq!(ranks(&vec![9, 3, 6, 10]), vec![2, 4, 3, 1]);
    assert_eq!(ranks(&vec![3, 3, 3, 3, 3, 5, 1]), vec![2, 2, 2, 2, 2, 1, 7]);
    assert_eq!(ranks(&vec![]), vec![]);
    assert_eq!(ranks(&vec![2]), vec![1]);
    assert_eq!(ranks(&vec![2, 2]), vec![1, 1]);
    assert_eq!(ranks(&vec![1, 2, 3]), vec![3, 2, 1]);
    assert_eq!(
        ranks(&vec![5, 2, 3, 5, 5, 4, 9, 8, 0]),
        vec![3, 8, 7, 3, 3, 6, 1, 2, 9]
    );
}

fn ranks(array: &Vec<isize>) -> Vec<usize> {
    let mut sorted = array.clone();
    let mut result = vec![];

    sorted.sort_by(|a, b| b.cmp(a));
    for i in 0..array.len() {
        let mut iter = sorted.iter();
        let index = iter.position(|&x| x == array[i]);
        result.push(index.unwrap() + 1);
    }

    result
}
