/*

Most modern training pipelines start with a warmup phase where the learning rate gradually increases from zero, followed by a decay phase where it gradually decreases. This prevents early instability from large updates while still allowing the optimizer to escape sharp minima later.

Given a base learning rate, warmup steps, total steps, and the current step, compute the learning rate at that step.

Schedule
Warmup phase (current_step < warmup_steps): the learning rate increases linearly from 0 to base_lr.

lr = base_lr * current_step/warmup_steps

Decay phase (current_step >= warmup_steps): the learning rate decreases linearly from base_lr to 0.

lr = base_lr * (total_steps - current_step) / (total_steps - warmup_steps)

Examples
Input: base_lr = 0.1, warmup_steps = 10, total_steps = 100, current_step = 5

Output: 0.05

Explanation: Step 5 is halfway through the linear warmup.

Input: base_lr = 0.1, warmup_steps = 10, total_steps = 100, current_step = 55

Output: 0.05

Hint 1
Use the warmup fraction when the current step is below the warmup boundary.

Hint 2
Use the remaining-step fraction during linear decay.

Requirements
During warmup, linearly increase lr from 0 to base_lr
During decay, linearly decrease lr from base_lr to 0
At current_step = warmup_steps, lr should equal base_lr
Round numeric outputs to 6 decimal places.
Constraints
base_lr > 0, warmup_steps >= 0, total_steps > warmup_steps
0 <= current_step <= total_steps
Return a single float
Time limit: 300 ms

*/

#include <stdio.h>

double
warmup_decay_schedule(double base_lr, int warmup_steps, int total_steps, int current_step)
{
	if (current_step < warmup_steps)
		return (base_lr * current_step) / warmup_steps;
	return (base_lr * (total_steps - current_step)) / (total_steps - warmup_steps);
}

int
main()
{
	printf("%f\n", warmup_decay_schedule(0.1, 10, 100, 5));
	printf("%f\n", warmup_decay_schedule(0.1, 10, 100, 55));
	return 0;
}
