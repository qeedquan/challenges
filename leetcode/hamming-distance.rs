/*

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 2^31.

*/

fn main() {
    assert_eq!(hamming_distance(1, 4), 2);
    assert_eq!(hamming_distance(0x7, 0x10), 4);
    assert_eq!(hamming_distance(0, 0xffffffff), 32);
    assert_eq!(hamming_distance(3, 3), 0);
    assert_eq!(hamming_distance(25, 87), 4);
    assert_eq!(hamming_distance(256, 302), 4);
    assert_eq!(hamming_distance(543, 634), 4);
    assert_eq!(hamming_distance(34013, 702), 7);
}

fn hamming_distance(x: u32, y: u32) -> u32 {
    (x ^ y).count_ones()
}
