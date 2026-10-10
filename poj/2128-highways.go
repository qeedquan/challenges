/*

Description

In a distant country Lineland there are N cities and they are all located along the highway. The highway is a straight line; it starts from the first city and runs through the second, third city and so on, ending in the N-th city. The i-th city is located at the distance of X i miles from the first one.
The highway is wide and smooth, so it is a pleasure for all people to drive along it. But there is one problem --- all roads in Lineland, including the highway, are one-way. So people are only allowed to drive along the highway from the city with smaller number to the city with greater number and they have to use country roads to get back, and that is not such a great pleasure indeed.
After the new president Mr. Pathwayson was elected in Lineland, he has decided that he would like to make it easier for people to get from one town to another. But he does not dare to change the traditions, and make the highway two-way. Therefore he has decided to build new highways to connect the cities, so that it would be possible to get from any city to any other one by highways. Traditionally, the new highways must be one-way.
Of course, Mr. Pathwayson is a great president, and he wants people to remember him in years. After a thought he has decided that building just one highway would not be enough for that. Therefore he has decided that he must build two new highways. Each highway would connect two different cities. Since people are anxious about their health, and cars running along the highway produce dangerous wastes, each new highway must not pass through any cities, except the cities it connects. Also building two new highways in one city would disturb people too much, so all the cities that would be the ends of the new highways must be different.
You are the assistant of the minister of transportation of Lineland, so you are asked to choose the cities to be connected by the new highways. Since the cost of building a highway is proportional to its length, the total length of the highways must be minimal possible. Write a program to solve this problem. You may assume that the distance between two cities along the new highway is equal to the distance between those cities along the main highway.

Input

The first line of the input contains N (2 <= N <= 50 000).
Next line contains N - 1 integer numbers: X2 , X3 , . . . , XN (1 <= X2 < X3 < . . . < XN <= 10^9 ).

Output

If it is impossible to build the highways satisfying all requirements, print number 0 on the first line of the output.
In the other case on the first line of the output file print the minimal possible total length of the highways to be built. On the second line print S1 , E1 , S2 and E2 --- the numbers of the cities to connect by the first and the second highway, respectively. Note that highways are one-way and must run from S1 to E1 and from S2 to E2 .

Sample Input

4
3 5 10

Sample Output

12
3 1 4 2

Source

Northeastern Europe 2003, Northern Subregion

*/

package main

import (
	"math"
)

func main() {
	assert(highway([]int{3, 5, 10}) == [5]int{12, 3, 1, 4, 2})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func highway(a []int) any {
	n := len(a) + 1
	if n < 4 {
		return 0
	}

	m := math.MaxInt
	c := 0
	p := a[0]
	for i := 2; i < n-1; i++ {
		if v := a[i-1] - p; m > v {
			m, c = v, i
		}
		p = a[i-1]
	}
	return [5]int{a[n-2] + m, c + 1, 1, n, c}
}
