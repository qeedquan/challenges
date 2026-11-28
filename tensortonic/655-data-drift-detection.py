#!/usr/bin/env python3

"""

Compare a production histogram with a reference histogram using total variation distance. First normalize each list of counts into a probability distribution. Then compute:

Dtv(P, Q) = 0.5 * Sum[i] (p[i] - q[i])

Here, p[i] and q[i] are the normalized probabilities for bin i.
Drift is detected only when the score is strictly greater than the threshold.
Return a dictionary containing the score as a float and the drift_detected flag as a Boolean.

Examples
Input: reference_counts = [50, 50], production_counts = [55, 45], threshold = 0.1

Output: {"score": 0.05, "drift_detected": false}

Explanation: The absolute probability differences sum to 0.1, so TVD is 0.05.

Input: reference_counts = [50, 50], production_counts = [90, 10], threshold = 0.1

Output: {"score": 0.4, "drift_detected": true}

Hint 1
Divide every bin count by the total count of its histogram.

Hint 2
Sum the absolute differences between matching probabilities, then multiply by one half.

Requirements
Normalize both histograms independently
Compute total variation distance across corresponding bins
Use a strict comparison with the threshold
Return the score and drift_detected flag in a dictionary
Constraints
Both count lists have the same nonzero length
Every count is nonnegative
Each histogram has a positive total count

"""

import numpy as np

def detect_drift(reference_counts: list, production_counts: list, threshold: float) -> dict:
    p = np.array(reference_counts, dtype=float)
    q = np.array(production_counts, dtype=float)
    p /= np.sum(p)
    q /= np.sum(q)
    score = 0.5 * np.sum(np.abs(p - q))
    return {
        "score": score,
        "drift_detected": score > threshold,
    }

def main():
    print(detect_drift([50, 50], [55, 45], 0.1))
    print(detect_drift([50, 50], [90, 10], 0.1))

main()
