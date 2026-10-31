#!/usr/bin/env pwsh

<#

Your task is to create a program that will display the following text, wait for the user to press a key (it is okay to ignore keys like ctrl, alt, caps lock, etc., as long as keys like letters, numbers, symbols, and enter are not ignored), and then terminate the program:

Press any key to continue...
Trailing newlines are allowed. The program must exit immediately after a key is pressed. Also, the program must be fairly portable (i.e no OS-specific headers or modules, runs outside of an IDE, etc.).

The prompt must be exactly as shown above, unless a trailing newline cannot be avoided.
This is code-golf, so the shortest answer in bytes wins. This is also my first code-golf question, so I apologize if I do not know the rules on PPCG.

#>

echo "Press any key to continue..."
$ign = [Console]::ReadKey()
echo ""
