#!/usr/bin/env python3

import argparse
import torch
import torch.nn as nn
import torch.optim as optim

def classify(X):
    if sum(X) > 0.75:
        return torch.Tensor([1])
    return torch.Tensor([0])

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("-e", "--epochs", type=int, default=200, help="Number of epochs")
    parser.add_argument("-s", "--samples", type=int, default=10000, help="Number of samples")
    args = parser.parse_args()

    model = nn.Sequential(
                nn.Linear(3, 10),
                nn.ReLU(),
                nn.Linear(10, 5),
                nn.Tanh(),
                nn.Linear(5, 1),
                nn.Sigmoid(),
            )
   
    criterion = nn.MSELoss()
    optimizer = optim.Adam(model.parameters(), lr=0.01)
    
    samples = args.samples
    epochs = args.epochs
    X_train = torch.rand(samples, 3)
    y_train = torch.zeros(samples, 1)
    for i in range(samples):
        y_train[i] = classify(X_train[i]) 

    model.train()
    for epoch in range(epochs):
        y_pred = model(X_train)
        loss = criterion(y_pred, y_train)
        optimizer.zero_grad()
        loss.backward()
        optimizer.step()
        if (epoch + 1) % 10 == 0:
            print(f"Epoch [{epoch + 1}/{epochs}], Loss: {loss.item():.4f}")

    torch.save(model.state_dict(), 'weights.pth')

main()
