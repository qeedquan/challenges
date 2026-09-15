/*

One of my friends is always drunk. So, sometimes I get a bit confused whether he is drunk or not. So, one day I was talking to him, about his drinks! He began to describe his way of drinking. So, let me share his ideas a bit. I am expressing in my words.

There are many kinds of drinks, which he used to take. But there are some rules; there are some drinks that have some pre requisites. Suppose if you want to take wine, you should have taken soda, water before it. That's why to get real drunk is not that easy.

Now given the name of some drinks! And the prerequisites of the drinks, you have to say that whether it's possible to get drunk or not. To get drunk, a person should take all the drinks.

Input
Input starts with an integer T (≤ 50), denoting the number of test cases.

Each case starts with an integer m (1 ≤ m ≤ 10000). Each of the next m lines will contain two names each in the format a b, denoting that you must have a before having b. The names will be non-empty and contain at most 10 characters.

Output
For each case, print the case number and Yes or No, depending on whether it's possible to get drunk or not.

Sample
Input	Output
2
2
soda wine
water wine
3
soda wine
water wine
wine water

Case 1: Yes
Case 2: No

*/

package main

const (
	WHITE = iota
	GRAY
	BLACK
)

func main() {
	assert(solve([][2]string{
		[2]string{"soda", "wine"},
		[2]string{"water", "wine"},
	}) == "Yes")

	assert(solve([][2]string{
		[2]string{"soda", "wine"},
		[2]string{"water", "wine"},
		[2]string{"wine", "water"},
	}) == "No")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(drinks [][2]string) string {
	child := make(map[string][]string)
	colors := make(map[string]int)
	for _, drink := range drinks {
		a, b := drink[0], drink[1]
		child[a] = append(child[a], b)
		colors[a] = WHITE
		colors[b] = WHITE
	}

	drunk := true
	for name, node := range colors {
		if node == WHITE {
			dfs(child, colors, name, &drunk)
		}
		if !drunk {
			return "No"
		}
	}
	return "Yes"
}

func dfs(child map[string][]string, colors map[string]int, parent string, drunk *bool) {
	colors[parent] = GRAY
	for _, name := range child[parent] {
		switch colors[name] {
		case WHITE:
			dfs(child, colors, name, drunk)
		case GRAY:
			*drunk = false
			return
		}
	}
	colors[parent] = BLACK
}
