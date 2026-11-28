#!/usr/bin/env python3

"""

https://en.wikipedia.org/wiki/Perceptron
https://en.wikipedia.org/wiki/Perceptrons_(book)

"""

import tkinter as tk
from torch import Tensor
import torch.nn as nn
import torch.optim as optim

class UI:
    def __init__(self):
        self.width = 800
        self.height = 800
        self.resolution = 32
        
        self.root = tk.Tk()
        self.root.geometry("%dx%d" % (self.width, self.height))
        self.root.title("XOR Problem")
        self.root.after(10, lambda: self.update())
        
        self.canvas = tk.Canvas(self.root, width=self.width, height=self.height, bg="white")
        self.canvas.pack()

        rows = self.height // self.resolution
        cols = self.width // self.resolution
        inputs = []
        rects = []
        texts = []
        for i in range(cols):
            for j in range(rows):
                x0 = i * self.resolution
                x1 = (i + 1) * self.resolution
                y0 = j * self.resolution
                y1 = (j + 1) * self.resolution
                rects.append(self.canvas.create_rectangle(x0, y0, x1, y1, fill="white"))
                texts.append(self.canvas.create_text(x0 + (x1-x0)//2, y0 + (y1-y0)//2, text="1.00", fill="white"))
                inputs.append([i/cols, j/rows])

        self.inputs = Tensor(inputs)
        self.rects = rects
        self.texts = texts

        self.model = nn.Sequential(
                         nn.Linear(2, 16),
                         nn.Sigmoid(),
                         nn.Linear(16, 1),
                         nn.Sigmoid(),
                     )
        self.criterion = nn.MSELoss()
        self.optimizer = optim.Adam(self.model.parameters(), lr=0.01)
    
    def learn(self):
        epochs = 5
        X_train = Tensor([[0, 0], [1, 0], [0, 1], [1, 1]])
        y_train = Tensor([[0], [1], [1], [0]])
        for epoch in range(epochs):
            y_pred = self.model(X_train)
            loss = self.criterion(y_pred, y_train)
            self.optimizer.zero_grad()
            loss.backward()
            self.optimizer.step()
        return self.model(self.inputs)

    def on_keypress(self, event):
        if event.keysym == "Escape":
            self.root.destroy()

    def update(self):
        y_pred = self.learn()
        for i in range(len(self.texts)):
            value = y_pred[i].item()
            bg = int(value * 255)
            fg = 255 - bg
            self.canvas.itemconfig(self.texts[i], text="%.2f" % (value), fill="#%02X%02X%02X" % (fg, fg, fg))
            self.canvas.itemconfig(self.rects[i], fill="#%02X%02X%02X" % (bg, bg, bg))

        self.root.after(10, lambda: self.update()) 

    def run(self):
        self.root.bind("<Key>", lambda event: self.on_keypress(event))
        self.root.mainloop()

def main():
    ui = UI()
    ui.run()

main()
