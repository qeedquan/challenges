#!/usr/bin/env python3

"""

You work as an architect, and you've been assigned the task of reviewing your coworker's skyscraper design. In your line of work, a skyscraper is just a tower of blocks. Nothing more, nothing less.

This means your job is really simple! You can describe a skyscraper with a mere string of digits, such as 11102. The digits are read from left-to-right, each digit specifying what kind of material the block is at that position.

A skyscraper, however, also needs to be stable. You can achieve stability by making sure all these conditions are satisfied:

0 cannot be sandwiched between two materials that add up to an even number. If 0 is at the top/bottom of the skyscraper, consider the ground/sky to be 0 as well.
1 may not have a 2 touching it on either side.
2 can only occupy even positions in the skyscraper.
Assume the bottom block (i.e. leftmost digit) is at position/index 0.

Input
You will receive a skyscraper's design, i.e. a string/array of the digits 0, 1, and 2. You can receive the input in whatever way works for you.

Output
Output, in your preferred format, the positions of all the blocks whose conditions are violated. The positions don't necessarily have to be in order, but you must find all of them correctly.

Rules
This is code-golf, so shortest number of bytes wins.

Test Cases
101          [1] (0 is sandwiched between 1+1=2)
201102       [5] (the rightmost 2 is at an odd position)
1012         [1, 2, 3] (0 is sandwiched, rightmost 1 touching 2, 2 at odd position)
0            [0] 0 is sandwiched between the ground and sky (0+0)
20101010002  [3, 5, 8, 9]
111020100102 [11]
20110010201  []
01102011100111100111 []
20111100102011102010011 []

"""

# ported from @138 Aspen solution
def process(array):
    # Use list comprehension with conditional filtering (similar to flatMap)
    result = []
    for current_index, current_value in enumerate(array):
        # Get the next value in the array (None if beyond array bounds)
        next_value = array[current_index + 1] if current_index + 1 < len(array) else None
        
        # Store the previous value for the next iteration
        previous_value = 0 if current_index == 0 else array[current_index - 1]
        
        # Determine which operation to perform based on current value
        if current_value == 0:
            # NOT of previous value XOR with next value
            # Using bitwise operators and handling None case
            next_val = 0 if next_value is None else next_value
            computed_result = (~previous_value ^ next_val)
        elif current_value == 1:
            # (previous value OR next value) divided by 2
            next_val = 0 if next_value is None else next_value
            computed_result = (previous_value | next_val) // 2
        elif current_value == 2:
            # Just return the current index
            computed_result = current_index
        else:
            computed_result = 0
        
        # Check if the least significant bit is set (result is odd)
        if computed_result & 1:
            result.append(current_index)
            
    return result

# Test cases
test_cases = [
    {"input": "101", "expected": [1]},
    {"input": "201102", "expected": [5]},
    {"input": "1012", "expected": [1, 2, 3]},
    {"input": "0", "expected": [0]},
    {"input": "20101010002", "expected": [3, 5, 8, 9]},
    {"input": "111020100102", "expected": [11]},
    {"input": "20110010201", "expected": []},
    {"input": "01102011100111100111", "expected": []},
    {"input": "20111100102011102010011", "expected": []}
]

# Run test cases
for case in test_cases:
    # Convert string to array of numbers
    array = [int(x) for x in case["input"]]
    
    # Process the array
    result = process(array)
    
    # Compare with expected result
    is_correct = result == case["expected"]
    
    # Output result and validation
    print(f"{result} {'✔️' if is_correct else '❌'}")

