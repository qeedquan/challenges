/*

Given a string of digits confirm whether the sum of all the individual even digits are greater than the sum of all the indiviudal odd digits. Always a string of numbers will be given.

If the sum of even numbers is greater than the odd numbers return: "Even is greater than Odd"

If the sum of odd numbers is greater than the sum of even numbers return: "Odd is greater than Even"

If the total of both even and odd numbers are identical return: "Even and Odd are the same"

*/

fn main() {
    assert_eq!(even_or_odd("12"), "Even is greater than Odd");
    assert_eq!(even_or_odd("123"), "Odd is greater than Even");
    assert_eq!(even_or_odd("112"), "Even and Odd are the same");
}

fn even_or_odd(string: &'static str) -> &'static str {
    let mut evens = 0;
    let mut odds = 0;
    for character in string.chars() {
        let mut value = character as u32;
        let zero = '0' as u32;
        if value >= zero {
            value -= zero;
        }

        match character {
            '0' | '2' | '4' | '6' | '8' => evens += value,
            '1' | '3' | '5' | '7' | '9' => odds += value,
            _ => (),
        }
    }
    if evens == odds {
        return "Even and Odd are the same";
    }
    if evens > odds {
        return "Even is greater than Odd";
    }
    return "Odd is greater than Even";
}
