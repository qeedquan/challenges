#!/usr/bin/env python3

"""

Your job is to animate this circle illusion. It looks like the points rotating inside of the circle, but they are actually just moving in straight lines.

https://i.sstatic.net/rsGXn.gif

Criterias
The result has to be animated. The way you do the animation is irrelevant, it can generate a .gif, it can draw to a window, some device screen or whatever.
This is a popularity contest, so you might want to add some additional features to your program to get more upvotes, for example varying the number of points.
The winner is the most upvoted valid answer 7 days after the last valid submission.
The answers that will actually implement points moving on straight lines and not another way around are more welcomed

"""

import turtle
import time
import sys
from math import sin, pi
from random import random

# ported from @trichoplax is on Codidact now solution

def circle_dance(population=11, resolution=480, loops=1, flip=0, lines=0):
    population = int(population)
    resolution = int(resolution)
    radius = 250
    screen = turtle.Screen()
    screen.tracer(0)
    if lines:
        arrange_lines(population, radius)
    turtles = [turtle.Turtle() for i in range(population)]
    for i in range(population):
        dancer = turtles[i]
        make_dancer(dancer, i, population)
    animate(turtles, resolution, screen, loops, flip, radius)


def arrange_lines(population, radius):
    artist = turtle.Turtle()
    for n in range(population):
        artist.penup()
        artist.setposition(0, 0)
        artist.setheading(n / population * 180)
        artist.forward(-radius)
        artist.pendown()
        artist.forward(radius * 2)
    artist.hideturtle()


def make_dancer(dancer, i, population):
    dancer.setheading(i / population * 180)
    dancer.color(random_turtle_colour())
    dancer.penup()
    dancer.shape('turtle')
    dancer.turtlesize(2)


def random_turtle_colour():
    return random() * 0.9, 0.5 + random() * 0.5, random() * 0.7


def animate(turtles, resolution, screen, loops, flip, radius):
    delay = 4 / resolution      # 4 seconds per repetition
    while True:
        for step in range(resolution):
            timer = time.perf_counter()
            phase = step / resolution * 2 * pi
            draw_dancers(turtles, phase, screen, loops, flip, radius)
            elapsed = time.perf_counter() - timer
            adjusted_delay = max(0, delay - elapsed)
            time.sleep(adjusted_delay)


def draw_dancers(turtles, phase, screen, loops, flip, radius):
    population = len(turtles)
    for i in range(population):
        individual_phase = (phase + i / population * loops * pi) % (2*pi)
        dancer = turtles[i]
        if flip:
            if pi / 2 < individual_phase <= 3 * pi / 2:
                dancer.settiltangle(180)
            else:
                dancer.settiltangle(0)
        distance = radius * sin(individual_phase)
        dancer.setposition(0, 0)
        dancer.forward(distance)
    screen.update()


def main():
    if len(sys.argv) < 2:
        print("usage: <n>")
        exit(2)
    
    circle_dance(int(sys.argv[1]))

main()
