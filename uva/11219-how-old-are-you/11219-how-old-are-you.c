#include <stdio.h>

int
solve(const char *date, const char *birthdate)
{
	int d1, m1, y1;
	int d2, m2, y2;
	int age;

	if (sscanf(date, "%d/%d/%d", &d1, &m1, &y1) != 3)
		return -1;
	if (sscanf(birthdate, "%d/%d/%d", &d2, &m2, &y2) != 3)
		return -1;

	age = y1 - y2;
	if (m2 > m1)
		age -= 1;
	if (m2 == m1 && d2 > d1)
		age -= 1;

	if (age < 0)
		puts("Invalid birth date");
	else if (age > 130)
		puts("Check birth date");
	else
		printf("%d\n", age);

	return 0;
}

int
main()
{
	solve("01/01/2007", "10/02/2007");
	solve("09/06/2007", "28/02/1871");
	solve("12/11/2007", "01/01/1984");
	solve("28/02/2005", "29/02/2004");

	return 0;
}
