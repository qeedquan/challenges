#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

void solve(int day, const char *month_name, int year)
{
	static const char *month_names[] = {
		"pop", "no", "zip", "zotz", "tzec",
		"xul", "yoxkin", "mol", "chen", "yax",
		"zac", "ceh", "mac", "kankin", "muan",
		"pax", "koyab", "cumhu", "uayet"
	};

	static const char *day_names[] = {
		"imix", "ik", "akbal", "kan", "chicchan",
		"cimi", "manik", "lamat", "muluk", "ok",
		"chuen", "eb", "ben", "ix", "mem", "cib",
		"caban", "eznab", "canac", "ahau"
	};

	int month;
	for (month = 0; month < (int)size(month_names); month++)
	{
		if (!strcmp(month_names[month], month_name))
			break;
	}

	int date = (year * 365) + (month * 20) + day;
	printf("%d %s %d\n", (date % 13) + 1, day_names[date % 20], date / 260);
}

int main()
{
	solve(10, "zac", 0);
	solve(0, "pop", 0);
	solve(10, "zac", 1995);

	return 0;
}
