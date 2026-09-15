#!/usr/bin/env Rscript

# Al wanted to use my computer to do some simple calculations, so I lent him the use of my R terminal for a bit.
# He complained though, saying it wasn't set up how he liked it. I said "No problem Al, set it up how you like and I'll just revert it later."
# This suited Al, and I left him to it. Al isn't a big fan of online R implementations like TIO, they don't seem to support his preferred way of coding.
# 
# After a few minutes, I came back and asked how it went. "everything fine", he said.
# I glanced at his session and it didn't look fine to me — only one of the four results looked correct!
# But Al knows R inside out, he must have been telling the truth.
# 
# Here is a transcript of Al's R session, as it appeared on the screen (Al uses RStudio 1.1.463 and R 3.6.3 if it matters, but I don't think it does here).
# The question is, how did Al "set up" his session to produce this output?
## what did Al type here?
# ‮32+55
# [1] 87
# ‮14*21
# [1] 294
# ‮91/7
# [1] 13
# ‮12-21
# [1] -9
# rules:
# Al only typed one function call which is somewhere in the standard R libraries.
# the function didn't import any code or refer to any external files (no source, install.packages, library etc..).
# Al didn't type cat("55+23\n[1]......-9"), it is something that could reasonably be interpreted as "setting up an R session"
# scoring:
#
# the primary scoring criterion is the number of bytes in the answer. Ties will be broken in ASCII-order, that is, if two valid answers are the same length the winner is the one which is first "alphabetically" (according to ASCII ordering).

comment <- "
@qwr

Uses RTL Override at the end to make all following input appear reversed. I tried entering the raw character in a string but it turns into a period for some reason. Tested with RStudio 1.2.1335 and R 3.6.3 on Ubuntu 20.04, but does not work in my terminal GNOME Terminal 3.36.2 which appears to do some kind of character stripping unless the character is printable. Note that default R prompt is "> " which works in GNOME Terminal and can be replicated to make it less suspicious.

Also Al and R sound like L and R.
"

options(prompt="\U202E")
