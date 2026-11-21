/*

SARSA is an on-policy temporal difference (TD) learning algorithm. The name comes from the quintuple (State, Action, Reward, next State, next Action) used in each update. It learns Q-values (action-value estimates) by bootstrapping from the next state-action pair that the agent actually takes.

Given a Q-table and a single transition (s, a, r, s', a'), perform one SARSA update and return the updated Q-table.

Algorithm
1. Compute the TD error:

delta = r + gamma*Q(s', a') - Q(s, a)

2. Update the Q-value for the current state-action pair:

Q(s, a) <- Q(s, a) + alpha*delta

Return a new two-dimensional list containing the updated Q-table.

Examples
Input: q_table = [[0, 0], [0, 0]], state = 0, action = 1, reward = 1, next_state = 1, next_action = 0, alpha = 0.1, gamma = 0.9

Output: [[0.0, 0.1], [0.0, 0.0]]

Explanation: The TD error is 1, so the selected Q-value increases by 0.1.

Input: q_table = [[1, 2], [3, 4]], state = 0, action = 0, reward = 5, next_state = 1, next_action = 1, alpha = 0.5, gamma = 0.9

Output: [[4.8, 2.0], [3.0, 4.0]]

Hint 1
Copy each Q-table row before writing the updated value.

Hint 2
Compute the TD error from the current and selected next-action values.

Requirements
Compute the TD error using the reward, discounted next Q-value, and current Q-value
Update only Q(state, action) using the learning rate alpha
Do not modify the original Q-table. Return a new 2D list
All other Q-values remain unchanged
Round numeric outputs to 4 decimal places.
Constraints
q_table is a 2D list of floats with shape [num_states][num_actions]
state, action, next_state, next_action are valid indices
0 <= alpha <= 1, 0 <= gamma <= 1
Return a new 2D list (do not modify the input)
Time limit: 300 ms

*/

package main

import "fmt"

func main() {
	fmt.Println(sarsa_update(
		[][]float64{{0, 0}, {0, 0}},
		0, 1,
		1,
		1, 0,
		0.1, 0.9,
	))

	fmt.Println(sarsa_update(
		[][]float64{{1, 2}, {3, 4}},
		0, 0,
		5,
		1, 1,
		0.5, 0.9,
	))
}

func sarsa_update(
	q_table [][]float64,
	state, action int,
	reward float64,
	next_state, next_action int,
	alpha, gamma float64,
) [][]float64 {
	td_error := reward + gamma*q_table[next_state][next_action] - q_table[state][action]
	q_table[state][action] += alpha * td_error
	return q_table
}
