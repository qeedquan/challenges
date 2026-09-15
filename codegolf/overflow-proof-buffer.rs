/*

Background
Programmers these days can't seem to keep their buffers straight! A common source of error is trying to use an array index that is too large for the buffer. Your task is to implement a buffer where large indices are reduced to a size that the buffer can handle. Because I decide exactly what's best for everyone, you will implement this buffer to my precise specifications.

Overview
You have a insert-only buffer that grows in size as elements are added to it. The buffer is zero-indexed, and also indexed modulo its current size. The special rule for this challenge is this:

To insert an item at index i means to compute j, j = i % buffer.length() and insert the new item after the jth item in the list.
The only special case is if the buffer is empty, as arithmetic modulo zero doesn't work. Thus, if the buffer is currently empty, the new item will be index 0.

If the buffer has only one item, then you are always inserting after the 0th item. This is just one instance of the general case.

If the buffer contains 6 items: [4, 9, 14, 8, 5, 2] and you are told to insert a new item 10 at index 15, you find that 15 % 6 == 3, and then insert the new 10 after the 8 at index 3 which gives a resulting buffer of [4, 9, 14, 8, 10, 5, 2]

Problem
Write a function or program that takes in an ordered list of positive integers, and positive integer indices at which to insert them.

Start with an empty buffer, and add the specified integers to the buffer at the corresponding indices.

Output the ordered list of integers that are in the buffer after all the specified insertions have been made.

This is a code-golf challenge, so shortest code wins.

Input guidelines
You may take the input lists however you see fit. Examples:

List of pairs: [ [1,1], [2,4], [3,9], [4,16], [5,25]...]
Item list and index list: [1, 2, 3, 4, 5...], [1, 4, 9, 16, 25]
Flattened: [1, 1, 2, 4, 3, 9, 4, 16, 5, 25 ...]
etc.
You may assume the input always contains at least one item and corresponding index.

Test cases
Squares case from above:

[(1, 1), (2, 4), (3, 9), (4, 16), (5, 25), (6, 36), (7, 49), (8, 64)] -> [1, 2, 8, 7, 6, 5, 4, 3]
I generated these randomly:

[(11, 9), (13, 14)] -> [11, 13]
[(1, 18), (11, 7), (3, 35), (16, 22)] -> [1, 11, 16, 3]
[(3, 16), (16, 37), (0, 28), (18, 24)] -> [3, 18, 0, 16]
[(7, 26), (8, 20), (11, 39), (1, 23), (17, 27)] -> [7, 8, 11, 1, 17]
[(15, 35), (17, 7), (16, 15), (1, 13), (2, 6), (11, 34)] -> [15, 17, 1, 2, 16, 11]
[(2, 13), (1, 20), (16, 25), (8, 21), (5, 2), (16, 37), (3, 0)] -> [2, 3, 8, 1, 16, 5, 16]
[(6, 20), (15, 15), (12, 26), (10, 27), (17, 13), (7, 18), (4, 16)] -> [6, 10, 17, 12, 7, 4, 15]
[(18, 9), (5, 34), (15, 4), (12, 29), (2, 5), (7, 0), (7, 10), (16, 38)] -> [18, 7, 15, 2, 16, 5, 7, 12]
[(0, 12), (12, 0), (4, 16), (15, 12), (6, 28), (8, 10), (11, 24), (0, 25)] -> [0, 11, 8, 6, 15, 0, 4, 12]
[(6, 12), (14, 13), (10, 33), (11, 35), (1, 3), (0, 28), (15, 27), (8, 10), (1, 2)] -> [6, 14, 10, 1, 11, 8, 15, 0, 1]
[(2, 29), (19, 30), (18, 17), (13, 3), (0, 21), (19, 19), (11, 13), (12, 31), (3, 25)] -> [2, 13, 3, 11, 0, 12, 19, 18, 19]

Python3 reference implementation
def f(inputs):
    # `inputs` is a list of pairs
    buff = []
    for item, index in inputs:
        if len(buff) == 0:
            buff.insert(0, item)
        else:
            insert_after = index % len(buff)
            buff.insert(insert_after+1, item)
    return buff

*/

fn main() {
    assert_eq!(insert(vec![[11, 9], [13, 14]]), vec![11, 13]);
    assert_eq!(
        insert(vec![[1, 18], [11, 7], [3, 35], [16, 22]]),
        vec![1, 11, 16, 3]
    );
    assert_eq!(
        insert(vec![[3, 16], [16, 37], [0, 28], [18, 24]]),
        vec![3, 18, 0, 16]
    );
    assert_eq!(
        insert(vec![[7, 26], [8, 20], [11, 39], [1, 23], [17, 27]]),
        vec![7, 8, 11, 1, 17]
    );

    assert_eq!(
        insert(vec![[15, 35], [17, 7], [16, 15], [1, 13], [2, 6], [11, 34]]),
        vec![15, 17, 1, 2, 16, 11]
    );
    assert_eq!(
        insert(vec![
            [2, 13],
            [1, 20],
            [16, 25],
            [8, 21],
            [5, 2],
            [16, 37],
            [3, 0]
        ]),
        vec![2, 3, 8, 1, 16, 5, 16]
    );
    assert_eq!(
        insert(vec![
            [6, 20],
            [15, 15],
            [12, 26],
            [10, 27],
            [17, 13],
            [7, 18],
            [4, 16]
        ]),
        vec![6, 10, 17, 12, 7, 4, 15]
    );
    assert_eq!(
        insert(vec![
            [18, 9],
            [5, 34],
            [15, 4],
            [12, 29],
            [2, 5],
            [7, 0],
            [7, 10],
            [16, 38]
        ]),
        vec![18, 7, 15, 2, 16, 5, 7, 12]
    );
    assert_eq!(
        insert(vec![
            [0, 12],
            [12, 0],
            [4, 16],
            [15, 12],
            [6, 28],
            [8, 10],
            [11, 24],
            [0, 25]
        ]),
        vec![0, 11, 8, 6, 15, 0, 4, 12]
    );
    assert_eq!(
        insert(vec![
            [6, 12],
            [14, 13],
            [10, 33],
            [11, 35],
            [1, 3],
            [0, 28],
            [15, 27],
            [8, 10],
            [1, 2]
        ]),
        vec![6, 14, 10, 1, 11, 8, 15, 0, 1]
    );
    assert_eq!(
        insert(vec![
            [2, 29],
            [19, 30],
            [18, 17],
            [13, 3],
            [0, 21],
            [19, 19],
            [11, 13],
            [12, 31],
            [3, 25]
        ]),
        vec![2, 13, 3, 11, 0, 12, 19, 18, 19]
    );
}

fn insert(inputs: Vec<[usize; 2]>) -> Vec<usize> {
    let mut buf = vec![];
    for input in inputs {
        let (item, index, size) = (input[0], input[1], buf.len());
        if size == 0 {
            buf.push(item);
        } else {
            buf.insert((index % size) + 1, item);
        }
    }
    return buf;
}
