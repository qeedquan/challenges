%{

The time response represents how the state of a dynamic system changes in time when subjected to a particular input
Usually to get the time response, use state space representation or inverse of transfer function and simulate it over time

Frequency response is used for LTI system, usually use the bode plot or nyquist diagram to characterize it

For our purposes, we will use the Bounded Input Bounded Output (BIBO) definition of stability which states that a system is stable if the output remains bounded for all bounded (finite) inputs.
Practically, this means that the system will not "blow up" while in operation.

First-order systems are the simplest dynamic systems to analyze. Some common examples include mass-damper systems and RC circuits.

The form of a first-order transfer function is
b / (s + a) or k_dc / (tau*s + 1)

where parameters k_dc and tau completely characterize the response

The DC gain k_dc is the ratio of the magnitude of the steady-state step response to the magnitude of the step input.
For stable transfer functions, the Final Value Theorem demonstrates that the DC gain is the value of the transfer function evaluated at s=0

For first-order systems of the forms shown, the DC gain is k_dc = b/a

For a first order system, we can think of a step response as how long it takes from 0 to final value and the impulse response as how long from initial (final) value going to 0
The first order response to step/impulse is always a exponential decay/increase that reaches a saturation point 
For sinusoidal inputs we can see that it is some sort of lowpass filter if we look at the bode plot

Settling Time

The settling time, T_s, is the time required for the system output to fall within a certain percentage (i.e. 2%) of the steady-state value for a step input.
The settling times for a first-order system for the most common tolerances are provided in the table below.
Note that the tighter the tolerance, the longer the system response takes to settle to within this band, as expected.

Ts = 2.3/a = 2.3Tc  (10%)
Ts = 3/a   = 3 Tc   (5%)
Ts = 3.9/a = 3.9Tc  (2%)
Ts = 4.6/a = 4.6Tc  (1%)

Rise Time
The rise time, T_r, is the time required for the system output to rise from some lower level x% to some higher level y% of the final steady-state value.
For first-order systems, the typical range is 10% - 90%.

Bandwidth
The bandwidth is the inverse of the time constant for first order system: 1/tau

%}

pkg load control;

function analyze(fig, pfx, G)
	% All of the roots of the poles has to have negative real part for it to be stable
	% In a proper first order system, there are no zeros, only 1 pole
	G
	disp('Zeros of the transfer function');
	zero(G)
	disp('Poles of the transfer function');
	pole(G)
	% The ZPK output gives zero, poles, and DC gain so combined information of the above
	disp('ZPK of the transfer function');
	[z, p, k] = zpkdata(G)

	% The DC gain (k_dc) is the transfer function evaluated at s=0
	disp('DC Gain');
	G(0)

	% Given a transfer functon, we can convert it to a state space representation with the ABCD matrix
	% The eigenvalues of matrix A can also determine the stability, all of the real parts of the eigenvalues has to be negative for stability
	disp('Eigenvalues of ABCD Matrix')
	[A, B, C, D] = ssdata(G);
	eig(A)

	damp(G);

	% The pole-zero map of a transfer function plots the location of zeros and poles on the complex plane
	pzmap(G);
	saveas(fig, strcat(pfx, '_pole_zero_map'), 'png');

	% Step input response of a magnitude u
	% The multiplier u determines the final/steady state value of the system (final_value = u*k_dc)
	% The time constant determines how long it reaches the final value, the smaller the time constant is, the faster it will reach the final value

	% The final value is 2*k_dc
	u = 2;
	step(u*G);
	saveas(fig, strcat(pfx, '_step_response_multiplier_2'), 'png');

	% The final value is 0.1*k_dc
	u = 0.1
	step(u*G);
	saveas(fig, strcat(pfx, '_step_response_multiplier_0_1'), 'png');

	% Impulse response of the function, since this is a first order system the response will go to 0 at some point (no oscillations)
	% How long depends on the time constant of the system, the initial value of the system is u*k_dc
	u = 2;
	impulse(u*G);
	saveas(fig, strcat(pfx, '_impulse_response_multiplier_2'), 'png');

	u = 0.1;
	impulse(u*G);
	saveas(fig, strcat(pfx, '_impulse_response_multiplier_0_1'), 'png');

	% Bode shows how it responds to various sine inputs, it might not be meaningful if we do not have such inputs but its there for information
	% For a first order system, the bode plot shows that it is a sort of low pass filter, as the magnitude gets attenuated as frequency increases
	% The phase gets shifted -45 degree per decade/magnitude change in frequency
	% The equation for low frequency magnitude is 20*log10(k_dc)
	% The bode plot also gives the frequency response of a system as it shows how the system responds to all sinusoidal inputs
	bode(G);
	saveas(fig, strcat(pfx, '_bode_plot'), 'png');

	clf;
	nyquist(G);
	saveas(fig, strcat(pfx, '_nyquist_plot'), 'png');
end

%{

Define all the important parameters of a first order system

DC gain (k_dc) and time constant (Tc)
Equating the standard form of b/(s+a) we have:

a = 1/Tc
b = k_dc/Tc
b/a = k_dc

%}

k_dc = 5;
Tc = 1;

s = tf('s');
G = k_dc/(Tc*s + 1);

fig = figure('visible', 'off');
analyze(fig, "first_order", G);

