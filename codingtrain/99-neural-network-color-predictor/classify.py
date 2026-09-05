#!/usr/bin/env python3

import cv2
import numpy as np
import torch
from torch import nn

def mouse_callback(event, x, y, flags, param):
    background = param
    if event == cv2.EVENT_LBUTTONDOWN:
        background[0] = torch.rand(1)
        background[1] = torch.rand(1)
        background[2] = torch.rand(1)

def load_model(name):
    model = nn.Sequential(
                nn.Linear(3, 10),
                nn.ReLU(),
                nn.Linear(10, 5),
                nn.Tanh(),
                nn.Linear(5, 1),
                nn.Sigmoid(),
            )
    weights = torch.load(name, weights_only=True)
    model.load_state_dict(weights)
    model.eval()
    return model

def main():
    model = load_model("weights.pth")
 
    background = torch.rand(3)
    width = 600
    height = 300
    window = "Color Classifier"
    cv2.namedWindow(window)
    cv2.setMouseCallback(window, mouse_callback, param=background)
    
    while True:
        image = np.zeros((height, width, 3), dtype=np.uint8)
        image[:] = background*255

        cv2.line(image, (width//2, 0), (width//2, height), (0, 0, 0), 2)
        cv2.putText(image, "Black", (100, 100), cv2.FONT_HERSHEY_DUPLEX, 1, (0, 0, 0), 1)
        cv2.putText(image, "White", (400, 100), cv2.FONT_HERSHEY_DUPLEX, 1, (255, 255, 255), 1)

        which = model(background)
        if which < 0.5:
            cv2.circle(image, center=(150, 200), radius=30, color=(0, 0, 0), thickness=-1)
        else:
            cv2.circle(image, center=(450, 200), radius=30, color=(255, 255, 255), thickness=-1)

        cv2.imshow(window, image)
    
        key = cv2.waitKey(10) & 0xFF
        if key == 27:
            break

    cv2.destroyAllWindows()

main()
