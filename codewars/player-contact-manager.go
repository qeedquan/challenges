/*

You are the Dungeon Master for a public DnD game at your local comic shop and recently you've had some trouble keeping your players' info neat and organized so you've decided to write a bit of code to help keep them sorted!

The goal of this code is to create an array of objects that stores a player's name and contact number from a given string.

The method should return an empty array if the argument passed is an empty string or nil/None/null.

Examples
player_manager("John Doe, 8167238327, Jane Doe, 8163723827") returns [{player: "John Doe", contact: 8167238327}, {player: "Jane Doe", contact: 8163723827}]
player_manager(nil) returns []
player_manager("") returns []
playerManager("John Doe, 8167238327, Jane Doe, 8163723827") returns [{player: "John Doe", contact: 8167238327}, {player: "Jane Doe", contact: 8163723827}]
playerManager(null) returns []
playerManager("")   returns []

Have at thee!

*/

package main

import (
	"fmt"
	"strconv"
	"strings"
)

type Info struct {
	player  string
	contact int
}

func main() {
	fmt.Println(playermanager("John Doe, 8167238327, Jane Doe, 8163723827"))
	fmt.Println(playermanager(""))
}

func playermanager(data string) []Info {
	var infos []Info
	tokens := strings.Split(data, ",")
	for i := 0; i+1 < len(tokens); i += 2 {
		contact, _ := strconv.Atoi(strings.TrimSpace(tokens[i+1]))
		infos = append(infos, Info{
			player:  strings.TrimSpace(tokens[i]),
			contact: contact,
		})
	}
	return infos
}
