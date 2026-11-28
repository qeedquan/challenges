/*

Compute the micro-averaged F1 score for equal-length sequences of single-label multiclass predictions.
First aggregate true positives, false positives, and false negatives across every class, then compute

F1,micro = 2*TP / (2*TP + FP + FN)

Here, TP, FP, and FN are the totals across all classes. Return the score as a Python float rounded to four decimal places.

Examples
Input: y_true = [0, 1, 1], y_pred = [0, 1, 0]

Output: 0.6667

Explanation: Across all classes there are two true positives, one false positive, and one false negative.

Input: y_true = [0, 1, 2, 2], y_pred = [0, 1, 2, 2]

Output: 1.0

Input: y_true = [2, 2, 1, 0], y_pred = [1, 2, 1, 0]

Output: 0.75

Hint 1
sum(actual == predicted for actual, predicted in zip(y_true, y_pred)) counts correct single-label predictions.

Hint 2
For single-label multiclass data, every mismatch contributes one false positive and one false negative.

Requirements
y_true and y_pred contain one integer class label per sample
Aggregate counts across every class
Return a Python float rounded to four decimal places
Constraints
y_true and y_pred have the same nonzero length
At most
100,000
100,000 labels are provided
Do not use an external machine learning library

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
f1micro(int *y_true, int *y_pred, size_t len)
{
	double tp, fp, fn;
	size_t i;

	tp = fp = fn = 0;
	for (i = 0; i < len; i++) {
		if (y_true[i] == y_pred[i])
			tp += 1;
		else {
			fn += 1;
			fp += 1;
		}
	}
	return (2 * tp) / (2 * tp + fp + fn);
}

int
main()
{
	int y_true1[] = { 0, 1, 1 };
	int y_true2[] = { 0, 1, 2, 2 };
	int y_true3[] = { 2, 2, 1, 0 };

	int y_pred1[] = { 0, 1, 0 };
	int y_pred2[] = { 0, 1, 2, 2 };
	int y_pred3[] = { 1, 2, 1, 0 };

	printf("%f\n", f1micro(y_true1, y_pred1, nelem(y_true1)));
	printf("%f\n", f1micro(y_true2, y_pred2, nelem(y_true2)));
	printf("%f\n", f1micro(y_true3, y_pred3, nelem(y_true3)));

	return 0;
}
