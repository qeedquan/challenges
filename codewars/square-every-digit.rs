/*

Welcome. In this kata, you are asked to square every digit of a number and concatenate them.

For example, if we run 9119 through the function, 811181 will come out, because 92 is 81 and 12 is 1.

Note: The function accepts an integer and returns an integer

*/

fn main() {
    assert_eq!(squaredigits(9119), 811181);
    assert_eq!(squaredigits(2483), 416649);
    assert_eq!(squaredigits(3212), 9414);
    assert_eq!(squaredigits(8726), 6449436);
    assert_eq!(squaredigits(9763), 8149369);
    assert_eq!(squaredigits(2230), 4490);
    assert_eq!(squaredigits(2797), 4498149);
    assert_eq!(squaredigits(233), 499);
    assert_eq!(squaredigits(7437), 4916949);
    assert_eq!(squaredigits(2483), 416649);
    assert_eq!(squaredigits(5742), 2549164);
    assert_eq!(squaredigits(5636), 2536936);
    assert_eq!(squaredigits(841), 64161);
}

fn squaredigits(mut n: usize) -> usize {
    let (mut r, mut p) = (0, 1);
    while n > 0 {
        let x = n % 10;
        let x = x * x;
        r = (x * p) + r;
        p *= 10;
        if x >= 10 {
            p *= 10;
        }
        n /= 10;
    }
    r
}
