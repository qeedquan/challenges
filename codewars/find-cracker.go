/*

Someone was hacking the score. Each student's record is given as an array The objects in the array are given again as an array of scores for each name and total score. ex>

var array = [
  ["name1", 445, ["B", "A", "A", "C", "A", "A"]],
  ["name2", 110, ["B", "A", "A", "A"]],
  ["name3", 200, ["B", "A", "A", "C"]],
  ["name4", 200, ["A", "A", "A", "A", "A", "A", "A"]]
];
The scores for each grade is:

A: 30 points
B: 20 points
C: 10 points
D: 5 points
Everything else: 0 points
If there are 5 or more courses and all courses has a grade of B or above, additional 20 points are awarded. After all the calculations, the total score should be capped at 200 points.

Returns the name of the hacked name as an array when scoring with this rule.

var array = [
  ["name1", 445, ["B", "A", "A", "C", "A", "A"]],     // name1 total point is over 200 => hacked
  ["name2", 110, ["B", "A", "A", "A"]],               // name2 point is right
  ["name3", 200, ["B", "A", "A", "C"]],               // name3 point is 200 but real point is 90 => hacked
  ,
  ["name4", 200, ["A", "A", "A", "A", "A", "A", "A"]] // name4 point is right
];

return ["name1", "name3"];

*/

package main

import (
	"fmt"
	"reflect"
)

type Record struct {
	name   string
	score  int
	grades []string
}

func main() {
	test([]Record{
		{"name1", 445, []string{"B", "A", "A", "C", "A", "A"}},
		{"name2", 110, []string{"B", "A", "A", "A"}},
		{"name3", 200, []string{"B", "A", "A", "C"}},
		{"name4", 200, []string{"A", "A", "A", "A", "A", "A", "A"}},
	}, []string{"name1", "name3"})

	test([]Record{
		{"name1", 150, []string{"B", "A", "A", "C", "A", "A"}},
		{"name2", 120, []string{"B", "A", "A", "A"}},
		{"name3", 160, []string{"B", "A", "A", "A", "A"}},
		{"name4", 140, []string{"B", "A", "A", "C", "A"}},
	}, []string{"name2", "name4"})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(records []Record, expected []string) {
	result := findhack(records)
	fmt.Println(result)
	assert(reflect.DeepEqual(result, expected))
}

func findhack(records []Record) []string {
	result := []string{}
	for _, record := range records {
		if record.score > 200 {
			result = append(result, record.name)
			continue
		}

		score := 0
		bonus := 0
		if len(record.grades) >= 5 {
			bonus = 20
		}
		for _, grade := range record.grades {
			switch grade {
			case "A":
				score += 30
				continue
			case "B":
				score += 20
				continue
			case "C":
				score += 10
			case "D":
				score += 5
			}
			bonus = 0
		}
		score = min(score+bonus, 200)

		if record.score != score {
			result = append(result, record.name)
		}
	}
	return result
}
