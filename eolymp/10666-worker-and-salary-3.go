/*

Each worker receives their salary several times during the year. Output the surnames of the workers along with their total salaries at the end of the year, sorted in ascending order by surname.

Input
Each line contains information about a worker: their surname and the salary they received. The same worker may appear in the list multiple times, which means they received their salary multiple times throughout the year.

Output
Print the surnames and the total salaries received by each worker during the entire year, in ascending order by surname. For each surname, output the sum of all salaries they received.

Examples

Input #1
Sidorov 100
Mamedov 150
Mamedov 250
Sidorov 110
Ivanov 200
Petrov 120
Sidorov 160
Ivanov 270

Answer #1
Ivanov 470
Mamedov 400
Petrov 120
Sidorov 370

*/

package main

import (
	"fmt"
	"sort"
)

type Worker struct {
	name   string
	salary int
}

func main() {
	fmt.Println(solve([]Worker{
		{"Sidorov", 100},
		{"Mamedov", 150},
		{"Mamedov", 250},
		{"Sidorov", 110},
		{"Ivanov", 200},
		{"Petrov", 120},
		{"Sidorov", 160},
		{"Ivanov", 270},
	}))
}

func solve(workers []Worker) []Worker {
	table := make(map[string]int)
	for _, worker := range workers {
		table[worker.name] += worker.salary
	}

	var result []Worker
	for name, salary := range table {
		result = append(result, Worker{name, salary})
	}

	sort.Slice(result, func(i, j int) bool {
		return result[i].name < result[j].name
	})
	return result
}
