#!/usr/bin/env python3

import tkinter as tk
import random
import re

class UI:
    width = 800
    height = 600

    words = []
    fg = []
    bg = []
    
    root = None
    frame = None
    labels = []

    def __init__(self):
        self.load_words("rainbow.txt")

        self.root = tk.Tk()
        self.root.geometry("%dx%d" % (self.width, self.height))
        self.root.title("Word Interactor")
        
        self.frame = tk.Frame(self.root)
        self.frame.grid(sticky="news")
        
        self.labels = []
        index = 0
        for word in self.words:
            label = tk.Label(self.frame, text=word, padx=0, bd=0)
            label.bind("<Enter>", self.on_label_hilight(index))
            self.labels.append(label)
            index += 1
        self.refresh_widgets()

    def on_label_hilight(self, index):
        def handle(event):
            if not re.search(r"(\w)+", self.words[index]):
                return
            self.words[index] = "rainbow"
            self.fg[index] = f"#{random.randint(0, 0xFFFFFF):06x}"
            self.bg[index] = f"#{random.randint(0, 0xFFFFFF):06x}"
            self.labels[index].config(text=self.words[index], fg=self.fg[index], bg=self.bg[index])
        return handle

    def on_keypress(self, event):
        if event.keysym == "Escape":
            self.root.destroy()

    def on_configure(self, event):
        self.width = self.root.winfo_width()
        self.height = self.root.winfo_height()
        self.frame.config(width=self.width, height=self.height)
        self.refresh_widgets()

    def refresh_widgets(self):
        i = x = y = 0
        for label in self.labels:
            lw = label.winfo_width()
            lh = label.winfo_height()
            if x + lw >= self.width:
                x = 0
                y += lh
            label.place(x=x, y=y)
            x += lw

    def load_words(self, name):
        self.words = []
        try:
            file = open(name, "r", encoding="utf-8")
            text = file.read()
            text = text.strip()
            file.close()

            self.words = []
            for word in re.split(r"(\W+)", text):
                if word != "":
                    self.words.append(word)
            self.fg = [""] * len(self.words)
            self.bg = [""] * len(self.words)
        except:
            print("WARN: Failed to load word file.")

    def run(self):
        self.root.bind("<Key>", lambda event: self.on_keypress(event))
        self.root.bind("<Configure>", lambda event: self.on_configure(event))
        self.root.mainloop()

def main():
    ui = UI()
    ui.run()

main()
