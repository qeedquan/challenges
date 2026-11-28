/*

Ronny the robot is watching someone perform the Cups and Balls magic trick. The magician has one ball and three cups, he shows Ronny which cup he hides the ball under (b), he then mixes all the cups around by performing multiple two-cup switches (arr). Ronny can record the switches but can't work out where the ball is. Write a programme to help him do this.

Rules:

There will only ever be three cups.
Only two cups will be swapped at a time.
The cups and their switches will be refered to by their index in a row of three, beginning at one. So [[1,2]] means the cup at position one, is swapped with the cup at position two.
Arr will be an array of integers 1 - 3 organised in pairs.
There won't be any empty sub-arrays.
If arr is just an empty array b should be returned.

Examples:

(b) = 2, (arr) = [[1,2]]

The ball is under cup number : 1

(b) = 1, (arr) = [[2,3],[1,2],[1,2]]

The ball is under cup number : 1

(b) = 2, (arr) = [[1,3],[1,2],[2,1],[2,3]]

The ball is under cup number : 3

*/

fn main() {
    assert_eq!(play(2, vec![(1, 2)]), 1);
    assert_eq!(play(1, vec![(2, 3), (1, 2), (1, 2)]), 1);
    assert_eq!(play(2, vec![(1, 3), (1, 2), (2, 1), (2, 3)]), 3);
}

fn play(ball: usize, switches: Vec<(usize, usize)>) -> usize {
    let mut cups = vec![0, 0, 0, 0];

    cups[ball] = 1;
    for switch in switches {
        let (i, j) = (switch.0, switch.1);
        (cups[i], cups[j]) = (cups[j], cups[i]);
    }

    for i in 0..cups.len() {
        if cups[i] != 0 {
            return i;
        }
    }
    return 0;
}
