/*

You will be given an array which will include both integers and characters.

Return an array of length 2 with a[0] representing the mean of the ten integers as a floating point number. There will always be 10 integers and 10 characters. Create a single string with the characters and return it as a[1] while maintaining the original order.

lst = ['u', '6', 'd', '1', 'i', 'w', '6', 's', 't', '4', 'a', '6', 'g', '1', '2', 'w', '8', 'o', '2', '0']
Here is an example of your return

[3.6, "udiwstagwo"]

In C# and Java the mean return is a double.

*/

fn main() {
    println!(
        "{:?}",
        mean(&[
            'u', '6', 'd', '1', 'i', 'w', '6', 's', 't', '4', 'a', '6', 'g', '1', '2', 'w', '8',
            'o', '2', '0'
        ])
    );
}

fn mean(list: &[char]) -> (f64, String) {
    let mut numerator = 0.0;
    let mut denominator = 0.0;
    let mut string = String::new();
    for &symbol in list {
        match symbol {
            '0'..='9' => {
                numerator += todigit(symbol);
                denominator += 1.0;
            }
            _ => string.push(symbol),
        }
    }
    (numerator / denominator, string)
}

fn todigit(symbol: char) -> f64 {
    let value = symbol as u32 - '0' as u32;
    value as f64
}
