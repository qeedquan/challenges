/*

When programming card games it is important to choose convenient internal representation for cards.

For humans the playing cards are identified by:

their rank i.e. 2, 3, ..., Queen, King, Ace;
and suit which can be one of four - Clubs, Spades, Diamonds and Hearts.
But for computer it is not handy. Computers want anything to be numbers. So instead it is nice to represent a card with a single integer value and derive its suit and rank when neccessary.

That is how it is usually done:

Let's use values 0, 1, 2, ..., 50, 51 to represent the cards of the full deck (52 in total).
To determine card's suit divide its value by 13, rounding down - you'll get the value 0, 1, 2 or 3.
To determine card's rank, take the remainder of division by 13 - the value from 0 to 12.
Now choose some arrangement of suits and of ranks (usually, relevant to your game) and put them into array of strings:

suits = ['Clubs', 'Spades', 'Diamonds', 'Hearts']
ranks = ['2', '3', '4', '5', '6', '7', '8', '9', '10', 'Jack', 'Queen', 'King', 'Ace']
and output the suit and the rank from these arrays according to indexes you've got by the rules above.

For example, if we have a card identified by value 23, the following calculations are done:

card_value = 23

suit_value = card_value / 13 = 23 / 13 = 1
rank_value = card_value % 13 = 23 % 13 = 10

suit = suits[suit_value] = suits[1] = 'Spades'
rank = ranks[rank_value] = ranks[10] = 'Queen'
Problem statement
You will be given several cards represented by their values (from 0 to 51). You will need to print out their names.

Input data will contain the amount of cards in the first line.
Next line will contain the card values themselves.
Answer should contains card names in form Rank-of-Suit, e.g. Queen-of-Spades, 2-of-Clubs separated with spaces. Use the names as given above.

Example:

input data:
5
25 32 51 20 6

answer:
Ace-of-Spades 8-of-Diamonds Ace-of-Hearts 9-of-Spades 8-of-Clubs

*/

fn main() {
    assert_eq!(card(25), "Ace-of-Spades");
    assert_eq!(card(32), "8-of-Diamonds");
    assert_eq!(card(51), "Ace-of-Hearts");
    assert_eq!(card(20), "9-of-Spades");
    assert_eq!(card(6), "8-of-Clubs");
    for i in 0..=51 {
        println!("{} {}", i, card(i));
    }
}

fn card(value: usize) -> String {
    let suits = ["Clubs", "Spades", "Diamonds", "Hearts"];
    let ranks = [
        "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace",
    ];
    if value > 51 {
        format!("Invalid")
    } else {
        format!("{}-of-{}", ranks[value % 13], suits[value / 13])
    }
}
