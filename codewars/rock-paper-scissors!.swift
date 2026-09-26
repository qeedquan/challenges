/*

Rock Paper Scissors
Let's play! You have to return which player won! In case of a draw return Draw!.

Examples:

rps('scissors','paper') // Player 1 won!
rps('scissors','rock') // Player 2 won!
rps('paper','paper') // Draw!

*/

func rps(_ p1: String, _ p2: String) -> String {
    switch (p1, p2) {
    case ("scissors", "paper"), ("paper", "rock"), ("rock", "scissors"):
        return "Player 1 won!"
    case ("paper", "scissors"), ("rock", "paper"), ("scissors", "rock"):
        return "Player 2 won!"
    default:
        return "Draw!"
    }
}

assert(rps("scissors", "paper") == "Player 1 won!")
assert(rps("scissors", "rock") == "Player 2 won!")
assert(rps("paper", "paper") == "Draw!")
