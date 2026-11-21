/*

Decode the diagonal.
Given a grid of characters. Output a decoded message as a string.

Input

  H Z R R Q
  D I F C A E A !
  G H T E L A E
  L M N H P R F
  X Z R P E
Output

HITHERE! (diagonally down right ↘ and diagonally up right ↗ if you can't go further).

The message ends when there is no space at the right up or down diagonal.

To make things even clearer: the same example, but in a simplified view

  H _ _ _ _
  _ I _ _ _ _ _ !
  _ _ T _ _ _ E
  _ _ _ H _ R _
  _ _ _ _ E

*/

package main

import (
	"bytes"
)

func main() {
	assert(decode([][]byte{
		[]byte("HZRRQ"),
		[]byte("DIFCAEA!"),
		[]byte("GHTELAE"),
		[]byte("LMNHPRF"),
		[]byte("XZRPE"),
	}) == "HITHERE!")

	assert(decode([][]byte{
		[]byte("C"),
		[]byte("DoFCAEAs!"),
		[]byte("GHdELAr"),
		[]byte("LMNePaF"),
		[]byte("XZRPW"),
	}) == "CodeWars")

	assert(decode([][]byte{
		[]byte("HXZ8QE"),
		[]byte("QNFCAEA!"),
		[]byte("GHTELAE"),
		[]byte("LMNPP"),
		[]byte("XZRP*"),
	}) == "HNTP*")

	assert(decode([][]byte{}) == "")

	assert(decode([][]byte{
		[]byte("qzJHMzDvHBHAEDGxsCCtHKwysGKIqLtKDEJwL"),
		[]byte("KpvrvzCyKMopDyoyrn"),
		[]byte("MEwBCpFnMsMJEsuArJGFLvtrFBHEEDyExAzFLqsr"),
	}) == "qpwrMzFyHMMpEyuysnG")

	assert(decode([][]byte{
		[]byte("BpEDyoqFqnCHvxKKD"),
		[]byte("CrIyowAnyFtBBqJCuBtzIAFI"),
		[]byte("FHussyHIDnB"),
		[]byte("LoJuFDFJAIsGsuoxEv"),
		[]byte("LrxGJKyxoIEnwGHJMMzwFMrG"),
		[]byte("K"),
	}) == "BruuJ")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func decode(m [][]byte) string {
	w, x, y, dy := new(bytes.Buffer), 0, 0, 1
	for 0 <= y && y < len(m) && x < len(m[y]) {
		w.WriteByte(m[y][x])
		if y+dy >= len(m) {
			dy = -1
		} else if y+dy < 0 {
			dy = 1
		}
		x, y = x+1, y+dy
	}
	return w.String()
}
