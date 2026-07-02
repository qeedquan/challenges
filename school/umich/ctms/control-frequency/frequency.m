%{

Frequency methods uses the bode and nyquist plots to design and analyze a feedback controller

The idea is to start with the open loop response of the plant and adjust gain to modify the frequency response

Here the example we use is a unity feedback system (constant gain for all inputs)
input ----> [K] Gain -> [G(s)] Plant ----> output
        ^------------------------------^
                   feedback

%}

pkg load control;

%{

G(s) here is the transfer function of the plant (open-loop response)
K is the constant gain

The gain margin is defined as the change in open-loop gain required to make the closed-loop system unstable.
Systems with greater gain margins can withstand greater changes in system parameters before becoming unstable in closed-loop.

The phase margin is defined as the change in open-loop phase shift required to make the closed-loop system unstable.
The phase margin also measures the system's tolerance to time delay.

If there is a time delay greater than PM/omega in the loop (where omega is the frequency in rad/sec where the magnitude is 0 dB and PM is the phase margin converted to radians),
the closed-loop system will become unstable.

The time delay, tau, can be thought of as an extra block in the forward path of the block diagram that adds phase lag to the system, but has no effect on the gain.
That is, a time delay can be represented as a block with magnitude of 1 and phase -omega*tau.

The closed-loop system's phase margin is the additional amount of phase lag that is required for the open-loop system's phase
to reach -180 degrees at the frequency where the open-loop system's magnitude is 0 dB (the gain crossover frequency omega).
Likewise, the gain margin is the additional amount of gain (usually in dB) required for the open-loop system's magnitude to reach 0 dB
at the frequency where the open-loop system's phase equals -180 degrees (the phase crossover frequency, omega).

%}

s = tf('s');
G = 50/(s^3 + 9*s^2 + 30*s +40);

% print out what various gains does to the gain/phase margin
f = fopen('transfer_function_margins.txt', 'w');
fprintf(f, 'GAIN\tGAIN_MARGIN\tPHASE_MARGIN\n');
for i = 1:1000
	[Gm, Pm] = margin(i*G);
	fprintf(f, '%4d\t%8.4f\t%8.4f\n', i, Gm, Pm);
end

% When a gain is applied, the bode plot only shifts the y-axis of the magnitude plot
% the phase plot doesn't change, so we don't need to "redraw" the plot, just find the new zero crossing of the magnitude plot to find the new phase margin
fig = figure('visible', 'off');
clf;
bode(G);
margin(G);
grid on;
title('Bode Plot with No Gain');
saveas(fig, 'bode_plot_no_gain', 'png');

clf;
bode(100*G);
margin(100*G);
grid on;
title('Bode Plot with 100 Gain');
saveas(fig, 'bode_plot_100_gain', 'png');

clf;
nyquist(G);
saveas(fig, 'nyquist_plot', 'png');

%{

Test bandwidth by sending a input less than the omega_bw, view the steady state response
Since the sinusoidal input is less than the bandwidth frequency, the output looks pretty close to the input, small to no attenuation and small phase shift

%}

W = 1;
Z = 0.25;
bw = W*sqrt(1 - 2*Z^2 + sqrt(2 - 4*Z^2 + 4*Z^4));
G = 1/(s^2 + 0.5*s + 1);
w = 0.3;
t = 0:0.1:100;
u = sin(w*t);
[y, t] = lsim(G,u,t);
plot(t, y, t, u);
title(sprintf('test frequency: %.3f bandwidth: %.3f', w, bw));
axis([50 100 -2 2]);
saveas(fig, 'test_frequency_less_than_bandwidth', 'png');

%{

If the sinusoidal input is larger than bandwidth the output looks very attenuated (magnitude much less than input and large phase shift)

%}

w = bw + 0.1;
t = 0:0.1:100;
u = sin(w*t);
[y,t] = lsim(G,u,t);
plot(t,y,t,u)
axis([90 100 -1 1])
title(sprintf('test frequency: %3f bandwidth: %.3f', w, bw));
saveas(fig, 'test_frequency_greater_than_bandwidth', 'png');

%{

The Nyquist diagram allows us to predict the stability and performance of a closed-loop system by observing its open-loop behavior.
The Nyquist criterion can be used for design purposes regardless of open-loop stability (remember that the Bode design methods assume that the system is stable in open-loop).
Therefore, we use this criterion to determine closed-loop stability when the Bode plots display confusing information.

The Cauchy criterion (from complex analysis) states that when taking a closed contour in the complex plane, and mapping it through a complex function G(s),
the number of times that the plot of G(s) encircles the origin is equal to the number of zeros of G(s) enclosed by the frequency contour minus the number of poles of G(s) enclosed by the frequency contour.
Encirclements of the origin are counted as positive if they are in the same direction as the original closed contour or negative if they are in the opposite direction.

When studying feedback control, we are not as interested in G(s) and, rather, are more concerned with the closed-loop transfer function:

G(s) / (1 + G(s))

If 1 + G(s) encircles the origin, then G(s) will enclose the point -1. Since we are interested in the closed-loop stability, we want to know if there are any closed-loop poles (zeros of 1 + G(s) in the right-half plane.

%}

s = tf('s');
G = 0.5/(s - 0.5);
nyquist(G);
axis([-1 0 -1 1]);
title('Nyquist plot');
saveas(fig, 'nyquist_plot', 'png');
