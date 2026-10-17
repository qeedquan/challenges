#!/usr/bin/env python3

"""

Your Task
Write a program that displays a dot that moves toward the position of your mouse at 4 pixels per second. The dot must be 100 pixels big and the window must fill the computer screen.

Input
None

Output
A window showing an animated dot moving towards the mouse at a fixed, non-changing speed.

Scoring
This is code-golf, so the shortest code in bytes wins.

"""

import tkinter as tk
import numpy as np

def track_pointer(pointer, event):
    pointer[:] = event.x, event.y

def animate(canvas, marker, pointer, position):
    displacement = pointer - position
    step = displacement / np.sqrt(np.dot(displacement, displacement) + 0.1)
    canvas.move(marker, *step)
    position[:] += step
    canvas.after(9, lambda: animate(canvas, marker, pointer, position))

def main():
    root = tk.Tk()
    root.title("Follow The Dot")

    pointer = np.array([1.0, 1.0])
    position = np.zeros(2)

    canvas = tk.Canvas(root)
    canvas.pack()

    canvas.bind("<Motion>", lambda event: track_pointer(pointer, event))
    marker = canvas.create_oval(0, 0, 2, 2)

    animate(canvas, marker, pointer, position)
    root.mainloop()

main()

