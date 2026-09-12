/*

Problem
The 20 commonly occurring amino acids are abbreviated by using 20 letters from the English alphabet (all letters except for B, J, O, U, X, and Z).
Protein strings are constructed from these 20 symbols.
Henceforth, the term genetic string will incorporate protein strings along with DNA strings and RNA strings.

The RNA codon table dictates the details regarding the encoding of specific codons into the amino acid alphabet.

Given: An RNA string s corresponding to a strand of mRNA (of length at most 10 kbp).

Return: The protein string encoded by s.

Sample Dataset
AUGGCCAUGGCGCCCAGAACUGAGAUCAAUAGUACCCGUAUUAACGGGUGA
Sample Output
MAMAPRTEINSTRING

*/

package main

import (
	"bytes"
)

func main() {
	assert(rna2pro("AUGGCCAUGGCGCCCAGAACUGAGAUCAAUAGUACCCGUAUUAACGGGUGA") == "MAMAPRTEINSTRING")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://bioinformatics.stackexchange.com/questions/19496/rna-strings-and-amino-acid-string
func rna2pro(s string) string {
	lut := map[string]string{
		"UUU": "F", "UUC": "F",
		"UUA": "L", "UUG": "L",
		"UCU": "S", "UCC": "S", "UCA": "S", "UCG": "S",
		"UAU": "Y", "UAC": "Y",
		"UGU": "C", "UGC": "C",
		"UGG": "W",
		"CUU": "L", "CUC": "L", "CUA": "L", "CUG": "L",
		"CCU": "P", "CCC": "P", "CCA": "P", "CCG": "P",
		"CAU": "H", "CAC": "H",
		"CAA": "Q", "CAG": "Q",
		"CGU": "R", "CGC": "R", "CGA": "R", "CGG": "R",
		"AUU": "I", "AUC": "I", "AUA": "I",
		"AUG": "M",
		"ACU": "T", "ACC": "T", "ACA": "T", "ACG": "T",
		"AAU": "N", "AAC": "N",
		"AAA": "K", "AAG": "K",
		"AGU": "S", "AGC": "S",
		"AGA": "R", "AGG": "R",
		"GUU": "V", "GUC": "V", "GUA": "V", "GUG": "V",
		"GCU": "A", "GCC": "A", "GCA": "A", "GCG": "A",
		"GAU": "D", "GAC": "D",
		"GAA": "E", "GAG": "E",
		"GGU": "G", "GGC": "G", "GGA": "G", "GGG": "G",
	}

	w := new(bytes.Buffer)
	for i := 0; i+2 < len(s); i += 3 {
		w.WriteString(lut[s[i:i+3]])
	}
	return w.String()
}
