/*

You have begun an internship at Retratek, and your first assignment is to create email addresses for the company's employees.

Each email address should use the domain "@retratek.com".
The username format should be "surname.name", where surname and name are the employee's last name and first name, respectively, both in lowercase.

Input
The first line contains an integer n (1≤n≤100) – the number of employees at the company.
The next n lines each contain an employee's first and last name.
Each name consists of at least one and no more than 20 letters.
It is guaranteed that the names contain only Latin letters, with the first letter capitalized and the rest in lowercase.

It is also guaranteed that no two employees share the same first and last name.

Output
Print n lines, each with the email address of a company employee.
The order of the email addresses should match the order of the employees as they appear in the input.

Examples

Input #1
5
Michael Jackson
Donald Knuth
Roman Jabarov
Sergey Baskakov
Madonna Ivanova

Answer #1
jackson.michael@retratek.com
knuth.donald@retratek.com
jabarov.roman@retratek.com
baskakov.sergey@retratek.com
ivanova.madonna@retratek.com

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void
solve(const char *firstname, const char *lastname, char *output)
{
	if (*lastname)
		output += sprintf(output, "%c%s.", tolower(*lastname), lastname + 1);
	else
		output += sprintf(output, ".");

	if (*firstname)
		output += sprintf(output, "%c%s", tolower(*firstname), firstname + 1);

	output += sprintf(output, "@retratek.com");
}

void
test(const char *firstname, const char *lastname, const char *expected)
{
	char result[64];

	solve(firstname, lastname, result);
	puts(result);
	assert(!strcmp(result, expected));
}

int
main()
{
	test("Michael", "Jackson", "jackson.michael@retratek.com");
	test("Donald", "Knuth", "knuth.donald@retratek.com");
	test("Roman", "Jabarov", "jabarov.roman@retratek.com");
	test("Sergey", "Baskakov", "baskakov.sergey@retratek.com");
	test("Madonna", "Ivanova", "ivanova.madonna@retratek.com");

	return 0;
}
