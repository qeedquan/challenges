/*

Description

An army of ants walk on a horizontal pole of length l cm, each with a constant speed of 1 cm/s. When a walking ant reaches an end of the pole, it immediatelly falls off it. When two ants meet they turn back and start walking in opposite directions. We know the original positions of ants on the pole, unfortunately, we do not know the directions in which the ants are walking. Your task is to compute the earliest and the latest possible times needed for all ants to fall off the pole.

Input

The first line of input contains one integer giving the number of cases that follow. The data for each case start with two integer numbers: the length of the pole (in cm) and n, the number of ants residing on the pole. These two numbers are followed by n integers giving the position of each ant on the pole as the distance measured from the left end of the pole, in no particular order. All input integers are not bigger than 1000000 and they are separated by whitespace.

Output

For each case of input, output two numbers separated by a single space. The first number is the earliest possible time when all ants fall off the pole (if the directions of their walks are chosen appropriately) and the second number is the latest possible such time.

Sample Input

2
10 3
2 6 7
214 7
11 12 7 13 176 23 191

Sample Output

4 8
38 207

Source

Waterloo local 2004.09.19

*/

use std::cmp::*;

fn main() {
    assert_eq!(falloff(10, vec![2, 6, 7]), (4, 8));
    assert_eq!(falloff(214, vec![11, 12, 7, 13, 176, 23, 191]), (38, 207));
}

fn falloff(l: isize, a: Vec<isize>) -> (isize, isize) {
    let (mut t0, mut t1) = (0, 0);
    for v in a {
        t0 = max(t0, min(v, l - v));
        t1 = max(t1, max(v, l - v));
    }
    (t0, t1)
}
