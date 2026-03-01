%{

https://uomustansiriyah.edu.iq/media/lectures/5/5_2020_04_13!08_16_05_AM.pdf

Second-order systems are commonly encountered in practice, and are the simplest type of dynamic system to exhibit oscillations.
Examples include mass-spring-damper systems and RLC circuits.
In fact, many true higher-order systems may be approximated as second-order in order to facilitate analysis.

A few forms of the equations of second order system:
m*y''(t) + b*y'(t) + k*y = f(t)
y''(t) + 2*zeta*omega*y'(t) + omega^2*y(t) = k_dc*omega^2

G(s) = 1 / (m*s^2 + b*s + k)
G(s) = k_dc*omega^2 / (s^2 + 2*zeta*omega*s + omega^2)

The parameters that characterize second order systems is

The DC gain (k_dc):
When we have the canonical transfer function form
k_dc = 1/k

Damping ratio (zeta):
Dimensionless quantity charaterizing the rate at which an oscillation in the system's response decays due to effects such as viscous friction or electrical resistance.
zeta = b / (2*sqrt(k*m))

Natural frequency
omega = sqrt(k / m)
The natural frequency omega is the frequency (in rad/s) that the system will oscillate at when there is no damping (zeta=0)

Poles/Zeros
The canonical second-order transfer function has two poles at:

poles = -zeta*omega +- j*omega * sqrt(1 - zeta^2)

Settling time
Ts = -ln(tolerance_fraction / (zeta*omega))
The settling times for the most common tolerances are presented in the following table:
Ts = 2.3/(zeta*w_n) (10%)
Ts = 3/(zeta*w_n)	(5%)
Ts = 3.9/(zeta*w_n) (2%)
Ts = 4.6/(zeta*w_n) (1%)

Percent overshoot
The percent overshoot is the percent by which a system's step response exceeds its final steady-state value.
For a second-order underdamped system, the percent overshoot Mp is directly related to the damping ratio by the following equation.
Here, Mp is a decimal number where 1 corresponds to 100% overshoot.
Mp = exp(-pi*zeta / sqrt(1-zeta^2))
zeta = -ln(Mp) / sqrt(pi^2 + ln^2(Mp))

Q-Factor
1/(2*zeta)

Bandwidth
The bandwidth is the frequency where the amplitude ratio drops by a factor of 0.707 = -3dB of its gain at zero or low-frequency.
bw = omega * sqrt(1 - 2*zeta^2 + sqrt(2 - 4*zeta^2 + 4*zeta^4))

Oscillates with damped frequency
omega_d = omega*sqrt(1 - zeta^2) in rad/sec

Damping Types:
zeta < 1 underdamped
both poles are complex-valued with negative real parts (2 complex conjugate roots); stable but oscillates torwards a steady value, the steady value is k_dc

zeta = 1 critically damped
two poles of real equal roots with negative value, fastest time with no oscillation

zeta > 1 overdamped
two poles of distinct real roots with negative value, no oscillations but slow

zeta = 0 undamped
poles are pure imaginary with real part equals 0, oscillates indefinitely

%}

pkg load control;
pkg load signal;

function G = analyze(fig, pfx, k_dc, w_n, zeta)
	clf;
	% Use the canonical form for the transfer function
	s = tf('s');
	G = k_dc*w_n^2 / (s^2 + 2*zeta*w_n*s + w_n^2)

	% Calculate the damped oscillation frequency
	damped_oscillation_frequency = w_n*sqrt(1 - zeta^2);
	printf("Damped Oscillation Frequency: %.4f\n",  damped_oscillation_frequency);

	% Calculate percent overshoot
	Mp = exp(-pi*zeta / sqrt(1-zeta^2));
	printf("Percent overshoot: %.4f\n", Mp);

	% Calculate the settling times
	Ts_10 = 2.3/(zeta*w_n);
	Ts_5 = 3/(zeta*w_n);
	Ts_2 = 3.9/(zeta*w_n);
	printf("Settling time %.4f %.4f %.4f\n", Ts_10, Ts_5, Ts_2);

	% Calculate the various parameters of the system
	damp(G);

	pzmap(G);
	saveas(fig, strcat(pfx, '_pole_zero_map'), "png");

	if zeta != 0
		impulse(G);
		saveas(fig, strcat(pfx, '_impulse_response'), 'png');
		
		step(G);
		saveas(fig, strcat(pfx, '_step_response'), 'png');
	end

	nyquist(G);
	saveas(fig, strcat(pfx, '_nyquist_plot'), 'png');

	% The bode plot can show the damped oscillation frequency by displaying a bump at that location, the damped oscillation frequency responds the strongest in the plot
	% The bode plot gives the frequency response of a system as it shows how the system behaves with all the sinusoidal inputs
	bode(G);
	saveas(fig, strcat(pfx, '_bode_plot'), 'png');
end

fig = figure('visible', 'off'); 

% Underdamped
k_dc = 30;
w_n = 10;
zeta = 0.2;
G1 = analyze(fig, "second_order_underdamped", k_dc, w_n, zeta);

% Overdamped
zeta = 1.2;
G2 = analyze(fig, "second_order_overdamped", k_dc, w_n, zeta);

% Critically Damped
zeta = 1;
G3 = analyze(fig, "second_order_critically_damped", k_dc, w_n, zeta);

% Undamped
zeta = 0;
G4 = analyze(fig, "second_order_undamped", k_dc, w_n, zeta);

% Show bode plot for all zeta values, the undamped with will have the largest bump at the oscillating frequency since it doesn't die out
bode(G1, G2, G3, G4);
legend('underdamped: zeta < 1',' overdamped: zeta > 1', 'critically-damped: zeta = 1', 'undamped: zeta = 0');
saveas(fig, 'second_order_bode_plot_all', 'png');

