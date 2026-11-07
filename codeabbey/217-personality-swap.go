/*

One of episodes of Futurama series is about Professor inventing personality-swapping machine - if two people use it, then their minds are exchanged and they can have fun wandering around in other one's body. However it soon appears, if people want to exchange back, machine woudn't work for the same pair of bodies.

This makes problem of returning personalities to their bodies somewhat complicated. It seems, however, that in general case it could be solved if we use two additional persons temporarily.

Problem Statement
We are given a set of several people, denoted with letters starting with A. They have exchanged personalities and we know the sequence of exchanges, like A-B, D-C etc (here letters refer to bodies, i.e. bodies A and B exchange personalities they contain, whatever these personalities are).

To return all their personalities to the proper bodies we now need another sequence of exchanges and (most probably) we need two additional people, (let's call them X and Y) temporarily.

As a result, every person should have his/her "self" back in his/her own body. Don't forget X and Y of course - don't leave them swapped :)

Input and Output
Input data will contain number of people N and number of swaps S in the first line. (and N is always small enough so that people "names" won't reach X and Y) Next line describes swap order - each consisting of two letters separated with dash; swapping pairs themselves are separated by space. Answer should have another sequence of personality swaps in the same format. There should be no same swaps in both sequences, and as result all personalities should be restored to respective bodies!

Example:

input data:
4 2
A-B C-D

answer:
B-D A-C D-A C-B
Note: supposing, that people's "souls" (i.e. personalities) are labeled with small letters a b c d (while capital letters mark the bodies), we have, after first sequence of swaps (given as input) situation described by A:b B:a C:d D:c. The next 4 swaps from the answer allow us to return to A:a B:b C:c D:d, even without using X and Y persons (but it was just luck).

*/

package main

import (
	"fmt"
	"slices"
)

type Person struct {
	mind string
	body string
}

func main() {
	test(4, []string{"A-B", "C-D"})
	test(2, []string{"A-B"})
	test(4, []string{"A-B", "B-C", "C-D"})
	test(5, []string{"A-B", "D-E"})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(size int, swaps []string) {
	people, transpositions, err := solve(size, swaps)
	if err != nil {
		panic(err)
	}

	fmt.Println(people)
	fmt.Println(transpositions)
	fmt.Println()

	for _, person := range people {
		assert(person.mind == person.body)
	}
}

// https://theinfosphere.org/Futurama_theorem
func solve(size int, swaps []string) ([]Person, []string, error) {
	people, mappings, err := parse(size, swaps)
	if err != nil {
		return nil, nil, err
	}

	transpositions := []string{}
	circles := circulars(people, mappings)
	helpera := &Person{"X", "X"}
	helperb := &Person{"Y", "Y"}
	for _, circle := range circles {
		transpositions = append(transpositions, fixup(circle, helpera, helperb)...)
	}
	if helpera.mind != helpera.body {
		swapmind(&transpositions, helpera, helperb)
	}
	people = append(people, *helpera)
	people = append(people, *helperb)
	return people, transpositions, nil
}

func parse(size int, swaps []string) (people []Person, mappings map[string]*Person, err error) {
	people = make([]Person, size)
	mappings = make(map[string]*Person)
	for index := range people {
		identity := fmt.Sprintf("%c", 'A'+index)
		people[index] = Person{identity, identity}
		mappings[identity] = &people[index]
	}

	for _, swap := range swaps {
		var from, to rune
		_, err = fmt.Sscanf(swap, "%c-%c", &from, &to)
		if err != nil {
			return
		}

		person1 := mappings[string(from)]
		person2 := mappings[string(to)]
		if person1 == nil || person2 == nil {
			err = fmt.Errorf("invalid swap %q", swap)
			return
		}
		person1.mind, person2.mind = person2.mind, person1.mind
	}
	return
}

func circulars(people []Person, mappings map[string]*Person) [][]*Person {
	circles := [][]*Person{}
	seen := make(map[string]bool)
	for index := range people {
		person := &people[index]
		if seen[person.body] {
			continue
		}

		circle := []*Person{}
		for !seen[person.body] {
			circle = append(circle, person)
			seen[person.body] = true
			person = mappings[person.mind]
		}
		slices.Reverse(circle)
		circles = append(circles, circle)
	}
	return circles
}

func fixup(circle []*Person, helpera, helperb *Person) []string {
	result := []string{}
	swapmind(&result, circle[0], helpera)
	for index := len(circle) - 1; index >= 0; index-- {
		swapmind(&result, circle[index], helperb)
	}
	swapmind(&result, circle[len(circle)-1], helpera)
	return result
}

func swapmind(result *[]string, person1, person2 *Person) {
	*result = append(*result, fmt.Sprintf("%s-%s", person1.mind, person2.mind))
	person1.mind, person2.mind = person2.mind, person1.mind
}
