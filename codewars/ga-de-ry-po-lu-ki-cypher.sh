#!/bin/sh

cat << EOF >/dev/null

Introduction
The GADERYPOLUKI is a simple substitution cypher used in scouting to encrypt messages. The encryption is based on short, easy to remember key. The key is written as paired letters, which are in the cipher simple replacement.

The most frequently used key is "GA-DE-RY-PO-LU-KI".

 G => A
 g => a
 a => g
 A => G
 D => E
  etc.
  
The letters, which are not on the list of substitutes, stays in the encrypted text without changes.

Task
Your task is to help scouts to encrypt and decrypt thier messages. Write the Encode and Decode functions.

Input/Output
The input string consists of lowercase and uperrcase characters and white . The substitution has to be case-sensitive.

Example
 encode("ABCD")          // => GBCE 
 encode("Ala has a cat") // => Gug hgs g cgt 
 encode("gaderypoluki"); // => agedyropulik
 decode("Gug hgs g cgt") // => Ala has a cat 
 decode("agedyropulik")  // => gaderypoluki
 decode("GBCE")          // => ABCD

EOF

translate() {
	echo "$@" | tr GADERYPOLUKIgaderypoluki AGEDYROPULIKagedyropulik
}

encode() {
	translate $@
}

decode() {
	translate $@
}

encode "ABCD"
encode "Ala has a cat"
encode "gaderypoluki"
decode "Gug hgs g cgt"
decode "agedyropulik"
decode "GBCE"

