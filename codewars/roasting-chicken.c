/*

Oliver likes to roast a chicken on a Sunday Afternoon.

He knows that in order to get it just how he wants it, he should roast it for 20 minutes for every 450g of uncooked weight plus an additional 20 minutes

You are given a weight of a uncooked chicken in kg, return for how long it needs to be roasted - in hours and minutes, rounding up to the nearest five minutes.

If the chicken is to be roasted for more than 2 hours then write hrs, otherwise write hr.

If the chicken is to be roasted for less than an hour, only give the number of minutes.

If the uncooked weight is 0, return "There is no chicken!"

An example time is 2 hrs 45 mins

*/

#include <stdio.h>
#include <string.h>
#include <math.h>

char *
cooktime(int weight, char *output)
{
	double value;
	int duration;
	int hour;
	int minute;
	int length;

	value = (weight * 1000) / 450.0;
	value = ((value * 20) + 20) / 5;

	duration = ceil(value) * 5;
	hour = duration / 60;
	minute = duration % 60;

	if (weight < 1)
		sprintf(output, "There is no chicken!");
	else if (hour < 1)
		sprintf(output, "%d mins", minute);
	else {
		length = sprintf(output, "%d hr", hour);
		if (hour > 1)
			length += sprintf(output + length, "s");
		if (minute > 0)
			length += sprintf(output + length, " %d mins", minute);
	}

	return output;
}

int
main()
{
	char output[128];
	int weight;

	for (weight = 0; weight <= 25; weight++)
		printf("%s\n", cooktime(weight, output));
	return 0;
}
