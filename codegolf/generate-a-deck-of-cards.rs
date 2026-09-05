/*

Here's an array representing a standard deck of cards, including two Jokers.

[
  "AS", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "10S", "JS", "QS", "KS", 
  "AD", "2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "10D", "JD", "QD", "KD", 
  "AH", "2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "10H", "JH", "QH", "KH", 
  "AC", "2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "10C", "JC", "QC", "KC", 
  "J", "J"
]

It's composed in this manner:

There are four suits; hearts, spades, diamonds, and clubs (H, S, D, C).
Each suit has one card for the numbers 2 to 10, plus 4 'picture' cards, Ace, Jack, Queen, and King (A, J, Q, K).
For each combination of suit and value, there should be one item in the array, which is a string, and is made up of the value followed by the suit (Whitespace between these is permitted).
On top of that, there are two Joker cards ('J').
Write in any language you please.
Golf it up! Try to produce this output in the smallest number of bytes.
It does not matter what order the output is in.

*/

fn main() {
    let cards = vec![
        "AS", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "10S", "JS", "QS", "KS", "AD", "2D",
        "3D", "4D", "5D", "6D", "7D", "8D", "9D", "10D", "JD", "QD", "KD", "AH", "2H", "3H", "4H",
        "5H", "6H", "7H", "8H", "9H", "10H", "JH", "QH", "KH", "AC", "2C", "3C", "4C", "5C", "6C",
        "7C", "8C", "9C", "10C", "JC", "QC", "KC", "J", "J",
    ];

    for card in cards {
        print!("{} ", card);
    }
    println!();
}
