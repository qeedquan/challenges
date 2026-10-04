/*

Roll 3 dice, count the two highest two values and add them to the result. Every 1 must be rolled once again.

Now show the average throw after 1000000 tries and the probabilities for each result occurring:
Desired Result:

    avg(9.095855)
    2: 0.0023
    3: 0.0448
    4: 1.1075
    5: 2.8983
    6: 6.116
    7: 10.1234
    8: 15.4687
    9: 18.9496
    10: 19.3575
    11: 16.0886
    12: 9.8433

*/

package main

import (
	"fmt"
	"math/rand"
	"sort"
)

func main() {
	sim(1e6)
}

func sim(n int) {
	var (
		p [13]int
		r [3]int
	)

	for i := 0; i < n; i++ {
		for j := range r {
			r[j] = rand.Intn(6) + 1
			if r[j] == 1 {
				r[j] = rand.Intn(6) + 1
			}
		}
		sort.Ints(r[:])
		p[r[1]+r[2]] += 1
	}

	fmt.Printf("avg(%.4f)\n", avg(p[2:], n))
	for i := 2; i < len(p); i++ {
		fmt.Printf("%d: %.4f\n", i, float64(p[i])/float64(n)*100)
	}
}

func avg(p []int, n int) float64 {
	if len(p) == 0 {
		return 0
	}

	r := 0.0
	for i := range p {
		r += float64(p[i]) / float64(n)
	}
	return r / float64(len(p)) * 100
}
