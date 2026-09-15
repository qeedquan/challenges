; I was trying to write a short MIPS32 code for computing the median of three registers.
;
; The rules:
;
; Assume that some values are pre-loaded into $t0, $t1, $t2.
; The median of the three values should be placed in $t0.
; No branches are allowed, but otherwise any instruction is okay.
; You may arbitrarily modify the values of all registers.
; I was able to optimize it down to 15 instructions. Can you do better?


; @m90
median3:
	; Compare all three pairs of values.
	slt $t3, $t0, $t1
	slt $t4, $t2, $t1
	slt $t5, $t2, $t0

	; $t1 is the median if it is greater than exactly one of the other values.
	xor $t3, $t3, $t4
	movn $t0, $t1, $t3

	; $t2 is the median if it is less than exactly one of the other values.
	; (Otherwise, $t0 is already the median.)
	xor $t5, $t5, $t4
	movn $t0, $t2, $t5

