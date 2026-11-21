#!/usr/bin/env python3

"""

Target encoding (also called mean encoding) is a feature engineering technique that replaces categorical values with the mean of the target variable for each category. This converts categorical features into numeric features that capture the relationship between the category and the target, making them usable by models that require numeric input.

Given a list of categorical values and corresponding target values, replace each category with the mean target value for that category.

Algorithm

1. For each unique category c, compute the mean of all target values where the category equals c:
encoding(c) = 1/|{i: cat_i = c}| = Sum[i=cat,c] target[i]

2. Replace each category in the input with its computed mean.
Return one floating-point encoding for each input category.


Examples
Input: categories = ["cat", "dog", "cat", "dog"], targets = [1, 2, 3, 4]

Output: [2.0, 3.0, 2.0, 3.0]

Explanation: Cat targets average to 2 and dog targets average to 3.

Input: categories = ["a", "b", "c", "a", "b", "c"], targets = [1, 2, 3, 4, 5, 6]

Output: [2.5, 3.5, 4.5, 2.5, 3.5, 4.5]

Hint 1
Track a target sum and count for every category.

Hint 2
Create category means, then map the original category sequence through them.

Requirements
Compute the mean target value for each unique category
Replace each category with its computed mean
Return a list of floats with the same length as the input
Constraints
categories and targets have the same length (at least 1)
Categories are strings
Targets are numbers
Return a list of floats
Time limit: 300 ms

"""

def target_encoding(categories: list, targets: list) -> list:
    count = {}
    total = {}
    for (index, category) in enumerate(categories):
        if category not in count:
            count[category] = 0
            total[category] = 0
        count[category] += 1
        total[category] += targets[index]
    
    result = []
    for category in categories:
        result.append(total[category] / count[category])
    return result

print(target_encoding(["cat", "dog", "cat", "dog"], [1, 2, 3, 4]))
print(target_encoding(["a", "b", "c", "a", "b", "c"], [1, 2, 3, 4, 5, 6]))
