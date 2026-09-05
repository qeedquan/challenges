#include <cassert>
#include <cstdio>
#include <format>
#include <string>

using namespace std;

string solve(const char *time)
{
	int hour, minute;
	if (sscanf(time, "%d:%d", &hour, &minute) != 2)
		return "invalid";

	hour = (11 - hour) + !minute;
	if (hour <= 0)
		hour += 12;
	if (minute != 0)
		minute = 60 - minute;
	return format("{:02}:{:02}", hour, minute);
}

int main()
{
	assert(solve("12:00") == "12:00");
	assert(solve("10:09") == "01:51");

	return 0;
}
