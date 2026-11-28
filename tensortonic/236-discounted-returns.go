/*

In reinforcement learning, an agent collects rewards at each timestep. The discounted return at timestep t is the sum of all future rewards, where each reward is discounted by a factor of gamma raised to the power of how far in the future it occurs. This captures the idea that immediate rewards are worth more than distant ones.

Given a list of rewards collected over T timesteps and a discount factor gamma, compute the discounted return for every timestep.

Formula
The discounted return at timestep t is:

G[t] = r[t] + gamma*r[t+1] + gamma^2*r[t+2] + ... gamma^(T-1-t)*r[t-1]

This can be computed efficiently using the backward recursive relation:

G[t] = r[t] + gamma*G[t+1]
G[T-1] = r[T-1]

Return the discounted returns as a list of floats with the same length as rewards.

Examples
Input: rewards = [1, 1, 1], gamma = 1

Output: [3.0, 2.0, 1.0]

Explanation: With no discounting, each position contains the sum of all rewards from that position onward.

Input: rewards = [0, 0, 0, 10], gamma = 0.9

Output: [7.29, 8.1, 9.0, 10.0]

Hint 1
Traverse rewards from right to left while carrying the next return.

Hint 2
Store reward plus gamma times the carried return at each position.

Requirements
Compute the discounted return for every timestep using backward recursion
Start from the last timestep where G[T-1] = rewards[T-1]
For each earlier timestep: G[t] = rewards[t] + gamma * G[t+1]
Return a list of floats with the same length as rewards
Round numeric outputs to 4 decimal places.
Constraints
rewards has at least one element
0 <= gamma <= 1
Return a list of floats with the same length as rewards
Time limit: 300 ms

*/

package main

import "fmt"

func main() {
	fmt.Println(discount_returns([]float64{1, 1, 1}, 1))
	fmt.Println(discount_returns([]float64{0, 0, 0, 10}, 0.9))
}

func discount_returns(rewards []float64, gamma float64) []float64 {
	T := len(rewards)
	G := make([]float64, T)
	if T == 0 {
		return G
	}

	G[T-1] = rewards[T-1]
	for t := T - 2; t >= 0; t-- {
		G[t] = rewards[t] + gamma*G[t+1]
	}
	return G
}
