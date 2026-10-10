/*

I am the father of three wonderful sons.
Before the beginning of the school year, I promised them that I would buy a bicycle for someone who would bring the best marks at the end of the school year.
It's time to keep promises and I count on you.

You have 3 input objects(school diaries) with school subjects and marks (1-10). For example:

{
  'algebra': 6,
  'history': 8,
  'physics': 9,
  'geography': 2,
  'chemistry': 9
}

Return please :

'I need to buy a bicycle for my first son.' // the sum of the marks is the highest  in the first diary.

'I need to buy a bicycle for my second son.' // the sum of the marks is the highest in the second diary.

'I need to buy a bicycle for my third son.' //  the sum of the marks is the highest in the third diary.

If two or three sons have the same highest marks, you need to choose the younger one. Use the age table which is constant and preloaded:

const ageTable = {
                  'firstSonAge': 14,
                  'secondSonAge': 9,
                  'thirdSonAge': 8
                }

*/

package main

import (
	"fmt"
	"sort"
)

func main() {
	diary := map[string]int{
		"algebra":   6,
		"history":   8,
		"physics":   9,
		"geography": 2,
		"chemistry": 9,
	}

	fmt.Println(whosebicycle(diary, diary, diary))
}

func whosebicycle(diary1, diary2, diary3 map[string]int) string {
	ordinal := []string{"first", "second", "third"}
	scores := [3][3]int{
		{0, 14, 0},
		{0, 9, 1},
		{0, 8, 2},
	}

	for _, score := range diary1 {
		scores[0][0] += score
	}
	for _, score := range diary2 {
		scores[1][0] += score
	}
	for _, score := range diary3 {
		scores[2][0] += score
	}

	sort.Slice(scores[:], func(i, j int) bool {
		if scores[i][0] == scores[j][0] {
			return scores[i][1] < scores[j][1]
		}
		return scores[i][0] < scores[j][0]
	})

	return fmt.Sprintf("I need to buy a bicycle for my %s son.", ordinal[scores[0][2]])
}
