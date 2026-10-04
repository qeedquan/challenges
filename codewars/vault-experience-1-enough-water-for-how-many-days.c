/*

Hello dweller,

I'm the overseer of our vault, in which we all live.

I make it short: We are out of water. The only question is when!
Here is a list of all dwellers with their respective age int[] ageOfDweller.
In our tank currently are int water liters of water.
I want to know from you: How long will rich our supplies.

Remember!
Each dweller has a different water consumption.
A dweller under 18 consumes 1 liter per day, everyone older than 50 needs 1.5 liters and the rest needs 2 liters per day.
Each dweller must get its prescribed ration of water, every day!
If not satisfied all dweller, then our days are numbered.

Good luck! I'll bet on you!


Note from Vault Technicians:
Your program returns a positive integer. The residual water is not calculated.
return -1; - If no dweller living inside of the Vault.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
thirsty_in(double water, int *dweller_age, size_t num_dwellers)
{
	double water_perday;
	size_t i;

	if (num_dwellers == 0)
		return -1;

	water_perday = 0;
	for (i = 0; i < num_dwellers; i++) {
		if (dweller_age[i] < 18)
			water_perday += 1;
		else if (dweller_age[i] > 50)
			water_perday += 1.5;
		else
			water_perday += 2;
	}
	return floor(water / water_perday);
}

int
main()
{
	int dweller_age_1[] = { 5, 30, 10 };

	assert(thirsty_in(150, dweller_age_1, nelem(dweller_age_1)) == 37);

	return 0;
}
