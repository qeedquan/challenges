/*

After a hard quarter in the office you decide to get some rest on a vacation. So you will book a flight for you and your girlfriend and try to leave all the mess behind you.

You will need a rental car in order for you to get around in your vacation. The manager of the car rental makes you some good offers.

Every day you rent the car costs $40. If you rent the car for 7 or more days, you get $50 off your total. Alternatively, if you rent the car for 3 or more days, you get $20 off your total.

Write a code that gives out the total amount for different days(d).

*/

#include <assert.h>

int
rental_car_cost(int days)
{
	int value;

	value = 0;
	if (days >= 7)
		value = 50;
	else if (days >= 3)
		value = 20;
	return (days * 40) - value;
}

int
main()
{
	assert(rental_car_cost(1) == 40);
	assert(rental_car_cost(2) == 80);
	assert(rental_car_cost(3) == 100);
	assert(rental_car_cost(4) == 140);
	assert(rental_car_cost(5) == 180);
	assert(rental_car_cost(6) == 220);
	assert(rental_car_cost(7) == 230);
	assert(rental_car_cost(8) == 270);
	assert(rental_car_cost(9) == 310);
	assert(rental_car_cost(10) == 350);

	return 0;
}
