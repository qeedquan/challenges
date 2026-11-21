#!/usr/bin/env python3

"""

Background
An interesting way to solve a Sudoku puzzle is to represent it as a Boolean satisfiability problem, and then feed it to a SAT solver.

A Boolean Satisfiability Problem (abbreviated as SAT problem) is a problem in which you are given a set of Boolean expressions,
and you need to find a set of values for the variables such that all the expressions evaluate to true.

SAT solvers usually take a CNF (conjunctive normal form) as input, and output a satisfying assignment if one exists.
A CNF is a conjunction (AND) of clauses. A clause is a disjunction (OR) of literals.
A literal is a variable or a negated variable.
For example, x1∨¬x2 is a clause, and x1 and  ¬x2 are literals.

Let's take the CNF  ((x1∨x2)∧(¬x1∨¬x2)) as an example.
This CNF has two variables, x1 and x2.
The first clause is x1∨x2, which means that either x1 or x2 must be true.
The second clause is ¬x1∨¬x2, which means that either x1 or x2 must be false.
Therefore, the CNF is satisfiable if and only if x1 and x2 have opposite values.
One possible satisfying assignment is x1=1 and x2=0.

Task
Your task is to write a program or function that takes a Sudoku puzzle as input, and outputs a CNF that represents the puzzle. This means that the output CNF should be satisfiable if and only if the input puzzle has at least one solution.

You don't need to actually find the solution.

A Sudoku puzzle is still considered solvable, even if it has multiple solutions.

Your program or function should pass the following test cases in reasonable time. This is to prevent answers that brute force the sudoku and return a trivial CNF.

Input
You can take the input in any reasonable format. For example, you can take the input as a list of 81 numbers, where 0 represents an empty cell. The list can be flattened, or as a 9x9 matrix, or even as a 3x3x3x3 array.

Output
The output is a CNF. The CNF should be represented as a list of lists of integers. Each inner list represents a clause, and each integer represents a literal. Positive integers represent variables, and negative integers represent negated variables.
For example, the CNF ((x1∨x2)∧(¬x1∨¬x2)) is represented as [[1, 2], [-1, -2]].

The format is based on the DIMACS CNF format used by many SAT solvers.

This is code-golf, so the shortest code in bytes wins.

Test cases
You can check your output CNF using an online SAT solver, such as this one. Your code should generate the CNF in reasonable time, but it's okay if the SAT solver can't solve it in reasonable time.

Satisfiable
[[8,0,0,0,0,0,0,0,0],[0,0,3,6,0,0,0,0,0],[0,7,0,0,9,0,2,0,0],[0,5,0,0,0,7,0,0,0],[0,0,0,0,4,5,7,0,0],[0,0,0,1,0,0,0,3,0],[0,0,1,0,0,0,0,6,8],[0,0,8,5,0,0,0,1,0],[0,9,0,0,0,0,4,0,0]]
[[0,0,0,7,0,0,0,0,0],[1,0,0,0,0,0,0,0,0],[0,0,0,4,3,0,2,0,0],[0,0,0,0,0,0,0,0,6],[0,0,0,5,0,9,0,0,0],[0,0,0,0,0,0,4,1,8],[0,0,0,0,8,1,0,0,0],[0,0,2,0,0,0,0,5,0],[0,4,0,0,0,0,3,0,0]]
[[0,0,0,0,0,0,0,1,0],[4,0,0,0,0,0,0,0,0],[0,2,0,0,0,0,0,0,0],[0,0,0,0,5,0,4,0,7],[0,0,8,0,0,0,3,0,0],[0,0,1,0,9,0,0,0,0],[3,0,0,4,0,0,2,0,0],[0,5,0,1,0,0,0,0,0],[0,0,0,8,0,6,0,0,0]]
[[0,0,0,0,0,0,0,3,4],[0,8,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,6,0],[0,0,0,0,3,9,0,0,0],[0,0,0,0,4,0,8,0,0],[0,0,1,0,0,0,0,0,0],[0,6,0,2,0,0,0,0,0],[4,0,0,0,0,0,7,0,0],[0,0,0,0,0,0,5,0,0]]
[[7,2,5,8,9,3,4,6,1],[8,4,1,6,5,7,3,9,2],[3,9,6,1,4,2,7,5,8],[4,7,3,5,1,6,8,2,9],[1,6,8,4,2,9,5,3,7],[9,5,2,3,7,8,1,4,6],[2,3,4,7,6,1,9,8,5],[6,8,7,9,3,5,2,1,4],[5,1,9,2,8,4,6,7,3]]
[[0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0]]
Unsatisfiable
[[0,0,0,3,0,0,0,1,6],[5,0,0,0,2,0,0,0,0],[0,0,0,0,0,0,0,3,0],[0,1,0,0,5,9,0,0,0],[0,3,6,0,0,0,0,0,0],[0,0,0,0,0,8,2,0,0],[7,0,0,0,0,0,9,0,0],[0,0,0,1,0,0,0,0,0],[9,0,0,0,0,0,0,0,0]]
[[3,0,0,0,0,0,2,0,8],[9,0,0,0,1,0,0,0,0],[0,0,0,0,0,0,0,0,0],[0,1,4,0,0,0,0,9,0],[0,6,0,7,0,3,0,0,0],[0,0,0,0,8,0,0,0,0],[7,5,0,8,0,0,0,0,0],[0,0,0,0,0,0,4,1,0],[0,0,0,3,0,0,0,0,0]]
[[0,0,2,0,6,0,0,0,0],[8,0,0,0,0,0,0,4,0],[0,0,0,0,0,0,0,0,1],[4,0,0,5,0,1,0,0,0],[0,0,0,0,0,0,2,0,0],[0,0,0,9,0,0,0,0,0],[0,0,0,0,3,0,6,2,0],[0,6,0,0,0,0,8,0,0],[1,0,0,7,0,0,0,0,0]]
[[5,0,0,0,0,9,3,0,0],[0,2,0,0,8,0,0,0,0],[0,0,0,0,0,0,1,0,0],[0,0,0,1,0,0,5,7,0],[0,0,4,0,0,0,0,0,0],[0,8,0,0,0,0,0,0,0],[0,0,6,0,0,0,0,8,4],[1,0,0,3,0,0,0,0,0],[0,0,0,0,0,0,0,2,0]]
[[1,0,0,0,0,0,0,0,0],[1,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0]]
[[1,2,3,4,5,6,7,8,9],[1,2,3,4,5,6,7,8,9],[1,2,3,4,5,6,7,8,9],[1,2,3,4,5,6,7,8,9],[1,2,3,4,5,6,7,8,9],[1,2,3,4,5,6,7,8,9],[1,2,3,4,5,6,7,8,9],[1,2,3,4,5,6,7,8,9],[1,2,3,4,5,6,7,8,9]]

"""

