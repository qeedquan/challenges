/*

We all know that (−a)×(−a)=a×a (hopefully), but can you prove it?

Your task is to prove this fact using the ring axioms. What are the ring axioms? The ring axioms are a list of rules that two binary operations on a set have to follow. The two operation are addition, +, and multiplication, ×.
For this challenge here are the ring axioms where + and × are closed binary operations on some set S, − is a closed unary operation on S, and a, b, c are members of S:

1. a+(b+c)=(a+b)+c
2. a+0=a
3. a+(−a)=0
4. a+b=b+a*
5. a×(b×c)=(a×b)×c
6. a×1=a†
7. 1×a=a†
8. a×(b+c)=(a×b)+(a×c)
9. (b+c)×a=(b×a)+(c×a)

Your proof should be a string of equalities each being the application of one axiom.

You may apply the axioms to either the entire expression or to some sub-expression. For example if we have (a+c)+(b+c) we can apply Axiom 4 to just the (b+c) term, the (a+c) term or the entire expression as a whole.
The variables can also stand in for arbitrarily complex expressions for instance we can apply axiom 4 to ((a×c)+b)+((−a)+1) to get ((−a)+1)+((a×c)+b).
In each step of the proof you can only apply one axiom to one expression.
All axioms are bidirectional, meaning substitution can go in either direction. Things like the following are not allowed

(a + b) + (c + d) = (a + (b + c)) + d Ax. 1
This should be done in two steps:

(a + b) + (c + d) = ((a + b) + c) + d Ax. 1
                  = (a + (b + c)) + d Ax. 1
Facts you might normally take for granted but are not listed on the axioms list cannot be assumed, for example (−a)=(−1)×a
 is true but requires multiple steps to preform.

User Anthony has kindly provided a online proof validator that can be used as a replacement for TIO.

Example proof
Here is an example proof that −(−a)=a
 with the axioms used labeled on the right of each step.

 -(-a) = (-(-a)) + 0          Ax. 2
       = 0 + (-(-a))          Ax. 4
       = (a + (-a)) + (-(-a)) Ax. 3
       = a + ((-a) + (-(-a))) Ax. 1
       = a + 0                Ax. 3
       = a                    Ax. 2
Try it online!

You will be tasked to prove (−a)×(−a)=a×a
 using successive substitution like that shown above.

Scoring
This is proof-golf so your answers will be scored in number of steps taken to get from (−a)×(−a) to a×a, with a lower score being better.

Lemmas
Some answers have chosen to use Lemmas in their proofs, so I will describe how that should be scored to avoid any confusion.
For the uninitiated, lemmas are proofs of facts that you use later in the proof.
In real mathematics they can be helpful in organizing your thoughts or conveying information clearly to the reader.
In this challenge using lemmas should not have an direct effect on your score. (Although proof organization may make it easier or harder to golf)

If you choose to use lemmas it will cost as many steps as it took to prove that lemma in the first place each time you use it. For example the here is the score breakdown of a proof using lemmas.

Lemma:
a × 0 = 0

Proof (7 steps):
a × 0 = (a × 0) + 0                        Ax. 2 (1)
      = (a × 0) + ((a × b) + (-(a × b)))   Ax. 3 (1)
      = ((a × 0) + (a × b)) + (-(a × b))   Ax. 1 (1)
      = (a × (0 + b)) + (-(a × b))         Ax. 8 (1)
      = (a × (b + 0)) + (-(a × b))         Ax. 4 (1)
      = (a × b) + (-(a × b))               Ax. 2 (1)
      = 0                                  Ax. 3 (1)

Theorem:
(a × 0) + (b × 0) = 0

Proof (15 steps):
(a × 0) + (b × 0) = 0 + (b × 0)  Lemma (7)
                  = (b × 0) + 0  Ax. 4 (1)
                  = b × 0        Ax. 2 (1)
                  = 0            Lemma (7)
*: It has been pointed out that this axiom is not strictly necessary to prove this property, however you are still allowed to use it.

†: Since 1
 does not appear in the desired equality any proof that uses these axioms is not minimal. That is these axioms cannot help with proving the desired fact. They have been included just for the sake of completeness.

*/

package main

import "math/rand"

func main() {
	for range 10000000 {
		prove(rand.Int())
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// @Etoplay
func prove(a int) {
	eq(
		(-a)*(-a),
		((-a)*(-a))+0, // Axiom 2
		((-a)*(-a))+(((a*a)+(a*(-a)))+(-((a * a) + (a * (-a))))),      // Axiom 3
		(((-a)*(-a))+((a*a)+(a*(-a))))+(-((a * a) + (a * (-a)))),      // Axiom 1
		(((a*a)+(a*(-a)))+((-a)*(-a)))+(-((a * a) + (a * (-a)))),      // Axiom 4
		((a*a)+((a*(-a))+((-a)*(-a))))+(-((a * a) + (a * (-a)))),      // Axiom 1
		((a*a)+((a+(-a))*(-a)))+(-((a * a) + (a * (-a)))),             // Axiom 9
		((a*a)+(0*(-a)))+(-((a * a) + (a * (-a)))),                    // Axiom 3
		((a*(a+0))+(0*(-a)))+(-((a * a) + (a * (-a)))),                // Axiom 2
		((a*(a+(a+(-a))))+(0*(-a)))+(-((a * a) + (a * (-a)))),         // Axiom 3
		(((a*a)+(a*(a+(-a))))+(0*(-a)))+(-((a * a) + (a * (-a)))),     // Axiom 8
		((a*a)+((a*(a+(-a)))+(0*(-a))))+(-((a * a) + (a * (-a)))),     // Axiom 1
		(a*a)+(((a*(a+(-a)))+(0*(-a)))+(-((a * a) + (a * (-a))))),     // Axiom 1
		(a*a)+((((a*a)+(a*(-a)))+(0*(-a)))+(-((a * a) + (a * (-a))))), // Axiom 8
		(a*a)+(((a*a)+((a*(-a))+(0*(-a))))+(-((a * a) + (a * (-a))))), // Axiom 1
		(a*a)+(((a*a)+((a+0)*(-a)))+(-((a * a) + (a * (-a))))),        // Axiom 9
		(a*a)+(((a*a)+(a*(-a)))+(-((a * a) + (a * (-a))))),            // Axiom 2
		(a*a)+0, // Axiom 3
		a*a,     // Axiom 2
	)
}

func eq(a ...int) {
	for i := 0; i < len(a)-1; i++ {
		assert(a[i] == a[i+1])
	}
}
