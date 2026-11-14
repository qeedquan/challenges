/*

I know, the title cracks you up

Given an amount of money, output the fewest number of coins that make up that amount.

Examples
0.1
1 dime

0.01
1 penny

0.28
1 quarter 3 penny

0.56
2 quarter 1 nickel 1 penny

1.43
5 quarter 1 dime 1 nickel 3 penny

Spec
100 cents in a dollar.
The values of each type of coin is:
penny 1 cent
nickel 5 cents
dime 10 cents
quarter 25 cents
Built-ins which trivialize this task are not allowed.

I/O
Input is a decimal representing the dollar value of the total

No need to pluralize
Order: quarter -> penny
Output should be <#_of_coins> <coin type>
Separators: , or , (comma and a space) or
The only trailing whitespace allowed is a single trailing newline/space.

If there is zero of a coin type, that coin type should not be shown. E.g. 0.25 -> 1 quarter not 1 quarter 0 dime 0 nickel 0 penny

*/

fn main() {
    assert_eq!(coins(0.1), "1 dime");
    assert_eq!(coins(0.01), "1 penny");
    assert_eq!(coins(0.28), "1 quarter 3 penny");
    assert_eq!(coins(0.56), "2 quarter 1 nickel 1 penny");
    assert_eq!(coins(1.43), "5 quarter 1 dime 1 nickel 3 penny");
}

fn coins(n: f64) -> String {
    let values = vec![25, 10, 5, 1];
    let strings = vec!["quarter", "dime", "nickel", "penny"];

    let mut x = (n * 100.0) as isize;
    let mut r = format!("");
    for i in 0..values.len() {
        if x <= 0 {
            break;
        }

        let p = x / values[i];
        if p != 0 {
            r = format!("{r} {} {}", p, strings[i]);
            x -= p * values[i];
        }
    }
    format!("{}", r.trim())
}
