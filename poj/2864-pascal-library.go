/*

Description

Pascal University, one of the oldest in the country, needs to renovate its Library Building, because after all these centuries the building started to show the effects of supporting the weight of the enormous amount of books it houses.

To help in the renovation, the Alumni Association of the University decided to organize a series of fund-raising dinners, for which all alumni were invited. These events proved to be a huge success and several were organized during the past year. (One of the reasons for the success of this initiative seems to be the fact that students that went through the Pascal system of education have fond memories of that time and would love to see a renovated Pascal Library.)

The organizers maintained a spreadsheet indicating which alumni participated in each dinner. Now they want your help to determine whether any alumnus or alumna took part in all of the dinners.

Input

The input contains several test cases. The first line of a test case contains two integers N and D indicating respectively the number of alumni and the number of dinners organized (1 <= N <= 100 and 1 <= D <= 500). Alumni are identified by integers from 1 to N. Each of the next D lines describes the attendees of a dinner, and contains N integers Xi indicating if the alumnus/alumna i attended that dinner (Xi = 1) or not (Xi = 0). The end of input is indicated by N = D = 0.

Output

For each test case in the input your program must produce one line of output, containing either the word `yes', in case there exists at least one alumnus/alumna that attended all dinners, or the word `no' otherwise.

Sample Input

3 3
1 1 1
0 1 1
1 1 1
7 2
1 0 1 0 1 0 1
0 1 0 1 0 1 0
0 0

Sample Output

yes
no

Hint

Alumna: a former female student of a particular school, college or university.
Alumnus: a former male student of a particular school, college or university.
Alumni: former students of either sex of a particular school, college or university.

Source

South America 2005

*/

package main

func main() {
	assert(alldinners([][]int{
		{1, 1, 1},
		{0, 1, 1},
		{1, 1, 1},
	}) == true)

	assert(alldinners([][]int{
		{1, 0, 1, 0, 1, 0, 1},
		{0, 1, 0, 1, 0, 1, 0},
	}) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func alldinners(m [][]int) bool {
	if len(m) == 0 || len(m[0]) == 0 {
		return true
	}
	w, h := len(m[0]), len(m)

	p := make([]int, w)
	for i := range p {
		p[i] = 1
	}

	for y := 0; y < h; y++ {
		for x := 0; x < w; x++ {
			p[x] &= m[y][x]
		}
	}

	r := 0
	for x := 0; x < w; x++ {
		r |= p[x]
	}
	return r != 0
}
