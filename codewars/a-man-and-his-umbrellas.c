/*

A Man and his Umbrellas

Each morning a man walks to work, and each afternoon he walks back home.

If it is raining in the morning and he has an umbrella at home, he takes an umbrella for the journey so he doesn't get wet, and stores it at work. Likewise, if it is raining in the afternoon and he has an umbrella at work, he takes an umbrella for the journey home.

Given an array of the weather conditions, your task is to work out the minimum number of umbrellas he needs to start with in order that he never gets wet. He can start with some umbrellas at home and some at work, but the output is a single integer, the minimum total number.

The input is an array/list of consecutive half-day weather forecasts. So, e.g. the first value is the 1st day's morning weather and the second value is the 1st day's afternoon weather. The options are:

Without umbrella:

    "clear",
    "sunny",
    "cloudy",
    "overcast",
    "windy".

With umbrella:

    "rainy",
    "thunderstorms".

e.g. for three days, 6 values:

weather = ["rainy", "cloudy", "sunny", "sunny", "cloudy", "thunderstorms"]

N.B. He never takes an umbrella if it is not raining.
Examples:

    minUmbrellas(["rainy", "clear", "rainy", "cloudy"])

    should return 2

    Because on the first morning, he needs an umbrella to take, and he leaves it at work. So on the second morning, he needs a second umbrella.

    minUmbrellas(["sunny", "windy", "sunny", "clear"])

    should return 0

    Because it doesn't rain at all

    minUmbrellas(["rainy", "rainy", "rainy", "rainy", "thunderstorms", "rainy"])

    should return 1

    Because he only needs 1 umbrella which he takes on every journey.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef enum {
	CLEAR,
	SUNNY,
	CLOUDY,
	RAINY,
	OVERCAST,
	WINDY,
	THUNDERSTORMS,
} Weather;

int
umbrellas(Weather *forecast, size_t nforecast)
{
	int umbrella;
	int journey;
	int home;
	int work;
	size_t index;

	home = work = 0;
	for (index = 0; index < nforecast; index++) {
		switch (forecast[index]) {
		case RAINY:
		case THUNDERSTORMS:
			umbrella = 1;
			break;
		default:
			umbrella = 0;
			break;
		}

		journey = max(work - umbrella, 0);
		work = home + umbrella;
		home = journey;
	}
	return home + work;
}

int
main()
{
	Weather forecasts_1[] = { CLOUDY, WINDY, SUNNY };
	Weather forecasts_2[] = { RAINY, RAINY, RAINY, RAINY };
	Weather forecasts_3[] = { OVERCAST, RAINY, CLEAR, THUNDERSTORMS };

	assert(umbrellas(forecasts_1, nelem(forecasts_1)) == 0);
	assert(umbrellas(forecasts_2, nelem(forecasts_2)) == 1);
	assert(umbrellas(forecasts_3, nelem(forecasts_3)) == 2);

	return 0;
}
