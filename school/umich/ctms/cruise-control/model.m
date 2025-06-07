%{

The purpose of the cruise control system is to maintain a constant vehicle speed despite external disturbances, such as changes in wind or road grade.
This is accomplished by measuring the vehicle speed, comparing it to the desired or reference speed, and automatically adjusting the throttle according to a control law.

Use a free-body diagram to generate the equations, get a mass-damper system out of it

m*v'(t) + b*v(t) = u

Since we are trying to control the speed, the output is velocity
y = v

Taking the laplace transform we get the following transfer function:

1/(m*s + b)

For this example, let's assume that the parameters of the system are:
(m)   vehicle mass          1000 kg
(b)   damping coefficient   50 N.s/m

%}

pkg load control;

% State space model
m = 1000;
b = 50;
F = 500;

A = -b/m;
B = 1/m;
C = 1;
D = 0;

cruise_ss = ss(A,B,C,D);

% Transfer function model
s = tf('s');
P_cruise = 1/(m*s + b);

% The two model is the same so the curves should match
fig = figure('visible', 'off');
step(cruise_ss, P_cruise);
saveas(fig, 'open_loop_step_response_unity', 'png');

%{

Here we are trying to design the system to get the response we want
We will apply a force of 500 N (step input of 500) and want the following behavior:

Rise time < 5 s
Overshoot < 10%
Steady-state error < 2%

First, just analyze it as an open loop with no controller and get the following:
DC gain: 10 m/s (22 mph)
Rise time: ~60 s (too slow) 

Single pole: -b/m

Since roots/poles are inherent to the system, applying a gain (step response) does not change locations of poles/zeros
It will affect the magnitude in the bode plot though

%}

u = F;
step(u*P_cruise);
saveas(fig, 'open_loop_step_response', 'png');

clf;
pzmap(P_cruise, '-', u*P_cruise, '--');
axis([-1 1 -1 1]);
saveas(fig, 'open_loop_pzmap', 'png');

clf;
bode(P_cruise, u*P_cruise);
saveas(fig, 'open_loop_bode', 'png');

%{

Now we have the open loop response, use feedback techniques to improve performance

Pole placement

%}

t = 0:0.1:10;
u = F*ones(size(t));
x0 = [0];
p1 = -1.5;
K = place(A,B,[p1]);
sys_cl = ss(A-B*K,B,C,D);

clf;
lsim(sys_cl, u, t, x0);
axis([0 10 0 0.35]);
saveas(fig, 'pole_placement', 'png');
