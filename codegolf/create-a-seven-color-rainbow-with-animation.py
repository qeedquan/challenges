#!/usr/bin/env python3

"""

Goal
Use any graphics library or environment that can use colours and animation to create a rainbow.

Rules
The rings should emerge one by one in some kind of animation or succession
The rainbow must have at least 7 colours.
Winning Criteria

Fewest bytes wins.

"""

import pygame
import sys

def main():
    pygame.init()

    screen = pygame.display.set_mode((720, 360))
    pygame.display.set_caption("Rainbow")

    clock = pygame.time.Clock()

    color = pygame.Color(0, 0, 0)
    radius = 360
    while True:
        for ev in pygame.event.get():
            if ev.type == pygame.QUIT:
                pygame.quit()
                sys.exit(0)

        if radius > 0:
            color.hsla = (radius, 100, 50, 100)
            pygame.draw.circle(screen, color, (360, 360), radius)
            radius -= 1

        pygame.display.flip()
        clock.tick(60)

main()

