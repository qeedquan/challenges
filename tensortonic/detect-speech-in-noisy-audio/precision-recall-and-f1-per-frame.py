#!/usr/bin/env python3

"""

To compare speech detectors you score their decisions against the true answer, frame by frame. A hit is a frame where both predicted and truth are True. Three numbers summarize the result.

Precision is the share of predicted speech frames that really are speech, hits divided by the number of True values in predicted. It drops when the detector calls noise speech.
Recall is the share of true speech frames the detector found, hits divided by the number of True values in truth. It drops when the detector misses speech.
F1 is the harmonic mean of the two, which is high only when both are high.

F1 = 2*P*R/(P + R)

Here P is precision and R is recall. When a denominator is 0 (nothing predicted, nothing true, or P plus R equal to 0), the matching value is 0.0 instead of an error.

Return a dict with the keys precision, recall and f1, each a Python float.

Examples
Input: predicted = [True, True, False, False], truth = [True, False, True, False]

Output: {"precision": 0.5, "recall": 0.5, "f1": 0.5}

Explanation: Frame 0 is a hit. Frame 1 is predicted but not true (a false alarm) and frame 2 is true but not predicted (a miss). Precision is 1 of 2 predicted, recall is 1 of 2 true, so both are 0.5 and F1 is 0.5.

Input: predicted = [True, True, True, True, True], truth = [False, True, True, False, False]

Output: {"precision": 0.4, "recall": 1.0, "f1": 0.5714}

Input: predicted = [False, False, False], truth = [False, True, True]

Output: {"precision": 0.0, "recall": 0.0, "f1": 0.0}

Hint 1
Count hits with (predicted & truth).sum().

Hint 2
Convert counts to Python ints before dividing.

Hint 3
Check each denominator before dividing.

Requirements
A hit is a frame where both tensors are True.
Precision divides by the predicted speech frames; recall divides by the true speech frames.
Any value whose denominator is 0 is 0.0.
Return plain Python floats, not tensors.
Constraints
1 to 1,000 frames.
predicted and truth have the same length.

"""

import torch

def precision_recall_f1(predicted: torch.Tensor, truth: torch.Tensor) -> dict:
    N = len(predicted)
    predicts = 0
    truths = 0
    hits = 0
    for i in range(N):
        if predicted[i] and truth[i]:
            hits += 1
        if predicted[i]:
            predicts += 1
        if truth[i]:
            truths += 1

    P = R = F1 = 0
    if predicts != 0:
        P = hits / predicts
    if truths != 0:
        R = hits / truths
    if P != 0 or R != 0:
        F1 = 2*P*R / (P + R)
    return {
        "precision": P,
        "recall": R,
        "f1": F1,
    }

print(precision_recall_f1(torch.Tensor([True, True, False, False]), torch.Tensor([True, False, True, False])))
print(precision_recall_f1(torch.Tensor([True, True, True, True, True]), torch.Tensor([False, True, True, False, False])))
print(precision_recall_f1(torch.Tensor([False, False, False]), torch.Tensor([False, True, True])))
