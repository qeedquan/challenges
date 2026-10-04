/*

From AZSPCS:
https://www.azspcs.net/Contest/Cards

Suppose you have a deck containing n cards. Each card contains a number from 1 to n, and each number appears on exactly one card. You look at the number on the top card -- let's says it's k -- and then reverse the order of the top k cards. You continue this procedure -- reading the top number and then reversing the corresponding number of cards -- until the top card is 1.

Write the fastest program to compute the number of reversals for a given deck. Note that if you are participating in the contest you are not allowed to post your code (and thus I will not post my code yet).

*/

fn main() {
    assert_eq!(revno(&mut vec![3, 2, 1]), 1);
    assert_eq!(revno(&mut vec![2, 3, 1]), 2);
    assert_eq!(revno(&mut vec![1, 2, 3]), 0);
    assert_eq!(revno(&mut vec![3, 6, 5, 1, 4, 2]), 10);
}

fn revno(deck: &mut Vec<usize>) -> usize {
    let mut r = 0;
    loop {
        let k = deck[0];
        if k == 1 {
            break;
        }

        for i in 0..k / 2 {
            (deck[i], deck[k - i - 1]) = (deck[k - i - 1], deck[i]);
        }

        r += 1;
    }
    r
}
