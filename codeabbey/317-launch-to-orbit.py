#!/usr/bin/env python3

"""

This problem could be solved by manual trying some variants and submitting the answer, i.e. without writing the code. It's OK - we'll have another task for creating automated flight controller!

In the Apogee problem we learnt how the object freely flies around the planet (or any celestial body) in circles, or rather ellipses, which we call its orbit. But we skipped very interesting process - how this object gets to the desired obrit, starting from the planet surface?

Let's try to simulate the flight of the rocket from the ground, controlling it so it reaches certain height and certain speed - we now know the obrit is defined by them - after which the engines are automatically shut and the rocket proceeds its free flight as a satellite. Free flight here means not affected by other forces than gravity.

Input data will give two values - the height of the orbit, in kilometers and the speed required at this height. Moreover the speed should be horizontal (so it is perigee point, where we turn off engines and start free flight).

Answer should contain the sequence of control commands in the simple format described further - this "flight program" should allow to reach the desired height and speed.

Tolerance for height is 20km, for velocity 200m/s and for direction error should be less than 1 degree.

The Rocket and its Controls
The rocket has predetermined mass (272 tons, with fuel, 10 when empty) and predetermined thrust force (3 mega-Newtons). Also the rate of fuel burning is predetermined (800 kg per second). These values roughly correspond to the Sputnik Rocket which delivered the first satellite to the orbit.

We control the flight simply by changing the rocket attitude. For this "vernier thrusters" - small engines on the sides - are engaged to create some turning force. Regretfully it is not possible just to say "rocket, please magically turn to 45 degrees". You'll see this turning force creates rotational acceleration and the rocket changes its direction faster and faster. So you engage vernier thrusters on one side, wait for few seconds, then shut them and engage their counterparts on the other side, wait few seconds more for rotation to stop and then shut these too.

Acceleration of main engines and vernier thrusters is greater when rocket becomes lighter due to more and more fuel burnt out.

Engaging vernier thrusters is done by single value in the range -1 .. +1. Positive values make rocket start turning into direction in which we want to flow around the planet. Vernier thrusters do not waste fuel and the force could be set to any fraction.

Two more control commands are possible:

command stage can be used once, it stops all main engines except the central one, reducing thrust (and fuel consumption) 4 times
command off also is used once and stops all engines, ending "controlled" part of the flight
If the off command is not used, the controlled flight ends either with fuel going to zero (and rocket mass becoming 10 tons) - or with "self-destruction" which happens if the attitude gets out of the range -45 ... 135 degrees, or flight altitude becomes negative.

Flight Program Format
You won't sit in the rocket yourself, hands on the wheel or something like this (it could be dangerous) - instead you create a simple sequence of values, which are used by rocket computer. Sequence consists of pairs, meaning when and what to do. "When" is expressed in seconds from start, e.g.

10 1 30 -0.98 50 0 200 stage 210 0.005 700 off
means engage full force on vernier thruster to start turning into direction of the orbit (right) on the second 10, then "start stopping" the turning on the second 30 and turn off all vernier engines on the second 50. Reduce thrust 4 times at second 200 (as rocket becomes much lighter then and easier to lift and to turn). Engage turning on second 210 with very small force, so that rocket shall turn gradually all the remaining time. Shut the engines at second 700.

Trajectory calculation
We disclose the precise algorithm of how trajectory is calculated in a form of BASIC program. You can not only study it, but you can easily test it with your own flight program!

(UPD here is a Python version created for you by our colleague Mathias aka "gardengnome")

Copy-paste this into the "solution" area, adjust "flight program" in the first line and click "BASIC" button below. The output will be filled with tabulated data, of which three first columns (Time, X, Y) are used to plot trajectory in on a small "screen" below.

Remember however - for submission only "flight plan" in the "answer" field is important. For solution you can submit whatever you like (perhaps you'll decide to create some optimization search algorithm).

data 10, 1, 30, -0.98, 50, 0, 200, "stage", 210, 0.005, 700, "off" : rem flight program

re = 6371 * 1e3 : g = -9.81                            : rem earth size and gravity
m0 = 272 * 1e3 : vm = -800 : fth = 3e6                 : rem mass, fuel consumption, F thrust
dt = 1/4
att = 0 : va = 0 : fa = 0                              : rem attitude (rad), speed and F turning
pi = atn(1) * 4

x = 0 : y = re : m = m0                                : rem current coordinates and mass
vx = 0 : vy = 0 : t = 0                                : rem current speed and time

read tc                                                : rem next "control command" time

loop:
r = sqr(x^2 + y^2)                                     : rem linear and turning accelerations
ag = g * (re / r)^2 : ath = fth / m
ax = ag * x/r + ath * sin(att) : ay = ag * y/r + ath * cos(att)
da = 0.001 * (m0 / m) * fa

xn = x + vx * dt : yn = y + vy * dt                    : rem new values for coordinates
vx = vx + ax * dt : vy = vy + ay * dt                  : rem new values for speed
attn = att + va * dt : va = va + da * dt               : rem new attitude and its change speed
m = m + vm * dt : t = t + dt                           : rem reduce mass, increment time
x = xn : y = yn : att = attn                           : rem update coordinates and attitude

hei = sqr(x^2 + y^2) - re                              : rem current height
if t = int(t) then print t, int(x), int(y), int(hei), att, vx, vy
if att > pi or att < - pi/4 or hei < 0 then print "self-destroyed" : end
if m <= 10e3 then goto shutdown

if t < tc then goto loop                               : rem is it time to apply next command?
read cmd, tc
if cmd = "stage" then if vm <= -800 then vm = vm / 4 : fth = fth / 4 : print "staged" : goto loop
if cmd = "off" then print "shut off" : goto shutdown
fa = cmd
if fa > 1 then fa = 1
if fa < -1 then fa = -1
print "set Fa="; fa
goto loop

data 10000

shutdown:
at1 = atn(x / y)                                       : rem at1 is attitude of X, Y vector
if vx < vy then at2 = atn(vx / vy)                     : rem at2 is attitude of Vx, Vy vector
if vx >= vy then at2 = atn(vy / -vx) + pi / 2          : rem we use them to find direction error
err = at1 + pi/2 - at2
print "H:", int(hei), "V:", int(sqr(vx^2 + vy^2)), "direction error:", err * 180/pi, "degrees"
Flight Screen
This small display shows how your flight goes, according to the data in the "answer" box. Rocket starts in the bottom left corner, from the earth surface (green line) and should reach the expected height (blue line). Trajectory itself is marked with red and pink (in 15-second segments). Remember however it is necessary to "enter" the orbit with proper velocity and direction!

"""

