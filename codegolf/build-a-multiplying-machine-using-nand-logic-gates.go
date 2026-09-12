/*

Based on my previous question of the same type, Build an adding machine using NAND logic gates, this time you're being asked to multiply instead of add.

Build a diagram of (two-wire) NAND logic gates that will take the input wires A1, A2, A4, B1, B2, B4,
representing two binary numbers A to B from 0 to 7, and return values on the output wires C1, C2, C4, C8, C16, and C32, representing C,
which is the product of A and B.

Your score is determined by the number of NAND gates you use (1 point per gate).
To simplify things, you may use AND, OR, NOT, and XOR gates in your diagram, with the following corresponding scores:

NOT: 1
AND: 2
OR: 3
XOR: 4
Each of these scores corresponds to the number of NAND gates that it takes to construct the corresponding gate.

Lowest score wins.

*/

package main

func main() {
	for A1 := range 2 {
		for A2 := range 2 {
			for A4 := range 2 {
				for B1 := range 2 {
					for B2 := range 2 {
						for B4 := range 2 {
							C1, C2, C4, C8, C16, C32 := mul(A1, A2, A4, B1, B2, B4)
							X := (A1*1 + A2*2 + A4*4) * (B1*1 + B2*2 + B4*4)
							Y := C1*1 + C2*2 + C4*4 + C8*8 + C16*16 + C32*32
							assert(X == Y)
						}
					}
				}
			}
		}
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func nand(A, B int) int {
	return ^(A & B) & 1
}

func not(A int) int {
	return nand(A, A)
}

func and(A, B int) int {
	return not(nand(A, B))
}

func xor(A, B int) int {
	C := nand(A, B)
	return nand(nand(A, C), nand(B, C))
}

// ported from @KimOyhus solution
func mul(A1, A2, A4, B1, B2, B4 int) (C1, C2, C4, C8, C16, C32 int) {
	N11 := nand(A1, B1)
	N21 := nand(A2, B1)
	N41 := nand(A4, B1)
	N12 := nand(A1, B2)
	N22 := nand(A2, B2)
	N42 := nand(A4, B2)
	N14 := nand(A1, B4)
	N24 := nand(A2, B4)
	N44 := nand(A4, B4)
	P11 := not(N11)
	P21_12 := nand(N21, N12)
	P41_14 := nand(N41, N14)
	P22 := not(N22)
	P42_24 := nand(N42, N24)
	P44 := not(N44)
	N11_22 := nand(P11, P22)
	N11_44 := nand(P11, P44)
	D := nand(P41_14, N11_44)
	E := nand(nand(P22, P44), N11_44)
	F := nand(P42_24, E)
	G := nand(N11_22, nand(P42_24, F))
	H := nand(nand(P41_14, P22), G)
	C1 = P11
	C2 = and(P21_12, N11_22)
	C4 = xor(nand(N11, P22), D)
	C8 = nand(nand(nand(D, P42_24), E), H)
	C16 = nand(nand(H, G), nand(F, P44))
	C32 = not(F)
	return
}
