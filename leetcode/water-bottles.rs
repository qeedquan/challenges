/*

There are numBottles water bottles that are initially full of water. You can exchange numExchange empty water bottles from the market with one full water bottle.

The operation of drinking a full water bottle turns it into an empty bottle.

Given the two integers numBottles and numExchange, return the maximum number of water bottles you can drink.

Example 1:

Input: numBottles = 9, numExchange = 3
Output: 13
Explanation: You can exchange 3 empty bottles to get 1 full water bottle.
Number of water bottles you can drink: 9 + 3 + 1 = 13.

Example 2:

Input: numBottles = 15, numExchange = 4
Output: 19
Explanation: You can exchange 4 empty bottles to get 1 full water bottle.
Number of water bottles you can drink: 15 + 3 + 1 = 19.

Constraints:

    1 <= numBottles <= 100
    2 <= numExchange <= 100

*/

fn main() {
    assert_eq!(bottles(9, 3), 13);
    assert_eq!(bottles(15, 4), 19);
    assert_eq!(bottles(50, 100), 50);
    assert_eq!(bottles(0, 1), 0);
}

fn bottles(mut b: isize, e: isize) -> isize {
    if b < 0 || e <= 0 {
        return -1;
    }

    if b > 0 && e == 1 {
        return isize::MAX;
    }

    let (mut r, mut a) = (0, 0);
    while b > 0 {
        r += b;
        a += b % e;
        b = (b / e) + (a / e);
        a %= e;
    }
    return r;
}
