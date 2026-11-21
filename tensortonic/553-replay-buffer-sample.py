#!/usr/bin/env python3

"""

A replay buffer (or experience replay memory) stores past transitions that an agent has experienced. During training, a random batch of transitions is sampled from the buffer to break temporal correlations and stabilize learning. This technique is used in DQN, SAC, DDPG, and many other off-policy algorithms.

Given a buffer of transitions, a batch size, and a random seed, sample a batch of transitions uniformly at random without replacement.

Algorithm
1. Set the random seed for reproducibility

2. Sample batch_size transitions from the buffer uniformly at random without replacement

Return the sampled transitions as a list ordered by ascending sampled index.

Examples
Input: buffer = [[0, 0, 1, 1, 0], [1, 1, 0.5, 2, 0], [2, 0, -1, 3, 1], [3, 1, 2, 4, 0], [4, 0, 0, 0, 1]], batch_size = 3, seed = 42

Output: [[1, 1, 0.5, 2, 0], [2, 0, -1, 3, 1], [4, 0, 0, 0, 1]]

Explanation: The seeded NumPy generator selects three distinct indices, which are sorted before retrieving transitions.

Input: buffer = [[0, 0, 1, 1, 0], [1, 1, 0.5, 2, 0], [2, 0, -1, 3, 1], [3, 1, 2, 4, 0], [4, 0, 0, 0, 1]], batch_size = 1, seed = 7

Output: [[0, 0, 1, 1, 0]]

Hint 1
Create a local generator with np.random.RandomState(seed).

Hint 2
Choose indices without replacement, sort them, and retrieve those buffer entries.

Requirements
Use NumPy for random sampling with the given seed
Sample without replacement (no duplicate transitions in the batch)
Return a list of transitions in a deterministic order
Constraints
batch_size <= len(buffer)
buffer is a list of lists (each inner list is a transition)
seed is an integer
Return a list of transitions (list of lists)
Time limit: 300 ms

"""

import numpy as np

def replay_buffer_sample(buffer: list, batch_size: int, seed: int) -> list:
    rng = np.random.RandomState(seed)
    indices = rng.choice(np.arange(0, len(buffer)), size=batch_size, replace=False)
    result = []
    for index in indices:
        result.append(buffer[index])
    return result

def main():
    print(replay_buffer_sample([[0, 0, 1, 1, 0], [1, 1, 0.5, 2, 0], [2, 0, -1, 3, 1], [3, 1, 2, 4, 0], [4, 0, 0, 0, 1]], 3, 42))
    print(replay_buffer_sample([[0, 0, 1, 1, 0], [1, 1, 0.5, 2, 0], [2, 0, -1, 3, 1], [3, 1, 2, 4, 0], [4, 0, 0, 0, 1]], 1, 7))

main()
