%{

The model of a PID controller is

Input -> Controller -> Plant -----> Output
       ^-----------------------^

with the equation:

u(t) = Kp*e(t) + Ki*Integral[e(t), dt] + Kp*de/dt

Taking the laplace transform we get:

Kp + Ki/s + Kd*s = (Kd*s^2 + Kp*s + Ki) / s

If all constants are 1 we have the following standard second order equation:

Kp = Ki = Kd = 1
(s^2 + s + 1) / s

Increasing the proportional gain (K_p) has the effect of proportionally increasing the control signal for the same level of error.
The fact that the controller will "push" harder for a given level of error tends to cause the closed-loop system to react more quickly, but also to overshoot more.
Another effect of increasing K_p is that it tends to reduce, but not eliminate, the steady-state error.

The addition of a derivative term to the controller K_d adds the ability of the controller to "anticipate" error.
With simple proportional control, if $K_p$ is fixed, the only way that the control will increase is if the error increases.
With derivative control, the control signal can become large if the error begins sloping upward, even while the magnitude of the error is still relatively small.
This anticipation tends to add damping to the system, thereby decreasing overshoot. The addition of a derivative term, however, has no effect on the steady-state error.

The addition of an integral term to the controller K_i tends to help reduce steady-state error. If there is a persistent, steady error, the integrator builds and builds, thereby increasing the control signal and driving the error down. A drawback of the integral term, however, is that it can make the system more sluggish (and oscillatory) since when the error signal changes sign, it may take a while for the integrator to "unwind."

The general effects of each controller parameter (K_p, K_d, K_i on a closed-loop system are summarized in the table below.
Note, these guidelines hold in many cases, but not all. If you truly want to know the effect of tuning the individual gains, you will have to do more analysis, or will have to perform testing on the actual system.


CL RESPONSE   RISE TIME    OVERSHOOT  SETTLING TIME  S-S ERROR
Kp            Decrease     Increase   Small change   Decrease
Ki            Decrease     Increase   Increase       Decrease
Kd            Small Change Decrease   Decrease       Small Change


%}

pkg load control;

Kp = 1;
Ki = 1;
Kd = 1;

s = tf('s');
C = Kp + Ki/s + Kd*s

% Another way to make a PID object
C = pid(Kp, Ki, Kd)

% Convert it to a transfer function
tf(C)

%{

Alot of physical system follow the form

G(s) = 1 / (a*s^2 + b*s + c) transfer function

If we set a = b = c = 1 and connect the system with a standard PID controller with Kp = Ki = Kd = 1,
the transfer function will become

H(s) = (s^2 + s + 1) / (s^3 + 2s^2 + 2s + 1)

So the transfer function becomes third order

%}

G = 1/(s^2 + s + 1);
feedback(C*G, 1)

%{

Given a mass-spring-damper system, we have the differential equation:

m*y''(t) + b*y'(t) + k*x = F

Take the laplace transform and simplify:
G(s) = X(s)/F(s) = 1/(m*s^2 + b*s + k)

Let
m = 1 kg
b = 10 N s/m
k = 20 N/m
F = 1 N

Plugging those values in, we get the following transfer function:

1/(s^2 + 10*s + 20)

Design specifications:
DC gain = 1

%}

%{

Model open loop response of the system

Observe the following characteristics:
DC gain - 1/20 = 0.05 (steady state final value)
Steady state error is 0.95 which is quite large (1 - 0.05)

Rise time is too slow, took 1.5 seconds

%}
fig = figure('visible', 'off');
s = tf('s');
P = 1/(s^2 + 10*s + 20);
step(P);
saveas(fig, 'open_loop_step_response', 'png');

%{

Add a P controller

T(s) = X(s)/R(s) = Kp / (s^2 + 10*s + (20 + Kp))

The step response shows the DC gain going up but not quite equal to 1
There is overshoot

%}

Kp = 300;
C = pid(Kp)
T = feedback(C*P,1)

step(T);
saveas(fig, 'p_step_response', 'png');

%{

Add a D term to make a PD controller

T(s) = X(s)/R(s) = (Kd*s + Kp) / (s^2 + (10 + Kd)*s + (20 + Kp))

%}


Kp = 300;
Kd = 10;
C = pid(Kp,0,Kd)
T = feedback(C*P,1)

step(T);
saveas(fig, 'pd_step_response', 'png');

%{

Add a I term to make a PI controller

T(s) = X(s)/R(s) = (Kp*s + Ki) / (s^3 + 10*s^2 + (20 + Kp)*s + Ki)

%}

Kp = 30;
Ki = 70;
C = pid(Kp,Ki)
T = feedback(C*P,1)

step(T);
saveas(fig, 'pi_step_response', 'png');

%{

Add a D and I term to make a PID controller

T(s) = X(s)/R(s) = (Kd*s^2 + Kp*s + Ki) / (s^3 + (10 + Kd)*s^2 + (20 + Kp)*s + Ki)

This works best from the plot since no overshoot, fast rise time, dc gain reached

%}

Kp = 350;
Ki = 300;
Kd = 50;
C = pid(Kp,Ki,Kd)
T = feedback(C*P,1)

step(T);
saveas(fig, 'pid_step_response', 'png');
