/*

I have a friend with a peculiar habit (more, a long-running joke) of introducing everyone present at an event in this fashion:

Alice, Bob. Bob, Tom. Tom, Bob. Bob...

When there are more than a few people, the number of such introductions can grow quite large and they will proceed until satisfied with the joke. In this problem, though, we want to completely introduce a group of people.

Task
Given a set of unique names L, output a permutation of all the possible introductions (ordered pairs) between different names in L.
The output introductions (except the first) must each begin with the previous introduction's second name.
The output may be a list of ordered pairs, or may be "flat" as just a list of names. As long as the answer could be read off by a host to introduce their guests, you're good.

This is code-golf, so fewest bytes wins!

Test Cases
These represent some possible solutions for various inputs

{a,b}   -> [(a,b), (b,a)]
{a,b,c} -> [(a,b), (b,c), (c,a), (a,c), (c,b), (b,a)]
{a,b,c} -> [a, b, b, a, a, c, c, b, b, c, c, a]

*/

package main

import "fmt"

func main() {
	fmt.Println(pairs([]string{"a", "b"}))
	fmt.Println(pairs([]string{"a", "b", "c"}))
	fmt.Println(pairs([]string{"Alice", "Bob", "Tom"}))
}

func pairs(s []string) [][2]string {
	r := [][2]string{}
	m := make(map[[2]string]bool)
	n := len(s)
	i := 0
	j := n - 1
	for ; i < n; i++ {
		if i == j {
			continue
		}

		k := [2]string{s[j], s[i]}
		if !m[k] {
			r = append(r, k)
			m[k] = true
			j = i
			i = -1
		}
	}
	return r
}
