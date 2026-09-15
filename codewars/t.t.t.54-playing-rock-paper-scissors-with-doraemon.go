/*

Story
Do you know who is the Doraemon? If you don't know, please refer to this ( https://en.wikipedia.org/wiki/Doraemon ).

https://upload.wikimedia.org/wikipedia/en/c/c8/Doraemon_volume_1_cover.jpg

Nobita Nobi and Doraemon to play "Rock Paper Scissors" game. Every round of game, the winner can get two Dorayaki(a kind of dessert). If there is a tie, everyone gets a Dorayaki. Kind Nobita Nobi not always action "Paper", because they are good friends.

Task
Complete function game() that accepts a argument:

nobi: An array that contains Nobita Nobi's action in each round.

Returns how much Dorayaki that Nobita Nobi and Doraemon will get. The result should be an array that contains two elements like this:

[Nobita Nobi's Dorayaki, Doraemon's Dorayaki]

Hint: Doraemon is a robot cat without fingers.

Example
game(["[]","8<","()"])  ===  [3,3]

Nobita Nobi win 1 time, Doraemon win 1 time, tie 1 time
Nobita Nobi got: 1 * 2 + 1 = 3 Dorayaki
Doraemon got: 1 * 2 + 1 = 3 Dorayaki

game(["[]","8<","[]","8<","()","8<","()"])  ===  [6,8]

Nobita Nobi win 2 times, Doraemon win 3 times, tie 2 times

Nobita Nobi got: 2 * 2 + 2 = 6 Dorayaki
Doraemon got: 3 * 2 + 2 = 8 Dorayaki

*/

package main

import "fmt"

func main() {
	fmt.Println(game([]string{"[]", "8<", "()"}))
	fmt.Println(game([]string{"[]", "8<", "[]", "8<", "()", "8<", "()"}))
}

func game(nobi []string) (int, int) {
	var rock, paper, scissor int
	for _, move := range nobi {
		switch move {
		case "()":
			rock += 1
		case "[]":
			paper += 1
		case "8<":
			scissor += 1
		}
	}
	return 2*paper + rock, 2*scissor + rock
}
