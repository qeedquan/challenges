#!/usr/bin/env pwsh

<#

Task
You're in charge of making a compass, of sorts.

Imagine your source code as the compass "needle" where running at different orientations produces distinct output.

Supported source code orientations are North, East, South, and West.

Example
Let's say you have source code:

ABCD
 J K
WXYZ
We'll consider this the North orientation, rotating 90 degrees clockwise points us to the East:

W A
XJB
Y C
ZKD
rotating again points South:

ZYXW
K J
DCBA
and finally, the last rotation to the West:

DKZ
C Y
BJX
A W
When ran, each of the above code examples should output a single, distinct printable ASCII character of your choosing.

Notes
Your code shall take no input.

Empty spaces or new lines do not collapse/disappear when rotating.

Leading/trailing new lines are okay in output.

Answers may be whole programs or functions, thus output to STDOUT or return the function result.

Standard code-golf rules apply; shortest answer in bytes wins!

#>

#4#
1#3
#2#
