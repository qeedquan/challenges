#!/usr/bin/env pwsh

<#

Task is to output this text:

ABCDEFGHIJKLMNOPQRSTUVWXYZA
A 00000000000000000000000 Z
B                         Y
C  101010101010101010101  X
D                         W
E                         V
F   2101210121012101210   U
G                         T
H                         S
I                         R
J    12321012321012321    Q
K                         P
L                         O
M     234321012343210     N
N     123432101234321     M
O                         L
P                         K
Q    23210123210123210    J
R                         I
S                         H
T                         G
U   1210121012101210121   F
V                         E
W                         D
X  010101010101010101010  C
Y                         B
Z 00000000000000000000000 A
ABCDEFGHIJKLMNOPQRSTUVWXYZA

Rules
shortest code wins, but you are encouraged to post answers even if your language is among more verbose ones
trailing newline allowed,
lowercase letters allowed

#>

echo @"
ABCDEFGHIJKLMNOPQRSTUVWXYZA
A 00000000000000000000000 Z
B                         Y
C  101010101010101010101  X
D                         W
E                         V
F   2101210121012101210   U
G                         T
H                         S
I                         R
J    12321012321012321    Q
K                         P
L                         O
M     234321012343210     N
N     123432101234321     M
O                         L
P                         K
Q    23210123210123210    J
R                         I
S                         H
T                         G
U   1210121012101210121   F
V                         E
W                         D
X  010101010101010101010  C
Y                         B
Z 00000000000000000000000 A
ABCDEFGHIJKLMNOPQRSTUVWXYZA
"@
