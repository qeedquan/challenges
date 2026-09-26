/*

Alice and Bob are playing a game with marbles; you may have played this game in childhood. The game is playing by alternating turns. In each turn a player can take exactly one or two marbles.

Both Alice and Bob know the number of marbles initially. Now the game can be started by any one. But the winning condition depends on the player who starts it. If Alice starts first, then the player who takes the last marble loses the game. If Bob starts first, then the player who takes the last marble wins the game.

Now you are given the initial number of marbles and the name of the player who starts first. Then you have to find the winner of the game if both of them play optimally.

Input
Input starts with an integer T (≤ 10000), denoting the number of test cases.

Each case contains an integer n (1 ≤ n < 2^31) and the name of the player who starts first.

Output
For each case, print the case number and the name of the winning player.

Sample
Input	Output
3
1 Alice
2 Alice
3 Bob

Case 1: Bob
Case 2: Alice
Case 3: Alice

*/

fn main() {
    assert_eq!(solve(1, "Alice"), "Bob");
    assert_eq!(solve(2, "Alice"), "Alice");
    assert_eq!(solve(3, "Bob"), "Alice");
}

/*

Lets consider '1' as first move and '2' as 2nd move. we will try to win the first move(1) if possible.

If Alice start first,

If N = 1 2 wins. who takes last loses
If N = 2 1 wins. Alice takes 1 marble and Bob have to take last one.
If N = 3 1 wins. Alice takes 2 marble and Bob have to take last one.
If N = 4 2 wins. If Bob takes 1 marble opposite N(4-1) = 2 and if he takes 2 marble opposite N(4-2) =2, So it is garanted 2 wins. continue this process you will find pattern of 2 1 1 2 1 1 ...

Similarly, if Bob starts first, the pattern is 1 1 2 1 1 2 ...

*/

fn solve(turn: isize, player: &'static str) -> &'static str {
    if player == "Alice" {
        if turn % 3 == 1 {
            return "Bob";
        }
        return "Alice";
    }
    if turn % 3 != 0 {
        return "Bob";
    }
    return "Alice";
}
