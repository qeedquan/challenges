/*

An ad click model sees a thousand impressions without a click for every impression with one. The sampling topic of the ML System Design course explains that teams throw away most of the negatives before training so the data fits and the model learns faster. It also warns that the scores such a model produces are no longer probabilities for the full population. If only one negative in ten was kept, the model believes clicks are ten times more common than they are, and its scores are too high.

Downstream systems that bid real money on the predicted click probability need the correction that undoes this shift. This problem asks you to apply it.

You are given a list p of scores from a model trained on downsampled data, each between 0 and 1. You are also given a number negative_keep_rate, the fraction of negatives that were kept during training, between 0 exclusive and 1 inclusive, while every positive was kept. For each score, the corrected probability is

q = p / (p + (1-p)/w)

where w is the keep rate. Return the corrected probabilities as a one-dimensional NumPy array of floats in the same order as the input. An empty input returns an empty array.

A score of 0 stays 0 and a score of 1 stays 1, because the correction only reweights the negatives that were removed. When the keep rate is 1, nothing was removed and every score is unchanged. The correction never changes the order of the scores, so a ranking built on them is unaffected, but any threshold or bid that reads the score as a probability must use the corrected value.

Worked example. With a keep rate of 0.1, a score of 0.5 becomes 0.5 divided by 0.5 plus 0.5 over 0.1, which is 0.5 divided by 5.5, about 0.0909. A score of 0.2 becomes 0.2 divided by 0.2 plus 8, about 0.0244. A score of 0.9 becomes 0.9 divided by 0.9 plus 1, about 0.4737. All three moved down, and the gaps between them shrank, because the model had been taught that positives are ten times more common than they are.

Examples
Input: p = [0.5, 0.2, 0.9], negative_keep_rate = 0.1

Output: [0.090909, 0.02439, 0.473684]

Explanation: Each score is divided by itself plus the missing negatives, which the keep rate of one tenth scales up tenfold.

Input: p = [0.0, 0.3, 1.0], negative_keep_rate = 1.0

Output: [0.0, 0.3, 1.0]

Explanation: Nothing was removed during training, so the scores are already calibrated to the population.

Hint 1
Convert p to a float NumPy array with np.asarray before dividing, so the result has the right type even for an empty list.

Hint 2
The denominator is p plus one minus p divided by the keep rate; NumPy applies it to every element at once.

Requirements
Apply the correction to every score
Leave scores of exactly 0 and exactly 1 unchanged
Return an unchanged copy when the keep rate is 1
Return a one-dimensional NumPy array of floats in input order
Constraints
0 <= len(p) <= 100000 and every score satisfies 0 <= p <= 1
0 < negative_keep_rate <= 1
Use NumPy only

*/

package main

import "fmt"

func main() {
	fmt.Println(recalibrate_after_downsampling(
		[]float64{0.5, 0.2, 0.9},
		0.1,
	))

	fmt.Println(recalibrate_after_downsampling(
		[]float64{0, 0.3, 1.0},
		1.0,
	))
}

func recalibrate_after_downsampling(p []float64, negative_keep_rate float64) []float64 {
	q := make([]float64, len(p))
	for i := range q {
		q[i] = p[i] / (p[i] + (1-p[i])/negative_keep_rate)
	}
	return q
}