from math import pi, sin, cos, atan
import matplotlib.pyplot as plt

# constants
R_EARTH = 6_371_000  # radius earth (m)
G = -9.81  # gravity of earth (m/s^2)

M0 = 272_000  # default mass of rocket (kg)
FTH = 3_000_000  # default thrust force (N = kg*m/s^2)
VM = -800  # default fuel burning rate (kg/s)
DT = 1 / 4  # deafult time step (s)

H_TOLERANCE = 20  # height tolerenace (km)
V_TOLERANCE = 200  # velocity tolerance (m/s)
A_TOLERANCE = 1.0  # angle tolerance (degree)


class Rocket:
    ON_GROUND, IN_FLIGHT, CRASH, SHUTDOWN = "on_ground", "in_flight", "crash", "shutdown"

    def __init__(self, mass_init, force_thrust, fuel_burning_rate, time_step, h_target, v_target):
        self.h_target = h_target  # target height (m)
        self.v_target = v_target  # target velocity (m/s)
        self.m0, self.m = mass_init, mass_init  # initial and current mass (kg)
        self.fth = force_thrust  # thrust force (N = kg*m/s^2)
        self.vm = fuel_burning_rate  # fuel burning rate (kg/s)
        self.x, self.y = [0.0], [R_EARTH]  # coordinates (m)
        self.vx, self.vy = 0.0, 0.0  # velocity (m/s)
        self.att = 0.0  # attitude / angle (radiant)
        self.va = 0.0  # attitude velocity
        self.fa = 0.0  # attitude turning force
        self.t, self.dt = 0.0, time_step  # time (s)
        self.stage = 0
        self.off = 0
        self.flight_status = Rocket.ON_GROUND
        self.show_output = False

    def height(self):
        return (self.x[-1] ** 2 + self.y[-1] ** 2) ** 0.5 - R_EARTH

    def velocity(self):
        return (self.vx ** 2 + self.vy ** 2) ** 0.5

    def height_error(self):
        return self.height() - self.h_target

    def velocity_error(self):
        return self.velocity() - self.v_target

    def angle_error(self):
        at1 = atan(self.x[-1] / self.y[-1])
        at2 = atan(self.vx / self.vy) if self.vx < self.vy else atan(self.vy / - self.vx) + pi / 2
        return (at1 + pi / 2 - at2) * 180 / pi  # corrected

    def set_show_output(self, yn):
        self.show_output = yn

    def set_flight_status(self, status):
        self.flight_status = status
        if self.show_output:
            print(f"t={self.t}: {self.flight_status}")

    def fly(self, program=None):
        self.set_flight_status(Rocket.IN_FLIGHT)
        while True:
            self.exec_move()
            if self.flight_status in [Rocket.CRASH, Rocket.SHUTDOWN]:
                break
            self.pilot(program)
            if self.stage:
                self.exec_stage()
            if self.off:
                self.set_flight_status(Rocket.SHUTDOWN)
                break

    def exec_move(self):
        r = (self.x[-1] ** 2 + self.y[-1] ** 2) ** 0.5
        ag = G * (R_EARTH / r) ** 2
        ath = self.fth / self.m
        ax = ag * self.x[-1] / r + ath * sin(self.att)
        ay = ag * self.y[-1] / r + ath * cos(self.att)
        da = 0.001 * (self.m0 / self.m) * self.fa
        self.x += [self.x[-1] + self.vx * self.dt]
        self.y += [self.y[-1] + self.vy * self.dt]
        self.vx += ax * self.dt
        self.vy += ay * self.dt
        self.att += self.va * self.dt
        self.va += da * self.dt
        self.m += self.vm * self.dt
        self.t += self.dt
        if self.show_output and self.t == int(self.t):
            print(f"t={self.t:,.0f}  "
                  f"x={self.x[-1]:,.0f}  y={self.y[-1]:,.0f}  h={self.height():,.0f}  "
                  f"vx={self.vx:,.0f}  vy={self.vy:,.0f}  v={self.velocity():,.0f}  "
                  f"att={self.att:,.2f}  fa={self.fa:,.4f}  m={self.m:,.0f}  "
                  f"h_error={self.height_error():,.0f}  "
                  f"v_error={self.velocity_error():,.0f}  "
                  f"a_error={self.angle_error():,.1f}  ")
        if self.att > pi or self.att < - pi / 4 or self.height() < 0:
            self.set_flight_status(Rocket.CRASH)
        elif self.m <= 10_000:
            self.set_flight_status(Rocket.SHUTDOWN)

    def exec_stage(self):
        if self.vm <= -800:
            self.vm /= 4.0
            self.fth /= 4.0
        if self.show_output:
            print(f"t={self.t}: stage")

    def pilot(self, program=None):
        if program is not None:
            self.stage, self.off = 0, 0
            for i in range(0, len(program), 2):
                tc, cmd = program[i], program[i + 1]
                if tc == self.t:
                    if cmd == "stage":
                        self.stage = 1
                    elif cmd == "off":
                        self.off = 1
                    else:
                        self.fa = min(1.0, max(-1.0, cmd))
                    return

    def display_flight(self):
        plt.plot([R_EARTH * cos(2 * pi / 1_000 * i) for i in range(1_000)],
                 [R_EARTH * sin(2 * pi / 1_000 * i) for i in range(1_000)],
                 "g-", label="earth")
        plt.plot([(R_EARTH + self.h_target) * cos(2 * pi / 1_000 * i) for i in range(1_000)],
                 [(R_EARTH + self.h_target) * sin(2 * pi / 1_000 * i) for i in range(1_000)],
                 "b--", label="orbit")
        plt.plot(self.x, self.y, "r-", label="rocket")
        plt.xlim([-500_000, 2_500_000])
        plt.ylim([R_EARTH - 300_000, R_EARTH + 1_000_000])
        plt.title("rocket flight")
        plt.legend()
        plt.show()


# inputs
h_target, v_target = 530, 8200

# ***CHANGE HERE*** manual flight program
program = [10, 1, 30, -0.98, 50, 0, 200, "stage", 210, 0.005, 700, "off"]

# simulate rocket path
rocket = Rocket(M0, FTH, VM, DT, h_target * 1_000, v_target)
rocket.set_show_output(True)
rocket.fly(program)

# results
print()
print(f"flight status: {rocket.flight_status}")
if rocket.flight_status == Rocket.SHUTDOWN:
    h_error = rocket.height_error() / 1_000
    v_error = rocket.velocity_error()
    a_error = rocket.angle_error()
    print(f"h_error: {h_error:.1f} km   {'(ok)' if abs(h_error) <= H_TOLERANCE else '(too large)'}")
    print(f"v_error: {v_error:.1f} m/s   {'(ok)' if abs(v_error) <= V_TOLERANCE else '(too large)'}")
    print(f"a_error: {a_error:.1f} degree   {'(ok)' if abs(a_error) <= A_TOLERANCE else '(too large)'}")
    print("flight program:", *program)

rocket.display_flight()
