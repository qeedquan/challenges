/*

𝖧ello all, I hope this finds you well.

There are 118 elements on the Periodic table at the moment, each one corresponds to the number of protons in an atom's nuclei.

Each element also has a 'symbol'. Hydrogen has 'H', Helium has 'He' and so on. I want to know about these!

Challenge:
Given 1 string as input, output true if the string is present as a symbol on the periodic table. Output false if not.

The string is case sensitive. While He is a valid symbol, he is not.

For reference, here are the elements that are valid symbols for this challenge (from wikipedia):

https://i.stack.imgur.com/VTwhl.png

That is, if the string is any one of the elements in this list, output 'true':

Ac,Ag,Al,Am,Ar,As,At,Au,Ba,B,Bh,Bi,Bk,Br,Ca,Cd,C,Ce,Cf,Cl,Cn,Cm,Co,Cr,Cs,Cu,Ds,Db,Dy,Er,Es,Eu,Fm,Fl,F,Fe,Fr,Ga,Gd,Ge,H,He,Hg,Hf,Ho,Hs,I,In,Ir,K,Kr,La,Li,Lr,Lv,Lu,Md,Mg,Mn,Mt,Mo,Mc,N,Na,Nb,Nd,Ne,Ni,Nh,No,Np,O,Og,Os,Pb,P,Pa,Pd,Po,Pr,Pm,Pt,Pu,Ra,Rb,Re,Rf,Rg,Rh,Rn,Ru,S,Sb,Sc,Sm,Sg,Se,Si,Sn,Sr,Ta,Tb,Tc,Te,Th,Ts,Tl,Ti,Tm,W,U,V,Xe,Y,Yb,Zn,Zr
And, Alphabetically indexed:

Ac,Ag,Al,Am,Ar,As,At,Au,
B,Ba,Bh,Bi,Bk,Br,
C,Ca,Cd,Ce,Cf,Cl,Cn,Cm,Co,Cr,Cs,Cu,
Db,Ds,Dy,
Er,Es,Eu,
F,Fe,Fm,Fl,Fr,
Ga,Gd,Ge,
H,He,Hg,Hf,Ho,Hs,
I,In,Ir,
K,Kr,
La,Li,Lr,Lu,Lv,
Mc,Md,Mg,Mn,Mo,Mt,
N,Na,Nb,Nd,Ne,Ni,Nh,No,Np,
O,Og,Os,
Pb,P,Pa,Pd,Po,Pr,Pm,Pt,Pu,
Ra,Rb,Re,Rf,Rg,Rh,Rn,Ru,
S,Sb,Sc,Sm,Sg,Se,Si,Sn,Sr,
Ta,Tb,Tc,Te,Th,Ts,Tl,Ti,Tm,
U,
V,
W,
Xe,
Y,Yb,
Zn,Zr

This is a classic code golf, so be sure to reduce the number of bytes you use in any way possible.

Good luck~!

*/

package main

import (
	"sort"
)

func main() {
	for _, e := range elements {
		assert(element(e) == true)
		assert(element("_"+e) == false)
		assert(element(e+"x") == false)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func element(s string) bool {
	n := len(elements)
	e := sort.Search(n, func(i int) bool {
		return s <= elements[i]
	})
	return e < n && s == elements[e]
}

func init() {
	sort.Strings(elements)
}

var elements = []string{
	"Ac", "Ag", "Al", "Am", "Ar", "As", "At", "Au",
	"B", "Ba", "Bh", "Bi", "Bk", "Br",
	"C", "Ca", "Cd", "Ce", "Cf", "Cl", "Cn", "Cm", "Co", "Cr", "Cs", "Cu",
	"Db", "Ds", "Dy",
	"Er", "Es", "Eu",
	"F", "Fe", "Fm", "Fl", "Fr",
	"Ga", "Gd", "Ge",
	"H", "He", "Hg", "Hf", "Ho", "Hs",
	"I", "In", "Ir",
	"K", "Kr",
	"La", "Li", "Lr", "Lu", "Lv",
	"Mc", "Md", "Mg", "Mn", "Mo", "Mt",
	"N", "Na", "Nb", "Nd", "Ne", "Ni", "Nh", "No", "Np",
	"O", "Og", "Os",
	"Pb", "P", "Pa", "Pd", "Po", "Pr", "Pm", "Pt", "Pu",
	"Ra", "Rb", "Re", "Rf", "Rg", "Rh", "Rn", "Ru",
	"S", "Sb", "Sc", "Sm", "Sg", "Se", "Si", "Sn", "Sr",
	"Ta", "Tb", "Tc", "Te", "Th", "Ts", "Tl", "Ti", "Tm",
	"U",
	"V",
	"W",
	"Xe",
	"Y", "Yb",
	"Zn", "Zr",
}
