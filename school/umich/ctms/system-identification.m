%{

Estimating the Order of a System
The order and relative degree of a system can be estimated from either the step response or the bode plot.
The relative degree of a system is the difference between the order of the denominator over the order of the numerator of the transfer function and is the lowest order the system can be.

Step Response

If the response of the system to a non-zero step input has a zero slope when t = 0, the system must be second order or higher because the system has a relative degree of two or higher.
If the step response shows oscillations, the system must be a second order or higher underdamped system and have a relative degree of two or higher.

Bode Plot

The phase plot can be a good indicator of order. If the phase drops below -90 degrees, the system must be second order or higher.
The relative degree of the system has to be at least as great as the number of multiples of -90 degrees achieved asymptotically at the lowest point on the phase plot of the system.

The system parameters for first and second order systems is as follows:

First Order:
G(s) = b / (s + a) = K / (tau*s + 1)

Second Order:
G(s) = a / (s^2 + bs + c) = K*omega^2 / (s^2 + 2*zeta*omega + omega^2)

%}

pkg load control;

%{

DC gain can be calculated by several methods:

Bode plot:
when s=0 -> K = 10^(M(0)/20) where M(0) is the magnitude when jw=0

Using a step response:
steady_state_step_response / magnitude_of_step_input

%}

sys = tf([1], [432, 54, 65]);
sys
damp(sys)

[y, t] = impulse(sys);
