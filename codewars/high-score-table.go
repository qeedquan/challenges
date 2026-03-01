/*

You just got done writing a function that calculates the player's final score for your new game, "Flight of the cockatoo".

Now all you need is a high score table that can be updated with the player's final scores. With such a feature, the player will be motivated to try to beat his previous scores, and hopefully, never stop playing your game.

The high score table will start out empty. A limit to the size of the table will be specified upon creation of the table.

Here's an example of the expected behavior of the high score table :

highScoreTable = HighScoreTable(3)
highScoreTable.scores == [] # evaluates to True
highScoreTable.update(10)
highScoreTable.scores == [10]
highScoreTable.update(8)
highScoreTable.update(12)
highScoreTable.update(5)
highScoreTable.update(10)
highScoreTable.scores == [12, 10, 10]
highScoreTable.reset()
highScoreTable.scores == []
# And so on...

*/

package main

import (
	"slices"
	"sort"
)

func main() {
	highScoreTable := newHighScoreTable(3)
	assert(slices.Equal(highScoreTable.scores, []int{}))
	highScoreTable.update(10)
	assert(slices.Equal(highScoreTable.scores, []int{10}))
	highScoreTable.update(8)
	highScoreTable.update(12)
	highScoreTable.update(5)
	highScoreTable.update(10)
	assert(slices.Equal(highScoreTable.scores, []int{12, 10, 10}))
	highScoreTable.reset()
	assert(slices.Equal(highScoreTable.scores, []int{}))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type HighScoreTable struct {
	limit  int
	scores []int
}

func newHighScoreTable(limit int) *HighScoreTable {
	return &HighScoreTable{limit: limit}
}

func (h *HighScoreTable) update(score int) {
	h.scores = append(h.scores, score)
	sort.Slice(h.scores, func(i, j int) bool {
		return h.scores[i] > h.scores[j]
	})
	if len(h.scores) > h.limit {
		h.scores = h.scores[:h.limit]
	}
}

func (h *HighScoreTable) reset() {
	h.scores = h.scores[:0]
}
