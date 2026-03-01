/*

Comparing Spectra

Suppose you have two mass spectra, and you want to check if they both were obtained from the same protein; you will need some notion of spectra similarity.
The simplest possible metric would be to count the number of peaks in the mass spectrum that the spectra share, called the shared peaks count;
its analogue for simplified spectra is the number of masses that the two spectra have in common.

The shared peaks count can be useful in the simplest cases, but it does not help us if, for example, one spectrum corresponds to a peptide contained inside of another peptide from which the second spectrum was obtained.
In this case, the two spectra are very similar, but the shared peaks count will be very small.
However, if we shift one spectrum to the right or left, then shared peaks will align.
In the case of simplified spectra, this means that there is some shift value x such that adding x to the weight of every element in one spectrum should create a large number of matches in the other spectrum.

Problem
A multiset is a generalization of the notion of set to include a collection of objects in which each object may occur more than once (the order in which objects are given is still unimportant).
For a multiset S, the multiplicity of an element x is the number of times that x occurs in the set; this multiplicity is denoted S(x).
Note that every set is included in the definition of multiset.

The Minkowski sum of multisets S1 and S2 containing real numbers is the new multiset S1⊕S2 formed by taking all possible sums s1+s2 of an element s1 from S1 and an element s2 from S2.
The Minkowski sum could be defined more concisely as S1⊕S2=s1+s2:s1∈S1,s2∈S2.
The Minkowski difference S1⊖S2 is defined analogously by taking all possible differences s1−s2.

If S1 and S2 represent simplified spectra taken from two peptides, then S1⊖S2 is called the spectral convolution of S1 and S2.
In this notation, the shared peaks count is represented by (S2⊖S1)(0), and the value of x for which (S2⊖S1)(x) has the maximal value is the shift value maximizing the number of shared masses of S1 and S2.

Given: Two multisets of positive real numbers S1 and S2. The size of each multiset is at most 200.

Return: The largest multiplicity of S1⊖S2, as well as the absolute value of the number x maximizing (S1⊖S2)(x) (you may return any such value if multiple solutions exist).

Sample Dataset
186.07931 287.12699 548.20532 580.18077 681.22845 706.27446 782.27613 968.35544 968.35544
101.04768 158.06914 202.09536 318.09979 419.14747 463.17369

Note
Observe that S1⊕S2 is equivalent to S2⊕S1, but it is not usually the case that S1⊖S2 is the same as S2⊖S1; in this case, one multiset can be obtained from the other by negating every element.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(
		[]float64{186.07931, 287.12699, 548.20532, 580.18077, 681.22845, 706.27446, 782.27613, 968.35544, 968.35544},
		[]float64{101.04768, 158.06914, 202.09536, 318.09979, 419.14747, 463.17369},
		3, 85.03163,
	)
	test(
		[]float64{71.03711, 163.06333, 225.11133, 326.12666, 353.16991, 816.41299, 931.43993, 983.41372, 1087.54104, 1098.44066, 1476.77249, 1591.79943, 1599.66638, 1696.71914, 1917.03596, 1939.80466, 2226.93165, 2338.25455, 2569.32232, 2699.14206, 2716.39073, 2812.22612, 2927.25306, 3040.33712, 3042.58613, 3171.62872, 3252.48959, 3456.77242, 3569.85648, 3664.66425, 3999.0723, 4185.13635, 4233.97166, 4362.03024, 4371.21566, 4484.29972, 4490.08882, 4706.18207, 4821.20901, 4935.25194, 5029.63228, 5132.64147, 5592.91003, 5724.69781, 5821.9799, 6038.07315, 6156.94631, 6294.19031, 6343.02562, 6472.06821, 6587.35033, 6600.12678, 6750.41366, 6855.2963, 7049.57703, 7071.38955, 7178.61962, 7275.67238, 7388.75644, 7715.93585, 7958.83965, 8086.89823, 8189.90742, 8301.23032, 8346.00853, 8417.04564, 8611.12601, 8710.19442, 8823.27848, 8928.49559, 8936.36254, 9051.38948, 9057.53818, 9327.53687, 9429.72131, 9544.74825, 9886.92867, 10001.95561, 10072.99272, 10087.96003, 10174.99206, 10365.09864, 10400.1034, 10457.12486, 10528.16197},
		[]float64{113.08406, 156.10111, 454.27912, 772.35377, 869.40653, 974.56612, 983.44946, 1077.57531, 1112.49205, 1512.7031, 1643.74359, 1678.8977, 1807.94029, 1871.82945, 2093.08399, 2099.94045, 2213.02451, 2309.17724, 2522.22974, 2635.38387, 2837.35164, 2950.4357, 3007.52723, 3113.49903, 3120.61129, 3283.67462, 3406.65905, 3439.77573, 3552.85979, 3665.94385, 3775.86027, 3878.86946, 3981.10551, 3993.8964, 4082.15319, 4107.93933, 4255.00774, 4343.26453, 4356.05542, 4455.12383, 4458.29147, 4568.20789, 4674.38472, 4802.4433, 4897.3852, 5053.48631, 5067.56079, 5216.54964, 5329.6337, 5499.80929, 5685.8886, 5701.77706, 5814.93119, 5871.88258, 5911.98395, 6027.98369, 6237.22048, 6244.07694, 6400.17805, 6465.33148, 6579.37441, 6658.26323, 6693.41734, 6757.33164, 6824.45783, 6984.45863, 7224.66888, 7362.59481, 7518.69592, 7564.80716, 7693.84975, 7821.90833, 7882.88181, 7934.99239, 7995.96587, 8066.03288, 8109.04993, 8224.07687},
		22, 827.31261,
	)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s1, s2 []float64, rc int, rv float64) {
	c, v := conv(s1, s2)
	fmt.Println(c, v)
	assert(c == rc)
	assert(math.Abs(v-rv) < 1e-5)
}

func conv(s1, s2 []float64) (int, float64) {
	m := make(map[string]int)
	c := 0
	v := 0.0
	for _, v1 := range s1 {
		for _, v2 := range s2 {
			d := math.Abs(v1 - v2)
			k := fmt.Sprintf("%.5f", d)
			if m[k]++; m[k] > c {
				c, v = m[k], d
			}
		}
	}
	return c, v
}
