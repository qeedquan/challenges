%{

Challenge
Given a list, determine if grouping the list into runs of increasing and decreasing elements will result in a list of equal-sized lists.

In other words, "turning points" of the list are spaced out evenly.

Example
Here's an example: 0, 3, 7, 5, 2, 3, 6

0, 3, 7 increases, 7, 5, 2 decreases, and 2, 3, 6 increases. Therefore this is truthy.

Another example: 1, 4, 6, 8, 5, 3, 5, 7, 9

1, 4, 6, 8 increases, 8, 5, 3 decreases, and 3, 5, 7, 9 increases. Therefore this is falsy.

Rules and Specifications
No adjacent elements will be equal
All numbers can be assumed to be within your language's reasonable number range
You may assume that all numbers are integers, if it helps you golf your submission
This is code-golf, so the shortest answer wins
Input as a list in any reasonable representation and output as any truthy/falsy value. The two values must be consistent.
Test Cases
Input -> Output
1, 3, 5, 8, 6, 4, 2, 3, 5, 7, 6, 4, 2, 5, 7, 9, 6, 4, 2 -> True
1, 3, 5, 7, 6, 4, 5, 7, 9, 8, 6, 4, 2, 3, 5 -> False
2, 3, 6, 4, 2, 3, 7, 5, 3, 4, 6 -> True
3, 6, 4, 8, 5, 7, 3, 5, 2 -> True
8 -> True
1, 3, 5, 7 -> True
4, 5, 7, 6, 8, 9 -> False
6, 4, 2, 3, 5, 4, 2 -> True
8, 5, 3, 2, 4, 6, 5, 3, 2, 5, 7 -> False
Note: You may not assume that all numbers are single digits (unless that is all your language is capable of handling); the test cases reflect that just because it's easier for me to type the cases this way :P Here are a few test cases with numbers outside of that range:

1, 5, 10, 19, 15, 13, 8, 13, 18, 23, 19, 18, 14 -> True
15, 14, 17, 16, 19, 18 -> True
12, 16, 19, 15, 18, 19 -> False

%}

%{

Ported from @Luis Mendo solution

@(x)                                                % Define anonymous function
                               diff(x)              % Deltas (consecutive differences)
                                      >0            % Positive? Gives signs
                          diff(         )           % Deltas between signs
                         [                1]        % Append 1 to "close" last group
                    find(                   )       % Indices of nonzeros
               diff(                         )      % Deltas. Gives group lengths
        unique(                               )     % Remove duplicates
    nnz(                                       )    % Number of nonzeros. Gives length
                                                <2  % If 1 or 0: input is periodic

%}

function oscillating(x)
	nnz(unique(diff(find([diff(diff(x) > 0) 1])))) < 2
end

inputs = {
	[1, 3, 5, 8, 6, 4, 2, 3, 5, 7, 6, 4, 2, 5, 7, 9, 6, 4, 2]
	[1, 3, 5, 7, 6, 4, 5, 7, 9, 8, 6, 4, 2, 3, 5]
	[2, 3, 6, 4, 2, 3, 7, 5, 3, 4, 6]
	[3, 6, 4, 8, 5, 7, 3, 5, 2]
	[8]
	[1, 3, 5, 7]
	[4, 5, 7, 6, 8, 9]
	[1, 5, 10, 19, 15, 13, 8, 13, 18, 23, 19, 18, 14]
	[15, 14, 17, 16, 19, 18]
	[12, 16, 19, 15, 18, 19]
};

cellfun(@oscillating, inputs)
