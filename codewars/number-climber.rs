/*

For every positive integer N, there exists a unique sequence starting with 1 and ending with N and such that every number in the sequence is either the double of the preceeding number or the double plus 1.

For example, given N = 13, the sequence is [1, 3, 6, 13], because . . . :

 3 =  2*1 +1
 6 =  2*3
 13 = 2*6 +1

Write a function that returns this sequence given a number N. Try generating the elements of the resulting list in ascending order, i.e., without resorting to a list reversal or prependig the elements to a list.

*/

fn main() {
    assert_eq!(climb(1), vec![1]);
    assert_eq!(climb(10), vec![1, 2, 5, 10]);
    assert_eq!(climb(13), vec![1, 3, 6, 13]);
}

fn climb(mut n: isize) -> Vec<isize> {
    let mut r = vec![n];
    while n > 1 {
        n /= 2;
        r.push(n);
    }
    r.reverse();
    r
}
