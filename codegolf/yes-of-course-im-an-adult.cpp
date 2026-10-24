/*

I think we've all done this as a kid: some websites require a minimum age of 18, so we just subtract a few years from the year of birth and voilà, we 'are' 18+.
In addition, for most rides at amusement parks the minimum height to enter is 1.40 meters (here in The Netherlands it as at least). Of course this can be cheated less easily than age, but you could wear shoes with thick heels, put your hair up, wear a hat, stand on your toes, etc.

Input:
Your program/function accepts a positive integer or decimal.

Output:
Is the input an integer >= 18? Simply print the input.
Is the input an integer 0-17? Print 18.
Is the input a decimal >= 1.4? Simply print the input.
Is the input a decimal 0.0-1.4? Print 1.4.
Challenge rules:
Assume the input will always be in the range of 0-122 (oldest woman ever was 122) or 0.0-2.72 (tallest man ever was 2.72).
You are allowed to take the input as a String, object, or anything else you prefer.
The decimal inputs will never have more than three decimal places after the decimal point.
2 or 2. both aren't valid outputs for 2.0. You are free to output 2.00 or 2.000 instead of 2.0 however.
Just like the input the output will never have more than three decimal places after the point.
General rules:
This is code-golf, so shortest answer in bytes wins.
Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.
Standard rules apply for your answer, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters, full programs. Your call.
Default Loopholes are forbidden.
If possible, please add a link with a test for your code.
Also, please add an explanation if necessary.

Test cases:
0      ->  18
1      ->  18
2      ->  18
12     ->  18
18     ->  18
43     ->  43
115    ->  115
122    ->  122

0.0    ->  1.4
1.04   ->  1.4
1.225  ->  1.4
1.399  ->  1.4
1.4    ->  1.4
1.74   ->  1.74
2.0    ->  2.0
2.72   ->  2.72

*/

#include <cassert>

template <typename T, T threshold>
T relative(T value)
{
	return (value >= threshold) ? value : threshold;
}

const auto relative_age = relative<int, 18>;
const auto relative_height = relative<double, 1.4>;

int main()
{
	assert(relative_age(0) == 18);
	assert(relative_age(1) == 18);
	assert(relative_age(2) == 18);
	assert(relative_age(12) == 18);
	assert(relative_age(18) == 18);
	assert(relative_age(43) == 43);
	assert(relative_age(115) == 115);
	assert(relative_age(122) == 122);

	assert(relative_height(0.0) == 1.4);
	assert(relative_height(1.04) == 1.4);
	assert(relative_height(1.225) == 1.4);
	assert(relative_height(1.399) == 1.4);
	assert(relative_height(1.4) == 1.4);
	assert(relative_height(1.74) == 1.74);
	assert(relative_height(2.0) == 2.0);
	assert(relative_height(2.72) == 2.72);

	return 0;
}
