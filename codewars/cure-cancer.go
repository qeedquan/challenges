/*

Now you are a doctor.

You are working with a patient's **body** which has many cells.

The patient's body is a matrix where every row represents a cell.

Each cell contains just uppercase and lowercase letters,

and every cell in the body should be the same.

Oh, no! It seems that one of the cells have mutated!

It is your job to locate the mutation so that the chemo specialists can fix it!

return the location [i,j] within the matrix...

before it's too late! :(

example:

    cellscellscellscodecodecells
    cellscellscellscodecodecells
    cellscellscellscodecodecells
    cellscellscellscodecodecells
    cellscellscellscodecodecells
    cellscellscellscodecodecells
    cellscellscellscodecodecells
    cellscellscellscodecodecells
    cellscellscellscodecodecells
    cellscellscellscodecadecells <- here it is! [20, 9]
    cellscellscellscodecodecells
    cellscellscellscodecodecells
    cellscellscellscodecodecells
    cellscellscellscodecodecells

no bodies will have less than 3 cells.

if the diagnosis was a false alarm, return an empty array.

*/

package main

func main() {
	assert(mutation([][]byte{
		[]byte("WellAndHealthy"),
		[]byte("WellAndHealthy"),
		[]byte("WellAndHealthy"),
		[]byte("WellAndHealthy"),
	}) == [2]int{0, 0})

	assert(mutation([][]byte{
		[]byte("thisssAsmallerPerson"),
		[]byte("thisIsAsmallerPerson"),
		[]byte("thisIsAsmallerPerson"),
		[]byte("thisIsAsmallerPerson"),
	}) == [2]int{0, 4})

	assert(mutation([][]byte{
		[]byte("thisIsAsmallerPerson"),
		[]byte("thisssAsmallerPerson"),
		[]byte("thisIsAsmallerPerson"),
		[]byte("thisIsAsmallerPerson"),
	}) == [2]int{1, 4})

	assert(mutation([][]byte{
		[]byte("thisIsAsmallerPerson"),
		[]byte("thisIsAsmallerPerson"),
		[]byte("thisssAsmallerPerson"),
		[]byte("thisIsAsmallerPerson"),
	}) == [2]int{2, 4})

	assert(mutation([][]byte{
		[]byte("thisIsAsmallerPerson"),
		[]byte("thisIsAsmallerPerson"),
		[]byte("thisIsAsmallerPerson"),
		[]byte("thisssAsmallerPerson"),
	}) == [2]int{3, 4})

	assert(mutation([][]byte{
		[]byte("someGreaTstuffIthinkThisIs"),
		[]byte("someGreaTstuffIthinkThisIs"),
		[]byte("someGreaTstuffIthinkThisIs"),
		[]byte("someGreaTstuffIthinkThisIs"),
		[]byte("someGreaTstuffIthinkThisIs"),
		[]byte("someGreaTstuffIthinkThisIs"),
		[]byte("someGreaTstuffIthinkThisIs"),
		[]byte("someGreaTstuffIthinkThisIs"),
		[]byte("someGreaTstuffIthinkThisIs"),
		[]byte("someGreaTstuff1thinkThisIs"),
		[]byte("someGreaTstuffIthinkThisIs"),
		[]byte("someGreaTstuffIthinkThisIs"),
		[]byte("someGreaTstuffIthinkThisIs"),
		[]byte("someGreaTstuffIthinkThisIs"),
		[]byte("someGreaTstuffIthinkThisIs"),
		[]byte("someGreaTstuffIthinkThisIs"),
	}) == [2]int{9, 14})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func mutation(body [][]byte) [2]int {
	for i := 1; i < len(body); i++ {
		for j := range body[i] {
			if body[0][j] != body[i][j] {
				if i > 1 || body[0][j] == body[2][j] {
					return [2]int{i, j}
				}
				return [2]int{0, j}
			}
		}
	}
	return [2]int{0, 0}
}