from itertools import chain

# Map (row, column, value) to a unique literal ID [1, 729]
def get_variable(r, c, v):
    return 81 * (r - 1) + 9 * (c - 1) + v

def generate_sudoku_cnf(filename, puzzle):
    grid = list(chain.from_iterable(puzzle))
    if len(grid) != 81:
        raise ValueError("Grid string must contain exactly 81 characters (excluding newlines).")

    clauses = []
    # 1. At least one number per cell
    for r in range(1, 10):
        for c in range(1, 10):
            clauses.append([get_variable(r, c, v) for v in range(1, 10)])

    # 2. At most one number per cell (Cell Uniqueness)
    for r in range(1, 10):
        for c in range(1, 10):
            for v1 in range(1, 10):
                for v2 in range(v1 + 1, 10):
                    clauses.append([-get_variable(r, c, v1), -get_variable(r, c, v2)])

    # 3. Row Uniqueness (No duplicates in the same row)
    for r in range(1, 10):
        for v in range(1, 10):
            for c1 in range(1, 10):
                for c2 in range(c1 + 1, 10):
                    clauses.append([-get_variable(r, c1, v), -get_variable(r, c2, v)])

    # 4. Column Uniqueness (No duplicates in the same column)
    for c in range(1, 10):
        for v in range(1, 10):
            for r1 in range(1, 10):
                for r2 in range(r1 + 1, 10):
                    clauses.append([-get_variable(r1, c, v), -get_variable(r2, c, v)])

    # 5. Box Uniqueness (No duplicates in the same 3x3 sub-grid)
    for br in range(3):  # Box row index
        for bc in range(3):  # Box column index
            for v in range(1, 10):
                # Gather all 9 cells inside this specific 3x3 box
                cells = []
                for dr in range(1, 4):
                    for dc in range(1, 4):
                        cells.append((3 * br + dr, 3 * bc + dc))
                # Generate pairwise exclusion clauses
                for i in range(len(cells)):
                    for j in range(i + 1, len(cells)):
                        r1, c1 = cells[i]
                        r2, c2 = cells[j]
                        clauses.append([-get_variable(r1, c1, v), -get_variable(r2, c2, v)])

    # 6. Parse initial clues from the grid
    for idx, char in enumerate(grid):
        if char != 0:
            r = (idx // 9) + 1
            c = (idx % 9) + 1
            v = int(char)
            # Add a unit clause fixing this value
            clauses.append([get_variable(r, c, v)])

    # Write to DIMACS file format
    num_variables = 729
    num_clauses = len(clauses)

    with open(filename, 'w') as f:
        f.write(f"c Sudoku CNF Translation\n")
        f.write(f"p cnf {num_variables} {num_clauses}\n")
        for clause in clauses:
            f.write(" ".join(map(str, clause)) + " 0\n")
        print(f"Written {num_clauses} clauses to '{filename}'")

def main():
    sat_1 = [
        [8, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 3, 6, 0, 0, 0, 0, 0],
        [0, 7, 0, 0, 9, 0, 2, 0, 0],
        [0, 5, 0, 0, 0, 7, 0, 0, 0],
        [0, 0, 0, 0, 4, 5, 7, 0, 0],
        [0, 0, 0, 1, 0, 0, 0, 3, 0],
        [0, 0, 1, 0, 0, 0, 0, 6, 8],
        [0, 0, 8, 5, 0, 0, 0, 1, 0],
        [0, 9, 0, 0, 0, 0, 4, 0, 0],
    ]
    sat_2 = [
        [0, 0, 0, 7, 0, 0, 0, 0, 0],
        [1, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 4, 3, 0, 2, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 6],
        [0, 0, 0, 5, 0, 9, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 4, 1, 8],
        [0, 0, 0, 0, 8, 1, 0, 0, 0],
        [0, 0, 2, 0, 0, 0, 0, 5, 0],
        [0, 4, 0, 0, 0, 0, 3, 0, 0],
    ]
    sat_3 = [
        [0, 0, 0, 0, 0, 0, 0, 1, 0],
        [4, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 2, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 5, 0, 4, 0, 7],
        [0, 0, 8, 0, 0, 0, 3, 0, 0],
        [0, 0, 1, 0, 9, 0, 0, 0, 0],
        [3, 0, 0, 4, 0, 0, 2, 0, 0],
        [0, 5, 0, 1, 0, 0, 0, 0, 0],
        [0, 0, 0, 8, 0, 6, 0, 0, 0],
    ]
    sat_4 = [
        [0, 0, 0, 0, 0, 0, 0, 3, 4],
        [0, 8, 0, 1, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 6, 0],
        [0, 0, 0, 0, 3, 9, 0, 0, 0],
        [0, 0, 0, 0, 4, 0, 8, 0, 0],
        [0, 0, 1, 0, 0, 0, 0, 0, 0],
        [0, 6, 0, 2, 0, 0, 0, 0, 0],
        [4, 0, 0, 0, 0, 0, 7, 0, 0],
        [0, 0, 0, 0, 0, 0, 5, 0, 0],
    ]
    sat_5 = [
        [7, 2, 5, 8, 9, 3, 4, 6, 1],
        [8, 4, 1, 6, 5, 7, 3, 9, 2],
        [3, 9, 6, 1, 4, 2, 7, 5, 8],
        [4, 7, 3, 5, 1, 6, 8, 2, 9],
        [1, 6, 8, 4, 2, 9, 5, 3, 7],
        [9, 5, 2, 3, 7, 8, 1, 4, 6],
        [2, 3, 4, 7, 6, 1, 9, 8, 5],
        [6, 8, 7, 9, 3, 5, 2, 1, 4],
        [5, 1, 9, 2, 8, 4, 6, 7, 3],
    ]
    sat_6 = [
        [0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0],
    ]

    unsat_1 = [
        [0, 0, 0, 3, 0, 0, 0, 1, 6],
        [5, 0, 0, 0, 2, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 3, 0],
        [0, 1, 0, 0, 5, 9, 0, 0, 0],
        [0, 3, 6, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 8, 2, 0, 0],
        [7, 0, 0, 0, 0, 0, 9, 0, 0],
        [0, 0, 0, 1, 0, 0, 0, 0, 0],
        [9, 0, 0, 0, 0, 0, 0, 0, 0],
    ]
    unsat_2 = [
        [3, 0, 0, 0, 0, 0, 2, 0, 8],
        [9, 0, 0, 0, 1, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 1, 4, 0, 0, 0, 0, 9, 0],
        [0, 6, 0, 7, 0, 3, 0, 0, 0],
        [0, 0, 0, 0, 8, 0, 0, 0, 0],
        [7, 5, 0, 8, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 4, 1, 0],
        [0, 0, 0, 3, 0, 0, 0, 0, 0],
    ]
    unsat_3 = [
        [0, 0, 2, 0, 6, 0, 0, 0, 0],
        [8, 0, 0, 0, 0, 0, 0, 4, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 1],
        [4, 0, 0, 5, 0, 1, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 2, 0, 0],
        [0, 0, 0, 9, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 3, 0, 6, 2, 0],
        [0, 6, 0, 0, 0, 0, 8, 0, 0],
        [1, 0, 0, 7, 0, 0, 0, 0, 0],
    ]
    unsat_4 = [
        [5, 0, 0, 0, 0, 9, 3, 0, 0],
        [0, 2, 0, 0, 8, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 1, 0, 0],
        [0, 0, 0, 1, 0, 0, 5, 7, 0],
        [0, 0, 4, 0, 0, 0, 0, 0, 0],
        [0, 8, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 6, 0, 0, 0, 0, 8, 4],
        [1, 0, 0, 3, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 2, 0],
    ]
    unsat_5 = [
        [1, 0, 0, 0, 0, 0, 0, 0, 0],
        [1, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0],
    ]
    unsat_6 = [
        [1, 2, 3, 4, 5, 6, 7, 8, 9],
        [1, 2, 3, 4, 5, 6, 7, 8, 9],
        [1, 2, 3, 4, 5, 6, 7, 8, 9],
        [1, 2, 3, 4, 5, 6, 7, 8, 9],
        [1, 2, 3, 4, 5, 6, 7, 8, 9],
        [1, 2, 3, 4, 5, 6, 7, 8, 9],
        [1, 2, 3, 4, 5, 6, 7, 8, 9],
        [1, 2, 3, 4, 5, 6, 7, 8, 9],
        [1, 2, 3, 4, 5, 6, 7, 8, 9],
    ]

    generate_sudoku_cnf("sat1.cnf", sat_1)
    generate_sudoku_cnf("sat2.cnf", sat_2)
    generate_sudoku_cnf("sat3.cnf", sat_3)
    generate_sudoku_cnf("sat4.cnf", sat_4)
    generate_sudoku_cnf("sat5.cnf", sat_5)
    generate_sudoku_cnf("sat6.cnf", sat_6)

    generate_sudoku_cnf("unsat1.cnf", unsat_1)
    generate_sudoku_cnf("unsat2.cnf", unsat_2)
    generate_sudoku_cnf("unsat3.cnf", unsat_3)
    generate_sudoku_cnf("unsat4.cnf", unsat_4)
    generate_sudoku_cnf("unsat5.cnf", unsat_5)
    generate_sudoku_cnf("unsat6.cnf", unsat_6)

main()
