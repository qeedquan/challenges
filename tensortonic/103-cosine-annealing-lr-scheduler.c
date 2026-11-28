/*

Cosine annealing smoothly decreases the learning rate following a half-cosine curve. Unlike linear decay, it slows down the rate of decrease near the start and end, spending more training time at moderate learning rates. This schedule is widely used in vision and language model training.

Given a base learning rate, a minimum learning rate, total steps, and the current step, compute the learning rate.

Formula

lr = min_lr + 0.5*(base_lr - min_lr) * (1 + cos(pi * current_step/total_steps))

At step 0 the cosine term equals 1, so lr = base_lr. At step = total_steps the cosine term equals -1, so lr = min_lr.

Examples
Input: base_lr = 0.1, min_lr = 0, total_steps = 100, current_step = 0

Output: 0.1

Explanation: At step zero, the cosine factor selects the base learning rate.

Input: base_lr = 0.1, min_lr = 0, total_steps = 100, current_step = 100

Output: 0.0

Hint 1
Convert the step fraction into an angle by multiplying it by pi.

Hint 2
Scale one plus the cosine between the base and minimum rates.

Requirements
Apply the cosine annealing formula exactly as specified
Support a non-zero minimum learning rate
Return base_lr at step 0 and min_lr at step = total_steps
Constraints
base_lr > min_lr >= 0
total_steps > 0, 0 <= current_step <= total_steps
Return a single float
Time limit: 300 ms

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

double
cosine_annealing_schedule(double base_lr, double min_lr, int total_steps, int current_step)
{
	double a, b, c;

	a = min_lr;
	b = 0.5 * (base_lr - min_lr);
	c = 1 + cos(M_PI * current_step / total_steps);
	return a + (b * c);
}

int
main()
{
	printf("%f\n", cosine_annealing_schedule(0.1, 0, 100, 0));
	printf("%f\n", cosine_annealing_schedule(0.1, 0, 100, 100));

	return 0;
}
