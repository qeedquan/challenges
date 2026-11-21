/*

Compute the Monte Carlo advantage at every time step of a completed episode. First compute each discounted return backward:

G[t] = r[t] + gamma*G[t+1]
G[T] = 0

Then subtract the value baseline for the visited state:
A[t] = G[t] - V(s[t])

Here, r[t] is the reward at time t, gamma is the discount factor,
and V(s) is the estimated value of the current state.
Do not bootstrap beyond the final reward. Return the advantages as a NumPy array rounded to four decimals.

Examples
Input: states = [0, 1, 2], rewards = [1, 2, 3], V = [0.5, 1, 1.5], gamma = 1

Output: [5.5, 4, 1.5]

Explanation: The returns are [6, 5, 3], and subtracting the three state baselines gives the advantages.

Input: states = [0, 1, 2], rewards = [1, 2, 3], V = [0, 0, 0], gamma = 0

Output: [1, 2, 3]

Hint 1
Fill a return array backward with running = rewards[index] + gamma * running.

Hint 2
Index the baseline vector with values[np.asarray(states, dtype=int)].

Requirements
Compute all returns in one backward pass
Subtract the value associated with each visited state
Do not add a value estimate after the final reward
Return a NumPy array rounded to four decimals
Constraints
states and rewards are nonempty lists of equal length
Every state index is valid for V
0 <= gamma <= 1
Use NumPy only

*/

package main

import "fmt"

func main() {
	fmt.Println(advantage(
		[]float64{0, 1, 2},
		[]float64{1, 2, 3},
		[]float64{0.5, 1, 1.5},
		1,
	))

	fmt.Println(advantage(
		[]float64{0, 1, 2},
		[]float64{1, 2, 3},
		[]float64{0, 0, 0},
		0,
	))
}

func advantage(states, rewards, V []float64, gamma float64) []float64 {
	A := make([]float64, len(states))
	G := 0.0
	for i := len(A) - 1; i >= 0; i-- {
		G = rewards[i] + gamma*G
		A[i] = G - V[i]
	}
	return A
}
