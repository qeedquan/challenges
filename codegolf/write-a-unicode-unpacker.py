#!/usr/bin/env python3

"""

We all know scoring by characters is ripe for abuse. Let's prove this.

The Challenge
Output the following:

"m8V}G=D@7G1lAI,v08`
#(hNb0A8T!g;==SVaG5~
g"jUF!bmRY(3I@na?2S{
fJVzo/GQYU%ybpfUq3aG
Yza[jc,WJ$bP^7r};Da}
V-!Z+Nk:`/poc}d/X:G\
sWX{dbAUv6,i]%RG$hRp
),bd+?/{U1tU[;<;u.Nk
ZFPIOzJ/HimL!nexc,ls
HM%k3D$n2|R,8L?'eI_n
qs.kzbil$UQy_#Z)l#i%
*G4gr2<R^y#/iQ9,<+p%
}BYnb3_&:!m;#~QL1C?t
f.U>wIkTz=P>bf!uwb!d
z()rG)>~:q4#\}~pQEvZ
=OT8T4<i50%/8%eX^"3E
#Ks(8}OzZ&]RQ(-BLy<7
p7B~GEsF$)>?a"dtGCC'
H;:n&p&Z($ukNd,Et.$O
F*Uq0$dm,m%ejPT~u,qL
The characters inside the box are selected uniformly at random between the codepoints 0x21 and 0x7e. This means they should not be compressable much ordinarily. However, in this challenge, your code is scored by the number of characters, which can range in codepoint between 0x00 and 0x10ffff. Since this gives about 21 bits of information per character, and the box contains about 7 bits of information per character, approaching a 3:1 packing should be possible.

Note that:

As usual, you may output to STDOUT or return the string from a function;
A trailing newline on the last line is optional. Apart from this, the output must be exactly as given.
List representations are acceptable if returning from a function.
Scoring
The score is the length of your code in characters, expressed in the encoding of your language's interpreter. For most languages, this will be UTF-8. Note that languages that use an SBCS, such as most golfing languages, are at a huge disadvantage here as the number of characters is equal to the number of bytes.

Note that characters are not the same as grapheme clusters. For example, 👨‍🦲 is actually 3 characters (0x1f468 0x200d 0x1f9b2).

"""

TEXT = """"m8V}G=D@7G1lAI,v08`
#(hNb0A8T!g;==SVaG5~
g"jUF!bmRY(3I@na?2S{
fJVzo/GQYU%ybpfUq3aG
Yza[jc,WJ$bP^7r};Da}
V-!Z+Nk:`/poc}d/X:G\\
sWX{dbAUv6,i]%RG$hRp
),bd+?/{U1tU[;<;u.Nk
ZFPIOzJ/HimL!nexc,ls
HM%k3D$n2|R,8L?'eI_n
qs.kzbil$UQy_#Z)l#i%
*G4gr2<R^y#/iQ9,<+p%
}BYnb3_&:!m;#~QL1C?t
f.U>wIkTz=P>bf!uwb!d
z()rG)>~:q4#\}~pQEvZ
=OT8T4<i50%/8%eX^"3E
#Ks(8}OzZ&]RQ(-BLy<7
p7B~GEsF$)>?a"dtGCC'
H;:n&p&Z($ukNd,Et.$O
F*Uq0$dm,m%ejPT~u,qL"""

def main():
    print(TEXT)

main()
