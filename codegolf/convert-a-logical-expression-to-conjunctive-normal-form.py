#!/usr/bin/env python3

"""

Goal:
Write a complete program or function which takes a formula in propositional logic (henceforth referred to as a logical expression or expression) and outputs that formula in conjunctive normal form. There are two constants, ⊤ and ⊥ representing true and false, a unary operator ¬ representing negation, and binary operators ⇒, ⇔, ∧, and ∨ representing implication, equivalence, conjunction, and disjunction, respectively which obey all of the usual logical operations (DeMorgan's law, double negation elimination, etc.).

Conjunctive normal form is defined as follows:

Any atomic expression (including ⊤ and ⊥) is in conjunctive normal form.
The negation of any previously constructed expression is in conjunctive normal form.
The disjunction of any two previously constructed expressions is in conjunctive normal form.
The conjunction of any two previously constructed expressions is in conjunctive normal form.
Any other expression is not in conjunctive normal form.
Any logical expression can be converted (non-uniquely) into a logically equivalent expression in conjunctive normal form (see this algorithm). You do not need to use that particular algorithm.

Input:
You may take input in any convenient format; e.g., a symbolic logical expression (if your language supports it), a string, some other data structure. You do not need to use the same symbols for true, false, and the logical operators as I do here, but your choice should be consistent and you should explain your choices in your answer if it's not clear. You may not accept any other input or encode any additional information in your input format. You should have some way of expressing an arbitrary number of atomic expressions; e.g. integers, characters, strings, etc.

Output:
The formula in conjunctive normal form, again in any convenient format. It need not be in the same format as your input, but you should explain if there are any differences.

Test cases:
P ∧ (P ⇒ R) -> P ∧ R
P ⇔ (¬ P) -> ⊥
(¬ P) ∨ (Q ⇔ (P ∧ R)) -> ((¬ P) ∨ ((¬ Q) ∨ R)) ∧ ((¬ P) ∨ (Q ∨ (¬ R)))

Notes:
If the input expression is a tautology, ⊤ would be a valid output. Similarly, if the input expression is a contradiction, ⊥ would be a valid output.
Both your input and output formats should have a well-defined order of operations capable of expressing all possible logical expressions. You may need parentheses of some sort.
You may use any well-defined choice of infix, prefix, or postfix notation for the logical operations. If your choice differs from the standard (negation is prefix, the rest are infix), please explain that in your answer.
Conjunctive normal form is not unique in general (not even up to reordering). You need only to output a valid form.
However you represent atomic expressions, they must be distinct from the logical constants, operators, and grouping symbols (if you have them).
Built-ins which compute conjunctive normal form are allowed.
Standard loopholes are forbidden.
This is code-golf; shortest answer (in bytes) wins.

"""

from sympy.logic.boolalg import to_cnf, Implies, Equivalent, And, Or, Not
from sympy.abc import P, Q, R

def cnf(expr):
    return to_cnf(expr, simplify=True)

def main():
    assert(cnf(And(P, Implies(P, R))) == (And(P, R)))
    assert(cnf(Equivalent(P, Not(P))) == False)
    assert(cnf(Or(Not(P), Equivalent(Q, And(P, R))))) == And(Or(Not(P), Or(Not(Q), R)), Or(Not(P), Or(Q, Not(R))))

main()
