#!/usr/bin/env python3

"""

Calculate effective communication bandwidth under the supplied ring-equivalent model.
Let S be payload_bytes, R be world_size, and t be duration_seconds.
The pass count c is two for all_reduce and one for all_gather, reduce_scatter, or all_to_all.
The modeled bytes per rank A and bandwidth B are:

A = c*S/(R-1)/R
B = A/t

A single rank requires no communication. Return a Python dictionary with algorithm_bytes and bandwidth_bytes_per_second, both finite Python floats.

Examples
Input: payload_bytes = 1024, world_size = 4, duration_seconds = 0.001, collective = "all_reduce"

Output: {"algorithm_bytes":1536,"bandwidth_bytes_per_second":1536000}

Explanation: Two ring passes move three quarters of the payload each, and dividing 1536 bytes by 0.001 seconds gives the bandwidth.

Input: payload_bytes = 1200, world_size = 3, duration_seconds = 0.002, collective = "all_gather"

Output: {"algorithm_bytes":800,"bandwidth_bytes_per_second":400000}

Input: payload_bytes = 2048, world_size = 2, duration_seconds = 0.004, collective = "reduce_scatter"

Output: {"algorithm_bytes":1024,"bandwidth_bytes_per_second":256000}

Hint 1
Python / performs floating-point division.

Hint 2
float converts a numeric value to a Python float.

Requirements
Use the stated ring-equivalent model with bytes and seconds as the units.
Return both modeled communication volume and bandwidth as Python floats.
Constraints
payload_bytes is a nonnegative Python integer.
world_size is a positive Python integer.
duration_seconds is a positive finite Python number.
collective is all_reduce, all_gather, reduce_scatter, or all_to_all.
Calculations use bytes and seconds without unit conversion.

"""

def collective_bandwidth(payload_bytes: int, world_size: int, duration_seconds: float, collective: str) -> dict:
    c = 1
    if collective == "all_reduce":
        c = 2
    A = c*payload_bytes * (world_size-1)/world_size
    B = A / duration_seconds
    return {
        "algorithm_bytes": A,
        "bandwidth_bytes_per_second": B,
    }

print(collective_bandwidth(1024, 4, 0.001, "all_reduce"))
print(collective_bandwidth(1200, 3, 0.002, "all_gather"))
print(collective_bandwidth(2048, 2, 0.004, "reduce_scatter"))
