/*

To celebrate the start of the Rio Olympics (and the return of 'the Last Leg' on C4 tonight) this is an Olympic inspired kata.

Given a string of random letters, you need to examine each. Some letters naturally have 'rings' in them. 'O' is an obvious example, but 'b', 'p', 'e', 'A', etc are all just as applicable. 'B' even has two!! Please note for this kata you can count lower case 'g' as only one ring.

Your job is to count the 'rings' in each letter and divide the total number by 2. Round the answer down. Once you have your final score:

if score is 1 or less, return 'Not even a medal!'; if score is 2, return 'Bronze!'; if score is 3, return 'Silver!'; if score is more than 3, return 'Gold!';

Dots over i's and any other letters don't count as rings.

*/

fn main() {
    assert_eq!(olympic("wHjMudLwtoPGocnJ"), "Bronze!");
    assert_eq!(olympic("eCEHWEPwwnvzMicyaRjk"), "Bronze!");
    assert_eq!(olympic("JKniLfLW"), "Not even a medal!");
    assert_eq!(olympic("BBBBBBBBBBBBBBBBBBBBB"), "Gold!");
}

fn olympic(string: &'static str) -> &'static str {
    let mut count = 0;
    for character in string.chars() {
        match character {
            'a' | 'b' | 'd' | 'e' | 'g' | 'o' | 'p' | 'q' | 'A' | 'D' | 'O' | 'P' | 'Q' | 'R' => {
                count += 1
            }
            'B' => count += 2,
            _ => (),
        };
    }
    count /= 2;

    if count < 2 {
        return "Not even a medal!";
    }
    if count == 2 {
        return "Bronze!";
    }
    if count == 3 {
        return "Silver!";
    }
    return "Gold!";
}
