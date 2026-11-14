; Introduction
; I've always liked the idea of finding the most possible bang-for-your-buck squeezed out of a tiny chip, like the 6502. Of course, I'll need to start small. Filling the screen on 6502asm.com should be easy enough.
;
; Challenge
; Fill the entire program output screen on 6502asm.com with the color white using the least amount of unique executed bytes as possible. Or, set every memory space between 0x0200 and 0x05FF with any byte whose lower nybble is 1.
;
; No self modifying code. (executing bytes that were changed after being assembled)
; Try to keep the memory changed to a minimum, don't go changing bytes willy-nilly.

; ported from @Tux1 solution
init:
	lda #1
	ldx #$02

fill_screen:
	stx $01

draw_segment:
	sta ($00), Y
	iny
	bne draw_segment

	inx
	cpx #$06
	bne fill_screen

