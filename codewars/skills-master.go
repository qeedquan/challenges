/*

Description
Below is described a skill tree:

https://gist.githubusercontent.com/el-f/387770bf21b35add9a694c829b7df855/raw/b2c8c551177d3220f48c58ada2e1902462c1206e/tree.svg

Tree
The array that describes this skill tree is as follows:

[
 0, # 0 is the root and does not depend on any skill.
 0, # 1 is unlocked by skill 0 (skill at index 0).
 0, # 2 is unlocked by skill 0.
 1, # 3 is unlocked by skill 1.
 3, # 4 is unlocked by skill 3.
 3, # 5 is unlocked by skill 3.
 2  # 6 is unlocked by skill 2.
]

In another words, each skill is identified by its index in the array, and its value identifies the skill that unlocks it.

Your Task:
Given a skill tree described as an array and a set of required skills, return the total number of skills needed to learn all of the required skills.

Intuition: In the example's tree, if I want to learn skill 6, I first need to learn skills 0 and 2 - a total of 3 skills learned.

Examples:

countSkills([ 0, 0, 0, 1, 3, 3, 2 ], new Set([ 6 ]));     -> 3
countSkills([ 0, 0, 0, 1, 3, 3, 2 ], new Set());          -> 0
countSkills([ 0, 0, 0, 1, 3, 3, 2 ], new Set([ 1, 2 ]));  -> 3

Constraints:
Each skill is only unlocked by exactly one skill!
Skills can unlock any number of skills.
Inputs are always valid and each skill can be unlocked by some other skill, except 0.
0≤len(tree)≤200000
0≤len(tree)≤200000
0≤len(required)≤len(tree)
0≤len(required)≤len(tree)

Notes:
You need to be somewhat efficient with your approach.
You are provided with 2 functions in preloaded to help you debug:
build_tree/buildTree - convert a tree array into a dict/Map describing which skills each skill unlocks.
visualize_tree/visualiseTree/visualizeTree - get a visual representation of the given tree array.

*/

package main

func main() {
	tree := []int{0, 0, 0, 1, 3, 3, 2}
	assert(countskills(tree, []int{6}) == 3)
	assert(countskills(tree, []int{}) == 0)
	assert(countskills(tree, []int{1, 2}) == 3)
	assert(countskills(tree, []int{}) == 0)
	assert(countskills(tree, []int{0}) == 1)
	assert(countskills(tree, []int{2}) == 2)
	assert(countskills(tree, []int{3}) == 3)
	assert(countskills(tree, []int{1, 2}) == 3)
	assert(countskills(tree, []int{3, 6}) == 5)
	assert(countskills(tree, []int{4}) == 4)
	assert(countskills(tree, []int{5}) == 4)
	assert(countskills(tree, []int{4, 5}) == 5)
	assert(countskills(tree, []int{1, 2, 3}) == 4)
	assert(countskills(tree, []int{0, 1, 2, 3, 4, 5, 6}) == 7)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func countskills(tree, required []int) int {
	visited := make(map[int]bool)
	for _, skill := range required {
		traverse(skill, tree, visited)
	}
	return len(visited)
}

func traverse(skill int, tree []int, visited map[int]bool) {
	for skill != 0 && !visited[skill] {
		visited[skill] = true
		skill = tree[skill]
	}
	visited[0] = true
}
