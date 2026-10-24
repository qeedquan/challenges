%{

First order lead compensator transfer function:

C(s) = Kc * (s - z0) / (s - p0)
|z0| < |p0| (magnitude of z0 has to be less than p0)

A phase-lead compensator tends to shift the root locus toward the left in the s-plane.
This results in an improvement in the system's stability and an increase in its response speed.

How is this accomplished?  If you recall finding the asymptotes of the root locus that lead to the zeros at infinity, the equation to determine the intersection of the asymptotes along the real axis is the following.
a = (Sum[poles] - Sum[zeros]) / (#poles - #zeros)

When a lead compensator is added to a system, the value of this intersection will be a larger negative number than it was before.
The net number of zeros and poles will be same (one zero and one pole are added), but the added pole is a larger negative number than the added zero.
Thus, the result of a lead compensator is that the asymptotes' intersection is moved further to the left in the complex plane, and the entire root locus is shifted to the left as well.
This tends to increase the region of stability and the system's response speed.

To connect the compensator to the system (plant), do it in a cascaded way
H(s) = C(s)*G(s)

If we just have real zeros/poles then the root locus plot is just a line connecting them

%}

pkg load control;

function analyze_varying(fig, file, K, z, p)
	clf;
	s = tf('s');

	C1 = K*(s - z) / (s - p);
	C2 = K*(s - 10^-1*z) / (s - p);
	C3 = K*(s - 10^-2*z) / (s - p);
	C4 = K*(s - 10^-3*z) / (s - p);
	C5 = K*(s - 10^-4*z) / (s - p);
	C6 = K*(s - 10^-5*z) / (s - p);
	C7 = K*(s - 10^1*z) / (s - p);
	C8 = K*(s - 10^2*z) / (s - p);
	C9 = K*(s - 10^3*z) / (s - p);
	C10 = K*(s - 10^4*z) / (s - p);
	C11 = K*(s - 10^5*z) / (s - p);

	pzmap(C1);
	saveas(fig, sprintf('%s_pzmap', file), 'png');
	rlocus(C1);
	saveas(fig, sprintf('%s_rlocus', file), 'png');
	bode(C1);
	saveas(fig, sprintf("%s_base", file), 'png');

	bode(C1, C2, C3, C4, C5, C6, C7, C8, C9, C10, C11);
	saveas(fig, sprintf("%s_varying_zero", file), 'png');

	C1 = K*(s - z) / (s - p);
	C2 = K*(s - z) / (s - 10^-1*p);
	C3 = K*(s - z) / (s - 10^-2*p);
	C4 = K*(s - z) / (s - 10^-3*p);
	C5 = K*(s - z) / (s - 10^-4*p);
	C6 = K*(s - z) / (s - 10^-5*p);
	C7 = K*(s - z) / (s - 10^1*p);
	C8 = K*(s - z) / (s - 10^2*p);
	C9 = K*(s - z) / (s - 10^3*p);
	C10 = K*(s - z) / (s - 10^4*p);
	C11 = K*(s - z) / (s - 10^5*p);

	bode(C1, C2, C3, C4, C5, C6, C7, C8, C9, C10, C11);
	saveas(fig, sprintf("%s_varying_pole", file), 'png');
end

function analyze_combine(fig, file, K1, z1, p1, K2, z2, p2)
	clf;
	s = tf('s');

	C1 = K1*(s - z1) / (s - p1);
	C2 = K2*(s - z2) / (s - p2);
	C3 = C1*C2;
	
	pzmap(C3);
	saveas(fig, sprintf("%s_combined_pzmap", file), 'png');

	rlocus(C3);
	saveas(fig, sprintf("%s_combined_rlocus", file), 'png');

	bode(C1, C2, C3);
	saveas(fig, sprintf("%s_combined", file), 'png');
end

fig = figure('visible', 'off');

%{

A lead compensator can be designed using a time constant parameter Ts
C(s) = (1 + a*Ts) / (1 + Ts) [a > 1]

Equating with the standard form of
C(s) = Kc*(s - z0) / (s - p0), we have
p = 1/T
z = 1/(a*T)
Kc = a
This form makes it easy to add positive phase to the system over the frequency range 1/(a*T) to 1/T

The maximum phase that can be added with one lead compensator is 90 degrees, if you need more than 90 degrees combine more lead compensators in series
C_combined = C1(s)*C2(s) ...

The maximum amount of phase is added at the center frequency, which is calculated according to the following equation.
w_m = 1/(T*sqrt(a))

The equation determines the maximum phase:
sin(theta) = (a - 1) / (a + 1)

The steady state magnitude is Kc

%}

analyze_varying(fig, 'lead_compensator_1', 1, 0.1, 1);
analyze_varying(fig, 'lead_compensator_2', 50, -5, -7.3);
analyze_varying(fig, 'lead_compensator_3', 25, 5, -10.3);


%{

A lag compensator has the same form as the lead compensator mathematically, but the restrictions on some parameters flipped
C(s) = (1 + a*Ts) / (1 + Ts) [a < 1]
|z0| > |p0| (magnitude of z0 has to be greater than p0)

%}

analyze_varying(fig, 'lag_compensator_1', 0.9, 1, 0.1);
analyze_varying(fig, 'lag_compensator_2', 0.5, -7.3, -5);
analyze_varying(fig, 'lag_compensator_3', 0.3, -10.3, 5);

%{

When we combine lead/lag compensator together, the zeros/poles of the lead and lag determines which behavior is dominant
The combined output will have a phase response looking more like lead or lag depending on which zeros/poles are dominant

%}

shift1 = 0;
shift2 = 0;
analyze_combine(fig, 'lead_lag_compensator_1', 10, -1-shift1, -2-shift1, 0.1, -5-shift2, -4-shift2);

shift1 = 10;
shift2 = 20;
analyze_combine(fig, 'lead_lag_compensator_2', 10, -1-shift1, -2-shift1, 0.1, -5-shift2, -4-shift2);

shift1 = 20;
shift2 = 10;
analyze_combine(fig, 'lead_lag_compensator_3', 10, -1-shift1, -2-shift1, 0.1, -5-shift2, -4-shift2);

%{

For lead-lead compensator, the phase response envelope becomes bigger to cover the phase response of the individual lead compensator
Same general behavior with lag-lag compensator

%}

shift1=0;
shift2=0;
analyze_combine(fig, 'lead_lead_compensator_1', 10, -1-shift1, -2-shift1, 20, -8-shift2, -10-shift2);
analyze_combine(fig, 'lag_lag_compensator_1', 0.1, -2-shift1, -1-shift1, 0.05, -10-shift2, -8-shift2);
