/*

Description
Most of us are familiar with word wrap and justifying blocks of text. Our text editors do this for us - "wrap text to a width of 80 characters" and such. We've done challenges where we have made columns of text and we've also played with decolumnizing text. But this one's a bit different.

Given a block of text, can your program correctly identify the start of the next paragraph? You're free to use any heuristic you want. This one differs from previous challenges in that there is no whitespace between paragraphs like you had before. You may want to think about the statistics of lines the close a paragraph.

Challenge Input
The ability to securely access (replicate and distribute) directory
information throughout the network is necessary for successful
deployment.  LDAP's acceptance as an access protocol for directory
information is driving the need to provide an access control model
definition for LDAP directory content among servers within an
enterprise and the Internet.  Currently LDAP does not define an
access control model, but is needed to ensure consistent secure
access across heterogeneous LDAP implementations.  The requirements
for access control are critical to the successful deployment and
acceptance of LDAP in the market place.
This section is divided into several areas of requirements: general,
semantics/policy, usability, and nested groups (an unresolved issue).
The requirements are not in any priority order.  Examples and
explanatory text is provided where deemed necessary.  Usability is
perhaps the one set of requirements that is generally overlooked, but
must be addressed to provide a secure system. Usability is a security
issue, not just a nice design goal and requirement. If it is
impossible to set and manage a policy for a secure situation that a
human can understand, then what was set up will probably be non-
secure. We all need to think of usability as a functional security
requirement.
Copyright (C) The Internet Society (2000).  All Rights Reserved.
This document and translations of it may be copied and furnished to
others, and derivative works that comment on or otherwise explain it
or assist in its implementation may be prepared, copied, published
and distributed, in whole or in part, without restriction of any
kind, provided that the above copyright notice and this paragraph are
included on all such copies and derivative works.  However, this
document itself may not be modified in any way, such as by removing
the copyright notice or references to the Internet Society or other
Internet organizations, except as needed for the purpose of
developing Internet standards in which case the procedures for
copyrights defined in the Internet Standards process must be
followed, or as required to translate it into languages other than
English.
The limited permissions granted above are perpetual and will not be
revoked by the Internet Society or its successors or assigns.
This document and the information contained herein is provided on an
"AS IS" basis and THE INTERNET SOCIETY AND THE INTERNET ENGINEERING
TASK FORCE DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING
BUT NOT LIMITED TO ANY WARRANTY THAT THE USE OF THE INFORMATION
HEREIN WILL NOT INFRINGE ANY RIGHTS OR ANY IMPLIED WARRANTIES OF
MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.

Challenge Output
Your program should emit something like this:

The ability to securely access (replicate and distribute) directory information throughout the network is necessary for successful deployment. LDAP's acceptance as an access protocol for directory information is driving the need to provide an access control model definition for LDAP directory content among servers within an enterprise and the Internet. Currently LDAP does not define an access control model, but is needed to ensure consistent secure access across heterogeneous LDAP implementations. The requirements for access control are critical to the successful deployment and acceptance of LDAP in the market place.

This section is divided into several areas of requirements: general, semantics/policy, usability, and nested groups (an unresolved issue). The requirements are not in any priority order. Examples and explanatory text is provided where deemed necessary. Usability is perhaps the one set of requirements that is generally overlooked, but must be addressed to provide a secure system. Usability is a security issue, not just a nice design goal and requirement. If it is impossible to set and manage a policy for a secure situation that a human can understand, then what was set up will probably be non- secure. We all need to think of usability as a functional security requirement.

Copyright (C) The Internet Society (2000). All Rights Reserved. This document and translations of it may be copied and furnished to others, and derivative works that comment on or otherwise explain it or assist in its implementation may be prepared, copied, published and distributed, in whole or in part, without restriction of any kind, provided that the above copyright notice and this paragraph are included on all such copies and derivative works. However, this document itself may not be modified in any way, such as by removing the copyright notice or references to the Internet Society or other Internet organizations, except as needed for the purpose of developing Internet standards in which case the procedures for copyrights defined in the Internet Standards process must be followed, or as required to translate it into languages other than English.

The limited permissions granted above are perpetual and will not be revoked by the Internet Society or its successors or assigns.

This document and the information contained herein is provided on an "AS IS" basis and THE INTERNET SOCIETY AND THE INTERNET ENGINEERING TASK FORCE DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO ANY WARRANTY THAT THE USE OF THE INFORMATION HEREIN WILL NOT INFRINGE ANY RIGHTS OR ANY IMPLIED WARRANTIES OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.

*/

#include <stdio.h>
#include <string.h>

void
unwrap(FILE *in, FILE *out, char *line, size_t size, size_t wrapmax)
{
	static const char punctuation[] = ".?!";

	size_t firstlen;
	size_t lastlen;
	size_t len;

	while (fgets(line, size, in)) {
		len = strcspn(line, "\r\n");
		if (lastlen) {
			firstlen = strcspn(line, " ");
			if (lastlen + firstlen + 1 <= wrapmax)
				putchar('\n');
		}
		lastlen = strchr(punctuation, line[len - 1]) ? len : 0;
		fputs(line, out);
	}
}

int
main()
{
	char line[BUFSIZ];

	unwrap(stdin, stdout, line, sizeof(line), 68);
	return 0;
}
