/*

John has invited some friends. His list is:

s = "Fred:Corwill;Wilfred:Corwill;Barney:Tornbull;Betty:Tornbull;Bjon:Tornbull;Raphael:Corwill;Alfred:Corwill";

Could you make a program that

    makes this string uppercase
    gives it sorted in alphabetical order by last name.

When the last names are the same, sort them by first name. Last name and first name of a guest come in the result between parentheses separated by a comma.

So the result of function meeting(s) will be:

"(CORWILL, ALFRED)(CORWILL, FRED)(CORWILL, RAPHAEL)(CORWILL, WILFRED)(TORNBULL, BARNEY)(TORNBULL, BETTY)(TORNBULL, BJON)"

It can happen that in two distinct families with the same family name two people have the same first name too.
Notes

    You can see another examples in the "Sample tests".

*/

package main

import (
	"bytes"
	"fmt"
	"sort"
	"strings"
)

func main() {
	test("Fred:Corwill;Wilfred:Corwill;Barney:Tornbull;Betty:Tornbull;Bjon:Tornbull;Raphael:Corwill;Alfred:Corwill", "(CORWILL, ALFRED)(CORWILL, FRED)(CORWILL, RAPHAEL)(CORWILL, WILFRED)(TORNBULL, BARNEY)(TORNBULL, BETTY)(TORNBULL, BJON)")
	test("Alexis:Wahl;John:Bell;Victoria:Schwarz;Abba:Dorny;Grace:Meta;Ann:Arno;Madison:STAN;Alex:Cornwell;Lewis:Kern;Megan:Stan;Alex:Korn", "(ARNO, ANN)(BELL, JOHN)(CORNWELL, ALEX)(DORNY, ABBA)(KERN, LEWIS)(KORN, ALEX)(META, GRACE)(SCHWARZ, VICTORIA)(STAN, MADISON)(STAN, MEGAN)(WAHL, ALEXIS)")
	test("John:Gates;Michael:Wahl;Megan:Bell;Paul:Dorries;James:Dorny;Lewis:Steve;Alex:Meta;Elizabeth:Russel;Anna:Korn;Ann:Kern;Amber:Cornwell", "(BELL, MEGAN)(CORNWELL, AMBER)(DORNY, JAMES)(DORRIES, PAUL)(GATES, JOHN)(KERN, ANN)(KORN, ANNA)(META, ALEX)(RUSSEL, ELIZABETH)(STEVE, LEWIS)(WAHL, MICHAEL)")
	test("Alex:Arno;Alissa:Cornwell;Sarah:Bell;Andrew:Dorries;Ann:Kern;Haley:Arno;Paul:Dorny;Madison:Kern", "(ARNO, ALEX)(ARNO, HALEY)(BELL, SARAH)(CORNWELL, ALISSA)(DORNY, PAUL)(DORRIES, ANDREW)(KERN, ANN)(KERN, MADISON)")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(list, expected string) {
	result := meeting(list)
	fmt.Println(result)
	assert(result == expected)
}

func meeting(list string) string {
	people := strings.Split(list, ";")
	names := [][2]string{}
	for i := range people {
		name := strings.Split(people[i], ":")
		if len(name) != 2 {
			return "INVALID"
		}
		for i := range name {
			name[i] = strings.ToLower(name[i])
		}
		names = append(names, [2]string{name[0], name[1]})
	}

	sort.Slice(names, func(i, j int) bool {
		for n := 1; n >= 0; n-- {
			if names[i][n] < names[j][n] {
				return true
			}
			if names[i][n] > names[j][n] {
				return false
			}
		}
		return false
	})

	buf := new(bytes.Buffer)
	for _, name := range names {
		fmt.Fprintf(buf, "(%s, %s)", strings.ToUpper(name[1]), strings.ToUpper(name[0]))
	}
	return buf.String()
}
