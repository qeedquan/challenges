/*

Description
Q: What if CSV files sucked and made no sense? A: We would call them fixed-length files.

The TSYS Draft 256 fixed-length data exchange format is a good example of an industry standard, enterprise-grade dumpster fire. Imagine a question phrased thusly:

How do we add columns to a fixed-length file?

The answer in the real world is, "You don't, idiot." The answer in the enterprise, however, is to shout, "Hold my beer!".

The problem
Imagine a format that needs to convey the following information: name, age, and birth date. This information is stored in the following format, where the item on the left is the data being provided and the item on the right is the length of the field:

<name: 20> <age: 2> <birth date: 6>
An example might look like this:

Bob Johnson         41760322
This record describes a man named "Bob Johnson", born on March 22, 1976.

Now, how would you then go about adding a record to store Bob's job title?

The 'solution'
You use an extension record!

An extension record is an alternate record type that stores information not found in the original record type. If you recall, the original type in this case was name + age + birth date. We now need to store job title. In practice, extension records are signaled in one of two ways: either the primary record will contain some metadata that lets the reader know an extension record follows after, or the extension record itself will include some kind of sigil marking it as such. Which option you use will depend largely on how far ahead you were thinking (or how drunk you were) when designing the original format.

In our case, I was clearly too drunk, or else not quite drunk enough, so there is no metadata field in the original record. We will signal an extension by the use of the following token:

::EXT::
Here's what a job title extension record looks like:

<ext token: 7> <type: 4> <value: 17>
An example would be

::EXT::JOB Clock Watcher
Why does the value field have a length of 17? Because, thanks to the glory of fixed-length files, all records must have the same length!

Now, it's important to remember that not all extension records are required for all primary records. To wit, not everyone needs to have a job title, or an annual bonus, or... Anything else, really, other than name, age, and birth date. Even if extensions are present, their order is unspecified.

We have to process such a file and tell me which C-suite exec is reaming you hardest providing the most value to the company (highest salary).

Input description
You will be given a file formatted as descripted above, like:

Boyce Calles        83460319
::EXT::SAL 00000000000044722
Marcelo Candela     29040821
::EXT::JOB loser
::EXT::SAL 00000000000047706
Milton Camper       32541106
Important notes:

The file will be in the format told about in the description

There is no spacing between columns

String columns such as names are padded with spaces to their right, until they fulfill the length requirement of the column

Number columns are padded with zeroes to their left until they fulfill the length requirement of the column

You cannot assume the order or presence of extensions

Output description
The output is the name and salary of the employee having the highest salary

Note: salary is an extension with the type "SAL "

Your output for above file would be:

Marcelo Candela, $47,706
Challenge input
input (raw text)

Challenge output
Randy Ciulla, $4,669,876

Credit
This challenge was suggested by user /u/svgwrk, many thanks! If you have a challenge idea, please share it in /r/dailyprogrammer_ideas and there's a good chance we'll use it

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

typedef struct {
	char name[32];
	int salary;
} Employee;

void
usage()
{
	fprintf(stderr, "usage: file\n");
	exit(2);
}

void
trim(char *buf)
{
	size_t len;

	len = strlen(buf);
	while (len > 0) {
		if (!isspace(buf[len - 1]))
			break;
		buf[--len] = '\0';
	}
}

void
process(const char *name)
{
	FILE *fp;
	char buf[64];
	Employee top;
	Employee cur;

	fp = fopen(name, "rt");
	if (!fp) {
		printf("Failed to open file: %s\n", strerror(errno));
		return;
	}

	memset(&top, 0, sizeof(top));
	memset(&cur, 0, sizeof(cur));
	while (fgets(buf, sizeof(buf), fp)) {
		if (!strncmp(buf, "::EXT::SAL", 10)) {
			cur.salary = atoi(buf + 11);
			if (cur.salary > top.salary) {
				top.salary = cur.salary;
				memcpy(top.name, cur.name, sizeof(cur.name));
			}
		} else {
			snprintf(cur.name, sizeof(cur.name), "%.20s", buf);
		}
	}
	trim(top.name);

	printf("%s, $%d\n", top.name, top.salary);
	fclose(fp);
}

int
main(int argc, char *argv[])
{
	if (argc < 2)
		usage();

	process(argv[1]);
	return 0;
}
