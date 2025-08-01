#!/usr/bin/env swipl

/*

Theme Week:
Welcome to my first attempt at a theme week. All week long the challenges will be related to this fascinating advanced version of the game Rock Paper Scissors. We will explore the depths of this game like none have before.

Description:
The best way to see this game and understand the rules is to do some basic research.

[Wikipedia Entry Link] (http://en.wikipedia.org/wiki/Rock-paper-scissors-lizard-Spock)

[Instructional Video] (https://www.youtube.com/watch?v=iapcKVn7DdY)

The challenge is to implement a basic game of Rock Paper Scissors Lizard Spock (to be called RPSLP for short). Your game will get the human choice. The computer AI will randomly pick a move. It will compare the results and display the moves and the out come (who wins or if a tie)

Input:
Get from the user their move being Rock, Paper Scissors, Lizard, Spock. Design and how you do it is up to you all.

Output:
Once the human move is obtained have the computer randomly pick their move. Display the moves back to the user and then give the results.

Again the exact design is up to you as long as the output shows the moves again and the result of the game (who wins or if a tie).

Example Output:
Player Picks: Rock. 
Computer Picks: Spock.

Spock Vaporizes Rock. Computer Wins!
For Weds:
As this is a theme challenge. Weds we continue with a more intermediate approach to the game. To plan ahead please consider in your design some ability to have a human choice be compared to a computer choice or a computer to play itself as well.

Extra Challenge:
The game loops and continues to play matches until the user quits or a fixed number of games is played. At the end it records some basic stats.

Total Games played

Computer Wins (Number and percentage)

Human Wins (Number and percentage)

Ties (Number and Percentage)

*/

beats(scissors, paper, 'Scissors cut paper').
beats(scissors, lizard, 'Scissors decapitate lizard').
beats(paper, rock, 'Paper covers rock').
beats(paper, spock, 'Paper disproves Spock').
beats(rock, lizard, 'Rock crushes lizard').
beats(rock, scissors, 'Rock crushes scissors').
beats(lizard, spock, 'Lizard poisons Spock').
beats(lizard, paper, 'Lizard eats paper').
beats(spock, scissors, 'Spock smashes scissors').
beats(spock, rock, 'Spock vaporizes rock').

score(X, X, 'It is a tie!', 'No winner.').
score(H, C, Msg, 'You win!') :- beats(H, C, Msg).
score(H, C, Msg, 'Computer wins!') :- beats(C, H, Msg).

play(H) :-
    random_member(C, [scissors, paper, rock, lizard, spock]),
    score(H, C, Msg, Result),
    write('You chose '), writeln(H),
    write('Computer chose '), writeln(C),
    writeln(Msg),
    writeln(Result).
