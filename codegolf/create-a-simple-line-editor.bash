#!/bin/bash

cat << EOF >/dev/null

In: a string without line breaks*
Allow the user to edit and submit the line
Out: the modified string (optionally with a trailing linebreak)

The line editor must at minimum allow the user to:

move a visible cursor left and right

insert and/or overwrite characters at the cursor position

remove characters at the cursor position

submit the new string, i.e. cease editing cause the modified string to be returned/printed/displayed/saved… (with no other text)

Appreciated, but not required:

explanation of your code.

link to an online testing site that can demonstrate your program/function

an animated image demonstrating usage (TIO, for instance, does not allow interactivity)

Note:

key-bindings are suggestions only

GUI or visual styling is not required

Examples
In the following, the cursor is illustrated with _.

In: Just some text
Allow the user to edit:
 Just some text_   User presses ← (left arrow key) nine times
 Just ̲some text    User presses Del four times
 Just ̲ text        User presses any
 Just any_text     User presses Enter
Out: Just any text

In: Remove me
Allow the user to edit:
 Remove me_        User presses Backspace nine times
 _                 User presses Enter
Out:  (empty string)

* To prevent trivial editor solutions, this must either be supplied via a different input method than the editing commands, or must be separated from them by a newline or similar.

EOF

read -ei "$*" input
echo "$input"

