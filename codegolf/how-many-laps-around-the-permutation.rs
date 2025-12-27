/*

Your input is an array of numbers: a permutation of {1,2…n} for some integer n≥2.

How many times must you repeat this list before you can "pick out" the numbers [1,2…n] in order?

That is: find the lowest t≥1 so that [1,2…n] is a subsequence of repeat(input,t).

This is code-golf: write the shortest program or function that accepts a list of numbers and produces t.

Example
For [6,1,2,3,5,4], the answer is 3:

6,1,2,3,5,4    6,1,2,3,5,4    6,1,2,3,5,4
  ^ ^ ^   ^            ^      ^
Test cases
[2,1] -> 2
[3,2,1] -> 3
[1,2,3,4] -> 1
[4,1,5,2,3] -> 2
[6,1,2,3,5,4] -> 3
[3,1,2,5,4,7,6] -> 4
[7,1,8,3,5,6,4,2] -> 4
[8,4,3,1,9,6,7,5,2] -> 5
[8,2,10,1,3,4,6,7,5,9] -> 5
[8,6,1,11,10,2,7,9,5,4,3] -> 7
[10,5,1,6,11,9,2,3,4,12,8,7] -> 5
[2,3,8,7,6,9,4,5,11,1,12,13,10] -> 6

*/

fn main() {
    assert_eq!(laps(&vec![2, 1]), 2);
    assert_eq!(laps(&vec![3, 2, 1]), 3);
    assert_eq!(laps(&vec![1, 2, 3, 4]), 1);
    assert_eq!(laps(&vec![4, 1, 5, 2, 3]), 2);
    assert_eq!(laps(&vec![6, 1, 2, 3, 5, 4]), 3);
    assert_eq!(laps(&vec![3, 1, 2, 5, 4, 7, 6]), 4);
    assert_eq!(laps(&vec![7, 1, 8, 3, 5, 6, 4, 2]), 4);
    assert_eq!(laps(&vec![8, 4, 3, 1, 9, 6, 7, 5, 2]), 5);
    assert_eq!(laps(&vec![8, 2, 10, 1, 3, 4, 6, 7, 5, 9]), 5);
    assert_eq!(laps(&vec![8, 6, 1, 11, 10, 2, 7, 9, 5, 4, 3]), 7);
    assert_eq!(laps(&vec![10, 5, 1, 6, 11, 9, 2, 3, 4, 12, 8, 7]), 5);
    assert_eq!(laps(&vec![2, 3, 8, 7, 6, 9, 4, 5, 11, 1, 12, 13, 10]), 6);
    assert_eq!(laps(&vec![1]), 1);
    assert_eq!(laps(&vec![0]), -1);
}

fn laps(a: &Vec<usize>) -> isize {
    let (mut l, mut c, n) = (0, 1, a.len());
    while c <= n {
        if l > n {
            return -1;
        }

        for v in a {
            if c == *v {
                c += 1;
            }
        }
        l += 1;
    }
    return l as isize;
}
