/*

Story

Jumbo Juice makes a fresh juice out of fruits of your choice.
Jumbo Juice charges $5 for regular fruits and $7 for special ones.
Regular fruits are Banana, Orange, Apple, Lemon and Grapes.
Special ones are Avocado, Strawberry and Mango.
Others fruits that are not listed are also available upon request.
Those extra special fruits cost $9 per each.
There is no limit on how many fruits she/he picks.
The price of a cup of juice is the mean of price of chosen fruits.
In case of decimal number (ex. $5.99), output should be the nearest integer (use the standard rounding function of your language of choice).

Input

The function will receive an array of strings, each with the name of a fruit. The recognition of names should be case insensitive. There is no case of an empty array input.
Example

['Mango', 'Banana', 'Avocado'] //the price of this juice bottle is (7+5+7)/3 = $6($6.333333...)

*/

fn main() {
    assert_eq!(price(&vec!["Mango", "Banana", "Avocado"]), 6);
    assert_eq!(price(&vec!["banana", "mango", "avocado"]), 6);
    assert_eq!(price(&vec!["melon", "Mango", "kiwi"]), 8);
    assert_eq!(price(&vec!["watermelon", "cherry", "avocado"]), 8);
    assert_eq!(price(&vec!["apple", "Banana"]), 5);
    assert_eq!(price(&vec!["watermelon", "lime", "tomato"]), 9);
    assert_eq!(price(&vec!["blackBerry", "coconut", "avocado"]), 8);
    assert_eq!(price(&vec!["waterMelon", "mango"]), 8);
    assert_eq!(price(&vec!["watermelon", "pEach"]), 9);
    assert_eq!(price(&vec!["watermelon", "Orange", "grapes"]), 6);
    assert_eq!(price(&vec!["watermelon"]), 9);
    assert_eq!(price(&vec!["BlACKbeRrY", "cOcONuT", "avoCaDo"]), 8);
}

fn price(fruits: &Vec<&'static str>) -> isize {
    let mut total = 0.0;
    for &fruit in fruits {
        let fruit = fruit.to_lowercase();
        total += match &*fruit {
            "banana" | "orange" | "apple" | "lemon" | "grapes" => 5.00,
            "avocado" | "strawberry" | "mango" => 7.00,
            _ => 9.0,
        };
    }
    (total / fruits.len() as f64).round() as isize
}
