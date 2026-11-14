/*

Given two string inputs of "Rock", "Paper", or "Scissors", determine the outcome of the RPS round. Output 1 if the first player wins, -1 if the second player wins, or 0 for a tie.

Rock Rock -> 0
Rock Paper -> -1
Rock Scissors -> 1
Paper Rock -> 1
Paper Paper -> 0
Paper Scissors -> -1
Scissors Rock -> -1
Scissors Paper -> 1
Scissors Scissors -> 0
You must use the exact strings "Rock", "Paper", and "Scissors" as inputs. You may choose whether the first players' choice is (consistently) given first or second. You may alternatively take them as a single input with a single-character or empty separator. The input is guaranteed one of the 9 possible pairings of the three choices in your input format.

The output should be a number 1, 0, or -1, or its string representation. Floats are fine. So are +1, +0, and -0.

Related: Coding an RPS game

https://codegolf.stackexchange.com/questions/11188/rock-paper-scissors

*/

fn main() {
    assert_eq!(score("Rock", "Rock"), 0);
    assert_eq!(score("Rock", "Paper"), -1);
    assert_eq!(score("Rock", "Scissors"), 1);
    assert_eq!(score("Paper", "Rock"), 1);
    assert_eq!(score("Paper", "Paper"), 0);
    assert_eq!(score("Paper", "Scissors"), -1);
    assert_eq!(score("Scissors", "Rock"), -1);
    assert_eq!(score("Scissors", "Paper"), 1);
    assert_eq!(score("Scissors", "Scissors"), 0);
}

fn score(s: &'static str, t: &'static str) -> isize {
    let rps = [[0, -1, 1], [1, 0, -1], [-1, 1, 0]];
    let i = index(s);
    let j = index(t);
    if i >= rps.len() || j >= rps[i].len() {
        return -1;
    }
    rps[i][j]
}

fn index(s: &'static str) -> usize {
    match &(*s.to_lowercase()) {
        "rock" => 0,
        "paper" => 1,
        "scissors" => 2,
        _ => 3,
    }
}
