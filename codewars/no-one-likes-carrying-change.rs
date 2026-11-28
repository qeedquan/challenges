/*

No one enjoys carrying around spare change. And to avoid all that jingling it's absolutely necessary to have an efficient algorithm to calculate the minimum number of coins needed to pay for something. So given a set of coin denominations determine the fewest number of coins required to add up to a given amount.

For example: US Currency includes the penny, nickel, dime and quarter or the coins with denominations: [1, 5, 10, 25] If I were to ask you to make 75 cents you would return 3 since 75 cents can be made with 3 quarters.

NOTES:

The coin denominations will contain at least one coin and will be greater than zero. [3] or [1, 100, 19] are both valid.
All amounts given will be solvable.
Be greedy...

*/

fn main() {
    assert_eq!(coins_needed(75, &mut [1, 5, 10, 25]), 3);
    assert_eq!(coins_needed(123, &mut [1, 5, 10, 25]), 9);
    assert_eq!(coins_needed(75, &mut [1, 2, 5, 10, 20, 50]), 3);
    assert_eq!(coins_needed(123, &mut [1, 2, 5, 10, 20, 50]), 5);
}

fn coins_needed(mut amount: isize, coins: &mut [isize]) -> isize {
    coins.sort_by(|a, b| b.cmp(a));

    let mut count = 0;
    for &mut coin in coins {
        if amount < 1 || coin < 1 {
            break;
        }
        let used = amount / coin;
        count += used;
        amount -= used * coin;
    }
    count
}
