#!/usr/bin/env python3

"""

Please read the rules, and the bold areas as well.

Write a program in any language, so long as it has GUI support for a window system (cannot be text-consoles, etc., and must be a GUI/toolkit/window).

The program must say hello world in any manner (splash image, menu bar, status bar, title, video, message box, other widget stuff, etc.), so long as a GUI-compliant window appears and shows this text for three seconds.
The person who can code this in the least amount of code used, counted in bytes, will take the cake.

"""

import tkinter as tk
from tkinter import ttk
import sys

def bail():
    sys.exit(0)

def main():
    root = tk.Tk()
    root.title("Hello, World!")
    root.geometry("256x32")
    button = ttk.Button(root, text='Hello, World!')
    button.pack()
    root.after(3000, bail)
    root.mainloop()

main()
