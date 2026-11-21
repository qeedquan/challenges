#!/usr/bin/env python3

"""

Create a scalar computation-graph node for addition. Each of left and right is a Python dictionary with exactly two fields: id, a string identifier, and data, its numeric value.

z = x + y

Here x and y are the left and right data values, and z is the new node's data.
This task constructs the forward node only; no backward pass is required.

Return a new Python dictionary with exactly these fields: id containing output_id, data containing the sum as a Python float, grad containing 0.0 as a Python float, op containing "+", and parents containing a two-item list of the original left and right dictionaries in that order.

Examples
Input: left={"id":"a","data":2.0}, right={"id":"b","data":3.0}, output_id="c"

Output: {"id":"c","data":5.0,"grad":0.0,"op":"+","parents":[{"id":"a","data":2.0},{"id":"b","data":3.0}]}

Explanation: The output stores the sum and retains the exact two input records as its ordered parents.

Input: left={"id":"x","data":-4.5}, right={"id":"y","data":1.25}, output_id="sum"

Output: {"id":"sum","data":-3.25,"grad":0.0,"op":"+","parents":[{"id":"x","data":-4.5},{"id":"y","data":1.25}]}

Input: left={"id":"zero_l","data":0.0}, right={"id":"zero_r","data":0.0}, output_id="zero_sum"

Output: {"id":"zero_sum","data":0.0,"grad":0.0,"op":"+","parents":[{"id":"zero_l","data":0.0},{"id":"zero_r","data":0.0}]}

Hint 1
Square-bracket dictionary access reads each leaf's data field.

Hint 2
A list stores the existing leaf objects without copying them.

Requirements
Use Python dictionaries and 64-bit floating-point arithmetic; NumPy is available.
Retain the original leaf objects as parents, not copied dictionaries or identifiers.
Leave both input records unchanged.
Constraints
Leaf IDs and output_id are distinct nonempty strings.
Leaf data values are finite numbers and are not Boolean values.
The computed sum must be finite.

"""

def value_addition_node(left: dict, right: dict, output_id: str) -> dict:
    return {
        "id": output_id,
        "data": left["data"] + right["data"],
        "grad": 0,
        "op": "+",
        "parents": [left, right],
    }

print(value_addition_node(left={"id":"a","data":2.0}, right={"id":"b","data":3.0}, output_id="c"))
print(value_addition_node(left={"id":"x","data":-4.5}, right={"id":"y","data":1.25}, output_id="sum"))
print(value_addition_node(left={"id":"zero_l","data":0.0}, right={"id":"zero_r","data":0.0}, output_id="zero_sum"))

