%{

The log1p transformation compresses the range of nonnegative data while handling zero naturally. Apply the natural logarithm of one plus each value:

y[i] = ln(1 + x[i])

Here, x_i is an input value and y_i is its transformed value. Round each result to four decimal places and return the transformed values as a list.

Examples
Input: values = [0, 1, 2, 3]

Output: [0.0, 0.6931, 1.0986, 1.3863]

Explanation: Adding one makes the zero input valid, and the natural logarithm compresses the remaining values.

Input: values = [99, 999]

Output: [4.6052, 6.9078]

Hint 1
Use math.log1p to compute the transformation directly.

Hint 2
Round each transformed value while building the result list.

Requirements
Apply the natural logarithm of 1 + x to every value.
Round every transformed value to four decimal places.
Preserve the original value order.
Return a list of floats.
Constraints
Every input value is nonnegative.
values is nonempty.
Time limit: 300 ms.

%}

function log_transform(values)
	log(1 + values)
end

log_transform([0 1 2 3])
log_transform([99 999])
