/*


Chef wants to appear in a competitive exam. To take the exam, there are following requirements:

Minimum age limit is XX (i.e. Age should be greater than or equal to XX).
Age should be strictly less than YY.
Chef's current Age is AA. Find whether he is currently eligible to take the exam or not.

Input Format
First line will contain TT, number of test cases. Then the test cases follow.
Each test case consists of a single line of input, containing three integers X, Y,X,Y, and AA as mentioned in the statement.
Output Format
For each test case, output YES if Chef is eligible to give the exam, NO otherwise.

You may print each character of the string in uppercase or lowercase (for example, the strings YES, yEs, yes, and yeS will all be treated as identical).

Constraints
1 <= T <= 1000 1≤T≤1000
20 <= X < Y <= 40 20≤X<Y≤40
10 <= A <= 50 10≤A≤50

Sample 1:
Input
Output
5
21 34 30
25 31 31
22 29 25
20 40 15
28 29 28
YES
NO
YES
NO
YES


*/

var assert = require('assert');

function eligible(x, y, a) {
	return (x <= a && a < y) ? "YES" : "NO";
}

function main() {
	assert(eligible(21, 34, 30) == "YES");
	assert(eligible(25, 31, 31) == "NO");
	assert(eligible(22, 29, 25) == "YES");
	assert(eligible(20, 40, 15) == "NO");
	assert(eligible(28, 29, 28) == "YES");
}

main();
