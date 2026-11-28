/*

Challenge
Given an array of integers, received from stdin, function arguments, program arguments, or some other method:

Output only the minimum and maximum numbers in the array, through a return value, stdout, or other fitting methods.

Example session
> minmax( {0, 15, 2, 3, 7, 18, -2, 9, 6, -5, 3, 8, 9, -14} )
-14 18
Reference implementation
// C++14

void minmax(std::vector<int> v) {
    int min = v[0]; int max = v[0];
    for(auto it : v) {
        if (*it < min)
            min = *it;
        if (*it > max)
            max = *it;
    }
    std::cout << min << ' ' << max << std::endl;
}
Rules
You may not use a built-in function to calculate the values.
Standard loopholes disallowed.
Creative implementations encouraged.
This is code-golf, shortest answer wins but will not be selected.
Clarifications
If the array contains 1 element you need to output it twice.
If the minimum and maximum values are the same, you need to output them both.

*/

function minmax(array) {
	array.sort((x, y) => x - y);
	return [array[0], array.pop()];
}

console.log(minmax([0, 15, 2, 3, 7, 18, -2, 9, 6, -5, 3, 8, 9, -14]));

