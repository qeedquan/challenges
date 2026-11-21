#!/usr/bin/env python3

"""

Calculate persistent model-state bytes per rank for replicated data parallelism (DDP) and ZeRO stages 1 through 3.
Use this pooled-byte model: P, G, and O are the supplied parameter, gradient, and optimizer-state byte counts, and
R is the number of ranks. Each M denotes the largest per-rank allocation under that model; ceiling brackets round up to an integer.

MDDP = P + G + O
MZERO1 = P + G + ceil(O/R)
MZERO2 = P + ceil((G + O) / R)
MZERO3 = ceil((P + G + O) / R)

The sharded categories in each numerator form one byte pool. Activations, transient gathered buffers, and allocator padding are excluded. Return a Python dictionary with ddp, zero1, zero2, and zero3, each an exact Python integer byte count.

Examples
Input: parameter_bytes = 400, gradient_bytes = 400, optimizer_bytes = 800, world_size = 4

Output: {"ddp":1600,"zero1":1000,"zero2":700,"zero3":400}

Explanation: DDP replicates all 1600 bytes. The ZeRO stages progressively shard optimizer, gradient, and parameter state across four ranks.

Input: parameter_bytes = 5, gradient_bytes = 7, optimizer_bytes = 11, world_size = 3

Output: {"ddp":23,"zero1":16,"zero2":11,"zero3":8}

Input: parameter_bytes = 100, gradient_bytes = 50, optimizer_bytes = 200, world_size = 1

Output: {"ddp":350,"zero1":350,"zero2":350,"zero3":350}

Hint 1
divmod returns an integer quotient and remainder.

Hint 2
Python integers support exact arithmetic without a fixed-width overflow.

Requirements
Follow the stated pooled-byte memory model.
Preserve exact integer byte counts, including uneven divisions.
Constraints
parameter_bytes, gradient_bytes, and optimizer_bytes are nonnegative Python integers.
Their sum is at most 9,007,199,254,740,991.
world_size is a positive Python integer no greater than 9,007,199,254,740,991.
Activations and transient gathered buffers are excluded.

"""

from math import ceil, floor

def zero_memory_accounting(parameter_bytes: int, gradient_bytes: int, optimizer_bytes: int, world_size: int) -> dict:
    return {
        "ddp": parameter_bytes + gradient_bytes + optimizer_bytes,
        "zero1": parameter_bytes + gradient_bytes + ceil(optimizer_bytes/world_size),
        "zero2": parameter_bytes + ceil((gradient_bytes + optimizer_bytes) / world_size),
        "zero3": ceil((parameter_bytes + gradient_bytes + optimizer_bytes) / world_size),
    }

print(zero_memory_accounting(400, 400, 800, 4))
print(zero_memory_accounting(5, 7, 11, 3))
print(zero_memory_accounting(100, 50, 200, 1))
