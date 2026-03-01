/*

In this kata, your task is to implement an extended version of the famous rock-paper-scissors game. The rules are as follows:

Scissors cuts Paper
Paper covers Rock
Rock crushes Lizard
Lizard poisons Spock
Spock smashes Scissors
Scissors decapitates Lizard
Lizard eats Paper
Paper disproves Spock
Spock vaporizes Rock
Rock crushes Scissors

Task:
Given two values from the above game, return the Player result as "Player 1 Won!", "Player 2 Won!", or "Draw!".

Inputs
Values will be given as one of "rock", "paper", "scissors", "lizard", "spock".

https://imgur.com/BWDszrL

*/

fn main() {
    assert_eq!(outcome("scissors", "paper"), "Player 1 Won!");
    assert_eq!(outcome("paper", "rock"), "Player 1 Won!");
    assert_eq!(outcome("rock", "lizard"), "Player 1 Won!");
    assert_eq!(outcome("lizard", "spock"), "Player 1 Won!");
    assert_eq!(outcome("spock", "scissors"), "Player 1 Won!");
    assert_eq!(outcome("scissors", "lizard"), "Player 1 Won!");
    assert_eq!(outcome("lizard", "paper"), "Player 1 Won!");
    assert_eq!(outcome("paper", "spock"), "Player 1 Won!");
    assert_eq!(outcome("spock", "rock"), "Player 1 Won!");
    assert_eq!(outcome("rock", "scissors"), "Player 1 Won!");

    assert_eq!(outcome("paper", "scissors"), "Player 2 Won!");
    assert_eq!(outcome("rock", "paper"), "Player 2 Won!");
    assert_eq!(outcome("lizard", "rock"), "Player 2 Won!");
    assert_eq!(outcome("spock", "lizard"), "Player 2 Won!");
    assert_eq!(outcome("scissors", "spock"), "Player 2 Won!");
    assert_eq!(outcome("lizard", "scissors"), "Player 2 Won!");
    assert_eq!(outcome("paper", "lizard"), "Player 2 Won!");
    assert_eq!(outcome("spock", "paper"), "Player 2 Won!");
    assert_eq!(outcome("rock", "spock"), "Player 2 Won!");
    assert_eq!(outcome("scissors", "rock"), "Player 2 Won!");

    assert_eq!(outcome("rock", "rock"), "Draw!");
    assert_eq!(outcome("paper", "paper"), "Draw!");
    assert_eq!(outcome("scissors", "scissors"), "Draw!");
    assert_eq!(outcome("lizard", "lizard"), "Draw!");
    assert_eq!(outcome("spock", "spock"), "Draw!");
}

fn outcome(s: &'static str, t: &'static str) -> String {
    let tab = vec![
        [0, 2, 1, 1, 2],
        [1, 0, 2, 2, 1],
        [2, 1, 0, 1, 2],
        [2, 1, 2, 0, 1],
        [1, 2, 1, 2, 0],
    ];

    let i = index(s);
    let j = index(t);
    if i >= tab.len() || j >= tab.len() {
        return format!("Invalid");
    }
    if tab[i][j] == 0 {
        return format!("Draw!");
    }
    return format!("Player {} Won!", tab[i][j]);
}

fn index(s: &'static str) -> usize {
    match s {
        "rock" => 0,
        "paper" => 1,
        "scissors" => 2,
        "lizard" => 3,
        "spock" => 4,
        _ => usize::MAX,
    }
}
