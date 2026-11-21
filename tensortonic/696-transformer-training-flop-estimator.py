#!/usr/bin/env python3

"""

Estimate the work of one training step from forward matrix multiplications and a supplied forward attention cost.
Count each multiplication and addition as one FLOP, and use twice the forward cost as the backward estimate.

F_forward = Sum_M(2*B_M*D_M*K_M) + F_attention
F_backward = 2 * F_forward
F_total = F_forward + F_backward

Here m indexes entries in matmuls; B is row count, D is input width, and K is output width for that entry. The four F values are the attention, forward, backward, and total operation counts; attention_flops supplies the attention term and defaults to zero. An empty multiplication list or a zero dimension contributes no matrix-multiplication work.

Return a Python dictionary with exactly the keys forward_flops, backward_flops, and total_flops, each holding an exact Python integer count under this estimate.

Examples
Input: matmuls = [[2,4,4]], attention_flops = 32

Output: {"forward_flops":96,"backward_flops":192,"total_flops":288}

Explanation: The matrix multiplication costs 64 FLOPs and attention adds 32, so forward costs 96. Backward costs twice the forward pass.

Input: matmuls = [[8,16,16],[8,16,4]], attention_flops = 0

Output: {"forward_flops":5120,"backward_flops":10240,"total_flops":15360}

Input: matmuls = [[0,512,512],[10,512,512]], attention_flops = 2000

Output: {"forward_flops":5244880,"backward_flops":10489760,"total_flops":15734640}

Hint 1
Tuple unpacking names the three dimensions in each entry.

Hint 2
Python integers retain exact products beyond fixed-width integer limits.

Requirements
Use exact Python integer arithmetic; tensor allocation and NumPy are not required.
Leave matmuls unchanged.
Constraints
matmuls is a Python list of [B, D, K] triples of nonnegative Python integers; the list may be empty.
Dimensions may describe large training runs and are not restricted to a fixed-width integer range.
attention_flops is a nonnegative Python integer.

"""

def flop_estimator(matmuls: list[list[int]], attention_flops: int = 0) -> dict:
    F = attention_flops
    for B, D, K in matmuls:
        F += 2*B*D*K
    return {
        "forward_flops": F,
        "backward_flops": 2*F,
        "total_flops": 3*F,
    }

def main():
    print(flop_estimator([[2, 4, 4]], 32))
    print(flop_estimator([[8, 16, 16], [8, 16, 4]], 0))
    print(flop_estimator([[0, 512, 512], [10, 512, 512]], 2000))

main()
