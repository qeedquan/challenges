#!/usr/bin/env python3

"""

My parents-in-law have a fishpond in their yard, filled with koi. It didn't really cross my mind until I noticed the following extract from my code.

',') & '_'

... I had fish-faces looking back at me from my screen...

Which has given me a great idea...

My quest for you, my dear golfers is to create a one-line ASCII aquarium, with the following rules:

The size of the aquarium from side of the tank to the other side of the tank should be no smaller than 60 characters and no bigger than 80 characters. Sides of the tank need to be indicated using the pipe/bar (|) character.
Fish must be able to "swim" left to right between the sides of the tank. As they will be turning, a front view is required for the transition from one direction to the other.
The fish must look like the following:

}}< }} ',') Fish swimming right
(',' {{ >{{ Fish swimming left
}}('_'){{ Fish facing the front
When a fish turns to change direction (30% chance), it must start from one direction, face the front, then face the other direction... Make sure there is ample room for the fish to turn, i.e. requires six spaces before the edge of the tank minimum...

Unless a fish is blowing a bubble or changing direction, it will continue in the direction it is facing, if it gets within six spaces of the side of the tank, it will change direction.
The fish (facing left or right) can on occasion (10% chance) stop to blow bubbles in succession (.oO*), so the fish is required to have a space available next to them in order for the bubble to exist, so a fish can only swim as close to the sides, save one space. The bubble must disappear before the fish can move on...
A series of example lines of the fish's behavior, with - characters indicating the spaces, as the code display feature on here is a little strict... I will expect these dashes to be replaced with spaces when you code this...

Each line here could be considered a frame in time-lapse.

|-}}< }} ',')----------|
|--}}< }} ',')---------|
|---}}< }} ',')--------|
|----}}< }} ',')-------|
|-----}}< }} ',')------|
|-----}}< }} ',').-----|
|-----}}< }} ',')o-----|
|-----}}< }} ',')O-----|
|-----}}< }} ',')*-----|
|---------}}('_'){{----|
|-----------(',' {{ >{{|
|----------(',' {{ >{{-|
|---------(',' {{ >{{--|
|--------.(',' {{ >{{--|
|--------o(',' {{ >{{--|
|--------O(',' {{ >{{--|
|--------*(',' {{ >{{--|
|--------(',' {{ >{{---|
|-------(',' {{ >{{----|
|------(',' {{ >{{-----|
etc. The above example is, as I said, small, but you get the general idea...

Shortest code wins...

I am expecting the output on the same line (if possible), if not, displaying frame after frame in succession is fine... Whether you go one line or multiple lines is up to you. If you are doing multiple lines, they must be separated by a newline.

Also a timer is imposed between frames, 2000ms . This is mandatory.

Let's see what you've got!

"""

from random import random
from time import sleep

# Ported from @poke solution
FISH = {
    1: "}}< }} ',')%s",
    0: "}}('_'){{%s",
    -1: "%s(',' {{ >{{",
}
BUBBLES = " .oO*"

position = 9
direction = 1
turning = 0
bubble = 0

while True:
    if turning:
        turn_distance = 4 if 2 * direction + turning == 1 else 1
        position -= turning * turn_distance
        if direction:
            direction = 0
        else:
            direction, turning = turning, 0
    elif bubble % 5:
        bubble += 1
    else:
        at_edge = position * direction in (-5, 53)
        if random() < 0.3 or at_edge:
            turning = -direction
        elif random() < 0.1:
            bubble = 1
        else:
            position += direction

    fish = FISH[direction] % BUBBLES[bubble % 5]
    print("|{:<70}|".format(" " * position + fish))
    sleep(2)
