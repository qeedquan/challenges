/*

Taken from lesswrong.com

Once upon a time, there was a court jester who dabbled in logic.

The jester presented the king with two boxes. Upon the first box was inscribed:

"Either this box contains an angry frog, or the box with a false inscription contains an angry frog, but not both."

On the second box was inscribed:

"Either this box contains gold and the box with a false inscription contains an angry frog, or this box contains an angry frog and the box with a true inscription contains gold."

And the jester said to the king: "One box contains an angry frog, the other box gold; and one, and only one, of the inscriptions is true."

Work out which box contains the gold and then write a program that proves that your solution is correct in the fewest bytes.

This question is ideal for proof-assistants like Lean but any language may be used providing that the subset you are using doesn't violate the laws of classical FOL.

For instance, if your language allows the False type to be inhabited, it makes it possible to prove any proposition (even if it isn't true). If your language uses general recursion, it means some types are not decidable.

You can still use a language with something like an inhabitable false type or general recursion as long as they don't form part of your proof.

For inspiration on using types in other languages to prove theorems, avail yourself of this primer and the topic of Howard-Curry isomorphism.

Note: points are awarded for the shortest valid proof in your chosen language (by usual code golf rules). Actually solving the riddle yourself is optional. As such, the question will be updated with the solution in a few days. It should go without saying that if you would like to solve without spoilers, avoid looking the solutions of others until you are ready.

Update
The correct answer is

that the gold is in box 2. Without more information, it is not possible to determine the true inscription.

Here is an example un-golfed proof in Lean as a starting point.

import Mathlib

section Jester

inductive Box where
| one: Box
| two: Box

open Box

-- The insciption of the box is true
variable (I : Box → Prop)

-- The box contains a frog
variable (R : Box → Prop)

-- "Either this box contains an angry frog,
-- or the box with a false inscription contains an angry frog,
-- but not both."
variable (inscr_one : ((R one)
                    ↔ ¬(∀ b : Box, ¬I b → R b)) ↔ I one)

-- "Either this box contains gold and the box with a false inscription contains an angry frog,
-- or this box contains an angry frog and the box with a true inscription contains gold."
variable (inscr_two : (¬(
                        ¬R two
                          ∧ (∀b : Box, ¬I b → R b))
                      ↔ (R two
                          ∧ (∀ b : Box, I b → ¬R b))) ↔ I two)

-- There is exactly one true inscription
variable (true_inscr_unique : ∃ x : Box, I x ∧ ∀ y : Box, I y ↔ y = x)

-- Only one box contains the frog
(exclusive_contain : (¬ R one) ↔ R two)


include I R inscr_two true_inscr_unique exclusive_contain in
theorem box_two_contains_gold : ¬R two := by
  by_contra two_frog
  rcases true_inscr_unique with ⟨x, x_true, x_unique⟩
  cases x with
  | one =>
    -- Suppose Box one's inscription is true
    have two_false := (x_unique two).mp; simp at two_false
    have two_text := inscr_two.not.mpr two_false
    rw [not_iff] at two_text
    have first_part := two_text.mpr ⟨two_frog, (fun (b: Box) (b_true: I b) => by
      rw [(x_unique b).mp b_true]
      apply exclusive_contain.mpr
      exact two_frog
    )⟩
    simp at first_part
    exact first_part.left two_frog
  | two =>
      -- Suppose Box two's inscription is true
    have two_text := inscr_two.mpr x_true
    simp at two_text
    let op := exclusive_contain.not; simp at op
    let one_false := x_unique one; simp at one_false
    have ⟨two_frog, if_true_then_gold⟩ := two_text.mp (fun (h: ¬R two) =>
                                      (Exists.intro (one) (by
                                        exact ⟨(one_false), exclusive_contain.mpr two_frog⟩)))
    exact ((if_true_then_gold two) x_true) two_frog

#print axioms box_two_contains_gold
end Jester

*/

#include <assert.h>

/*

@OSI8

Description

Definitions

box 1 contains gold: a = 0

box 1 contains frog: a = 1

box 2 contains gold: b = 0

box 2 contains frog: b = 1

box with false inscription contains gold: f = 0

box with false inscription contains frog: f = 1

box with true inscription contains gold: t = 0

box with true inscription contains frog: t = 1

Rules

"One box contains an angry frog, the other box gold":

b = 1 - a

t = 1 - f
"Either this box contains an angry frog, or the box with a false inscription contains an angry frog, but not both":
x = a XOR f
in C64 BASIC:

x = a<>f
"Either this box contains gold and the box with a false inscription contains an angry frog, or this box contains an angry frog and the box with a true inscription contains gold":
y = ((b=0) AND f) XOR (b AND (t=0))
in C64 BASIC:

y = (f and b=0)<>(b and t=0)
"one, and only one, of the inscriptions is true":
x XOR y = 1
in C64 BASIC:

x<>y = -1
Algorithm

iterate through all cases until x<>y = -1
output box number with gold:
if box 1 contains gold (a = 0) print 1
if box 1 contains frog (a = 1) print 2
so the output is always a + 1
Result

The output is 2, so box 2 contains gold.

Additum

The above program stops at the first result found. But if you iterate to the end, it finds two cases, both with gold in box 2 but different statements about the inscription.

case 1: gold in box 2, inscription 1 true, inscription 2 false
case 2: gold in box 2, inscription 1 false, inscription 2 true

*/

int
solve()
{
	int a, b;
	int f, t;
	int x, y;

	for (a = 0; a <= 1; a++) {
		for (f = 0; f <= 1; f++) {
			b = 1 - a;
			t = 1 - f;
			x = a ^ f;
			y = (f & !b) ^ (b & !t);
			if ((x ^ y) == 1)
				return a + 1;
		}
	}
	return 0;
}

int
main()
{
	assert(solve() == 2);
	return 0;
}
