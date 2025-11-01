/*

In this Kata, we will calculate the minimum positive number that is not a possible sum from a list of positive integers.

solve([1,2,8,7]) = 4 => we can get 1, 2, 3 (from 1+2), but we cannot get 4. 4 is the minimum number not possible from the list. 
solve([4,1,2,3,12]) = 11. We can get 1, 2, 3, 4, 4+1=5, 4+2=6,4+3=7,4+3+1=8,4+3+2=9,4+3+2+1=10. But not 11. 
solve([2,3,2,3,4,2,12,3]) = 1. We cannot get 1.

More examples in test cases.

Good luck!

*/

fn main() {
    assert_eq!(solve(&mut vec![1, 2, 8, 7]), 4);
    assert_eq!(solve(&mut vec![4, 1, 2, 3, 12]), 11);
    assert_eq!(solve(&mut vec![2, 3, 2, 3, 4, 2, 12, 3]), 1);
}

fn solve(a: &mut Vec<usize>) -> usize {
    a.sort();

    let mut r = 1;
    for &mut v in a {
        if v > r {
            break;
        }
        r += v;
    }
    r
}
