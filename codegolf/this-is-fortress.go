/*

Fortress was a language being developed by the Sun Programming Language Research Group (R.I.P. Fortress) that had a unique property to it, it was possible to render ("Fortify") programs in different font-styles (i.e. blackboard bold, bold, italics, roman, etc. ). The goal is to represent a one-char Fortress variable in HTML markup.

Here's how the fortification of one-char variables worked (simplified/modified from documentation for code-golfing purposes):

If the variable is a repeated capital (i.e. ZZ), it becomes formatted in blackboard bold (𝔸𝔹ℂ𝔻𝔼𝔽𝔾ℍ𝕀𝕁𝕂𝕃𝕄ℕ𝕆ℙℚℝ𝕊𝕋𝕌𝕍𝕎𝕏𝕐ℤ)
If the variable is preceded by an underscore, the variable is rendered in roman font (left alone)
If the variable is followed by an underscore, the variable is rendered in bold font (<b>v</b>)
If the variable is neither preceded nor followed by an underscore, the variable is rendered in italic font (<i>v</i>)
The codepoints of the blackboard bolds are: 𝔸:1D538, 𝔹:1D539, ℂ:2102, 𝔻:1D53B, 𝔼:1D53C, 𝔽:1D53D, 𝔾:1D53E, ℍ:210D, 𝕀:1D540, 𝕁:1D541, 𝕂:1D542, 𝕃:1D543, 𝕄:1D544, ℕ:2115, 𝕆:1D546, ℙ:2119, ℚ:211A, ℝ:211D, 𝕊:1D54A, 𝕋:1D54B, 𝕌:1D54C, 𝕍:1D54D, 𝕎:1D54E, 𝕏:1D54F, 𝕐:1D550, ℤ:2124. These count as one byte each in your program (if your language of choice can handle these characters at all)
Input will be either a repeated ASCII capital, or a single ASCII letter with either no underscore, a leading underscore, or a trailing underscore (AKA _a_ will not be an input). This is code-golf so lowest byte count wins!

Test cases:

a => <i>a</i>
BB => 𝔹
c_ => <b>c</b>
_d => d
E => <i>E</i>
G_ => <b>G</b>
_H => H
ZZ => ℤ
Links: Specification, Direct download of version 0.1 alpha.

Reference implementation (This would be in Fortress, but Fortress doesn't like most of the doublestruck characters, so this implementation is in D):

dstring fortify(string arg) {
    import std.string, std.conv;

    alias D = to!dstring; //Convert to a string that accepts the unicode needed
    dstring BB = "𝔸𝔹ℂ𝔻𝔼𝔽𝔾ℍ𝕀𝕁𝕂𝕃𝕄ℕ𝕆ℙℚℝ𝕊𝕋𝕌𝕍𝕎𝕏𝕐ℤ"d; //blackboard bold capitals
    string UC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //normal ASCII capitals

    if(arg.length == 1)
        return D("<i>" ~ arg ~ "</i>");
    if(arg[0] == a[1])
        return D(BB[UC.indexOf(arg[0])]);
    if(arg[0] == '_')
        return D(arg[1]);
    return D("<b>" ~ arg[0] ~ "</b>");
}

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	assert(fortress("a") == "<i>a</i>")
	assert(fortress("BB") == "𝔹")
	assert(fortress("c_") == "<b>c</b>")
	assert(fortress("_d") == "d")
	assert(fortress("E") == "<i>E</i>")
	assert(fortress("G_") == "<b>G</b>")
	assert(fortress("_H") == "H")
	assert(fortress("ZZ") == "ℤ")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func fortress(s string) string {
	normal := `ABCDEFGHIJKLMNOPQRSTUVWXYZ`
	bold := []rune(`𝔸𝔹ℂ𝔻𝔼𝔽𝔾ℍ𝕀𝕁𝕂𝕃𝕄ℕ𝕆ℙℚℝ𝕊𝕋𝕌𝕍𝕎𝕏𝕐ℤ`)

	switch n := len(s); {
	case n == 0:
		return ""
	case n == 1:
		return fmt.Sprintf("<i>%c</i>", s[0])
	case s[0] == s[1]:
		i := strings.IndexByte(normal, s[0])
		return string(bold[i])
	case s[0] == '_':
		return string(s[1])
	default:
		return fmt.Sprintf("<b>%c</b>", s[0])
	}
}
