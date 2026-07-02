#!/bin/bash

cat << EOF >/dev/null

Prove anti-virus software is paranoid by making a program that simply opens and alphabetically sorts a CSV file, that will get flagged as a virus (or malware/spyware/any threat really) when run.

You will be assessed by the following criteria:

Does the cross-platform anti-virus package ClamAV detect it as a threat?

Your code is not actually a virus (if the code looks fishy it will be deducted points)

Conciseness of code
The specific target for this challenge is the following version of ClamAV with the following virus definitions (current as of the posting of this challenge). Your program must trigger this set of software/definitions to be eligible.

You may wish to use a virtual machine for testing your code.

Latest ClamAV® stable release is: 0.98.1
ClamAV Virus Databases:
main.cvd ver. 55 released on 17 Sep 2013 10:57 :0400 (sig count: 2424225)
daily.cvd ver. 18639 released on 19 Mar 2014 06:45 :0400 (sig count: 839186)
bytecode.cvd ver. 236 released on 05 Feb 2014 12:36 :0500 (sig count: 43)
safebrowsing.cvd ver. 41695 released on 19 Mar 2014 03:00 :0400 (sig count: 1147457)

EOF

cat << EOF >/dev/null

ported from @Dennis solution

The above uses caret notation. Notably, ^@ indicates a null byte.

How it works
sort -t, "$1" sorts the file specified as the first command-line argument ($1), using the comma character as field delimiter (-t,).

# at the beginning of the second line comments it out; it will get ignored by bash.

PK^C^D^@^@^@^@^@^@^@^@^@^@^@^@^@^@D^@^@^@D^@^@^@^@^@^@^@ is the shortest possible ZIP file local file header:

PK^C^D (0x04034B50) is the local file header signature.

^@^@^@^@^@^@^@^@^@^@^@^@^@^@ specifies the ZIP version, a bit flag, the compression method and the compressed file's mtime and checksum. All are set to zero.

The twice occurring D^@^@^@ (0x00000044 or 68) specifies the file's compressed and uncompressed length (68 bytes).

^@^@^@^@ specifies the filename and extra header length. Both are set to zero.

X5O!P%@AP[4\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H* is the 68 byte long EICAR test string, which serves as the data associated to the above header.

This takes advantage of the fact that ClamAV will act on all ZIP file local file headers, even if they're encountered outside of actual ZIP files.

EOF

sort -t ','
#PK^C^D^@^@^@^@^@^@^@^@^@^@^@^@^@^@D^@^@^@D^@^@^@^@^@^@^@X5O!P%@AP[4\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*
