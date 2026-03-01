#!/usr/bin/env python3

"""

Task
Your task is to write a program that always wins its opponent in rock-paper-scissors.

Instructions
The game is based on classic rock paper scissors, except the program always wins.

If player chooses rock, program chooses rock killer, which is paper. If player chooses paper, program chooses paper killer, which is scissors, and so on.

Rules
After player chooses, output must be

You choose <player choice>.[newline] Computer chooses <player choice killer>. You lose!.

Please note that there must be a newline after outputting player choice. Output must contain the choices as words (rock, raper, scissors), not as characters, such as R, P or S. Word libraries are allowed.

If input is invalid, program must output invalid choice and ask again until the choice is valid. Program must ask for another round Want to try again? (y/n) and continue playing until n is received. Newlines after all of these actions.

This is code golf, so shortest code wins. Good luck!

"""

def play(choice):
    selection = {"rock": "paper", "paper": "scissor", "scissor": "rock"}
    return selection[choice]

def main():
    assert(play("rock") == "paper")
    assert(play("paper") == "scissor")
    assert(play("scissor") == "rock")

main()
