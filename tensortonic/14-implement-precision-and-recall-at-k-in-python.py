#!/usr/bin/env python3

"""

Given a ranked recommendation list, a collection of relevant items, and a cutoff k,
compute precision at k and recall at k. Only the first k recommendations are evaluated.

Precision@k = |top-k intersect relevant| / k
Recall@k    = |top-k intersect relevant| / length(relevant)

The numerator is the number of relevant items appearing among the first k recommendations.
Return the two metrics as [precision, recall].

Examples
Input: recommended = [1, 3, 5, 7, 9], relevant = [1, 2, 3, 4, 5], k = 3

Output: [1.0, 0.6]

Explanation: All three top recommendations are relevant, giving 3/3 precision and 3/5 recall.

Input: recommended = [10, 20, 30], relevant = [1, 2, 3], k = 3

Output: [0.0, 0.0]

Hint 1
set(relevant) provides direct membership checks for the relevant items.

Hint 2
sum(item in relevant_set for item in recommended[:k]) counts the top-k hits.

Requirements
Evaluate only the first k recommendations
Count each relevant recommendation once
Return [precision, recall] as a list of two floats
Constraints
recommended contains at least k unique item identifiers
relevant contains at least one unique item identifier
k >= 1

"""

def precision_recall_at_k(recommended: list, relevant: list, k: int) -> list[float]:
    if len(relevant) == 0:
        return [0, 0]
    relevant_set = set(relevant)
    total = sum(item in relevant_set for item in recommended[:k])
    return [total/k, total/len(relevant)]

def main():
    print(precision_recall_at_k([1, 3, 5, 7, 9], [1, 2, 3, 4, 5], 3))
    print(precision_recall_at_k([10, 20, 30], [1, 2, 3], 3))

main()
