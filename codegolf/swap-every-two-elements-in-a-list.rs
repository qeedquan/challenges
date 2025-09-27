/*

Challenge
Let's have a list L of n elements. The task is to swap every two elements in this list.

Constrains
the list L has at least two elements
size of the list L is a multiple of two (i.e. number of elements is even)
Example
input: [1,2,3,4,5,6]

output: [2,1,4,3,6,5]

input: [0,1,0,1]

output: [1,0,1,0]

Rules
this is code-golf challenge, so the shortest code wins
standard rules apply for your answer with default I/O rules, so you are allowed to use stdin/stdout, functions/method with the proper parameters and return-type, full programs
default Loopholes are forbidden.

*/

fn main() {
    assert_eq!(
        swap2(&mut vec![1, 2, 3, 4, 5, 6]),
        &mut vec![2, 1, 4, 3, 6, 5]
    );
    assert_eq!(swap2(&mut vec![0, 1, 0, 1]), &mut vec![1, 0, 1, 0]);
}

fn swap2(a: &mut Vec<isize>) -> &mut Vec<isize> {
    let mut i = 0;
    while i + 1 < a.len() {
        (a[i], a[i + 1]) = (a[i + 1], a[i]);
        i += 2;
    }
    a
}
