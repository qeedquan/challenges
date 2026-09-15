/*

Rules:

Your program can be in any programming language.
Your program should not take any input.
Your program should transform the word "RELATIVE" into "STATIC". The word can at any stage only consist of uppercase letters A-Z.
Your program can only use 8 different operations.
The length, in number of letters, of the word cannot exceed 10 letters. If letters moves beyond that limit the letters will be deleted.
Your program must use all 8 operations before it can start reusing the operations again. All operations must be used the same amount of times.
The word must be "STATIC" at the end of the last chunk of 8 operations.
The very first OP used in the first chunk of OPs is never executed, so the program must output word "RELATIVE" of the first row.
The lines should be outputted in chunks of 8 lines, separated by a double linefeed between the chunks.
Your program should output the lines describing how it manipulates the string. Output each iteration of operations, one line for every applied operation in this form:
<iteration # in 6 numbers>: <operation> <current word after OP is executed>

The operations available:

INS     Move the current word 1 character to the right and
        replace first letter with 'A'.

DEL     Deletes the last letter in the word.

INC     Increase the second letter from the left with 1.
        Example: 'A' converts into 'B' or a 'Z' converts into 'A'.
        If the letter position is outside of the current word, nothing happens.

DEC     Decrease the fourth letter from the left with 4.
        Example: 'T' converts into 'P' or a 'C' converts into 'Y'.
        If the letter position is outside of the current word, nothing happens.

SWT     Swith letter number three from left with letter number two from right.
        If any of the letters are outside of current word, nothing happens.

INV     Invert the current word.

JMP     Invalidates the nextcoming OP.
        If this OP is used as OP #8 in a chunk, nothing happens.

REP     Execute the previous op again.
        If this OP is used as OP #1 in a chunk, nothing happens.
Example output (incomplete as the word is not "STATIC" at the end of the last chunk of 8 OPs):

000001: REP RELATIVE
000002: DEL RELATIV
000003: INS ARELATIV
000004: INC ASELATIV
000005: SWT ASILATEV
000006: INV VETALISA
000007: JMP VETALISA
000008: DEC VETALISA

000009: DEC VETWLISA
000010: JMP VETWLISA
000011: INS VETWLISA
000012: DEL VETWLIS
000013: REP VETWLI
000014: SWT VELWTI
000015: INC VFLWTI
000016: INV ITWLFV

The scoring is: (Sourcecode size in bytes) * (# OP-chunks). The program with the smallest score wins. The competition ends at 2014-12-31.

*/

package main

import "fmt"

func main() {
	fmt.Println(CODE)
}

// Code by @Volatility
const CODE = `
000001: INC RELATIVE
000002: DEL RELATIV
000003: REP RELATI
000004: INS ARELATI
000005: DEC AREHATI
000006: INV ITAHERA
000007: JMP ITAHERA
000008: SWT ITAHERA

000009: DEC ITADERA
000010: INS AITADERA
000011: INV AREDATIA
000012: DEL AREDATI
000013: INC ASEDATI
000014: JMP ASEDATI
000015: SWT ASEDATI
000016: REP ASEDATI

000017: DEC ASEZATI
000018: INV ITAZESA
000019: DEL ITAZES
000020: SWT ITEZAS
000021: INS AITEZAS
000022: JMP AITEZAS
000023: INC AITEZAS
000024: REP AITEZAS

000025: DEC AITAZAS
000026: REP AITWZAS
000027: INS AAITWZAS
000028: INC ABITWZAS
000029: INV SAZWTIBA
000030: DEL SAZWTIB
000031: JMP SAZWTIB
000032: SWT SAZWTIB

000033: DEC SAZSTIB
000034: DEL SAZSTI
000035: INV ITSZAS
000036: SWT ITAZSS
000037: INS AITAZSS
000038: REP AAITAZSS
000039: JMP AAITAZSS
000040: INC AAITAZSS

000041: DEL AAITAZS
000042: INV SZATIAA
000043: INC SAATIAA
000044: REP SBATIAA
000045: INS ASBATIAA
000046: JMP ASBATIAA
000047: DEC ASBATIAA
000048: SWT ASAATIBA

000049: SWT ASBATIAA
000050: INS AASBATIAA
000051: INV AAITABSAA
000052: INC ABITABSAA
000053: DEL ABITABSA
000054: JMP ABITABSA
000055: DEC ABITABSA
000056: REP ABITABSA

000057: INV ASBATIBA
000058: DEL ASBATIB
000059: INS AASBATIB
000060: DEC AASXATIB
000061: JMP AASXATIB
000062: INC AASXATIB
000063: SWT AAIXATSB
000064: REP AASXATIB

000065: INV BITAXSAA
000066: DEL BITAXSA
000067: REP BITAXS
000068: SWT BIXATS
000069: INS ABIXATS
000070: INC ACIXATS
000071: JMP ACIXATS
000072: DEC ACIXATS

000073: INS AACIXATS
000074: INC ABCIXATS
000075: INV STAXICBA
000076: DEL STAXICB
000077: REP STAXIC
000078: JMP STAXIC
000079: SWT STAXIC
000080: DEC STATIC
`
